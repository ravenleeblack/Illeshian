#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"

void process_literal_section(enum scope_type current_scope)
{
    char preserve_text[60]; // Temporary buffer to store Text
    int ending_type = 0;

    literal(_literal_section, ".literal");

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
            strcpy(preserve_text, Text);   // Preserve the value of Text in the buffer so next scan doesnt over write it.

            switch(current_scope)      //this should be a placeholder already called in declare. SO we search, get it, then assign it a literal value.
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
            strcpy(literal_buffer, Token.string_value);

            switch(current_scope) {
                case scope_universal:     insert_universal_scope(literal_buffer, scope_strand_tool, scope_literal_data_type);     break;
                case scope_global:        insert_global_scope(literal_buffer, scope_strand_tool, scope_literal_data_type);        break;
                case scope_global_block:  insert_global_block_scope(literal_buffer, scope_strand_tool, scope_literal_data_type);  break;
                case scope_local:         insert_local_scope(literal_buffer, scope_strand_tool, scope_literal_data_type);         break;
                case scope_local_block:   insert_local_block_scope(literal_buffer, scope_strand_tool, scope_literal_data_type);   break;
                default: error("seeding error: Invalid scope for strand literal"); break;
            }
            
            scan(&Token);
            comma(_comma, ",");

            scan(&Token);
            num_literal(_num_literal, Token.num_value); 
            encode_literal_with_num_section(preserve_text, literal_buffer, Token.num_value);
           
            scan(&Token);
            semicolon(_semicolon, ";");
        }
       else if(Token.token_rep == _end)
        {
            end(_end, ".end");
            return 0;
        }
    }
}