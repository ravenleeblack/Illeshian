#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"


void process_file_section(enum scope_type current_scope)
{
    int file_type = 0;

    file_section(_file_section, ".file");

    while(1)
    {
        scan(&Token);

        if(Token.token_rep == _extern)
        {
            external(_extern, "extern");

            scan(&Token);
            colon(_colon, ":");

            scan(&Token);
            parse_ident(current_scope);
            convert_extern_label(Text);

            scan(&Token);
            semicolon(_semicolon, ";");
        }
        else if(Token.token_rep == _passage)
        {
            char preserve_file[60]; // Temporary buffer to store Text

            passage(_passage, "passage");

            scan(&Token);
            colon(_colon, ":");

            scan(&Token);
            ident(_ident, Text);
            strcpy(preserve_file, Text);    // preserve the file name so that scan doesnt over it

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
                case scope_universal:     insert_universal_scope(Text, tool_strand, type_strand);     break;
                case scope_global:        insert_global_scope(Text, tool_strand, type_strand);        break;
                case scope_global_block:  insert_global_block_scope(Text, tool_strand, type_strand);  break;
                case scope_local:         insert_local_scope(Text, tool_strand, type_strand);         break;
                case scope_local_block:   insert_local_block_scope(Text, tool_strand, type_strand);   break;
                 default: error("seeding error: Invalid scope for strand literal"); break;
            }
               
            scan(&Token);
            comma(_comma, ",");

            scan(&Token);
            num_literal(_num_literal, Token.num_value);
            encode_literal_section(preserve_file, Token.string_value, Token.num_value);

            scan(&Token);
            semicolon(_semicolon, ";");
        }
        else
        {
            reject_token(&Token);
            break;
        }
    }
}
