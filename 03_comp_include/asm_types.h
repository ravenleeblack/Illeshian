

#define NOREG	-1		        // Use NOREG when the AST generation // functions have no register to return
#define NOLABEL	 0		        // Use NOLABEL when we have no label to // pass to genAST()

// ast node types
enum asm_type
{
    // Operators and comparison AST nodes
    ast_add, ast_minus, ast_multi, ast_divi, ast_equal, ast_not_equal, ast_less_then, ast_great_then, ast_less_equal, ast_great_equal, ast_assign,
    
    // Basic AST nodes for program structure
    ast_ident, ast_enfi, ast_glue, ast_scale, ast_widen,
    
    // Literal value AST nodes
    ast_num_literal, ast_mark_literal,
    
    // Control flow AST nodes
    ast_check, ast_loop,
    
    // Function and manager AST nodes
    ast_manager, ast_function, ast_mana_call, ast_func_call, ast_pre_func_call, ast_mana_pass_arg, ast_func_pass_arg,
    
    // Memory operation AST nodes
    ast_address, ast_pointer, ast_resize,
    
    // Complex data type AST nodes
    ast_list, ast_log,
    
    // Identifier position AST nodes
    ast_left_ident, ast_right_ident,
    
    // Operation AST nodes
    ast_transfer, ast_write,
    
    // Scope field AST nodes
    ast_universal_field, ast_global_field, ast_local_field,
    
    // Assignment scope AST nodes
    ast_assign_universal, ast_assign_global, ast_assign_local,
    
    // Universal path AST nodes
    ast_univ_tool_path, ast_universal_mid_path, ast_univ_manager_path,
    
    // Global path and tool AST nodes
    ast_global_tool_path, ast_global_func_path, ast_global_pass_arg, ast_global_param, ast_new_global_tool,
    
    // Local path and tool AST nodes
    ast_local_tool_path, ast_local_right_path, ast_local_pass_arg, ast_local_param, ast_new_local_tool,
    
    // New path and node creation AST nodes
    ast_new_mana_path, ast_new_func_node, ast_new_tool_path,

    ast_root_node, ast_use_node, ast_link_node,
    ast_mana_head, ast_mana_param, ast_mana_body, ast_mana_foot,
};
