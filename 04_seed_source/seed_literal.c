#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"



static char* current_var_name = NULL;



void process_literal_section(enum scope_type current_scope)
{
    literal(_literal_section, ".literal");

    while(1) 
    {
        scan(&Token);

        if(Token.token_rep == _strand) 
        {
            strand(_strand, "strand");

            scan(&Token);
            colon(_colon, ":");

            scan(&Token);
            ident(_ident, Text);
            char* var_name = strdup(Text);
            current_var_name = strdup(var_name);

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
            if (Token.token_rep == _strand_literal) 
            {
                strand_literal(_strand_literal, Token.string_value);
                encode_literal_section(var_name, Token.string_value, length);
                
                // Insert into appropriate scope table
                switch(current_scope) {
                    case scope_universal:     insert_universal_scope(var_name, tool_strand, type_strand);     break;
                    case scope_global:        insert_global_scope(var_name, tool_strand, type_strand);        break;
                    case scope_global_block:  insert_global_block_scope(var_name, tool_strand, type_strand);  break;
                    case scope_local:         insert_local_scope(var_name, tool_strand, type_strand);         break;
                    case scope_local_block:   insert_local_block_scope(var_name, tool_strand, type_strand);   break;
                    default: error("seeding error: Invalid scope for strand literal"); break;
                }


                scan(&Token);
                while (Token.token_rep == _comma) {
                    comma(_comma, ",");
                    
                    scan(&Token);
                    if (Token.token_rep == _num_literal) {
                        num_literal(_num_literal, Token.num_value);
                        
                        
                        scan(&Token);
                    } else {
                        error("Expected numeric literal for escape character");
                    }
                }
              
                semicolon(_semicolon, ";");
            }
           
        }
        else if(Token.token_rep == _end_section) {
            reject_token(&Token);
            break;
        }
        else {
            reject_token(&Token);
            break;
        }
    }
}