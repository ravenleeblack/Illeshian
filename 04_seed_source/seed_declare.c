#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"

int declare_type = 0;

void process_declare_section(enum scope_type current_scope)
{
    declare(_declare_section, ".declare");
    output_declare_section_header();        //should be called once only

    while(1)
    {
        scan(&Token);
        if(Token.token_rep == _end_section)
        {
            reject_token(&Token);
            break;
        }
        switch(Token.token_rep)
        {
            case _hold:
            {
                hold(_hold, "hold");

                scan(&Token);  // Get type
                declare_type = parse_type(current_scope);
            
                scan(&Token);
                colon(_colon, ":");

                scan(&Token);
                ident(_ident, Text);  // Variable name

                // Insert into current scope
                switch(current_scope) {
                    case scope_universal:     insert_universal_scope(Text, tool_hold, declare_type);     break;  
                    case scope_global:        insert_global_scope(Text, tool_hold, declare_type);        break;
                    case scope_global_param:  insert_global_param_scope(Text, tool_hold, declare_type);  break;
                    case scope_global_block:  insert_global_block_scope(Text, tool_hold, declare_type);  break;
                    case scope_local:         insert_local_scope(Text, tool_hold, declare_type);         break;
                    case scope_local_param:   insert_local_param_scope(Text, tool_hold, declare_type);   break; 
                    case scope_local_block:   insert_local_block_scope(Text, tool_hold, declare_type);   break;
                    default:  error("seeding error: declare error: Invalid scope for declaration"); break;
                }
                output_declare_section_body(Text, declare_type);

                scan(&Token);
                semicolon(_semicolon, ";");
            }
            break;
            case _aisle: 
            {
                 declare_type = parse_type(current_scope);

                scan(&Token);
                if(Token.token_rep == _table) {
                    table(_table, "table");

                    scan(&Token);
                    colon(_colon, ":");

                    scan(&Token);
                    ident(_ident, Text);  // Get array name
                
                                // Insert into current scope
                    switch(current_scope) {
                        case scope_universal:     insert_universal_scope(Text, tool_table, declare_type);     break;  
                        case scope_global:        insert_global_scope(Text, tool_table, declare_type);        break;
                        case scope_global_param:  insert_global_param_scope(Text, tool_table, declare_type);  break;
                        case scope_global_block:  insert_global_block_scope(Text, tool_table, declare_type);  break;
                        case scope_local:         insert_local_scope(Text, tool_table, declare_type);         break;
                        case scope_local_param:   insert_local_param_scope(Text, tool_table, declare_type);   break; 
                        case scope_local_block:   insert_local_block_scope(Text, tool_table, declare_type);   break;
                        default:  error("seeding error: declare error: Invalid scope for declaration"); break;
                    }
                    output_declare_section_body(Text, declare_type);

                    scan(&Token);
                    lbrace(_lbrace, "[");
                
                    scan(&Token);
                    num_literal(_num_literal, Token.num_value);  // Get array size
                    int size = Token.num_value;
                
                    scan(&Token);
                    rbrace(_rbrace, "]");

                    scan(&Token);
                    semicolon(_semicolon, ";");
                }
            }
            break;
            case _aisle_ptr:
            {
                declare_type = parse_type(current_scope);

                scan(&Token);
                semicolon(_semicolon, ";");
            }
            break;
            default:  reject_token(&Token); return 0;
        }
    }
}
