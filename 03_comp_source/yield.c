#include "comp_def.h"  
#include "comp_data.h"   
#include "comp_decl.h" 



struct scope_table_entry *yield_data_tool()
{
    struct scope_table_entry* result = NULL;

    scan(&Token);
    yield(_yield, "yield");


    scan(&Token);
    colon(_colon, ":");

    set_express_state(express_yield);
    result = parse_expressions();


    scan(&Token);
    ender(_ender, "`");

    scan(&Token);
    semicolon(_semicolon, ";");

    return result;
}


struct scope_table_entry* parse_yield()
{
    express_state_machine state = get_express_state();
    struct scope_table_entry* entry = NULL;
    int data_type;

    if (state == express_yield)
    {
        scan(&Token);
        switch(Token.token_rep)
        {
            case _ident:         
            ident(_ident, Text); 
        
            break;
            case _strand_literal: strand_literal(_strand_literal, Token.token_str); break;
            case _num_literal:    num_literal(_num_literal, Token.num_value);       break;

            default:             break;
        }
    }
    return entry;
}

