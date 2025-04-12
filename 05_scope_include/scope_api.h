#ifndef SCOPE_API_H
#define SCOPE_API_H

#include <stdio.h>
#include "scope_types.h"

#ifdef _WIN32
    #ifdef SCOPE_TABLE_EXPORTS
        #define scope_api __declspec(dllexport)
    #else
        #define scope_api __declspec(dllimport)
    #endif
#else
    #define scope_api __attribute__((visibility("default")))
#endif

// System initialization and cleanup
scope_api int init_scope_table_system(void);
scope_api int cleanup_scope_table_system(void);

// Individual scope cleanup functions
scope_api int cleanup_universal_scope(void);
scope_api int cleanup_global_param_scope(void);
scope_api int cleanup_global_scope(void);
scope_api int cleanup_global_block_scope(void);
scope_api int cleanup_local_param_scope(void);
scope_api int cleanup_local_scope(void);
scope_api int cleanup_local_block_scope(void);

// Hash function
scope_api int get_scope_hash(char *name);

// Universal scope operations
scope_api int insert_universal_scope(char *name, int tool_type, int data_type);
scope_api int search_universal_scope(char *name);

// Global parameter scope operations
scope_api int insert_global_param_scope(char *name, int tool_type, int data_type);
scope_api int search_global_param_scope(char *name);

// Global scope operations
scope_api int insert_global_scope(char *name, int tool_type, int data_type);
scope_api int search_global_scope(char *name);

// Global block scope operations
scope_api int insert_global_block_scope(char *name, int tool_type, int data_type);
scope_api int search_global_block_scope(char *name);

// Local parameter scope operations
scope_api int insert_local_param_scope(char *name, int tool_type, int data_type);
scope_api int search_local_param_scope(char *name);

// Local scope operations
scope_api int insert_local_scope(char *name, int tool_type, int data_type);
scope_api int search_local_scope(char *name);

// Local block scope operations
scope_api int insert_local_block_scope(char *name, int tool_type, int data_type);
scope_api int search_local_block_scope(char *name);

// Utility functions
scope_api void scope_print_table(FILE *out, const char *table_name);
scope_api void scope_print_all_tables(FILE *out);

#endif // SCOPE_API_H