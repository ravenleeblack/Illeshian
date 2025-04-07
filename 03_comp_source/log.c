#include "comp_def.h"  
#include "comp_data.h"   
#include "comp_decl.h" 



struct scope_table_entry *log_data_tool()
{
    struct scope_table_entry* result = NULL;
    
    scan(&Token);
    colon(_colon, ":");

    scan(&Token);
    lbracket(_lbracket, "{");

    set_express_state(express_log);
    result = parse_expressions();

    scan(&Token);
    rbracket(_rbracket, "}");

    scan(&Token);
    semicolon(_semicolon, ";");

    return result;
}


struct scope_table_entry* parse_log() 
{
    express_state_machine state = get_express_state();
    struct scope_table_entry* entry = NULL;
    
    if (state == express_log) 
    {
        while (1) 
        {
            scan(&Token);

            if (Token.token_rep == _rbracket) 
            {
                reject_token(&Token);
                break;
            }

            switch (Token.token_rep) 
            {
                case _hold:    hold_data_tool();    break;
                case _pare:    pare_data_tool();    break;    
                case _tripare: tripare_data_tool(); break;    
                default: break;
            }
        }
    }
    return entry;
}

            