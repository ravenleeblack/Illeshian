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
    fprintf(temp_text, "%s:\n", label);
}

// Function to convert local scope label into nasm
void convert_local_label(const char* label_name)
{
    fprintf(temp_text, "%s:\n", label_name);
}

// Function to convert local block scope label into nasm
void convert_local_block_label(const char* label_name)
{
    fprintf(temp_text, "%s:\n", label_name);
}


// Function to add ret onto end of global scope label
void convert_label_pass_arg()
{
    fprintf(temp_text, "    ret\n");
}


void convert_extern_label(const char* label_name)
{
    fprintf(temp_text, "    extern %s\n", label_name);
}




// Function to encode a Seedling instruction to NASM
void encode_instruction(const char* instr, const char* dest, const char* src) {

    fprintf(temp_text, "    %s %s, %s\n", instr, dest, src);
}

// Function to encode a Seedling call function instruction to NASM
void encode_call_function_instruction(const char* label_one, const char* label_two) {

    fprintf(temp_text, "    call %s.%s\n", label_one, label_two);
}

// Function to encode a Seedling call manager instruction to NASM
void encode_call_manager_instruction(const char* label) {

    fprintf(temp_text, "    call %s\n", label);
}


// Function to encode a Seedling lend instruction to NASM
void encode_lend_instruction(const char* reg1) {

    fprintf(temp_text, "    int %s\n", reg1);
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
void output_declare_section_body(const char* ident, int byte_size, int type) 
{
    switch(byte_size)
    {
        case 1:  fprintf(temp_bss, "    %s resb %d\n", ident, type); break;
        case 2:  fprintf(temp_bss, "    %s resw %d\n", ident, type); break;
        case 4:  fprintf(temp_bss, "    %s resd %d\n", ident, type); break;
        case 8:  fprintf(temp_bss, "    %s resq %d\n", ident, type); break;
        default: fprintf(temp_bss, "    %s resb %d\n", ident, type); break;
    }
}

// Function to encode a Seedling literal section to NASM
void encode_literal_section(const char* hold_name, const char* strand_value, int null_value)
{
    fprintf(temp_data, "    %s db \"%s\", %d\n", hold_name, strand_value, null_value);
}

void encode_file_section(const char* label_name, const char* label_strand, int length)
{
    fprintf(temp_data, "    %s db \"%s\", %d\n", label_name, label_strand, length);
}

//=====================================================================================
// sections header functions

void output_code_section_header()    
{
    if (!text_header_printed) {
        fprintf(temp_text, "section .text\n");
        text_header_printed = 1;  // Set the flag after printing the header
    }
}

void output_declare_section_header() 
{
    if (!bss_header_printed) {
        fprintf(temp_bss, "section .bss\n");
        bss_header_printed = 1;  // Set the flag after printing the header
    }
}

void output_assign_section_header()  
{
    if (!data_header_printed) {
        fprintf(temp_data, "section .data\n");
        data_header_printed = 1;  // Set the flag after printing the header
    }
}

void output_literal_section_header() 
{
    if (!rodata_header_printed) {
        fprintf(temp_rodata, "section .rodata\n");
        rodata_header_printed = 1;  // Set the flag after printing the header
    }
}