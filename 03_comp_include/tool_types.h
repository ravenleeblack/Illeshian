


// DATA TOOL REPRESENTIVES
enum data_tool_type {
    tool_none = 0,
    
    // Function tools
    tool_manager,
    tool_function,
    tool_call,
    tool_prototype,
    tool_proto_direct,
    tool_proto_indirect,
    tool_manager_param,
    tool_function_param,
    // Data structure tools
    tool_log,
    tool_list,


    // Data handling tools
    tool_hold,
    tool_assign,
    tool_table,
    tool_pare,
    tool_tripare,
    tool_strand,
    // Control flow tools
    tool_check,
    tool_else,
    tool_loop,
    tool_set_loop,
    tool_compare,
    tool_state,

    tool_comp_line_pos,
    tool_otherwise,
    tool_step,
    tool_end_state,
    
    // Return tools
    tool_pass_arg,
    tool_yield,
    
    // Scope tools
    tool_external,
    tool_internal,
    tool_change_global,
    tool_change_local,
    
    // File tools
    tool_use,
    tool_link,
    tool_alter,
    tool_replace,
    tool_transfer,
 
    tool_file,
    tool_member,

    tool_cycle, 
    tool_next,
    tool_continue,

    tool_expression = 300, 
    tool_passage = 301,
    tool_sibling = 400,
};


extern enum data_tool_type current_manager_return_type;