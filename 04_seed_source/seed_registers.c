#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"

/*functions to retrieve registers for parsing*/

struct phrase *get_den_reg() // 8-bit registers
{
    struct phrase *reg_op;

    switch(Token.token_rep) 
    {
        case _al:  al(_al, "al");        strcpy(reg_op->src_buffer, "al");  break;
        case _bl:  bl(_bl, "bl");        strcpy(reg_op->src_buffer, "bl");  break;
        case _cl:  cl(_cl, "cl");        strcpy(reg_op->src_buffer, "cl");  break;
        case _dl:  dl(_dl, "dl");        strcpy(reg_op->src_buffer, "dl");  break;
        case _ah:  ah(_ah, "ah");        strcpy(reg_op->src_buffer, "ah");  break;
        case _bh:  bh(_bh, "bh");        strcpy(reg_op->src_buffer, "bh");  break;
        case _ch:  ch(_ch, "ch");        strcpy(reg_op->src_buffer, "ch");  break;
        case _dh:  dh(_dh, "dh");        strcpy(reg_op->src_buffer, "dh");  break;
        default: break;
    }

    return reg_op;
}

struct phrase *get_bay_reg() // 16-bit registers
{
    struct phrase *reg_op;

    switch(Token.token_rep) 
    {
        case _ax:  ax(_ax, "ax");        strcpy(reg_op->src_buffer, "ax");  break;
        case _bx:  bx(_bx, "bx");        strcpy(reg_op->src_buffer, "bx");  break;
        case _cx:  cx(_cx, "cx");        strcpy(reg_op->src_buffer, "cx");  break;
        case _dx:  dx(_dx, "dx");        strcpy(reg_op->src_buffer, "dx");  break;
        case _si:  si(_si, "si");        strcpy(reg_op->src_buffer, "si");  break;
        case _di:  di(_di, "di");        strcpy(reg_op->src_buffer, "di");  break;
        case _bp:  bp(_bp, "bp");        strcpy(reg_op->src_buffer, "bp");  break;
        case _sp:  sp(_sp, "sp");        strcpy(reg_op->src_buffer, "sp");  break;
        default: break;
    }
     return reg_op;
}

struct phrase *get_aisle_reg() // 32-bit registers
{
    struct phrase *reg_op;

    switch(Token.token_rep) 
    {
        case _eax:  eax(_eax, "eax");    strcpy(reg_op->src_buffer, "eax");  break;
        case _ebx:  ebx(_ebx, "ebx");    strcpy(reg_op->src_buffer, "ebx");  break;
        case _ecx:  ecx(_ecx, "ecx");    strcpy(reg_op->src_buffer, "ecx");  break;
        case _edx:  edx(_edx, "edx");    strcpy(reg_op->src_buffer, "edx");  break;
        case _esi:  esi(_esi, "esi");    strcpy(reg_op->src_buffer, "esi");  break;
        case _edi:  edi(_edi, "edi");    strcpy(reg_op->src_buffer, "edi");  break;
        case _ebp:  ebp(_ebp, "ebp");    strcpy(reg_op->src_buffer, "ebp");  break;
        case _esp:  esp(_esp, "esp");    strcpy(reg_op->src_buffer, "esp");  break;
        default: break;
    }
     return reg_op;
}

struct phrase *get_zone_reg() // 64-bit registers
{
    struct phrase *reg_op;

    switch(Token.token_rep) 
    {
        case _rax:  rax(_rax, "rax");    strcpy(reg_op->src_buffer, "rax");  break;
        case _rbx:  rbx(_rbx, "rbx");    strcpy(reg_op->src_buffer, "rbx");  break;
        case _rcx:  rcx(_rcx, "rcx");    strcpy(reg_op->src_buffer, "rcx");  break;
        case _rdx:  rdx(_rdx, "rdx");    strcpy(reg_op->src_buffer, "rdx");  break;
        case _rsi:  rsi(_rsi, "rsi");    strcpy(reg_op->src_buffer, "rsi");  break;
        case _rdi:  rdi(_rdi, "rdi");    strcpy(reg_op->src_buffer, "rdi");  break;
        case _rbp:  rbp(_rbp, "rbp");    strcpy(reg_op->src_buffer, "rbp");  break;
        case _rsp:  rsp(_rsp, "rsp");    strcpy(reg_op->src_buffer, "rsp");  break;
        case _r8:   r8(_r8, "r8");       strcpy(reg_op->src_buffer, "r8");   break;
        case _r9:   r9(_r9, "r9");       strcpy(reg_op->src_buffer, "r9");   break;
        case _r10:  r10(_r10, "r10");    strcpy(reg_op->src_buffer, "r10");  break;
        case _r11:  r11(_r11, "r11");    strcpy(reg_op->src_buffer, "r11");  break;
        case _r12:  r12(_r12, "r12");    strcpy(reg_op->src_buffer, "r12");  break;
        case _r13:  r13(_r13, "r13");    strcpy(reg_op->src_buffer, "r13");  break;
        case _r14:  r14(_r14, "r14");    strcpy(reg_op->src_buffer, "r14");  break;
        case _r15:  r15(_r15, "r15");    strcpy(reg_op->src_buffer, "r15");  break;
        default: break;
    }
     return reg_op;
}




