#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"

int declare_type = 0;
int byte_size = 0;

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



/*SO the current issue here is that in nasm it declares a placeholder or vairable, then byte size, then
actually gives a numbered value. We dont do that in seedling. In seedling we only declare a placeholder
or variable and let the .assign section take care ove assigment. So that means is we have no numbered 
values to pass nasm right now. May have to create a global variable to keep track of assignment so we
have something to convert over. I am stumped on this part right now.*/
