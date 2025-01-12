#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"

int declare_type = 0;
int byte_size = 0;
int assign_flag = 0;



void process_declare_section(enum scope_type current_scope)
{
    declare(_declare_section, ".declare");

    while(1)
    {
        scan(&Token);

        if(Token.token_rep == _hold)
        {
            

            hold(_hold, "hold");

            scan(&Token);  // Get type
            declare_type = parse_type(current_scope);
            byte_size = get_byte_size(declare_type); // Get byte size

            scan(&Token);
            if(Token.token_rep == _colon)
            {
                colon(_colon, ":");

                scan(&Token);
                ident(_ident, Text);  // Variable name
                strcpy(declare_buffer, Text);

                    // Insert into current scope
                switch(current_scope) {
                    case scope_universal:     insert_universal_scope(Text, scope_hold_data_tool, declare_type);     break;  
                    case scope_global:        insert_global_scope(Text, scope_hold_data_tool, declare_type);        break;
                    case scope_global_param:  insert_global_param_scope(Text, scope_hold_data_tool, declare_type);  break;
                    case scope_global_block:  insert_global_block_scope(Text, scope_hold_data_tool, declare_type);  break;
                    case scope_local:         insert_local_scope(Text, scope_hold_data_tool, declare_type);         break;
                    case scope_local_param:   insert_local_param_scope(Text, scope_hold_data_tool, declare_type);   break; 
                    case scope_local_block:   insert_local_block_scope(Text, scope_hold_data_tool, declare_type);   break;
                    default:  error("seeding error: declare error: Invalid scope for declaration"); break;
                }
                
                encode_declare_instruction(declare_buffer, byte_size, 1);
            }
            else if(Token.token_rep == _table)
            {
                 assign_flag = 1;  
                 // Set a flag for a table array we have to handle it different. Since in seedling we do not iniialize the declare section 
                 // we wait till the assign section to finish and output to nasm with uninialized and the right array elements needed

                table(_table, "table");

                scan(&Token);
                colon(_colon, ":");

                scan(&Token);
                ident(_ident, Text);  // Variable name
                strcpy(declare_buffer, Text);

                    // Insert into current scope
                switch(current_scope) {
                    case scope_universal:     insert_universal_scope(Text, scope_hold_data_tool, declare_type);     break;  
                    case scope_global:        insert_global_scope(Text, scope_hold_data_tool, declare_type);        break;
                    case scope_global_param:  insert_global_param_scope(Text, scope_hold_data_tool, declare_type);  break;
                    case scope_global_block:  insert_global_block_scope(Text, scope_hold_data_tool, declare_type);  break;
                    case scope_local:         insert_local_scope(Text, scope_hold_data_tool, declare_type);         break;
                    case scope_local_param:   insert_local_param_scope(Text, scope_hold_data_tool, declare_type);   break; 
                    case scope_local_block:   insert_local_block_scope(Text, scope_hold_data_tool, declare_type);   break;
                    default:  error("seeding error: declare error: Invalid scope for declaration"); break;
                }
            }


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



/*SO the current issue here is that in nasm it declares a placeholder or vairable, then byte size, then
actually gives a numbered value. We dont do that in seedling. In seedling we only declare a placeholder
or variable and let the .assign section take care ove assigment. So that means is we have no numbered 
values to pass nasm right now. May have to create a global variable to keep track of assignment so we
have something to convert over. I am stumped on this part right now.*/
