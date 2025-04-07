#include "comp_def.h"  
#include "comp_data.h"   
#include "comp_decl.h" 



struct scope_table_entry *set_loop_data_tool()
{
    struct scope_table_entry *entry = NULL;
    set_loop(_set_loop, "set_loop");

    scan(&Token);
    colon(_colon, ":");

    // Initialize in current scope
    set_express_state(express_set_loop_initialize);
    entry = parse_expressions();

    scan(&Token);
    semicolon(_semicolon, ";");

    // Condition in current scope
    set_express_state(express_set_loop_condition);
    entry = parse_expressions();

    scan(&Token);
    semicolon(_semicolon, ";");

    // Iteration in current scope
    set_express_state(express_set_loop_iterate);
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

struct scope_table_entry* parse_set_loop_init()
{
    express_state_machine state = get_express_state();
    struct scope_table_entry* entry = NULL;
    int data_type;

    if (state == express_set_loop_initialize)
    {
        scan(&Token);
        int init_type = parse_type();

        scan(&Token);
        ident(_ident, Text);
    }
    return entry;
}

struct scope_table_entry* parse_set_loop_condition()
{
    express_state_machine state = get_express_state();
    struct scope_table_entry* entry = NULL;
    struct scope_table_entry* condition_var = NULL;
    int data_type;

    if (state == express_set_loop_condition)
    {
        scan(&Token);
        ident(_ident, Text);
        
        scan(&Token);
        entry = process_condition(Text, Token.token_rep, condition_var);
        
        scan(&Token);
        num_literal(_num_literal, Token.num_value);
    }
    return entry;
}

struct scope_table_entry* parse_set_loop_increment()
{
    express_state_machine state = get_express_state();
    struct scope_table_entry* entry = NULL;
    struct scope_table_entry* increment_var = NULL;
    int data_type;

    if (state == express_set_loop_iterate)
    {
        scan(&Token);
        ident(_ident, Text);

        scan(&Token);
        entry = process_increment_decrement(Text, Token.token_rep);
    }
    return entry;
}