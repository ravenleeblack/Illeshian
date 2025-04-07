#include "comp_def.h"  
#include "comp_data.h"   
#include "comp_decl.h" 



struct scope_table_entry *global_compound(void)
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
            case _hold:     hold_data_tool();      break;
            case _assign:   assign_data_tool();    break;
            case _call:     call_data_tool();      break;
            case _check:    check_data_tool();     break;
            case _loop:     loop_data_tool();      break;
            case _set_loop: set_loop_data_tool();  break;
            case _compare:  compare_data_tool();   break;
            case _state:    state_data_tool();     break;
            default:  break;
        }

        switch (Token.token_rep)
        {
            case _hollow:
            case _num:
            case _mark:
            case _deci:
            case _log:
            case _list: 
            {
                parse_type();

                scan(&Token);
                if (Token.token_rep == _ident) 
                {
                    function_data_tool();
                } 
                else if (Token.token_rep == _table) 
                {
                    table_data_tool();
                }
                break;
            }
            default: break;
        }
    }

    return NULL;
}