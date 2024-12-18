#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"

void process_set_flag_instruction(enum scope_type current_scope) 
{
    set_flag(_set_flag, "set_flag");

    scan(&Token);
    colon(_colon, ":");

    scan(&Token);                   // Handle destination operand
    switch(Token.token_rep) 
    {
        case _ebp:  ebp(_ebp, "ebp");    strcpy(dest, "ebp"); break;
        case _esp:  esp(_esp, "esp");    strcpy(dest, "esp"); break;
        case _eax:  eax(_eax, "eax");    strcpy(dest, "eax"); break;
        case _ebx:  ebx(_ebx, "ebx");    strcpy(dest, "ebx"); break;
        case _ecx:  ecx(_ecx, "ecx");    strcpy(dest, "ecx"); break;
        case _edx:  edx(_edx, "edx");    strcpy(dest, "edx"); break;  
        default: 
            error("Invalid destination operand for move instruction");
            break;
    }


    scan(&Token);
    comma(_comma, ",");

    scan(&Token);                   // Handle destination operand
    switch(Token.token_rep) 
    {
        case _ebp:  ebp(_ebp, "ebp");    strcpy(src, "ebp"); break;
        case _esp:  esp(_esp, "esp");    strcpy(src, "esp"); break;
        case _eax:  eax(_eax, "eax");    strcpy(src, "eax"); break;
        case _ebx:  ebx(_ebx, "ebx");    strcpy(src, "ebx"); break;
        case _ecx:  ecx(_ecx, "ecx");    strcpy(src, "ecx"); break;
        case _edx:  edx(_edx, "edx");    strcpy(src, "edx"); break;  
        default: 
            error("Invalid destination operand for move instruction");
            break;
    }

    encode_set_flag_instruction(dest, src);

    scan(&Token);
    semicolon(_semicolon, ";");
}

void process_test_instruction(enum scope_type current_scope) 
{
    test(_test, "test");

    scan(&Token);
    colon(_colon, ":");

    scan(&Token);                   // Handle destination operand
    switch(Token.token_rep) 
    {
        case _ebp:  ebp(_ebp, "ebp");    strcpy(dest, "ebp"); break;
        case _esp:  esp(_esp, "esp");    strcpy(dest, "esp"); break;
        case _eax:  eax(_eax, "eax");    strcpy(dest, "eax"); break;
        case _ebx:  ebx(_ebx, "ebx");    strcpy(dest, "ebx"); break;
        case _ecx:  ecx(_ecx, "ecx");    strcpy(dest, "ecx"); break;
        case _edx:  edx(_edx, "edx");    strcpy(dest, "edx"); break;  
        default: 
            error("Invalid destination operand for move instruction");
            break;
    }


    scan(&Token);
    comma(_comma, ",");

    scan(&Token);                   // Handle destination operand
    switch(Token.token_rep) 
    {
        case _ebp:  ebp(_ebp, "ebp");    strcpy(src, "ebp"); break;
        case _esp:  esp(_esp, "esp");    strcpy(src, "esp"); break;
        case _eax:  eax(_eax, "eax");    strcpy(src, "eax"); break;
        case _ebx:  ebx(_ebx, "ebx");    strcpy(src, "ebx"); break;
        case _ecx:  ecx(_ecx, "ecx");    strcpy(src, "ecx"); break;
        case _edx:  edx(_edx, "edx");    strcpy(src, "edx"); break;  
        default: 
            error("Invalid destination operand for move instruction");
            break;
    }

    encode_test_instruction(dest, src);

    scan(&Token);
    semicolon(_semicolon, ";");
}

