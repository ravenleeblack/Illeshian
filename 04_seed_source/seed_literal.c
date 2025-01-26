#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"

void process_literal_section(enum scope_type current_scope)
{
    phrase_retrievel src_index;

    char preserve_text[60]; // Temporary buffer to store Text

    literal(_literal_section, "literal");


    while(1) 
    {
        scan(&Token);

        if(Token.token_rep == _period)
        {
            period(_period, ".");
            
            scan(&Token);
            end(_end, "end");
            return 0;
        }
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
                case scope_universal:    search_universal_scope(Text);    break;  
                case scope_global:       search_global_scope(Text);       break;
                case scope_global_block: search_global_block_scope(Text); break;
                case scope_local:        search_local_scope(Text);        break;
                case scope_local_block:  search_local_block_scope(Text);  break;
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
            if(Token.token_rep == _num_value)
            {
               src_index = parse_num_literal(current_scope); 
               encode_literal_with_num_section(preserve_text, literal_buffer, src_index);
            }
            if(Token.token_rep == _hex_value)
            {
               src_index = parse_hex_literal(current_scope, 8);    //the end of literals are in 8 bit format I think??
               encode_literal_with_hex_section(preserve_text, literal_buffer, src_index);
            }

            scan(&Token);
            semicolon(_semicolon, ";");
        }
    }
}