#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"


void process_file_section(enum scope_type current_scope)
{
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
            ident(_ident, Text);
            strcpy(file_buffer, Text);

            switch(current_scope) {
                case scope_universal:     insert_universal_scope(file_buffer, scope_extern_file_tool, scope_extern_file_type);     break;
                case scope_global:        insert_global_scope(file_buffer, scope_extern_file_tool, scope_extern_file_type);        break;
                case scope_global_block:  insert_global_block_scope(file_buffer, scope_extern_file_tool, scope_extern_file_type);  break;
                case scope_local:         insert_local_scope(file_buffer, scope_extern_file_tool, scope_extern_file_type);         break;
                case scope_local_block:   insert_local_block_scope(file_buffer, scope_extern_file_tool, scope_extern_file_type);   break;
                default: error("seeding error: Invalid scope for strand literal"); break;
            }

            encode_extern_label(file_buffer);

            scan(&Token);
            semicolon(_semicolon, ";");
        }
        else if (Token.token_rep == _assign)
        {
            char preserve_file[60]; // Temporary buffer to store Text

            assign(_assign, "assign");

            scan(&Token);
            colon(_colon, ":");

            scan(&Token);
            ident(_ident, Text);
            strcpy(preserve_file, Text);    // preserve the file name so that scan doesnt over it

            switch(current_scope) {
                case scope_universal:     insert_universal_scope(preserve_file, scope_file_tool, scope_file_type);     break;
                case scope_global:        insert_global_scope(preserve_file, scope_file_tool, scope_file_type);        break;
                case scope_global_block:  insert_global_block_scope(preserve_file, scope_file_tool, scope_file_type);  break;
                case scope_local:         insert_local_scope(preserve_file, scope_file_tool, scope_file_type);         break;
                case scope_local_block:   insert_local_block_scope(preserve_file, scope_file_tool, scope_file_type);   break;
                default: error("seeding error: Invalid scope for strand literal"); break;
            }

            scan(&Token);
            assigner(_assigner, "=");

            scan(&Token);
            strand_literal(_strand_literal, Token.string_value);
            strcpy(literal_buffer, Token.string_value);

            switch(current_scope) {
                case scope_universal:     insert_universal_scope(literal_buffer, scope_file_name_literal_tool, scope_file_name_literal);     break;
                case scope_global:        insert_global_scope(literal_buffer, scope_file_name_literal_tool, scope_file_name_literal);        break;
                case scope_global_block:  insert_global_block_scope(literal_buffer, scope_file_name_literal_tool, scope_file_name_literal);  break;
                case scope_local:         insert_local_scope(literal_buffer, scope_file_name_literal_tool, scope_file_name_literal);         break;
                case scope_local_block:   insert_local_block_scope(literal_buffer, scope_file_name_literal_tool, scope_file_name_literal);   break;
                default: error("seeding error: Invalid scope for strand literal"); break;
            }
                
            scan(&Token);
            comma(_comma, ",");

            scan(&Token);
            num_literal(_num_literal, Token.num_value); 
            encode_literal_with_num_section(preserve_file, literal_buffer, Token.num_value);

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
