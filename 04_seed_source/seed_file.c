#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"

int file_type = 0;
static char* current_file_name = NULL;




void process_file_section(enum scope_type current_scope)
{
    file_section(_file_section, ".file");

    while(1)
    {
        scan(&Token);

        if(Token.token_rep == _end_section)
        {
            reject_token(&Token);  // Check if this is interfering
            break;
        }

        switch(Token.token_rep)
        {
            case _intern:
            {
                internal(_intern, "intern");

                scan(&Token);
                switch(Token.token_rep) {
                    case _global:         global(_global, "global");                    break;
                    case _local:          local(_local, "local");                       break;
                }

                scan(&Token);
                colon(_colon, ":");

                scan(&Token);
                ident(_ident, Text);
                             
               switch(current_scope) {
                    case scope_universal:     insert_universal_scope(Text, tool_intern, file_type);     break;  
                    case scope_global:        insert_global_scope(Text, tool_intern, file_type);        break;
                    case scope_global_param:  insert_global_param_scope(Text, tool_intern, file_type);  break;
                    case scope_global_block:  insert_global_block_scope(Text, tool_intern, file_type);  break;
                    case scope_local:         insert_local_scope(Text, tool_intern, file_type);         break;
                    case scope_local_param:   insert_local_param_scope(Text, tool_intern, file_type);   break; 
                    case scope_local_block:   insert_local_block_scope(Text, tool_intern, file_type);   break;
                    default:  error("seeding error: declare error: Invalid scope for declaration"); break;
                }
                encode_file_section(Text);

                scan(&Token);
                semicolon(_semicolon, ";");
            }
            break;  
            case _extern:
            {
                external(_extern, "extern");

                scan(&Token);
                switch(Token.token_rep) {
                    case _global:         global(_global, "global");                    break;
                    case _local:          local(_local, "local");                       break;
                }

                scan(&Token);
                colon(_colon, ":");

                scan(&Token);
                ident(_ident, Text);
                             
                switch(current_scope) {
                    case scope_universal:     insert_universal_scope(Text, tool_extern, file_type);     break;  
                    case scope_global:        insert_global_scope(Text, tool_extern, file_type);        break;
                    case scope_global_param:  insert_global_param_scope(Text, tool_extern, file_type);  break;
                    case scope_global_block:  insert_global_block_scope(Text, tool_extern, file_type);  break;
                    case scope_local:         insert_local_scope(Text, tool_extern, file_type);         break;
                    case scope_local_param:   insert_local_param_scope(Text, tool_extern, file_type);   break; 
                    case scope_local_block:   insert_local_block_scope(Text, tool_extern, file_type);   break;
                    default:  error("seeding error: declare error: Invalid scope for declaration"); break;
                }
                encode_file_section(Text);

                scan(&Token);
                semicolon(_semicolon, ";");
            }
            break;  
            case _passage:
            {
                passage(_passage, "passage");

                scan(&Token);
                colon(_colon, ":");

               scan(&Token);
               ident(_ident, Text);
               char* var_name = strdup(Text);
               current_file_name = strdup(var_name);

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
               strand_literal(_strand_literal, Token.string_value);
                
               switch(current_scope) {
                    case scope_universal:     insert_universal_scope(var_name, tool_strand, type_strand);     break;
                    case scope_global:        insert_global_scope(var_name, tool_strand, type_strand);        break;
                    case scope_global_block:  insert_global_block_scope(var_name, tool_strand, type_strand);  break;
                    case scope_local:         insert_local_scope(var_name, tool_strand, type_strand);         break;
                    case scope_local_block:   insert_local_block_scope(var_name, tool_strand, type_strand);   break;
                    default: error("seeding error: Invalid scope for strand literal"); break;
                }
                encode_file_section(strlen(Token.string_value));

                scan(&Token);
                comma(_comma, ",");

                scan(&Token);
                num_literal(_num_literal, Token.num_value);

                scan(&Token);
                semicolon(_semicolon, ";");
            }
            break;        
            default: reject_token(&Token); return 0;
        }
    }
}
