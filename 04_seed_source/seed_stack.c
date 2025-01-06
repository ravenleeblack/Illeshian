#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"




void process_push_radule_instruction(enum scope_type current_scope) 
{
    push_radule(_push_radule, "push_radule");

    scan(&Token);
    colon(_colon, ":");

    scan(&Token);
    switch(Token.token_rep) 
    {
        case _ebp:  ebp(_ebp, "ebp"); strcpy(dest, "ebp");   break;
        case _esp:  esp(_esp, "esp"); strcpy(dest, "esp");   break;
        case _eax:  eax(_eax, "eax"); strcpy(dest, "eax");   break;
        case _ebx:  ebx(_ebx, "ebx"); strcpy(dest, "ebx");   break;
        case _ecx:  ecx(_ecx, "ecx"); strcpy(dest, "ecx");   break;
        case _edx:  edx(_edx, "edx"); strcpy(dest, "edx");   break;
    }
    encode_push_instruction(dest);

    scan(&Token);
    comma(_comma, ",");

    scan(&Token);
    ident(_ident, Text);
    encode_push_instruction(src);

    scan(&Token);
    semicolon(_semicolon, ";");
}

void process_pop_radule_instruction(enum scope_type current_scope) 
{
    pop_radule(_pop_radule, "pop_radule");

    scan(&Token);
    colon(_colon, ":");

    scan(&Token);
    switch(Token.token_rep) 
    {
        case _ebp:  ebp(_ebp, "ebp");  strcpy(dest, "ebp");  break;
        case _esp:  esp(_esp, "esp");  strcpy(dest, "esp");  break;
        case _eax:  eax(_eax, "eax");  strcpy(dest, "eax");  break;
        case _ebx:  ebx(_ebx, "ebx");  strcpy(dest, "ebx");  break;
        case _ecx:  ecx(_ecx, "ecx");  strcpy(dest, "ecx");  break;
        case _edx:  edx(_edx, "edx");  strcpy(dest, "edx");  break;
    }
    encode_pop_instruction(dest);

    scan(&Token);
    comma(_comma, ",");

    scan(&Token);
    ident(_ident, Text);
    encode_pop_instruction(src);

    scan(&Token);
    semicolon(_semicolon, ";");
}

void process_push_instruction(enum scope_type current_scope) 
{
    push_radule(_push, "push");

    scan(&Token);
    colon(_colon, ":");

    scan(&Token);
    switch(Token.token_rep) 
    {
        case _ebp:  ebp(_ebp, "ebp"); strcpy(dest, "ebp"); break;
        case _esp:  esp(_esp, "esp"); strcpy(dest, "esp"); break;
        case _eax:  eax(_eax, "eax"); strcpy(dest, "eax"); break;
        case _ebx:  ebx(_ebx, "ebx"); strcpy(dest, "ebx"); break;
        case _ecx:  ecx(_ecx, "ecx"); strcpy(dest, "ecx"); break;
        case _edx:  edx(_edx, "edx"); strcpy(dest, "edx"); break;
    }
    encode_push_instruction(dest);
    
    scan(&Token);
    semicolon(_semicolon, ";");
}

void process_pop_instruction(enum scope_type current_scope) 
{
    pop_radule(_pop, "pop");

    scan(&Token);
    colon(_colon, ":");

    scan(&Token);
    switch(Token.token_rep) 
    {
        case _ebp:  ebp(_ebp, "ebp"); strcpy(dest, "ebp"); break;
        case _esp:  esp(_esp, "esp"); strcpy(dest, "esp"); break;
        case _eax:  eax(_eax, "eax"); strcpy(dest, "eax"); break;
        case _ebx:  ebx(_ebx, "ebx"); strcpy(dest, "ebx"); break;
        case _ecx:  ecx(_ecx, "ecx"); strcpy(dest, "ecx"); break;
        case _edx:  edx(_edx, "edx"); strcpy(dest, "edx"); break;
    }
    encode_pop_instruction(dest);
    
    scan(&Token);
    semicolon(_semicolon, ";");
}


