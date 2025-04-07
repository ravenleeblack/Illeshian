#ifndef EXPRESS_HANDLER_H
#define EXPRESS_HANDLER_H


#define MAX_NAME_LENGTH 256
#define MAX_OPERATOR_LENGTH 8
#define MAX_VALUE_LENGTH 256


// expression states
typedef enum express_state {
    express_none = 0,
    
    express_manager_arg,
    express_manager_call,
    express_manager_call_arg,

    express_function_arg,
    express_function_call,
    express_function_call_arg,
    express_pass_arg,
    express_yield,
    express_assign,
    express_pare,
    express_tripare,
    express_table,
    express_check_condition,
    express_loop_condition,
    express_set_loop_initialize,
    express_set_loop_condition,
    express_set_loop_iterate,

    express_compare,
    express_compare_line,
    express_compare_otherwise,
    express_compare_cycle,
    express_state,
    express_sub_state,
    express_state_step,
    express_state_cycle,
    express_end_state,
    express_ptr_arg,
    express_address,
    express_fetch,
    express_log,
    express_list,
    express_list_parse,
    express_external,
    express_internal,
    express_condition,
    express_expression,
    express_statement,
    express_convert,
    express_retrieve,
    express_vine,
    express_passage,
    express_port_hub,
    express_strand,
    express_proto,

} express_state_machine;

// expression types
typedef enum express_type {
    express_type_none,
    express_type_literal,
    express_type_identifier,
    express_type_unary,
    express_type_binary,
    express_type_call_manager,
    express_type_call_function,
    express_type_call_access,
    express_type_log_access,
    express_type_list_access,
    express_type_table_access,
    express_type_array_access,
    express_type_ptr_access
} express_type;

// operator precedence
typedef enum op_precedence {
    preced_none = 0,
    preced_primary,
    preced_pare,
    preced_tripare,
    preced_mana_call,
    preced_func_call,
    preced_asm_call,
    preced_address,
    preced_ptr,
    preced_access,
    preced_retrieve,
    preced_convert,
    preced_table,
    preced_strand,
    preced_unary,
    preced_factor,
    preced_term,
    preced_compare,
    preced_equal,
    preced_logic_and,
    preced_logic_or,
    preced_assign
} op_precedence;

// function pointer type for parse functions
typedef struct scope_table_entry* (*parse_func_ptr)(void);

// state handler structure
typedef struct express_state_handler 
{
    express_state_machine current_state;
    parse_func_ptr parse_func;
} express_state_handler;

// parse rule structure
typedef struct parse_rule
 {
    int token_type;
    op_precedence precedence;
    struct parse_rule* pre_rule;
    struct parse_rule* mid_rule;
    struct parse_rule* post_rule;
} parse_rule;

// expression handler structure
typedef struct express_handler 
{
    struct scope_table_entry* current_entry;
    express_type express_tool_type;
    struct express_handler* lvalue;
    struct express_handler* rvalue;
    parse_rule* get_rule;
} express_handler;


#endif // EXPRESS_HANDLER_H
