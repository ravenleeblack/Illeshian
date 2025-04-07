#include "comp_def.h"  
#include "comp_data.h"   
#include "comp_decl.h" 

// File handle for output assembly
FILE* nasm_out = NULL;

// Basic section generation
void generate_section_data(void)
{
    fprintf(nasm_out, "section .data\n");
    // Add any universal scope data (logs/lists) here
}

void generate_section_bss(void)
{
    fprintf(nasm_out, "section .bss\n");
    // Add any uninitialized data here
}

void generate_section_text(void)
{
    fprintf(nasm_out, "section .text\n");
    fprintf(nasm_out, "global _start\n");  // NASM entry point
    
    // Generate _start that calls main
    fprintf(nasm_out, "_start:\n");
    fprintf(nasm_out, "    call main\n");
    fprintf(nasm_out, "    mov rdi, rax\n");  // Exit code from main
    fprintf(nasm_out, "    mov rax, 60\n");   // sys_exit
    fprintf(nasm_out, "    syscall\n\n");
}

// Manager/Function prologue and epilogue
void generate_manager_prologue(const char* name)
{
    fprintf(nasm_out, "%s:\n", name);
    fprintf(nasm_out, "    push rbp\n");
    fprintf(nasm_out, "    mov rbp, rsp\n");
}

void generate_manager_epilogue(void)
{
    fprintf(nasm_out, "    mov rsp, rbp\n");
    fprintf(nasm_out, "    pop rbp\n");
    fprintf(nasm_out, "    ret\n");
}

// Initialize code generation
int init_code_gen(const char* output_file)
{
    nasm_out = fopen(output_file, "w");
    if (!nasm_out) return 0;
    return 1;
}

// Close code generation
void close_code_gen(void)
{
    if (nasm_out) {
        fclose(nasm_out);
        nasm_out = NULL;
    }
}

// Main code generation function
int generate_code(void)
{
    // Generate assembly sections
    generate_section_data();
    generate_section_bss();
    generate_section_text();

    // Process universal scope first (globals, prototypes, etc)
    generate_universal_scope();
    

    return 1;
}

// Generate code from universal scope entries
void generate_universal_scope(void)
{
    // Iterate through universal scope table
    for (int i = 0; i < scope_total_entries; i++) {
        if (universal_scope.entries[i].scope_table_flags == scope_flag_active) {
            generate_universal_entry(&universal_scope.entries[i]);
        }
    }
}

// Generate assembly for log data tool
void generate_log(struct scope_table_entry* entry)
{
    // Generate struct in data section
    fprintf(nasm_out, "; Log: %s\n", entry->scope_table_name);
    fprintf(nasm_out, "struc %s\n", entry->scope_table_name);
    
    // Process log members from universal scope
    for (int i = 0; i < scope_total_entries; i++) {
        if (universal_scope.entries[i].scope_table_flags == scope_flag_active &&
            universal_scope.entries[i].scope_table_tool_type == scope_tool_log &&
            strcmp(universal_scope.entries[i].manager_name, entry->scope_table_name) == 0) {
            
            switch(universal_scope.entries[i].scope_table_data_type) {
                case type_num:
                    fprintf(nasm_out, "    .%s: resd 1\n", 
                            universal_scope.entries[i].scope_table_name);
                    break;
                case type_mark:
                    fprintf(nasm_out, "    .%s: resb 1\n",
                            universal_scope.entries[i].scope_table_name);
                    break;
                // Add other types as needed
            }
        }
    }
    fprintf(nasm_out, "endstruc\n\n");
}

// Generate assembly for list data tool
void generate_list(struct scope_table_entry* entry)
{
    // Generate enum values
    fprintf(nasm_out, "; List: %s\n", entry->scope_table_name);
    fprintf(nasm_out, "%%define enum_%s_start 0\n", entry->scope_table_name);
    
    int enum_value = 0;
    // Process list items from universal scope
    for (int i = 0; i < scope_total_entries; i++) {
        if (universal_scope.entries[i].scope_table_flags == scope_flag_active &&
            universal_scope.entries[i].scope_table_tool_type == scope_tool_list &&
            strcmp(universal_scope.entries[i].manager_name, entry->scope_table_name) == 0) {
            
            fprintf(nasm_out, "%%define %s_%s %d\n",
                    entry->scope_table_name,
                    universal_scope.entries[i].scope_table_name,
                    enum_value++);
        }
    }
    fprintf(nasm_out, "%%define enum_%s_end %d\n\n", 
            entry->scope_table_name, enum_value);
}

// Generate assembly for hold data tool
void generate_hold(struct scope_table_entry* entry)
{
    // TODO: Implement hold generation
    fprintf(nasm_out, "; Generating hold: %s\n", entry->scope_table_name);
}

// Generate assembly for assign data tool
void generate_assign(struct scope_table_entry* entry)
{
    // TODO: Implement assign generation
    fprintf(nasm_out, "; Generating assign: %s\n", entry->scope_table_name);
}

// Generate assembly for function
void generate_function(struct scope_table_entry* entry)
{
    // Local labels in NASM start with .
    fprintf(nasm_out, ".%s:\n", entry->scope_table_name);
    fprintf(nasm_out, "    push rbp\n");
    fprintf(nasm_out, "    mov rbp, rsp\n");
    
    // Function body generation here
    
    fprintf(nasm_out, "    mov rsp, rbp\n");
    fprintf(nasm_out, "    pop rbp\n");
    fprintf(nasm_out, "    ret\n");
}




// Generate code for a universal scope entry
void generate_universal_entry(struct scope_table_entry* entry)
{
    switch (entry->scope_table_tool_type) {
        case scope_tool_log:
            generate_log(entry);
            break;
        case scope_tool_list:
            generate_list(entry);
            break;
        // Add other universal scope tools
    }
}

// Generate code for a manager entry
void generate_manager_entry(struct scope_table_entry* entry)
{
    if (entry->scope_table_tool_type == scope_tool_manager) {
        generate_manager_prologue(entry->scope_table_name);
        
        // Generate manager body by processing global scope
        generate_manager_body(entry);
        
        generate_manager_epilogue();
    }
}

// Generate manager body code
void generate_manager_body(struct scope_table_entry* manager_entry)
{
    // Process global scope entries for this manager
    for (int i = 0; i < scope_total_entries; i++) {
        if (global_scope.entries[i].scope_table_flags == scope_flag_active) {
            // Check if entry belongs to this manager using manager_name field
            if (strcmp(global_scope.entries[i].manager_name, manager_entry->scope_table_name) == 0) {
                generate_global_entry(&global_scope.entries[i]);
            }
        }
    }
}

// Generate code for global scope entry
void generate_global_entry(struct scope_table_entry* entry)
{
    switch (entry->scope_table_tool_type) {
        case scope_tool_hold:
            generate_hold(entry);
            break;
        case scope_tool_assign:
            generate_assign(entry);
            break;
        case scope_tool_function:
            generate_function(entry);
            break;
        // Add other global scope tools
    }
}



