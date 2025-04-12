#include <string.h>
#include "scope_types.h"
#include "scope_api.h"
#include "scope_table.h"



// Clean up the scope table system
int cleanup_scope_table_system(void) 
{
    // Cleanup all scope tables
    cleanup_universal_scope();

    cleanup_global_param_scope();
    cleanup_global_scope();
    cleanup_global_block_scope();
    
    cleanup_local_param_scope();
    cleanup_local_scope();
    cleanup_local_block_scope();
    return 0;
}

// Get hash value for symbol
int get_scope_hash(char *name) 
{
    int hash = 0;
    while (*name) {
        hash = (hash * 31 + *name) % scope_total_entries;
        name++;
    }
    return hash;
}

// Define scope table instances
struct scope_table universal_scope;
struct scope_table global_param_scope;
struct scope_table global_scope;
struct scope_table global_block_scope;
struct scope_table local_param_scope;
struct scope_table local_scope;
struct scope_table local_block_scope;

// Initialize functions
int init_universal_scope(void) 
{
    memset(&universal_scope, 0, sizeof(struct scope_table));
    return 0;
}

int init_global_param_scope(void)
{
    memset(&global_param_scope, 0, sizeof(struct scope_table));
    return 0;
}

int init_global_scope(void)
{
    memset(&global_scope, 0, sizeof(struct scope_table));
    return 0;
}

int init_global_block_scope(void)
{
    memset(&global_block_scope, 0, sizeof(struct scope_table));
    return 0;
}

int init_local_param_scope(void)
{
    memset(&local_param_scope, 0, sizeof(struct scope_table));
    return 0;
}

int init_local_scope(void)
{
    memset(&local_scope, 0, sizeof(struct scope_table));
    return 0;
}

int init_local_block_scope(void)
{
    memset(&local_block_scope, 0, sizeof(struct scope_table));
    return 0;
}

// Cleanup functions
int cleanup_universal_scope(void) 
{
    memset(&universal_scope, 0, sizeof(struct scope_table));
    return 0;
}

int cleanup_global_param_scope(void)
{
    memset(&global_param_scope, 0, sizeof(struct scope_table));
    return 0;
}

int cleanup_global_scope(void)
{
    memset(&global_scope, 0, sizeof(struct scope_table));
    return 0;
}

int cleanup_global_block_scope(void)
{
    memset(&global_block_scope, 0, sizeof(struct scope_table));
    return 0;
}

int cleanup_local_param_scope(void)
{
    memset(&local_param_scope, 0, sizeof(struct scope_table));
    return 0;
}

int cleanup_local_scope(void)
{
    memset(&local_scope, 0, sizeof(struct scope_table));
    return 0;
}

int cleanup_local_block_scope(void)
{
    memset(&local_block_scope, 0, sizeof(struct scope_table));
    return 0;
}