#include "comp_def.h"  
#include "comp_data.h"   
#include "comp_decl.h" 



struct scope_table_entry *pass_arg_data_tool()
{
    struct scope_table_entry* result = NULL; 

    scan(&Token);
    pass_arg(_pass_arg, "pass_arg");

    scan(&Token);
    colon(_colon, ":");

    set_express_state(express_pass_arg);
    result = parse_expressions();

    scan(&Token);
    ender(_ender, "`");

    scan(&Token);
    semicolon(_semicolon, ";");

    return result;
}



struct scope_table_entry* parse_pass_arg()
{
    express_state_machine state = get_express_state();
    struct scope_table_entry* entry = NULL;
    int data_type;
    
    if (state == express_pass_arg)
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
