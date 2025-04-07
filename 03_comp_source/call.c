#include "comp_def.h"  
#include "comp_data.h"   
#include "comp_decl.h" 





struct scope_table_entry *call_data_tool()
{
    struct scope_table_entry* result;

    
    call(_call, "call");

    set_express_state(express_manager_call_arg);
    result = parse_expressions();


    scan(&Token);
    if (Token.token_rep == _period)
    {
        period(_period, ".");


        set_express_state(express_function_call_arg);
        result = parse_expressions();


        scan(&Token);
        colon(_colon, ":");

        scan(&Token);
        if (Token.token_rep != _ender)
         {

            set_express_state(express_function_call_arg);
            result = parse_expressions();

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
            result = parse_expressions();

            scan(&Token);
            ender(_ender, "`");
        } 
        else 
        {
            ender(_ender, "`");
        }
    }

    scan(&Token);
    semicolon(_semicolon, ";"); 

    return result;
}


struct scope_table_entry* parse_manager_call() 
{
    express_state_machine state = get_express_state();
    struct scope_table_entry* entry = NULL;
    int data_type;

    if (state == express_manager_call_arg)
    {
        switch(Token.token_rep)
        {
            case _ident:          
                ident(_ident, Text);  
                break;
            default: break;
        }
    }
    return entry;
}



struct scope_table_entry* parse_function_call() 
{
    express_state_machine state = get_express_state();
    struct scope_table_entry* entry = NULL;
    int data_type;

    if (state == express_function_call_arg) 
    {
        switch(Token.token_rep)
        {
            case _ident:          
                ident(_ident, Text);
                break;
            default:             
                break;
        }
    }
    return entry;
}


struct scope_table_entry* parse_manager_call_args()
{
    express_state_machine state = get_express_state();
    struct scope_table_entry* entry = NULL;
    int data_type;  

    if (state == express_manager_call_arg)
    {
        while(1)
        {
            entry = parse_type();

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


struct scope_table_entry* parse_function_call_args() 
{
    express_state_machine state = get_express_state();
    struct scope_table_entry* entry = NULL;
    int data_type;

    if (state == express_function_call_arg) 
    {
        while(1)
        {
            entry = parse_type();

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
