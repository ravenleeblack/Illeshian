#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"



void process_compare_instruction(enum scope_type current_scope) 
{
    compare(_compare, "compare");

    scan(&Token);
    colon(_colon, ":");

    scan(&Token);                   // Handle destination operand
    switch(Token.token_rep) 
    {
        case _eax:  eax(_eax, "eax");    strcpy(dest, "eax"); break;
        case _ebp:  ebp(_ebp, "ebp");    strcpy(dest, "ebp"); break;
        case _esp:  esp(_esp, "esp");    strcpy(dest, "esp"); break;
        case _ebx:  ebx(_ebx, "ebx");    strcpy(dest, "ebx"); break;
        case _ecx:  ecx(_ecx, "ecx");    strcpy(dest, "ecx"); break;
        case _edx:  edx(_edx, "edx");    strcpy(dest, "edx"); break;  
        case _address:
            address(_address, "address");

            scan(&Token);
            lbrace(_lbrace, "[");

            scan(&Token);
            ident(_ident, Text);
            
            switch(current_scope)
            {
                case scope_universal:    entry_index = search_universal_scope(Text);    break;  
                case scope_global:       entry_index = search_global_scope(Text);       break;
                case scope_global_block: entry_index = search_global_block_scope(Text); break;
                case scope_local:        entry_index = search_local_scope(Text);        break;
                case scope_local_block:  entry_index = search_local_block_scope(Text);  break;
                default: error("seeding error: assign error: Invalid scope");           break;
            }

            strcpy(dest, Text);
                
            scan(&Token);
            rbrace(_rbrace, "]");

            scan(&Token);
            semicolon(_semicolon, ";");
            break;

        case _fetch:
            fetch(_fetch, "fetch");

            scan(&Token);
            lbrace(_lbrace, "[");

            scan(&Token);
            if(Token.token_rep == _ident)
            {
                ident(_ident, Text);

                switch(current_scope)
                {
                    case scope_universal:    entry_index = search_universal_scope(Text);    break;  
                    case scope_global:       entry_index = search_global_scope(Text);       break;
                    case scope_global_block: entry_index = search_global_block_scope(Text); break;
                    case scope_local:        entry_index = search_local_scope(Text);        break;
                    case scope_local_block:  entry_index = search_local_block_scope(Text);  break;
                    default: error("seeding error: assign error: Invalid scope");           break;
                }
                strcpy(dest, Text);

            }
            else
            {
                switch(Token.token_rep)
                {
                    case _eax:  eax(_eax, "eax");    strcpy(dest, "eax"); break;
                    case _ebp:  ebp(_ebp, "ebp");    strcpy(dest, "ebp"); break;
                    case _esp:  esp(_esp, "esp");    strcpy(dest, "esp"); break;
                    case _ebx:  ebx(_ebx, "ebx");    strcpy(dest, "ebx"); break;
                    case _ecx:  ecx(_ecx, "ecx");    strcpy(dest, "ecx"); break;
                    case _edx:  edx(_edx, "edx");    strcpy(dest, "edx"); break;  
                    case _ident:
                    ident(_ident, Text);

                    switch(current_scope)
                    {
                        case scope_universal:    entry_index = search_universal_scope(Text);    break;  
                        case scope_global:       entry_index = search_global_scope(Text);       break;
                        case scope_global_block: entry_index = search_global_block_scope(Text); break;
                        case scope_local:        entry_index = search_local_scope(Text);        break;
                        case scope_local_block:  entry_index = search_local_block_scope(Text);  break;
                        default: error("seeding error: assign error: Invalid scope");           break;
                    }
                    strcpy(dest, Text);
                    break;
                }

 
                scan(&Token);
                if (Token.token_rep == _add)
                {
                   add(_add, "+");
                } 

                scan(&Token);
                switch(Token.token_rep)
                {
                    case _eax:  eax(_eax, "eax");    strcpy(dest, "eax"); break;
                    case _ebp:  ebp(_ebp, "ebp");    strcpy(dest, "ebp"); break;
                    case _esp:  esp(_esp, "esp");    strcpy(dest, "esp"); break;
                    case _ebx:  ebx(_ebx, "ebx");    strcpy(dest, "ebx"); break;
                    case _ecx:  ecx(_ecx, "ecx");    strcpy(dest, "ecx"); break;
                    case _edx:  edx(_edx, "edx");    strcpy(dest, "edx"); break;  
                    case _ident:
                    ident(_ident, Text);

                    switch(current_scope)
                    {
                        case scope_universal:    entry_index = search_universal_scope(Text);    break;  
                        case scope_global:       entry_index = search_global_scope(Text);       break;
                        case scope_global_block: entry_index = search_global_block_scope(Text); break;
                        case scope_local:        entry_index = search_local_scope(Text);        break;
                        case scope_local_block:  entry_index = search_local_block_scope(Text);  break;
                        default: error("seeding error: assign error: Invalid scope");           break;
                    }
                    strcpy(dest, Text);
                    break;
                   case _num_literal:  num_literal(_num_literal, Token.num_value);  break;
                }
            }
           
            scan(&Token);
            rbrace(_rbrace, "]");
            break;

        default: 
            error("Compare instruction requires a register (ebp, esp, eax, ebx, ecx, edx)");
            break;
    }

    scan(&Token);
    comma(_comma, ",");

    scan(&Token);
    if (Token.token_rep == _num_literal) 
    {
        num_literal(_num_literal, Token.num_value);
        snprintf(src, sizeof(src), "%d", Token.num_value);
    } else {
        error("Compare instruction requires a numeric literal as second operand");
    }

    scan(&Token);
    semicolon(_semicolon, ";");

    if (nasm_flag) {
        encode_instruction("cmp", dest, src);
    }
}