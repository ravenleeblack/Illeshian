#include "comp_def.h"
#include "comp_data.h"
#include "comp_decl.h"


// Single state variable
static express_state_machine current_express_state = express_none;

// State handler table
static const express_state_handler express_handlers[] = {
    {express_manager_arg,        parse_manager_args},
    {express_manager_call,       parse_manager_call},
    {express_manager_call_arg,   parse_manager_call_args},

    {express_function_call,      parse_manager_call},
    {express_function_arg,       parse_function_args},
    {express_function_call_arg,  parse_function_call_args},

    {express_pass_arg,           parse_pass_arg},
    {express_yield,              parse_yield},
    {express_assign,             parse_assign},
    {express_pare,               parse_pare},
    {express_tripare,            parse_tripare},
    {express_table,              parse_table},
    {express_check_condition,    parse_check},
    {express_loop_condition,     parse_loop},
    {express_set_loop_initialize,      parse_set_loop_init},
    {express_set_loop_condition,       parse_set_loop_condition},
    {express_set_loop_iterate,         parse_set_loop_increment},

    {express_compare,           parse_compare},
    {express_compare_line,      parse_compare_line},
    {express_compare_otherwise, parse_compare_otherwise},
    {express_compare_cycle,     parse_compare_cycle},
    {express_state,             parse_state},
    {express_sub_state,         parse_sub_state},
    {express_state_step,        parse_step},
    {express_state_cycle,       parse_state_cycle},
    {express_end_state,         parse_end_state},
    {express_ptr_arg,           parse_ptr_arg},
    {express_address,           parse_address},
    {express_fetch,             parse_fetch},
    {express_log,               parse_log},
    {express_list,              parse_list},
    {express_list_parse,        parse_expression_list},
    {express_external,          parse_external_express},
    {express_internal,          parse_internal_express},
    {express_convert,           parse_convert},
    {express_retrieve,          parse_retrieve},
    {express_vine,              parse_vine},
    {express_passage,           parse_passage},
    {express_port_hub,          parse_port_hub},
    {express_strand,            parse_strand},
    {express_proto,             parse_proto},
    {express_none,              NULL}
};





void set_express_state(express_state_machine state)
{
    current_express_state = state;
}

express_state_machine get_express_state(void)
{
    return current_express_state;
}

struct scope_table_entry* parse_expressions() 
{
    for (int i = 0; express_handlers[i].parse_func != NULL; i++)
    {
        if (express_handlers[i].current_state == current_express_state) 
        {
            return express_handlers[i].parse_func();
        }
    }
    return NULL;
}
