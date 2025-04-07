#include "comp_def.h"  
#include "comp_data.h"   
#include "comp_decl.h" 



struct scope_table_entry *block_compound(void)
{
    while(1)
    {
        scan(&Token);

        if (Token.token_rep == _rbracket)
        {
            reject_token(&Token);
            break;
        }
        switch(Token.token_rep)
        {
            case _hold:     hold_data_tool();     break;
            case _assign:   assign_data_tool();   break;
            case _check:    check_data_tool();    break;
            case _loop:     loop_data_tool();     break;
            case _set_loop: set_loop_data_tool(); break;
            case _compare:  compare_data_tool();  break;
            case _pare:     pare_data_tool();     break;    
            case _tripare:  tripare_data_tool();  break;    
            case _call:     call_data_tool();     break;    
            default: break;
        }
    }
    return NULL;
}
