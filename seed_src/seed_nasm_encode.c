#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"


void clear_temp_files(void)
{
    // Close any existing temp files
    if (temp_text_file) {
        fclose(temp_text_file);
        temp_text_file = NULL;
    }
    if (temp_data_file) {
        fclose(temp_data_file);
        temp_data_file = NULL;
    }
    if (temp_bss_file) {
        fclose(temp_bss_file);
        temp_bss_file = NULL;
    }

    // Create new temporary files
    temp_text_file = tmpfile();
    temp_data_file = tmpfile();
    temp_bss_file = tmpfile();

    if (!temp_text_file || !temp_data_file || !temp_bss_file) {
        fprintf(stderr, "Failed to create temporary files: %s\n", strerror(errno));
        // Cleanup any files that were created
        if (temp_text_file) fclose(temp_text_file);
        if (temp_data_file) fclose(temp_data_file);
        if (temp_bss_file) fclose(temp_bss_file);
        temp_text_file = temp_data_file = temp_bss_file = NULL;
        exit(1);
    }
}

void encode_universal_scope_section(FILE* output, const char* label, enum scope_type scope)
{
    (void)output;  // Mark as intentionally unused
    (void)scope;   // Mark as intentionally unused
    
    if (!temp_text_file || !label) return;

    fprintf(temp_text_file, "global %s\n", label);
    fprintf(temp_text_file, "%s:\n", label);              // jmp not needed here because .code section handles it 
}


void encode_global_scope_section(FILE* output, const char* label, enum scope_type scope)
{
    (void)output;  // Mark as intentionally unused
    (void)scope;   // Mark as intentionally unused
    
    if (!temp_text_file || !label) return;

    fprintf(temp_text_file, "%s:\n", label);
}

void encode_global_block_scope_section(FILE* output, const char* label, enum scope_type scope)
{
    // Global blocks go in .text
    fprintf(temp_text_file, "\n; Global block: %s\n", label);
    fprintf(temp_text_file, "%s:\n", label);
}

void encode_local_scope_section(FILE* output, const char* label, enum scope_type scope)
{
    // Local functions go in .text
    fprintf(temp_text_file, "\n; Local function: %s\n", label);
    fprintf(temp_text_file, "%s:\n", label);
    // Add function prologue
    fprintf(temp_text_file, "    push ebp\n");
    fprintf(temp_text_file, "    mov ebp, esp\n");
}


void encode_file_section(const char* ident, int type, enum scope_type scope)
{
    if (!temp_bss_file) return;
    
    switch(type) {
        case tool_extern:           fprintf(temp_text_file, "\textern %s\n", ident);      break;
        default: break;
    }
}

void encode_declare_section(const char* ident, int type, enum scope_type scope)
{
    if (!temp_bss_file) return;
    
    switch(type) {
        case tool_hold:             fprintf(temp_bss_file, "\t%s resd 1\n", ident);       break;
        case tool_aisle:            fprintf(temp_bss_file, "\t%s resd 1\n", ident);       break;
        case tool_aisle_ptr:        fprintf(temp_bss_file, "\t%s resd 1\n", ident);       break;
        default: break;
    }
}

void encode_literal_section(const char* ident, const char* value, int length)
{
    if (!temp_data_file || !ident || !value) return;
    
    // First write the string
    fprintf(temp_data_file, "\t%s db \"%s\"\n", ident, value);
    fprintf(temp_data_file, "\t%s equ $ - %s\n", ident, ident);
}

void encode_assign_section(const char* ident, int value, enum scope_type scope)
{
    if (!temp_data_file) return;
    fprintf(temp_data_file, "\t%s dd %d\n", ident, value);
}

void finalize_nasm_output(FILE* output)
{
    if (!output) return;

    // Write NASM header
    fprintf(output, "BITS %d\n\n", get_architecture());

    // Write BSS section first (uninitialized data)
    fprintf(output, "section .bss\n");
    if (temp_bss_file) {
        copy_temp_file_contents(temp_bss_file, output);
    }
    fprintf(output, "\n");

    // Write DATA section second (initialized data)
    fprintf(output, "section .data\n");
    if (temp_data_file) {
        copy_temp_file_contents(temp_data_file, output);
    }
    fprintf(output, "\n");

    // Write TEXT section last (code)
    fprintf(output, "section .text\n");
    if (temp_text_file) {
        copy_temp_file_contents(temp_text_file, output);
    }
}



void encode_instruction(const char* instr, const char* dest, const char* src)
{
    if (!temp_text_file || !instr || !dest) return;

    if (src && *src) {
        // Two operands
        fprintf(temp_text_file, "\t%s %s, %s\n", instr, dest, src);
    } else {
        // Single operand
        fprintf(temp_text_file, "\t%s %s\n", instr, dest);
    }
}

void encode_register(const char* reg, char* nasm_reg)
{
    if (!reg || !nasm_reg) return;
    strcpy(nasm_reg, reg); // For now, just copy as-is since we're using same names
}






void encode_fetch_reference(const char* dest, const char* src, bool is_dest)
 {
    if (!temp_text_file || !dest) return;

    // Adjust encoding based on whether it's the destination or source
    if (is_dest) {
        // For destination
        fprintf(temp_text_file, "\tmove [%s], %s\n", dest, src);
    } else {
        // For source
        fprintf(temp_text_file, "\tmove %s, [%s]\n", dest, src);
    }
}

// For push/pop instructions
void encode_push_instruction(const char* reg)
{
    if (!temp_text_file || !reg) return;
    fprintf(temp_text_file, "\tpush %s\n", reg);
}

void encode_pop_instruction(const char* reg)
{
    if (!temp_text_file || !reg) return;
    fprintf(temp_text_file, "\tpop %s\n", reg);
}

// For call instructions
void encode_call_manager_instruction(const char* label)
{
    if (!temp_text_file || !label) return;
    fprintf(temp_text_file, "\tcall %s\n", label);
}

void encode_call_function_instruction(const char* label_one, const char* label_two)
{
    if (!temp_text_file || !label_one || !label_two) return;
    fprintf(temp_text_file, "\tcall %s.%s\n", label_one, label_two);
}

// For jump instructions
void encode_jump_instruction(const char* label)
{
    if (!temp_text_file || !label) return;
    fprintf(temp_text_file, "\tjmp %s\n", label);
}

void encode_jump_less_instruction(const char* label)
{
    if (!temp_text_file || !label) return;
    fprintf(temp_text_file, "\tjmp %s\n", label);
}

void encode_jump_neg_instruction(const char* label)
{
    if (!temp_text_file || !label) return;
    fprintf(temp_text_file, "\tjmp %s\n", label);
}


// For numeric/system call instructions
void encode_numeric_instruction(const char* value)
{
    if (!temp_text_file || !value) return;
    fprintf(temp_text_file, "\tint %s\n", value);
}

// For pass_arg instructions
void encode_pass_arg_instruction(const char* reg)
{
    if (!temp_text_file || !reg) return;
    fprintf(temp_text_file, "\tmov eax, %s\n", reg);
}

void encode_compare_instruction(const char* reg1, const char* reg2)
{
    if (!temp_text_file || !reg1 || !reg2) return;
    fprintf(temp_text_file, "\tcmp %s, %s\n", reg1, reg2);
}

// For set_flag instructions
void encode_set_flag_instruction(const char* reg1, const char* reg2)
{
    if (!temp_text_file || !reg1 || !reg2) return;
    fprintf(temp_text_file, "\txor %s, %s\n", reg1, reg2);
}
// For test instructions
void encode_test_instruction(const char* reg1, const char* reg2)
{
    if (!temp_text_file || !reg1 || !reg2) return;
    fprintf(temp_text_file, "\ttest %s, %s\n", reg1, reg2);
}


void encode_lend_instruction(const char* reg1)
{
    if (!temp_text_file || !reg1) return;
    fprintf(temp_text_file, "\tint 0x%02X\n\n", reg1);
}



int get_architecture(void)
{
    return 32; // Default to 32-bit for now
}

void set_architecture(int bits)
{
    // Implementation for setting architecture bits
}


void copy_temp_file_contents(FILE* temp, FILE* output)
{
    char buffer[1024];
    size_t bytes;
    
    rewind(temp);
    while ((bytes = fread(buffer, 1, sizeof(buffer), temp)) > 0) {
        fwrite(buffer, 1, bytes, output);
    }
    fflush(output);
}
