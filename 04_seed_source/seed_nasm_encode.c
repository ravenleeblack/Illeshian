#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"


// Function to encode a Seedling universal scope section to NASM
void encode_universal_scope_section(FILE* output, const char* label_name, enum scope_type scope)
{
    output = fopen("temp_text.asm", "a");
    if (!output) {
        fprintf(stderr, "Error: Unable to open temp_data.asm\n");
        return;
    }
    fprintf(output, "section .text\n");
    fprintf(output, "%s:\n\n", label_name);
    fclose(output);
}

void output_code_section_header() 
{
    FILE* output = fopen("temp_text.asm", "a");
    if (!output) {
        fprintf(stderr, "Error: Unable to open temp_text.asm\n");
        return;
    }
    // Generate NASM code section 
    fprintf(output, "section .text\n");
    fclose(output);
}
// Function to encode a Seedling manager or global scope to NASM
void encode_manager_to_nasm(FILE* output, const char* label_name)
{
    output = fopen("temp_text.asm", "a");
    if (!output) {
        fprintf(stderr, "Error: Unable to open temp_data.asm\n");
        return;
    }
    
    fprintf(output, "global %s\n", label_name);
    fprintf(output, "%s:\n", label_name);

    fprintf(output, "    ret                 ; Return the result in eax\n");
    fclose(output);
}



// Function to encode a Seedling global scope section to NASM
void encode_global_scope_section(FILE* output, const char* label) {
    if (output == NULL) {
        fprintf(stderr, "Error: output is NULL in encode_global_scope_section\n");
        return; // Check for null pointer
    }
    // Generate NASM code for the global scope section
    fprintf(output, "section .%s\n", label);
}

// Function to encode a Seedling scope to NASM section
void encode_scope_to_nasm(const char* scope_name, const char* label)
 {
    FILE* output = fopen("temp_data.asm", "a");
    if (!output) {
        fprintf(stderr, "Error: Unable to open temp_data.asm\n");
        return;
    }
    fprintf(output, "section .data\n");
    fprintf(output, "%s:\n", label);
    fclose(output);
}


// Function to encode a Seedling function or local scope to NASM
void encode_function_to_nasm(const char* func_name, const char* arg1, const char* arg2) 
{
    FILE* output = fopen("temp_text.asm", "a");
    if (!output) {
        fprintf(stderr, "Error: Unable to open temp_text.asm\n");
        return;
    }
    // Generate NASM code for the function
    fprintf(output, "local %s\n", func_name);
    fprintf(output, "%s:\n", func_name);
    fprintf(output, "    ; Function to add two numbers\n");
    fprintf(output, "    ; Arguments: eax (%s), ebx (%s)\n", arg1, arg2);
    fprintf(output, "    add eax, ebx        ; Add the two numbers\n");
    fprintf(output, "    ret                 ; Return the result in eax\n");
    fclose(output);
}

void output_declare_section_header() 
{
    FILE* output = fopen("temp_bss.asm", "a");
    if (output == NULL) {
        fprintf(stderr, "Error: nasm_out is NULL in encode_declare_section\n");
        return; // Check for null pointer
    }
    // Generate NASM code for the declare section
    fprintf(output, "section .bss\n");
    fclose(output);
}

// Function to encode a Seedling declare section to NASM
void output_declare_section_body(const char* ident, int type) 
{
    FILE* output = fopen("temp_bss.asm", "a");
    if (output == NULL) {
        fprintf(stderr, "Error: nasm_out is NULL in encode_declare_section\n");
        return; // Check for null pointer
    }
    // Generate NASM code for the declare section body
    fprintf(output, "    %s resb %d\n", ident, type); // Assuming 'type' is the size in bytes
    fclose(output);
}

/*This function is only to output the section header. I am thinking that I may need to call this outside
the loop in finalize nasm function so that we do not get a ton of repeated section headers. Then we the
output_assign_section_body function in the assign parse function in order to assign every placeholder or 
variable that comes through. This allows us to remove the section header from the body so it doesnt get 
re-called over and over.*/
void output_assign_section_header()
{
    FILE* output = fopen("temp_data.asm", "a");
    if (!output) {
        fprintf(stderr, "Error: Unable to open temp_bss.asm\n");
        return;
    }
    // Generate NASM code for the assign section
    fprintf(output, "section .data\n");
    fclose(output);
}

/* Function to encode a Seedling assign section to NASM  */
void output_assign_section_body(const char* ident, int type)
{
    FILE* output = fopen("temp_data.asm", "a");
    if (!output) {
        fprintf(stderr, "Error: Unable to open temp_bss.asm\n");
        return;
    }
    fprintf(output, "    %s db %d\n", ident, type); // Assuming 'type' is the size in bytes
    fclose(output);
}



// Function to encode a Seedling instruction to NASM
void encode_instruction(const char* instr, const char* dest, const char* src) {
    FILE* output = fopen("temp_text.asm", "a");
    if (!output) {
        fprintf(stderr, "Error: Unable to open temp_text.asm\n");
        return;
    }
    fprintf(stderr, "Debug: Encoding instruction %s %s, %s\n", instr, dest, src);
    // Generate NASM code for the instruction
    fprintf(output, "    %s %s, %s\n", instr, dest, src);
    fclose(output);
}

// Function to encode a Seedling call function instruction to NASM
void encode_call_function_instruction(const char* label_one, const char* label_two) {
    if (nasm_out == NULL) {
        fprintf(stderr, "Error: nasm_out is NULL in encode_call_function_instruction\n");
        return; // Check for null pointer
    }
    // Generate NASM code for the call function instruction
    fprintf(nasm_out, "    call %s\n", label_one);
    fprintf(nasm_out, "    call %s\n", label_two);
}

// Function to encode a Seedling call manager instruction to NASM
void encode_call_manager_instruction(const char* label) {
    if (nasm_out == NULL) {
        fprintf(stderr, "Error: nasm_out is NULL in encode_call_manager_instruction\n");
        return; // Check for null pointer
    }
    // Generate NASM code for the call manager instruction
    fprintf(nasm_out, "    call %s\n", label);
}

// Function to encode a Seedling global block scope section to NASM
void encode_global_block_scope_section(FILE* output, const char* label) {
    if (output == NULL) {
        fprintf(stderr, "Error: output is NULL in encode_global_block_scope_section\n");
        return; // Check for null pointer
    }
    // Generate NASM code for the global block scope section
    fprintf(output, "section .%s\n", label);
}


// Function to encode a Seedling lend instruction to NASM
void encode_lend_instruction(const char* reg1) {
    if (nasm_out == NULL) {
        fprintf(stderr, "Error: nasm_out is NULL in encode_lend_instruction\n");
        return; // Check for null pointer
    }
    // Generate NASM code for the lend instruction
    fprintf(nasm_out, "    lend %s\n", reg1);
}

// Function to encode a Seedling literal section to NASM
void encode_literal_section(const char* value, int length)
 {
    if (nasm_out == NULL) {
        fprintf(stderr, "Error: nasm_out is NULL in encode_literal_section\n");
        return; // Check for null pointer
    }
    // Generate NASM code for the literal section
    fprintf(nasm_out, "    db %s, %d\n", value, length);
}

// Function to encode a Seedling local scope section to NASM
void encode_local_scope_section(FILE* output, const char* label)
 {
    if (output == NULL) {
        fprintf(stderr, "Error: output is NULL in encode_local_scope_section\n");
        return; // Check for null pointer
    }
    // Generate NASM code for the local scope section
    fprintf(output, "section .%s\n", label);
}

// Function to encode a Seedling file section to NASM
void encode_file_section(const char* ident)
{
    if (nasm_out == NULL) {
        fprintf(stderr, "Error: nasm_out is NULL in encode_file_section\n");
        return; // Check for null pointer
    }
    // Generate NASM code for the file section
    fprintf(nasm_out, "; File section: %s\n", ident);
}





// Function to encode a Seedling fetch reference to NASM
void encode_fetch_reference(const char* dest, const char* src) {
    if (nasm_out == NULL) {
        fprintf(stderr, "Error: nasm_out is NULL in encode_fetch_reference\n");
        return; // Check for null pointer
    }
    // Generate NASM code for the fetch reference
    fprintf(nasm_out, "    mov %s, %s\n", dest, src);
}

// Function to encode a Seedling jump instruction to NASM
void encode_jump_instruction(const char* label) {
    if (nasm_out == NULL) {
        fprintf(stderr, "Error: nasm_out is NULL in encode_jump_instruction\n");
        return; // Check for null pointer
    }
    // Generate NASM code for the jump instruction
    fprintf(nasm_out, "    jmp %s\n", label);
}

// Function to encode a Seedling jump less instruction to NASM
void encode_jump_less_instruction(const char* label) {
    if (nasm_out == NULL) {
        fprintf(stderr, "Error: nasm_out is NULL in encode_jump_less_instruction\n");
        return; // Check for null pointer
    }
    // Generate NASM code for the jump less instruction
    fprintf(nasm_out, "    jl %s\n", label);
}

// Function to encode a Seedling jump neg instruction to NASM
void encode_jump_neg_instruction(const char* label) {
    if (nasm_out == NULL) {
        fprintf(stderr, "Error: nasm_out is NULL in encode_jump_neg_instruction\n");
        return; // Check for null pointer
    }
    // Generate NASM code for the jump neg instruction
    fprintf(nasm_out, "    jng %s\n", label);
}

// Function to encode a Seedling set flag instruction to NASM
void encode_set_flag_instruction(const char* reg1, const char* reg2) {
    if (nasm_out == NULL) {
        fprintf(stderr, "Error: nasm_out is NULL in encode_set_flag_instruction\n");
        return; // Check for null pointer
    }
    // Generate NASM code for the set flag instruction
    fprintf(nasm_out, "    set %s, %s\n", reg1, reg2);
}

// Function to encode a Seedling test instruction to NASM
void encode_test_instruction(const char* reg1, const char* reg2) {
    if (nasm_out == NULL) {
        fprintf(stderr, "Error: nasm_out is NULL in encode_test_instruction\n");
        return; // Check for null pointer
    }
    // Generate NASM code for the test instruction
    fprintf(nasm_out, "    test %s, %s\n", reg1, reg2);
}

// Function to encode a Seedling push instruction to NASM
void encode_push_instruction(const char* reg) {
    if (nasm_out == NULL) {
        fprintf(stderr, "Error: nasm_out is NULL in encode_push_instruction\n");
        return; // Check for null pointer
    }
    // Generate NASM code for the push instruction
    fprintf(nasm_out, "    push %s\n", reg);
}

// Function to encode a Seedling pop instruction to NASM
void encode_pop_instruction(const char* reg) {
    if (nasm_out == NULL) {
        fprintf(stderr, "Error: nasm_out is NULL in encode_pop_instruction\n");
        return; // Check for null pointer
    }
    // Generate NASM code for the pop instruction
    fprintf(nasm_out, "    pop %s\n", reg);
}

// Function to encode a Seedling number to NASM
void encode_number(int num) {
    if (nasm_out == NULL) {
        fprintf(stderr, "Error: nasm_out is NULL in encode_number\n");
        return; // Check for null pointer
    }
    fprintf(stderr, "Debug: Encoding number 0x%X\n", num);
    // Generate NASM code for the number
    fprintf(nasm_out, "    mov eax, 0x%X\n", num);
}

// Function to finalize NASM output
void finalize_nasm_output(FILE* output) {
    if (output == NULL) {
        fprintf(stderr, "Error: output is NULL in finalize_nasm_output\n");
        return; // Check for null pointer
    }

    // Append contents of temp_data.asm
    FILE* temp_data = fopen("temp_data.asm", "r");
    if (temp_data) {
        char buffer[256];
        while (fgets(buffer, sizeof(buffer), temp_data)) {
            fputs(buffer, output);
        }
        fclose(temp_data);
    } else {
        fprintf(stderr, "Error: Unable to open temp_data.asm\n");
    }

    // Append contents of temp_bss.asm
    FILE* temp_bss = fopen("temp_bss.asm", "r");
    if (temp_bss) 
    {
        char buffer[256];

        while (fgets(buffer, sizeof(buffer), temp_bss)) {
            fputs(buffer, output);
        }
        fclose(temp_bss);
    } else {
        fprintf(stderr, "Error: Unable to open temp_bss.asm\n");
    }

    // Append contents of temp_text.asm
    FILE* temp_text = fopen("temp_text.asm", "r");
    if (temp_text) {
        char buffer[256];
        while (fgets(buffer, sizeof(buffer), temp_text)) {
            fputs(buffer, output);
        }
        fclose(temp_text);
    } else {
        fprintf(stderr, "Error: Unable to open temp_text.asm\n");
    }
}
