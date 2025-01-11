#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"

void process_set_flag_instruction(enum scope_type current_scope) 
{
    char* src_entry;
    char* dest_entry;

    set_flag(_set_flag, "set_flag");

    scan(&Token);
    colon(_colon, ":");

    scan(&Token);
    dest_entry = get_undetermined_reg();

    scan(&Token);
    comma(_comma, ",");

    scan(&Token);  
    src_entry = get_undetermined_reg();
    encode_set_flag_instruction(dest_entry, src_entry);

    scan(&Token);
    semicolon(_semicolon, ";");
}

void process_test_instruction(enum scope_type current_scope) 
{
    char* src_entry;
    char* dest_entry;

    test(_test, "test");

    scan(&Token);
    colon(_colon, ":");

    scan(&Token);  
    dest_entry = get_undetermined_reg();  

    scan(&Token);
    comma(_comma, ",");

    scan(&Token);  
    src_entry = get_undetermined_reg();
    encode_test_instruction(dest_entry, src_entry);

    scan(&Token);
    semicolon(_semicolon, ";");
}

char* get_undetermined_reg() 
{
    switch(Token.token_rep) { 
        case _al: strcpy(reg_buffer, "al"); al(_al, "al"); break;
        case _bl: strcpy(reg_buffer, "bl"); bl(_bl, "bl"); break;
        case _cl: strcpy(reg_buffer, "cl"); cl(_cl, "cl"); break;
        case _dl: strcpy(reg_buffer, "dl"); dl(_dl, "dl"); break;
        case _ah: strcpy(reg_buffer, "ah"); ah(_ah, "ah"); break;
        case _bh: strcpy(reg_buffer, "bh"); bh(_bh, "bh"); break;
        case _ch: strcpy(reg_buffer, "ch"); ch(_ch, "ch"); break;
        case _dh: strcpy(reg_buffer, "dh"); dh(_dh, "dh"); break;
        case _ax: strcpy(reg_buffer, "ax"); ax(_ax, "ax"); break;
        case _bx: strcpy(reg_buffer, "bx"); bx(_bx, "bx"); break;
        case _cx: strcpy(reg_buffer, "cx"); cx(_cx, "cx"); break;
        case _dx: strcpy(reg_buffer, "dx"); dx(_dx, "dx"); break;
        case _si: strcpy(reg_buffer, "si"); si(_si, "si"); break;
        case _di: strcpy(reg_buffer, "di"); di(_di, "di"); break;
        case _bp: strcpy(reg_buffer, "bp"); bp(_bp, "bp"); break;
        case _sp: strcpy(reg_buffer, "sp"); sp(_sp, "sp"); break;
        case _eax: strcpy(reg_buffer, "eax"); eax(_eax, "eax"); break;
        case _ebx: strcpy(reg_buffer, "ebx"); ebx(_ebx, "ebx"); break;
        case _ecx: strcpy(reg_buffer, "ecx"); ecx(_ecx, "ecx"); break;
        case _edx: strcpy(reg_buffer, "edx"); edx(_edx, "edx"); break;
        case _esi: strcpy(reg_buffer, "esi"); esi(_esi, "esi"); break;
        case _edi: strcpy(reg_buffer, "edi"); edi(_edi, "edi"); break;
        case _ebp: strcpy(reg_buffer, "ebp"); ebp(_ebp, "ebp"); break;
        case _esp: strcpy(reg_buffer, "esp"); esp(_esp, "esp"); break;
        case _rax: strcpy(reg_buffer, "rax"); rax(_rax, "rax"); break;
        case _rbx: strcpy(reg_buffer, "rbx"); rbx(_rbx, "rbx"); break;
        case _rcx: strcpy(reg_buffer, "rcx"); rcx(_rcx, "rcx"); break;
        case _rdx: strcpy(reg_buffer, "rdx"); rdx(_rdx, "rdx"); break;
        case _rsi: strcpy(reg_buffer, "rsi"); rsi(_rsi, "rsi"); break;
        case _rdi: strcpy(reg_buffer, "rdi"); rdi(_rdi, "rdi"); break;
        case _rbp: strcpy(reg_buffer, "rbp"); rbp(_rbp, "rbp"); break;
        case _rsp: strcpy(reg_buffer, "rsp"); rsp(_rsp, "rsp"); break;
        case _r8: strcpy(reg_buffer, "r8"); r8(_r8, "r8"); break;
        case _r9: strcpy(reg_buffer, "r9"); r9(_r9, "r9"); break;
        case _r10: strcpy(reg_buffer, "r10"); r10(_r10, "r10"); break;
        case _r11: strcpy(reg_buffer, "r11"); r11(_r11, "r11"); break;
        case _r12: strcpy(reg_buffer, "r12"); r12(_r12, "r12"); break;
        case _r13: strcpy(reg_buffer, "r13"); r13(_r13, "r13"); break;
        case _r14: strcpy(reg_buffer, "r14"); r14(_r14, "r14"); break;
        case _r15: strcpy(reg_buffer, "r15"); r15(_r15, "r15"); break;
        default: reg_buffer[0] = '\0'; break; // Clear buffer if no valid case is found break;
    }

    return reg_buffer;
}
