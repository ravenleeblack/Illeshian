#ifndef SCOPE_TABLE_H
#define SCOPE_TABLE_H

#include "scope_types.h"

// External scope table instances
extern struct scope_table universal_scope;
extern struct scope_table global_param_scope;
extern struct scope_table global_scope;
extern struct scope_table global_block_scope;
extern struct scope_table local_param_scope;
extern struct scope_table local_scope;
extern struct scope_table local_block_scope;



extern const char* get_tool_type_str(int type);        // Convert tool type enum to string representation
extern const char* get_data_type_str(int data_type);   // Convert data type enum to string representation  

#endif // SCOPE_TABLE_H