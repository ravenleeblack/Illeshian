


// data types 
enum scope_data_types
{
    // Special type
    scope_type_none = 0,
    
    
    scope_universal_label,
    scope_global_label,
    scope_global_block_label,
    scope_local_label,
    scope_local_block_label,
    
    scope_arch_08_type,
    scope_arch_16_type,
    scope_arch_32_type,
    scope_arch_64_type,

    scope_jump_type,

    scope_literal_data_type,

    // Basic data types
    scope_type_hollow,    
    scope_type_mark,      
    scope_type_num,       
    scope_type_long,      
    scope_type_deci,      
    scope_type_decii,     
    scope_type_strand,    
    
    // Complex data types  
    scope_type_table,     
    scope_type_pare,      
    scope_type_tripare,   
    scope_type_log,       
    scope_type_list,      
    scope_type_prototype, 

    // Stream types
    scope_type_vine,
    scope_type_passage,
    
    // Basic pointer types
    scope_type_hollow_ptr,
    scope_type_mark_ptr,
    scope_type_num_ptr,
    scope_type_long_ptr,
    scope_type_deci_ptr,
    scope_type_decii_ptr,
    scope_type_strand_ptr,
    
    // Complex pointer types
    scope_type_log_ptr,    
    scope_type_list_ptr,   
    scope_type_table_ptr,  
    scope_type_pare_ptr,
    scope_type_tripare_ptr,
    
    // Stream pointer types
    scope_type_vine_ptr,
    scope_type_passage_ptr,
    
    // File types
    scope_file_type,
    scope_file_name_literal, 
    scope_extern_file_type,
    scope_intern_file_type,    
    scope_type_header,   
    scope_type_source,   
    scope_type_module,   
    scope_type_loop_func,
    
    // 64-bit types
    scope_type_zone, scope_type_zones,
    scope_type_aisle, scope_type_aisles,
    scope_type_bay, scope_type_bays,
    scope_type_den, scope_type_dens,
    
    // 64-bit pointer types
    scope_type_zone_ptr, scope_type_zones_ptr,
    scope_type_aisle_ptr, scope_type_aisles_ptr,
    scope_type_bay_ptr, scope_type_bays_ptr,
    scope_type_den_ptr, scope_type_dens_ptr,

    scope_type_header_file,
    scope_type_source_file,
    scope_type_seed_file,
    scope_type_mod_file,
    scope_type_sibling,

    scope_type_address,
    scope_type_fetch,
};




