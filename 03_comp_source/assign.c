#include "comp_def.h"  
#include "comp_data.h"   
#include "comp_decl.h" 

struct scope_table_entry *assign_data_tool()
{
    struct scope_table_entry* result = NULL;

    assign(_assign, "assign");

    scan(&Token);
    colon(_colon, ":");

    set_express_state(express_assign);
    result = parse_expressions();  

    scan(&Token);  
    semicolon(_semicolon, ";");

    return result; 
}


struct scope_table_entry* parse_assign() 
{
    express_state_machine state = get_express_state();
    struct scope_table_entry* entry = NULL;

    if (state == express_assign) 
    {
        scan(&Token);
        ident(_ident, Text);

        scan(&Token);
        assigner(_assigner, "=");

        scan(&Token);
        switch(Token.token_rep)
        {
            case _ident: 
                ident(_ident, Text);
                break;
            
            case _strand_literal: strand_literal(_strand_literal, Token.token_str);  break;
            case _num_literal:    num_literal(_num_literal, Token.num_value);        break;
            
            case _call: 
                call(_call, "call");

                scan(&Token);
                ident(_ident, Text);
                
                scan(&Token);
                if (Token.token_rep == _period)
                {
                    period(_period, ".");

                    scan(&Token);
                    ident(_ident, Text);

                    scan(&Token);
                    colon(_colon, ":");

                    scan(&Token);
                    if (Token.token_rep != _ender)
                    {
                        set_express_state(express_function_call_arg);
                        entry = parse_expressions();

                        scan(&Token);
                        ender(_ender, "`");
                    } 
                    else
                    {
                        ender(_ender, "`");
                    }
                } 
                else 
                {
                    colon(_colon, ":");

                    scan(&Token);
                    if (Token.token_rep != _ender) 
                    {
                        set_express_state(express_manager_call_arg);
                        entry = parse_expressions();

                        scan(&Token);
                        ender(_ender, "`");
                    } 
                    else 
                    {
                        ender(_ender, "`");
                    }
                }
                break;

            case _address:
                address(_address, "address");
                scan(&Token);
                lbrace(_lbrace, "[");
                scan(&Token);
                ident(_ident, Text);

                break;
            case _fetch:
                fetch(_fetch, "fetch");
                scan(&Token);
                lbrace(_lbrace, "[");
                scan(&Token);
                ident(_ident, Text);

                break;
            case _semicolon:  break;
            default: break;
        }
    }

    return entry;
}
