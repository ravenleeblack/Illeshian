#ifndef SCOPE_TYPES_H
#define SCOPE_TYPES_H


// Include the enum definitions
#include "scope_data_types.h"
#include "scope_tool_types.h"


// Basic configuration
#define max_scope_name 60
#define max_tree_map_nodes 1000
#define max_treemap_child_nodes 1000

// Table structure
#define scope_table_regions 4
#define scope_table_sectors 12
#define scope_entries_sector 20
#define scope_entries_region (scope_table_sectors * scope_entries_sector)
#define scope_total_entries (scope_table_regions * scope_entries_region)

// Flags
#define scope_flag_empty 0
#define scope_flag_active 1
#define scope_flag_full 2
#define scope_flag_collision 3


// Scope types
enum scope_type {
    scope_universal,      // Top level scope
    scope_global_param,  // Global parameter scope
    scope_global,        // Global scope
    scope_global_block,  // Global block scope
    scope_local_param,   // Local parameter scope
    scope_local,         // Local scope
    scope_local_block,   // Local block scope
} ;

// Forward declaration for tree map node
struct tree_map_node;

// Core structures
struct scope_table_entry
{
    char scope_table_name[max_scope_name];  // Symbol name
    int scope_table_tool_type;              // Tool type
    int scope_table_data_type;              // Data type
    int scope_table_current_scope;          // Current scope level
    int scope_table_region;                 // Region in table
    int scope_table_sector;                 // Sector in region
    int scope_table_entry;                  // Entry in sector
    int scope_table_flags;                  // Entry flags
    int scope_table_value;                  // Value if constant/literal

    // New fields for pointer and literal type
    int is_pointer;                         // 0 = not a pointer, 1 = pointer
    int literal_type;                       // One of the values from enum literal_type

    // Scope relationships
    int scope_table_parent_scope;           // ID of parent scope
    char manager_name[max_scope_name];      // Parent manager name
    char function_name[max_scope_name];     // Function name if in function

    // Symbol table navigation
    struct scope_table_entry *parent_entry; // Link to parent entry
    struct scope_table_entry *child_entry;  // Link to child entry
    struct scope_table_entry *next_arg;     // Link to next argument

    // Tree map connection
    struct tree_map_node *treemap_node;     // Link to tree map node
};

struct scope_table {
    struct scope_table_entry entries[scope_total_entries];
    int region_flags[scope_table_regions];
    int sector_flags[scope_table_regions][scope_table_sectors];
    int current_region;
    int current_sector;
    int current_entry;
};

#endif // SCOPE_TYPES_H