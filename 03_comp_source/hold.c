#include "comp_def.h"  
#include "comp_data.h"   
#include "comp_decl.h" 




struct scope_table_entry *hold_data_tool()
{
    struct scope_table_entry *entry = NULL;
    hold(_hold, "hold");
    
    scan(&Token);
    int hold_return = parse_type();

    scan(&Token);
    colon(_colon, ":");

    while (1)
    {
        scan(&Token);

        if (Token.token_rep == _semicolon) 
        {
            reject_token(&Token);
            break;
        }

        if (Token.token_rep == _comma) 
        {
            comma(_comma, ",");
            continue;
        }

        if (Token.token_rep == _ident) 
        {
            ident(_ident, Text);
        }
    }

    scan(&Token);
    semicolon(_semicolon, ";");
    
    return entry;
}


