#include <stdio.h>
#include "scope_types.h"
#include "scope_api.h"
#include "scope_table.h"
#include "tool_types.h"    // Now include the actual enum definitions
#include "type_types.h"


const char* get_tool_type_str(int type) {
    switch(type) {

        // seedling label tools
        case scope_universal_tool:    return "tool_universal";
        case scope_global_tool:       return "tool_global";
        case scope_global_block_tool: return "tool_global_block";
        case scope_local_tool:        return "tool_local";
        case scope_local_block_tool:  return "tool_local_block";

        case scope_arch_08_tool:  return "arch_08";
        case scope_arch_16_tool:  return "arch_16";
        case scope_arch_32_tool:  return "arch_32";
        case scope_arch_64_tool:  return "arch_64";


        // File types
        case scope_file_tool: return "file tool";
        case scope_file_name_literal_tool: return "file name literal tool";
        case scope_extern_file_tool: return "extern tool";
        case scope_intern_file_tool: return "intern tool";

        case scope_jump_tool: return "jump tool";

        case scope_hold_data_tool: return "hold data tool";

        case scope_strand_tool: return "strand data tool";

        // Function tools
        case scope_tool_none: return "tool_none";
        case scope_tool_manager: return "tool_manager";
        case scope_tool_function: return "tool_function";
        case scope_tool_call: return "tool_call";
        case scope_tool_prototype: return "tool_prototype";
        case scope_tool_proto_direct: return "tool_proto_direct";
        case scope_tool_proto_indirect: return "tool_proto_indirect";
        case scope_tool_manager_param: return "tool_manager_param";
        case scope_tool_function_param: return "tool_function_param";
        
        // Data structure tools
        case scope_tool_log: return "tool_log";
        case scope_tool_list: return "tool_list";
        
        // Data handling tools
        case scope_tool_hold: return "tool_hold";
        case scope_tool_assign: return "tool_assign";
        case scope_tool_table: return "tool_table";
        case scope_tool_pare: return "tool_pare";
        case scope_tool_tripare: return "tool_tripare";
        case scope_tool_strand: return "tool_strand";
        
        // Control flow tools
        case scope_tool_check: return "tool_check";
        case scope_tool_else: return "tool_else";
        case scope_tool_loop: return "tool_loop";
        case scope_tool_set_loop: return "tool_set_loop";
        case scope_tool_compare: return "tool_compare";
        case scope_tool_state: return "tool_state";
        case scope_tool_comp_line_pos: return "tool_comp_line_pos";
        case scope_tool_otherwise: return "tool_otherwise";
        case scope_tool_step: return "tool_step";
        case scope_tool_end_state: return "tool_end_state";
        
        // Return tools
        case scope_tool_pass_arg: return "tool_pass_arg";
        case scope_tool_yield: return "tool_yield";
        
        // Scope tools
        case scope_tool_external: return "tool_external";
        case scope_tool_internal: return "tool_internal";
        case scope_tool_change_global: return "tool_change_global";
        case scope_tool_change_local: return "tool_change_local";
        
        // File tools
        case scope_tool_use: return "tool_use";
        case scope_tool_link: return "tool_link";
        case scope_tool_alter: return "tool_alter";
        case scope_tool_replace: return "tool_replace";
        case scope_tool_transfer: return "tool_transfer";
        case scope_tool_file: return "tool_file";
        case scope_tool_member: return "tool_member";
        
        // Flow control tools
        case scope_tool_cycle: return "tool_cycle";
        case scope_tool_next: return "tool_next";
        case scope_tool_continue: return "tool_continue";
        
        // Special tools
        case scope_tool_expression: return "tool_expression";
        case scope_tool_passage: return "tool_passage";
        case scope_tool_sibling: return "tool_sibling";
        
        default: return "unknown_tool";
    }
}

const char* get_data_type_str(int data_type) {
    switch(data_type) {

        // seedling label types
        case scope_universal_label:    return "universal_label";
        case scope_global_label:       return "global_label";
        case scope_global_block_label: return "global_block_label";
        case scope_local_label:        return "local_label";
        case scope_local_block_label:  return "local_block_label";

        case scope_arch_08_type:  return "arch_08";
        case scope_arch_16_type:  return "arch_16";
        case scope_arch_32_type:  return "arch_32";
        case scope_arch_64_type:  return "arch_64";

        case scope_file_type: return "file type";
        case scope_file_name_literal: return "file name literal";
        case scope_extern_file_type: return "extern file";
        case scope_intern_file_type: return "intern file";

        case scope_jump_type: return "jump label";

        case scope_literal_data_type: return "strand literal";

        // Special type
        case scope_type_none: return "type_none";
        
        // Basic data types
        case scope_type_hollow: return "type_hollow";
        case scope_type_mark: return "type_mark";
        case scope_type_num: return "type_num";
        case scope_type_long: return "type_long";
        case scope_type_deci: return "type_deci";
        case scope_type_decii: return "type_decii";
        case scope_type_strand: return "type_strand";
        
        // Complex data types
        case scope_type_table: return "type_table";
        case scope_type_pare: return "type_pare";
        case scope_type_tripare: return "type_tripare";
        case scope_type_log: return "type_log";
        case scope_type_list: return "type_list";
        case scope_type_prototype: return "type_prototype";
        
        // Stream types
        case scope_type_vine: return "type_vine";
        case scope_type_passage: return "type_passage";
        
        // Basic pointer types
        case scope_type_hollow_ptr: return "type_hollow_ptr";
        case scope_type_mark_ptr: return "type_mark_ptr";
        case scope_type_num_ptr: return "type_num_ptr";
        case scope_type_long_ptr: return "type_long_ptr";
        case scope_type_deci_ptr: return "type_deci_ptr";
        case scope_type_decii_ptr: return "type_decii_ptr";
        case scope_type_strand_ptr: return "type_strand_ptr";
        
        // Complex pointer types
        case scope_type_log_ptr: return "type_log_ptr";
        case scope_type_list_ptr: return "type_list_ptr";
        case scope_type_table_ptr: return "type_table_ptr";
        case scope_type_pare_ptr: return "type_pare_ptr";
        case scope_type_tripare_ptr: return "type_tripare_ptr";
        
        // Stream pointer types
        case scope_type_vine_ptr: return "type_vine_ptr";
        case scope_type_passage_ptr: return "type_passage_ptr";
        
        // File types


        case scope_type_header: return "type_header";
        case scope_type_source: return "type_source";
        case scope_type_module: return "type_module";
        case scope_type_loop_func: return "type_loop_func";
        
        // 64-bit types
        case scope_type_zone: return "type_zone";
        case scope_type_zones: return "type_zones";
        case scope_type_aisle: return "type_aisle";
        case scope_type_aisles: return "type_aisles";
        case scope_type_bay: return "type_bay";
        case scope_type_bays: return "type_bays";
        case scope_type_den: return "type_den";
        case scope_type_dens: return "type_dens";
        
        // 64-bit pointer types
        case scope_type_zone_ptr: return "type_zone_ptr";
        case scope_type_zones_ptr: return "type_zones_ptr";
        case scope_type_aisle_ptr: return "type_aisle_ptr";
        case scope_type_aisles_ptr: return "type_aisles_ptr";
        case scope_type_bay_ptr: return "type_bay_ptr";
        case scope_type_bays_ptr: return "type_bays_ptr";
        case scope_type_den_ptr: return "type_den_ptr";
        case scope_type_dens_ptr: return "type_dens_ptr";
        
        // File specific types
        case scope_type_header_file: return "type_header_file";
        case scope_type_source_file: return "type_source_file";
        case scope_type_seed_file: return "type_seed_file";
        case scope_type_mod_file: return "type_mod_file";
        case scope_type_sibling: return "type_sibling";
        
        // Special types
        case scope_type_address: return "type_address";
        case scope_type_fetch: return "type_fetch";
        
        default: return "unknown_type";
    }
}



void print_scope_entry(FILE *out, struct scope_table_entry *entry) 
{
    fprintf(out, "| %-20s | %-15s | %-15s | %-2d | R%d:S%d:E%d | %d |\n",
            entry->scope_table_name,
            get_tool_type_str(entry->scope_table_tool_type),
            get_data_type_str(entry->scope_table_data_type),
            entry->scope_table_current_scope,
            entry->scope_table_region,
            entry->scope_table_sector,
            entry->scope_table_entry,
            entry->scope_table_flags);
}

void print_scope_table(FILE *out, struct scope_table *table, const char *table_name) 
{
    fprintf(out, "\n=== %s ===\n", table_name);
    fprintf(out, "| %-20s | %-15s | %-15s | %-5s | %-8s | %-3s |\n",
            "Name", "Tool Type", "Data Type", "Scope", "Location", "Flg");
    fprintf(out, "|----------------------|-----------------|-----------------|-------|------------|-----|\n");
    
    for (int i = 0; i < scope_total_entries; i++) {
        if (table->entries[i].scope_table_flags == scope_flag_active) {
            print_scope_entry(out, &table->entries[i]);
        }
    }
}

void print_all_scope_tables(FILE *out) 
{
    fprintf(out, "SCOPE TABLE OUTPUT\n");
    fprintf(out, "==================\n");
    
    print_scope_table(out, &universal_scope, "Universal Scope");
    //print_scope_table(out, &global_param_scope, "Global Parameter Scope");
    print_scope_table(out, &global_scope, "Global Scope");
    print_scope_table(out, &global_block_scope, "Global Block Scope");
   // print_scope_table(out, &local_param_scope, "Local Parameter Scope");
    print_scope_table(out, &local_scope, "Local Scope");
    print_scope_table(out, &local_block_scope, "Local Block Scope");
}