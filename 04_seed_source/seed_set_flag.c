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

char* get_undetermined_reg() {
    static char buffer[32]; // Buffer to store the token representation

    switch(Token.token_rep) { 
        case _al: strcpy(buffer, "al"); al(_al, "al"); break;
        case _bl: strcpy(buffer, "bl"); bl(_bl, "bl"); break;
        case _cl: strcpy(buffer, "cl"); cl(_cl, "cl"); break;
        case _dl: strcpy(buffer, "dl"); dl(_dl, "dl"); break;
        case _ah: strcpy(buffer, "ah"); ah(_ah, "ah"); break;
        case _bh: strcpy(buffer, "bh"); bh(_bh, "bh"); break;
        case _ch: strcpy(buffer, "ch"); ch(_ch, "ch"); break;
        case _dh: strcpy(buffer, "dh"); dh(_dh, "dh"); break;
        case _ax: strcpy(buffer, "ax"); ax(_ax, "ax"); break;
        case _bx: strcpy(buffer, "bx"); bx(_bx, "bx"); break;
        case _cx: strcpy(buffer, "cx"); cx(_cx, "cx"); break;
        case _dx: strcpy(buffer, "dx"); dx(_dx, "dx"); break;
        case _si: strcpy(buffer, "si"); si(_si, "si"); break;
        case _di: strcpy(buffer, "di"); di(_di, "di"); break;
        case _bp: strcpy(buffer, "bp"); bp(_bp, "bp"); break;
        case _sp: strcpy(buffer, "sp"); sp(_sp, "sp"); break;
        case _eax: strcpy(buffer, "eax"); eax(_eax, "eax"); break;
        case _ebx: strcpy(buffer, "ebx"); ebx(_ebx, "ebx"); break;
        case _ecx: strcpy(buffer, "ecx"); ecx(_ecx, "ecx"); break;
        case _edx: strcpy(buffer, "edx"); edx(_edx, "edx"); break;
        case _esi: strcpy(buffer, "esi"); esi(_esi, "esi"); break;
        case _edi: strcpy(buffer, "edi"); edi(_edi, "edi"); break;
        case _ebp: strcpy(buffer, "ebp"); ebp(_ebp, "ebp"); break;
        case _esp: strcpy(buffer, "esp"); esp(_esp, "esp"); break;
        case _rax: strcpy(buffer, "rax"); rax(_rax, "rax"); break;
        case _rbx: strcpy(buffer, "rbx"); rbx(_rbx, "rbx"); break;
        case _rcx: strcpy(buffer, "rcx"); rcx(_rcx, "rcx"); break;
        case _rdx: strcpy(buffer, "rdx"); rdx(_rdx, "rdx"); break;
        case _rsi: strcpy(buffer, "rsi"); rsi(_rsi, "rsi"); break;
        case _rdi: strcpy(buffer, "rdi"); rdi(_rdi, "rdi"); break;
        case _rbp: strcpy(buffer, "rbp"); rbp(_rbp, "rbp"); break;
        case _rsp: strcpy(buffer, "rsp"); rsp(_rsp, "rsp"); break;
        case _r8: strcpy(buffer, "r8"); r8(_r8, "r8"); break;
        case _r9: strcpy(buffer, "r9"); r9(_r9, "r9"); break;
        case _r10: strcpy(buffer, "r10"); r10(_r10, "r10"); break;
        case _r11: strcpy(buffer, "r11"); r11(_r11, "r11"); break;
        case _r12: strcpy(buffer, "r12"); r12(_r12, "r12"); break;
        case _r13: strcpy(buffer, "r13"); r13(_r13, "r13"); break;
        case _r14: strcpy(buffer, "r14"); r14(_r14, "r14"); break;
        case _r15: strcpy(buffer, "r15"); r15(_r15, "r15"); break;
        default: reject_token(Token.token_rep); buffer[0] = '\0'; break; // Clear buffer if no valid case is found break;
    }

    return buffer;
}
