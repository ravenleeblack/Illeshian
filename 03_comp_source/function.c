#include "comp_def.h"  
#include "comp_data.h"   
#include "comp_decl.h" 

struct scope_table_entry *function_arg_param()
{

    scan(&Token);
    if (Token.token_rep == _ender) 
    {
        reject_token(&Token);
        return NULL;
    }
    
    reject_token(&Token);

    set_express_state(express_function_arg);
    struct scope_table_entry* result = parse_expressions();   

    return result;
}



struct scope_table_entry *function_data_tool()
{
    parse_type();

    scan(&Token);
    ident(_ident, Text);

    scan(&Token);
    function(_function, "function");

    scan(&Token);
    colon(_colon, ":");

    function_arg_param();

    scan(&Token);
    ender(_ender, "`");

    scan(&Token);
    lbracket(_lbracket, "{");

    local_compound();

    scan(&Token);
    rbracket(_rbracket, "}");

    pass_arg_data_tool();  // Functions always use pass_arg

    return NULL;
}


struct scope_table_entry* parse_function_args() 
{
    express_state_machine state = get_express_state();
    struct scope_table_entry* entry = NULL;

    if (state == express_function_arg) 
    {
        while(1)
        {
            int data_type = parse_type();

            scan(&Token);
            if(Token.token_rep == _ident)
            {
                ident(_ident, Text);
            }
            if(Token.token_rep == _comma)
            {
                comma(_comma, ",");
                continue;
            }

            if(Token.token_rep == _ender)
            {
               reject_token(&Token);
               break;
            }
        }
    }
    return entry;
}