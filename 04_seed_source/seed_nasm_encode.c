#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"


// Function to convert universal scope label into nasm
void encode_universal_label(const char* label_name)
{
    fprintf(temp_text, "\n");
    fprintf(temp_text, "global _start\n", label_name);
    fprintf(temp_text, "_start:\n", label_name);
}

// Function to convert global scope label into nasm
void encode_global_label(const char* label_name)
{
    fprintf(temp_text, "global %s\n\n", label_name);

    fprintf(temp_text, "%s:\n", label_name);
}

// Function to convert global block scope label into nasm
void encode_global_block_label(const char* label) 
{
    fprintf(temp_text, "%s:\n", label);
}

// Function to convert local scope label into nasm
void encode_local_label(const char* label_name)
{
    fprintf(temp_text, "%s:\n", label_name);
}

// Function to convert local block scope label into nasm
void encode_local_block_label(const char* label_name)
{
    fprintf(temp_text, "%s:\n", label_name);
}

// Function to add ret onto end of global scope label
void encode_pass_arg_label()
{
    fprintf(temp_text, "    ret\n");
}


void encode_extern_label(const char* label_name)
{
    fprintf(temp_text, "    extern %s\n", label_name);
}


void encode_align_instruction(int architecture)
{

}

// function to convert a seedling placeholder assignment into nasm
void encode_assign_hold_instruction(char *ident, int byte_size, int num_to_be_assigned)
{
    switch(byte_size)
    {
        case 1:  fprintf(temp_text, "    mov byte [%s], %d\n", ident, num_to_be_assigned); break;
        case 2:  fprintf(temp_text, "    mov word [%s], %d\n", ident, num_to_be_assigned); break;
        case 4:  fprintf(temp_text, "    mov dword [%s], %d\n", ident, num_to_be_assigned); break;
        case 8:  fprintf(temp_text, "    mov qword [%s], %d\n", ident, num_to_be_assigned); break;
        default: break;
    }
}

// function to convert a seedling table assignment into nasm
void encode_assign_table_instruction(char *ident, int byte_size, int num_to_be_assigned)
{
    switch(byte_size)
    {
        case 1:  fprintf(temp_bss, "    %s resb %d\n", ident, num_to_be_assigned); break;
        case 2:  fprintf(temp_bss, "    %s resw %d\n", ident, num_to_be_assigned); break;
        case 4:  fprintf(temp_bss, "    %s resd %d\n", ident, num_to_be_assigned); break;
        case 8:  fprintf(temp_bss, "    %s resq %d\n", ident, num_to_be_assigned); break;
        default: break;
    }
}

// function to convert seedling arch type arch_08, arch_16, arch_32, arch_64 into a into nasm bit directive
void encode_arch_instruction(int architecture)
 {
    switch (architecture) {
        case 8:  fprintf(output, "[bit %d]\n", architecture);  break;
        case 16: fprintf(output, "[bit %d]\n", architecture); break;
        case 32: fprintf(output, "[bit %d]\n", architecture); break;
        case 64: fprintf(output, "[bit %d]\n", architecture); break;
        default: printf("Unknown architecture encoding\n"); break;
    }
}

// function to convert seedling arith instructionss into nasm arith instructions
void encode_arith_instruction(const char* operation, phrase_retrievel dest, phrase_retrievel src)
{
     fprintf(temp_text, "    %s ", operation);

        // Check if the phrase in dest is not NULL
    if (dest.phrase != NULL)
    {
        switch (dest.type)
        {
            case phrase_address:
                switch (byte_size)
                {
                    case 8:  fprintf(temp_text, "byte [%s], ", dest.phrase); break;
                    case 16: fprintf(temp_text, "word [%s], ", dest.phrase); break;
                    case 32: fprintf(temp_text, "dword [%s], ", dest.phrase); break;
                    case 64: fprintf(temp_text, "qword [%s], ", dest.phrase); break;
                    default: break;
                }
            break;
            case phrase_pointer:  fprintf(temp_text, "[%s], ", dest.phrase);break;
            case phrase_fetch: fprintf(temp_text, "[%s], ", dest.phrase); break;
            case phrase_register:  fprintf(temp_text, "%s, ", dest.phrase); break;
            case phrase_ident:     fprintf(temp_text, "%s, ", dest.phrase); break;
            case phrase_number:    fprintf(temp_text, "%d, ", dest.phrase); break;
            default: break;
        }
    }
    
    // Check if the phrase in src is not NULL
    if (src.phrase != NULL)
    {
        switch (src.type)
        {
            case phrase_address:
                switch (byte_size)
                {
                    case 8:  fprintf(temp_text, "byte [%s]\n", src.phrase); break;
                    case 16: fprintf(temp_text, "word [%s]\n", src.phrase); break;
                    case 32: fprintf(temp_text, "dword [%s]\n", src.phrase); break;
                    case 64: fprintf(temp_text, "qword[%s]\n", src.phrase); break;
                    default: break;
                }   
            break;
            case phrase_pointer:   fprintf(temp_text, "[%s]\n", src.phrase);  break;
            case phrase_fetch:     fprintf(temp_text, "[%s]\n", src.phrase);  break;
            case phrase_register:  fprintf(temp_text, "%s\n", src.phrase); break;
            case phrase_ident:     fprintf(temp_text, "%s\n", src.phrase); break;
            case phrase_number:    fprintf(temp_text, "%d\n", src.phrase); break;
            default: break;
        }
    }
}

// Function to encode a Seedling push instruction to NASM
void encode_push_instruction(int byte_size, phrase_retrievel src)
{
   
    switch (src.type)
    {
        case phrase_pointer:
        {
            switch (byte_size)
            {
                case 8: fprintf(temp_text, "    push byte [%s]\n", src.phrase); break;
                case 16: fprintf(temp_text, "    push word [%s]\n", src.phrase); break;
                case 32: fprintf(temp_text, "    push dword [%s]\n", src.phrase); break;
                case 64: fprintf(temp_text, "    push qword [%s]\n", src.phrase);break;
                default: break;
            }
        }
        break;
        case phrase_address:
        {
            switch (byte_size)
            {
                case 8: fprintf(temp_text, "    push byte [%s]\n", src.phrase); break;
                case 16: fprintf(temp_text, "    push word [%s]\n", src.phrase); break;
                case 32: fprintf(temp_text, "    push dword [%s]\n", src.phrase); break;
                case 64: fprintf(temp_text, "    push qword [%s]\n", src.phrase);break;
                default: break;
           }
        }
        break;
        case phrase_fetch:
        {
            switch (byte_size)
            {
                case 8: fprintf(temp_text, "    push byte [%s]\n", src.phrase); break;
                case 16: fprintf(temp_text, "    push word [%s]\n", src.phrase); break;
                case 32: fprintf(temp_text, "    push dword [%s]\n", src.phrase); break;
                case 64: fprintf(temp_text, "    push qword [%s]\n", src.phrase);break;
                default: break;
            } 
        } 
        break;
        case phrase_register:
        {
            switch (byte_size)
            {
                case 8: fprintf(temp_text, "    push byte  %s\n", src.phrase); break;
                case 16: fprintf(temp_text, "    push word  %s\n", src.phrase); break;
                case 32: fprintf(temp_text, "    push dword  %s\n", src.phrase); break;
                case 64: fprintf(temp_text, "    push qword  %s\n", src.phrase); break;
                default: break;
            }
        }  
        break;
        default: break;
    }
}


// Function to encode a Seedling pop instruction to NASM
void encode_pop_instruction(phrase_retrievel src) 
{
    switch (src.type)
    {
        case phrase_pointer:   fprintf(temp_text, "    pop [%s]\n", src.phrase); break;
        case phrase_address:   fprintf(temp_text, "    pop [%s]\n", src.phrase); break;
        case phrase_fetch:     fprintf(temp_text, "    pop [%s]\n", src.phrase); break;
        case phrase_register:  fprintf(temp_text, "    pop  %s\n", src.phrase); break;
        default: break;
    }
}

void encode_move_instruction(const char* operation, int byte_size, phrase_retrievel dest, phrase_retrievel src)
{
    fprintf(temp_text, "    %s ", operation);

        // Check if the phrase in dest is not NULL
    if (dest.phrase != NULL)
    {
        switch (dest.type)
        {
            case phrase_ident:     fprintf(temp_text, "%s, ", dest.phrase); break;
            case phrase_number:    fprintf(temp_text, "%d, ", dest.phrase_value); break;
            case phrase_address:
            {
                switch (byte_size)
                {
                    case 8:  fprintf(temp_text, "byte [%s], ", dest.phrase); break;
                    case 16: fprintf(temp_text, "word [%s], ", dest.phrase); break;
                    case 32: fprintf(temp_text, "dword [%s], ", dest.phrase); break;
                    case 64: fprintf(temp_text, "qword [%s], ", dest.phrase); break;
                    default: break;
                }
            }
            break;
            case phrase_pointer:  fprintf(temp_text, "[%s], ", dest.phrase);break;
            case phrase_fetch: fprintf(temp_text, "[%s], ", dest.phrase); break;
            case phrase_register:  fprintf(temp_text, "%s, ", dest.phrase); break;
            default: break;
        }
    }
    
    // Check if the phrase in src is not NULL
    if (src.phrase != NULL)
    {
        switch (src.type)
        {
            case phrase_ident:     fprintf(temp_text, "%s\n", src.phrase); break;
            case phrase_number:    fprintf(temp_text, "%d\n", src.phrase_value); break;
            case phrase_address:
            {
                switch (byte_size)
                {
                    case 8:  fprintf(temp_text, "byte [%s]\n", src.phrase); break;
                    case 16: fprintf(temp_text, "word [%s]\n", src.phrase); break;
                    case 32: fprintf(temp_text, "dword [%s]\n", src.phrase); break;
                    case 64: fprintf(temp_text, "qword[%s]\n", src.phrase); break;
                    default: break;
                }   
            }
            break;
            case phrase_pointer:   fprintf(temp_text, "[%s]\n", src.phrase);  break;
            case phrase_fetch:     fprintf(temp_text, "[%s]\n", src.phrase);  break;
            case phrase_register:  fprintf(temp_text, "%s\n", src.phrase); break;
            default: break;
        }
    }
}



void encode_increment_instruction(phrase_retrievel src)
{
     fprintf(temp_text, "    inc %s\n", src.phrase); 
}
// Function to encode a Seedling jump instruction to NASM
void encode_jump_instruction(const char* operation)
{
    fprintf(temp_text, "    jmp %s\n", operation);
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
void encode_system_instruction()
{
   fprintf(temp_text, "    int 0x80\n\n");
}

// Function to encode a Seedling set flag instruction to NASM
void encode_compare_instruction(const char* operation,  phrase_retrievel dest,  phrase_retrievel src)
{
    fprintf(temp_text, "    %s ", operation);

        // Check if the phrase in dest is not NULL
    if (dest.phrase != NULL)
    {
        switch (dest.type)
        {
            case phrase_address:
            {
                switch (byte_size)
                {
                    case 8:  fprintf(temp_text, "byte [%s], ", dest.phrase); break;
                    case 16: fprintf(temp_text, "word [%s], ", dest.phrase); break;
                    case 32: fprintf(temp_text, "dword [%s], ", dest.phrase); break;
                    case 64: fprintf(temp_text, "qword [%s], ", dest.phrase); break;
                    default: break;
                }
            }
            break;
            case phrase_pointer:  fprintf(temp_text, "[%s], ", dest.phrase);break;
            case phrase_fetch: fprintf(temp_text, "[%s], ", dest.phrase); break;
            case phrase_register:  fprintf(temp_text, "%s, ", dest.phrase); break;
            case phrase_ident:     fprintf(temp_text, "%s, ", dest.phrase); break;
            case phrase_number:    fprintf(temp_text, "%d, ", dest.phrase); break;
            default: break;
        }
    }
    
    // Check if the phrase in src is not NULL
    if (src.phrase != NULL)
    {
        switch (src.type)
        {
            case phrase_address:
            {
                switch (byte_size)
                {
                    case 8:  fprintf(temp_text, "byte [%s]\n", src.phrase); break;
                    case 16: fprintf(temp_text, "word [%s]\n", src.phrase); break;
                    case 32: fprintf(temp_text, "dword [%s]\n", src.phrase); break;
                    case 64: fprintf(temp_text, "qword[%s]\n", src.phrase); break;
                    default: break;
                }   
            }
            break;
            case phrase_pointer:   fprintf(temp_text, "[%s]\n", src.phrase);  break;
            case phrase_fetch:     fprintf(temp_text, "[%s]\n", src.phrase);  break;
            case phrase_register:  fprintf(temp_text, "%s\n", src.phrase); break;
            case phrase_ident:     fprintf(temp_text, "%s\n", src.phrase); break;
            case phrase_number:    fprintf(temp_text, "%d\n", src.phrase); break;
            default: break;
        }
    }
}


// Function to encode a Seedling set flag instruction to NASM
void encode_set_flag_instruction(const char* reg1, const char* reg2) {
    fprintf(temp_text, "    xor %s, %s\n", reg1, reg2);
}

// Function to encode a Seedling test instruction to NASM
void encode_test_instruction(const char* reg1, const char* reg2) {
    fprintf(temp_text, "    test %s, %s\n", reg1, reg2);
}


// Function to encode a Seedling number to NASM
void encode_number(int num) {
    fprintf(temp_text, "    mov eax, 0x%X\n", num);
}


// function to convert a seedling declaration into nasm
void encode_declare_instruction(const char* ident, int byte_size, int type) 
{
    switch(byte_size)
    {
        case 1:  fprintf(temp_bss, "    %s resb %d\n", ident, type); break;
        case 2:  fprintf(temp_bss, "    %s resw %d\n", ident, type); break;
        case 4:  fprintf(temp_bss, "    %s resd %d\n", ident, type); break;
        case 8:  fprintf(temp_bss, "    %s resq %d\n", ident, type); break;
        default: break;
    }
}



// Function to encode a Seedling literal section to NASM
void encode_literal_with_num_section(char * hold_name, char *src, int null_value)
{
    fprintf(temp_data, "    %s db \"%s\", %d\n", hold_name, src, null_value);
}

void encode_literal_with_hex_section(char *hold_name, char *src, unsigned int hex_value)
{
    // Print the value as a hexadecimal number (in NASM format, starting with '0x')
    fprintf(temp_data, "    %s db \"%s\", 0x%X\n", hold_name, src, hex_value);
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