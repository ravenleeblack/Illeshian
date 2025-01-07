#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"

void process_literal_section(enum scope_type current_scope)
{
    char preserve_text[60]; // Temporary buffer to store Text

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
            strcpy(preserve_text, Text);   // Preserve the value of Text in the buffer so next scan doesnt over write it.

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
                
            // Insert into appropriate scope table
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
            encode_literal_section(preserve_text, Token.string_value, Token.num_value);

            scan(&Token);
            semicolon(_semicolon, ";");
        }
        else
        {
            reject_token(&Token);  //we reject it so the next section can handle it then we break out of this loop.
            break;
        }
    }
}