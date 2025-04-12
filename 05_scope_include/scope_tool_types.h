

enum literal_type {
    literal_none = 0,
    literal_num,
    literal_mark,
    literal_strand,
    literal_hex,
    literal_deci,
    literal_decii
};


// DATA TOOL REPRESENTIVES
enum scope_tool_type {
    scope_tool_none = 0,
    

    scope_universal_tool,
    scope_global_tool,
    scope_global_block_tool,
    scope_local_tool,
    scope_local_block_tool,

    scope_arch_08_tool,
    scope_arch_16_tool,
    scope_arch_32_tool,
    scope_arch_64_tool,

    // File tools
    scope_file_tool,
    scope_file_name_literal_tool, 
    scope_extern_file_tool,
    scope_intern_file_tool,
    
    scope_jump_tool,

    scope_hold_data_tool,


    scope_strand_tool,

    // Function tools
    scope_tool_manager,
    scope_tool_function,
    scope_tool_call,
    scope_tool_prototype,
    scope_tool_proto_direct,
    scope_tool_proto_indirect,
    scope_tool_manager_param,
    scope_tool_function_param,
    
    // Data structure tools
    scope_tool_log,
    scope_tool_list,

    // Data handling tools
    scope_tool_hold,
    scope_tool_assign,
    scope_tool_table,
    scope_tool_pare,
    scope_tool_tripare,
    scope_tool_strand,
    
    // Control flow tools
    scope_tool_check,
    scope_tool_else,
    scope_tool_loop,
    scope_tool_set_loop,
    scope_tool_compare,
    scope_tool_state,
    scope_tool_comp_line_pos,
    scope_tool_otherwise,
    scope_tool_step,
    scope_tool_end_state,
    
    // Return tools
    scope_tool_pass_arg,
    scope_tool_yield,
    
    // Scope tools
    scope_tool_external,
    scope_tool_internal,
    scope_tool_change_global,
    scope_tool_change_local,
    
    // File tools
    scope_tool_use,
    scope_tool_link,
    scope_tool_alter,
    scope_tool_replace,
    scope_tool_transfer,
    scope_tool_file,
    scope_tool_member,

    scope_tool_cycle, 
    scope_tool_next,
    scope_tool_continue,

    scope_tool_expression = 300, 
    scope_tool_passage = 301,
    scope_tool_sibling = 400,
};