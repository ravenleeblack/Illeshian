#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"

/*functions to retrieve registers for parsing*/

char *get_den_reg() // 8-bit registers
{
    switch(Token.token_rep) 
    {
        case _al:  al(_al, "al");        strcpy(reg_buffer, "al");  break;
        case _bl:  bl(_bl, "bl");        strcpy(reg_buffer, "bl");  break;
        case _cl:  cl(_cl, "cl");        strcpy(reg_buffer, "cl");  break;
        case _dl:  dl(_dl, "dl");        strcpy(reg_buffer, "dl");  break;
        case _ah:  ah(_ah, "ah");        strcpy(reg_buffer, "ah");  break;
        case _bh:  bh(_bh, "bh");        strcpy(reg_buffer, "bh");  break;
        case _ch:  ch(_ch, "ch");        strcpy(reg_buffer, "ch");  break;
        case _dh:  dh(_dh, "dh");        strcpy(reg_buffer, "dh");  break;
        default: break;
    }

    return reg_buffer;
}

char *get_bay_reg() // 16-bit registers
{
    switch(Token.token_rep) 
    {
        case _ax:  ax(_ax, "ax");        strcpy(reg_buffer, "ax");  break;
        case _bx:  bx(_bx, "bx");        strcpy(reg_buffer, "bx");  break;
        case _cx:  cx(_cx, "cx");        strcpy(reg_buffer, "cx");  break;
        case _dx:  dx(_dx, "dx");        strcpy(reg_buffer, "dx");  break;
        case _si:  si(_si, "si");        strcpy(reg_buffer, "si");  break;
        case _di:  di(_di, "di");        strcpy(reg_buffer, "di");  break;
        case _bp:  bp(_bp, "bp");        strcpy(reg_buffer, "bp");  break;
        case _sp:  sp(_sp, "sp");        strcpy(reg_buffer, "sp");  break;
        default: break;
    }
     return reg_buffer;
}

char *get_aisle_reg() // 32-bit registers
{
    switch(Token.token_rep) 
    {
        case _eax:  eax(_eax, "eax");    strcpy(reg_buffer, "eax");  break;
        case _ebx:  ebx(_ebx, "ebx");    strcpy(reg_buffer, "ebx");  break;
        case _ecx:  ecx(_ecx, "ecx");    strcpy(reg_buffer, "ecx");  break;
        case _edx:  edx(_edx, "edx");    strcpy(reg_buffer, "edx");  break;
        case _esi:  esi(_esi, "esi");    strcpy(reg_buffer, "esi");  break;
        case _edi:  edi(_edi, "edi");    strcpy(reg_buffer, "edi");  break;
        case _ebp:  ebp(_ebp, "ebp");    strcpy(reg_buffer, "ebp");  break;
        case _esp:  esp(_esp, "esp");    strcpy(reg_buffer, "esp");  break;
        default: break;
    }
     return reg_buffer;
}

char *get_zone_reg() // 64-bit registers
{
    switch(Token.token_rep) 
    {
        case _rax:  rax(_rax, "rax");    strcpy(reg_buffer, "rax");  break;
        case _rbx:  rbx(_rbx, "rbx");    strcpy(reg_buffer, "rbx");  break;
        case _rcx:  rcx(_rcx, "rcx");    strcpy(reg_buffer, "rcx");  break;
        case _rdx:  rdx(_rdx, "rdx");    strcpy(reg_buffer, "rdx");  break;
        case _rsi:  rsi(_rsi, "rsi");    strcpy(reg_buffer, "rsi");  break;
        case _rdi:  rdi(_rdi, "rdi");    strcpy(reg_buffer, "rdi");  break;
        case _rbp:  rbp(_rbp, "rbp");    strcpy(reg_buffer, "rbp");  break;
        case _rsp:  rsp(_rsp, "rsp");    strcpy(reg_buffer, "rsp");  break;
        case _r8:   r8(_r8, "r8");       strcpy(reg_buffer, "r8");   break;
        case _r9:   r9(_r9, "r9");       strcpy(reg_buffer, "r9");   break;
        case _r10:  r10(_r10, "r10");    strcpy(reg_buffer, "r10");  break;
        case _r11:  r11(_r11, "r11");    strcpy(reg_buffer, "r11");  break;
        case _r12:  r12(_r12, "r12");    strcpy(reg_buffer, "r12");  break;
        case _r13:  r13(_r13, "r13");    strcpy(reg_buffer, "r13");  break;
        case _r14:  r14(_r14, "r14");    strcpy(reg_buffer, "r14");  break;
        case _r15:  r15(_r15, "r15");    strcpy(reg_buffer, "r15");  break;
        default: break;
    }
     return reg_buffer;
}




