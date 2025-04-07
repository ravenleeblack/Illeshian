#include "comp_def.h"  
#include "comp_data.h"   
#include "comp_decl.h" 




struct scope_table_entry *list_data_tool()
{
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
        else
        {
             set_express_state(express_list);
             struct scope_table_entry* result = parse_expressions();      
        }
    }

    scan(&Token);
    semicolon(_semicolon, ";");
    return NULL;
}


struct scope_table_entry* parse_list()
 {
    express_state_machine state = get_express_state();
    struct scope_table_entry* entry = NULL;
    int data_type;

    if (state == express_list) 
    {
        switch(Token.token_rep)
        {
            case _ident:          
            
            list_ident(_ident, Text);  
             
            break;
            case _strand_literal: strand_literal(_strand_literal, Token.token_str); break;
            case _num_literal:    num_literal(_num_literal, Token.num_value);       break;
            default: return NULL;
        }
    }
    return entry;
}



struct scope_table_entry* parse_expression_list(void) {
    express_state_machine state = get_express_state();
    struct scope_table_entry* entry = NULL;
    
    if (state == express_list_parse) {
        // Match tokens for expression list pattern
        // expr1, expr2, expr3
    }
    return entry;
}
