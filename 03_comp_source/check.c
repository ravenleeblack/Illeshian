#include "comp_def.h"  
#include "comp_data.h"   
#include "comp_decl.h" 



struct scope_table_entry *check_data_tool()
{
    struct scope_table_entry *entry = NULL;
    check(_check, "check");

    scan(&Token);
    colon(_colon, ":");

    // Parse condition in current scope (manager or function)
    set_express_state(express_check_condition);
    entry = parse_expressions();

    scan(&Token);
    ender(_ender, "`");   
    
    scan(&Token);
    lbracket(_lbracket, "{");

    block_compound();

    scan(&Token);
    rbracket(_rbracket, "}");

    pass_arg_data_tool();

    return entry;
}

struct scope_table_entry* parse_check() 
{
    express_state_machine state = get_express_state();
    struct scope_table_entry* entry = NULL;
    int data_type;

    if (state == express_check_condition) 
    {
        scan(&Token);
        if (Token.token_rep == _ident) 
        {
            ident(_ident, Text);

            scan(&Token);
            entry = process_condition(Text, Token.token_rep, entry);
            
            // Get and validate rvalue
            scan(&Token);
            if (Token.token_rep == _num_literal)
            {
                num_literal(_num_literal, Token.num_value);
            }
            else if (Token.token_rep == _ident) 
            {
                struct scope_table_entry* rvalue_var = NULL;
                ident(_ident, Text);
            }
        }
    }
    return entry;
}