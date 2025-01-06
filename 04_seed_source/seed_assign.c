#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"




void process_assign_section(enum scope_type current_scope)
{
    struct scope_table_entry* entry = NULL;

    assign(_assign_section, ".assign");
    
    while(1)
    {
        scan(&Token);

        if(Token.token_rep == _assign)
        {
            assign(_assign, "assign");

            scan(&Token);
            colon(_colon, ":");

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

            scan(&Token);
            assigner(_assigner, "=");

            scan(&Token);  
            num_literal(_num_literal, Token.num_value);
            encode_assign_section(Text, Token.num_value, current_scope);  // Pass Token.num_value, not declare_type
        }
        if(Token.token_rep == _semicolon)
        {
            break;
        }
    }
    semicolon(_semicolon, ";");

    // Example: Encode NASM for assign section
    encode_scope_to_nasm("data", "assign_section");
    encode_assign_section("assign_section", 0, scope_global);
}