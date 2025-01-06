#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"

void process_move_instruction(enum scope_type current_scope) 
{
    int src_scope_index;
    int dest_scope_index;

    move_aisle(_move_aisle, "move_aisle");

    scan(&Token);
    colon(_colon, ":");

    scan(&Token);                   // Handle destination operand
    switch(Token.token_rep) 
    {
        case _ebp:  ebp(_ebp, "ebp");    strcpy(dest, "ebp");  break;
        case _esp:  esp(_esp, "esp");    strcpy(dest, "esp");  break;
        case _eax:  eax(_eax, "eax");    strcpy(dest, "eax");  break;
        case _ebx:  ebx(_ebx, "ebx");    strcpy(dest, "ebx");  break;
        case _ecx:  ecx(_ecx, "ecx");    strcpy(dest, "ecx");  break;
        case _edx:  edx(_edx, "edx");    strcpy(dest, "edx");  break;
        case _ident:  
            ident(_ident, Text);
            switch(current_scope)
            {
                case scope_universal:    dest_scope_index = search_universal_scope(Text);    break;  
                case scope_global:       dest_scope_index = search_global_scope(Text);       break;
                case scope_global_block: dest_scope_index = search_global_block_scope(Text); break;
                case scope_local:        dest_scope_index = search_local_scope(Text);        break;
                case scope_local_block:  dest_scope_index = search_local_block_scope(Text);  break;
                default: error("seeding error: assign error: Invalid scope");           break;
            }
            strcpy(dest, Text);
            break;
        default: break;
    }

    scan(&Token);
    comma(_comma, ",");

    scan(&Token);                   // Handle source operand
    switch(Token.token_rep)
    {
        case _ebp:  ebp(_ebp, "ebp");  strcpy(src, "ebp");  encode_instruction("mov", dest, src); break;
        case _esp:  esp(_esp, "esp");  strcpy(src, "esp");  encode_instruction("mov", dest, src); break;
        case _eax:  eax(_eax, "eax");  strcpy(src, "eax");  encode_instruction("mov", dest, src); break;
        case _ebx:  ebx(_ebx, "ebx");  strcpy(src, "ebx");  encode_instruction("mov", dest, src); break;
        case _ecx:  ecx(_ecx, "ecx");  strcpy(src, "ecx");  encode_instruction("mov", dest, src); break;
        case _edx:  edx(_edx, "edx");  strcpy(src, "edx");  encode_instruction("mov", dest, src); break;

        case _num_literal: 
            num_literal(_num_literal, Token.num_value); 
            snprintf(src, sizeof(src), "%d", Token.num_value); 
            encode_instruction("mov", dest, src);
            break;

        case _address:
            address(_address, "address");

            scan(&Token);
            lbrace(_lbrace, "[");

            scan(&Token);
            ident(_ident, Text);
            
            switch(current_scope)
            {
                case scope_universal:    src_scope_index = search_universal_scope(Text);    break;  
                case scope_global:       src_scope_index = search_global_scope(Text);       break;
                case scope_global_block: src_scope_index = search_global_block_scope(Text); break;
                case scope_local:        src_scope_index = search_local_scope(Text);        break;
                case scope_local_block:  src_scope_index = search_local_block_scope(Text);  break;
                default: error("seeding error: assign error: Invalid scope");           break;
            }

            strcpy(src, Text);
            encode_instruction("mov", dest, src);

            scan(&Token);
            rbrace(_rbrace, "]");
            break;

        case _fetch:
            fetch(_fetch, "fetch");

            scan(&Token);
            lbrace(_lbrace, "[");

            scan(&Token);
            ident(_ident, Text);
            
            switch(current_scope)
            {
                case scope_universal:    src_scope_index = search_universal_scope(Text);    break;  
                case scope_global:       src_scope_index = search_global_scope(Text);       break;
                case scope_global_block: src_scope_index = search_global_block_scope(Text); break;
                case scope_local:        src_scope_index = search_local_scope(Text);        break;
                case scope_local_block:  src_scope_index = search_local_block_scope(Text);  break;
                default: error("seeding error: assign error: Invalid scope");           break;
            }

            strcpy(src, Text);
            encode_fetch_reference(src, "", false);  // Fetch for source

            scan(&Token);
            rbrace(_rbrace, "]");
            break;

        case _ident:
            ident(_ident, Text);
            switch(current_scope)
            {
                case scope_universal:    src_scope_index = search_universal_scope(Text);    break;  
                case scope_global:       src_scope_index = search_global_scope(Text);       break;
                case scope_global_block: src_scope_index = search_global_block_scope(Text); break;
                case scope_local:        src_scope_index = search_local_scope(Text);        break;
                case scope_local_block:  src_scope_index = search_local_block_scope(Text);  break;
                default: error("seeding error: assign error: Invalid scope");           break;
            }
            strcpy(src, Text);
            encode_instruction("mov", dest, src);
            break;
    }

    scan(&Token);
    semicolon(_semicolon, ";");
}