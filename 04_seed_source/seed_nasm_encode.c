#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"


// Function to convert universal scope label into nasm
void convert_universal_label(const char* label_name)
{
    fprintf(temp_text, "global _%s\n", label_name);
}

// Function to convert global scope label into nasm
void convert_global_label(const char* label_name)
{
    fprintf(temp_text, "%s:\n", label_name);
}

// Function to convert global block scope label into nasm
void convert_global_block_label(const char* label) 
{
    fprintf(temp_text, ".%s:\n", label);
}

// Function to convert local scope label into nasm
void convert_local_label(const char* label_name)
{
    fprintf(temp_text, "%s:\n", label_name);
}

// Function to add ret onto end of global scope label
void convert_global_label_pass_arg()
{
    fprintf(temp_text, "    ret\n");
}

// Function to add ret onto end of global scope label
void convert_local_label_pass_arg()
{
    fprintf(temp_text, "    ret\n");
}

/* Function to encode a Seedling assign section to NASM  */
void output_assign_section_body(const char* ident, int type)
{
    fprintf(temp_data, "    %s db %d\n", ident, type); 
}



// Function to encode a Seedling instruction to NASM
void encode_instruction(const char* instr, const char* dest, const char* src) {

    fprintf(temp_text, "    %s %s, %s\n", instr, dest, src);
}

// Function to encode a Seedling call function instruction to NASM
void encode_call_function_instruction(const char* label_one, const char* label_two) {

    fprintf(temp_text, "    call %s\n", label_one);
    fprintf(temp_text, "    call %s\n", label_two);
}

// Function to encode a Seedling call manager instruction to NASM
void encode_call_manager_instruction(const char* label) {

    fprintf(temp_text, "    call %s\n", label);
}


// Function to encode a Seedling lend instruction to NASM
void encode_lend_instruction(const char* reg1) {

    fprintf(temp_text, "    lend %s\n", reg1);
}



// Function to encode a Seedling file section to NASM
void encode_file_section(const char* value, int length)
{
    fprintf(temp_rodata, "    db %s, %d\n", value, length);
}


// Function to encode a Seedling fetch reference to NASM
void encode_fetch_reference(const char* dest, const char* src) {
    fprintf(temp_text, "    mov %s, %s\n", dest, src);
}



// Function to encode a Seedling jump instruction to NASM
void encode_jump_instruction(const char* label)
{
    fprintf(temp_text, "    jmp %s\n", label);
}

// Function to encode a Seedling jump less instruction to NASM
void encode_jump_less_instruction(const char* label)
{
    fprintf(temp_text, "    jl %s\n", label);
}

// Function to encode a Seedling jump neg instruction to NASM
void encode_jump_neg_instruction(const char* label) 
{
    fprintf(temp_text, "    jng %s\n", label);
}

// Function to encode a Seedling set flag instruction to NASM
void encode_set_flag_instruction(const char* reg1, const char* reg2) {
    fprintf(temp_text, "    set %s, %s\n", reg1, reg2);
}

// Function to encode a Seedling test instruction to NASM
void encode_test_instruction(const char* reg1, const char* reg2) {
    fprintf(temp_text, "    test %s, %s\n", reg1, reg2);
}

// Function to encode a Seedling push instruction to NASM
void encode_push_instruction(const char* reg) {
    fprintf(temp_text, "    push %s\n", reg);
}

// Function to encode a Seedling pop instruction to NASM
void encode_pop_instruction(const char* reg) {
    fprintf(temp_text, "    pop %s\n", reg);
}

// Function to encode a Seedling number to NASM
void encode_number(int num) {
    fprintf(temp_text, "    mov eax, 0x%X\n", num);
}


// Function to encode a Seedling declare section to NASM
void output_declare_section_body(const char* ident, int type) 
{
    fprintf(temp_bss, "    %s resb %d\n", ident, type); 
}

// Function to encode a Seedling literal section to NASM
void encode_literal_section(const char* value, int length)
{
    fprintf(temp_rodata, "    db %s, %d\n", value, length);
}

//=====================================================================================
// sections header functions

void output_code_section_header()    { fprintf(temp_text, "section .text\n");     }
void output_declare_section_header() { fprintf(temp_bss, "section .bss\n");       }
void output_assign_section_header()  { fprintf(temp_data, "section .data\n");     }
void output_literal_section_header() { fprintf(temp_rodata, "section .rodata\n"); }

