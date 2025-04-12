#include <string.h>
#include "scope_types.h"
#include "scope_api.h"
#include "scope_table.h"

// Universal scope functions
int insert_universal_scope(char *name, int tool_type, int data_type) 
{
    int region = 0;
    int sector = 0;
    int entry = 0;
    int hash = (region * scope_entries_region) + (sector * scope_entries_sector) + entry;
    
    while (universal_scope.entries[hash].scope_table_flags != scope_flag_empty) {
        if (strcmp(universal_scope.entries[hash].scope_table_name, name) == 0) {
            universal_scope.sector_flags[region][sector] = scope_flag_collision;
            sector++;
            if (sector >= scope_entries_sector) {
                sector = 0;
                region++;
            }
            hash = (region * scope_entries_region) + (sector * scope_entries_sector) + entry;
            continue;
        }
        
        entry++;
        if (entry >= scope_entries_sector) {
            entry = 0;
            sector++;
            if (sector >= scope_entries_sector) {
                sector = 0;
                region++;
            }
        }
        hash = (region * scope_entries_region) + (sector * scope_entries_sector) + entry;
    }
    
    strncpy(universal_scope.entries[hash].scope_table_name, name, max_scope_name);
    universal_scope.entries[hash].scope_table_tool_type = tool_type;
    universal_scope.entries[hash].scope_table_data_type = data_type;
    universal_scope.entries[hash].scope_table_current_scope = scope_universal;
    universal_scope.entries[hash].scope_table_region = region;
    universal_scope.entries[hash].scope_table_sector = sector;
    universal_scope.entries[hash].scope_table_entry = entry;
    universal_scope.entries[hash].scope_table_flags = scope_flag_active;
    
    universal_scope.region_flags[region] = scope_flag_active;
    universal_scope.sector_flags[region][sector] = scope_flag_active;
    
    return hash;
}

int search_universal_scope(char *name) 
{
    int region = 0;
    int sector = 0;
    int entry = 0;
    
    while (region < scope_table_regions) {
        if (universal_scope.region_flags[region] == scope_flag_empty) {
            region++;
            continue;
        }
        
        while (sector < scope_entries_sector) {
            if (universal_scope.sector_flags[region][sector] == scope_flag_empty) {
                sector++;
                continue;
            }
            
            for (entry = 0; entry < scope_entries_sector; entry++) {
                int hash = (region * scope_entries_region) + (sector * scope_entries_sector) + entry;
                
                if (universal_scope.entries[hash].scope_table_flags == scope_flag_active && 
                    strcmp(universal_scope.entries[hash].scope_table_name, name) == 0) {
                    return hash;
                }
            }
            sector++;
        }
        sector = 0;
        region++;
    }
    return -1;
}


// Global parameter scope functions
int insert_global_param_scope(char *name, int tool_type, int data_type) 
{
    int region = 0;
    int sector = 0;
    int entry = 0;
    int hash = (region * scope_entries_region) + (sector * scope_entries_sector) + entry;
    
    while (global_param_scope.entries[hash].scope_table_flags != scope_flag_empty) {
        if (strcmp(global_param_scope.entries[hash].scope_table_name, name) == 0) {
            global_param_scope.sector_flags[region][sector] = scope_flag_collision;
            sector++;
            if (sector >= scope_entries_sector) {
                sector = 0;
                region++;
            }
            hash = (region * scope_entries_region) + (sector * scope_entries_sector) + entry;
            continue;
        }
        
        entry++;
        if (entry >= scope_entries_sector) {
            entry = 0;
            sector++;
            if (sector >= scope_entries_sector) {
                sector = 0;
                region++;
            }
        }
        hash = (region * scope_entries_region) + (sector * scope_entries_sector) + entry;
    }
    
    strncpy(global_param_scope.entries[hash].scope_table_name, name, max_scope_name);
    global_param_scope.entries[hash].scope_table_tool_type = tool_type;
    global_param_scope.entries[hash].scope_table_data_type = data_type;
    global_param_scope.entries[hash].scope_table_current_scope = scope_global_param;
    global_param_scope.entries[hash].scope_table_region = region;
    global_param_scope.entries[hash].scope_table_sector = sector;
    global_param_scope.entries[hash].scope_table_entry = entry;
    global_param_scope.entries[hash].scope_table_flags = scope_flag_active;
    
    global_param_scope.region_flags[region] = scope_flag_active;
    global_param_scope.sector_flags[region][sector] = scope_flag_active;
    
    return hash;
}

int search_global_param_scope(char *name) 
{
    int region = 0;
    int sector = 0;
    int entry = 0;
    
    while (region < scope_table_regions) {
        if (global_param_scope.region_flags[region] == scope_flag_empty) {
            region++;
            continue;
        }
        
        while (sector < scope_entries_sector) {
            if (global_param_scope.sector_flags[region][sector] == scope_flag_empty) {
                sector++;
                continue;
            }
            
            for (entry = 0; entry < scope_entries_sector; entry++) {
                int hash = (region * scope_entries_region) + (sector * scope_entries_sector) + entry;
                
                if (global_param_scope.entries[hash].scope_table_flags == scope_flag_active && 
                    strcmp(global_param_scope.entries[hash].scope_table_name, name) == 0) {
                    return hash;
                }
            }
            sector++;
        }
        sector = 0;
        region++;
    }
    return -1;
}

// Global scope functions
int insert_global_scope(char *name, int tool_type, int data_type) 
{
    int region = 0;
    int sector = 0;
    int entry = 0;
    int hash = (region * scope_entries_region) + (sector * scope_entries_sector) + entry;
    
    while (global_scope.entries[hash].scope_table_flags != scope_flag_empty) {
        if (strcmp(global_scope.entries[hash].scope_table_name, name) == 0) {
            global_scope.sector_flags[region][sector] = scope_flag_collision;
            sector++;
            if (sector >= scope_entries_sector) {
                sector = 0;
                region++;
            }
            hash = (region * scope_entries_region) + (sector * scope_entries_sector) + entry;
            continue;
        }
        
        entry++;
        if (entry >= scope_entries_sector) {
            entry = 0;
            sector++;
            if (sector >= scope_entries_sector) {
                sector = 0;
                region++;
            }
        }
        hash = (region * scope_entries_region) + (sector * scope_entries_sector) + entry;
    }
    
    strncpy(global_scope.entries[hash].scope_table_name, name, max_scope_name);
    global_scope.entries[hash].scope_table_tool_type = tool_type;
    global_scope.entries[hash].scope_table_data_type = data_type;
    global_scope.entries[hash].scope_table_current_scope = scope_global;
    global_scope.entries[hash].scope_table_region = region;
    global_scope.entries[hash].scope_table_sector = sector;
    global_scope.entries[hash].scope_table_entry = entry;
    global_scope.entries[hash].scope_table_flags = scope_flag_active;
    
    global_scope.region_flags[region] = scope_flag_active;
    global_scope.sector_flags[region][sector] = scope_flag_active;
    
    return hash;
}

int search_global_scope(char *name) 
{
    int region = 0;
    int sector = 0;
    int entry = 0;
    
    while (region < scope_table_regions) {
        if (global_scope.region_flags[region] == scope_flag_empty) {
            region++;
            continue;
        }
        
        while (sector < scope_entries_sector) {
            if (global_scope.sector_flags[region][sector] == scope_flag_empty) {
                sector++;
                continue;
            }
            
            for (entry = 0; entry < scope_entries_sector; entry++) {
                int hash = (region * scope_entries_region) + (sector * scope_entries_sector) + entry;
                
                if (global_scope.entries[hash].scope_table_flags == scope_flag_active && 
                    strcmp(global_scope.entries[hash].scope_table_name, name) == 0) {
                    return hash;
                }
            }
            sector++;
        }
        sector = 0;
        region++;
    }
    return -1;
}

// Global block scope functions
int insert_global_block_scope(char *name, int tool_type, int data_type) 
{
    int region = 0;
    int sector = 0;
    int entry = 0;
    int hash = (region * scope_entries_region) + (sector * scope_entries_sector) + entry;
    
    while (global_block_scope.entries[hash].scope_table_flags != scope_flag_empty) {
        if (strcmp(global_block_scope.entries[hash].scope_table_name, name) == 0) {
            global_block_scope.sector_flags[region][sector] = scope_flag_collision;
            sector++;
            if (sector >= scope_entries_sector) {
                sector = 0;
                region++;
            }
            hash = (region * scope_entries_region) + (sector * scope_entries_sector) + entry;
            continue;
        }
        
        entry++;
        if (entry >= scope_entries_sector) {
            entry = 0;
            sector++;
            if (sector >= scope_entries_sector) {
                sector = 0;
                region++;
            }
        }
        hash = (region * scope_entries_region) + (sector * scope_entries_sector) + entry;
    }
    
    strncpy(global_block_scope.entries[hash].scope_table_name, name, max_scope_name);
    global_block_scope.entries[hash].scope_table_tool_type = tool_type;
    global_block_scope.entries[hash].scope_table_data_type = data_type;
    global_block_scope.entries[hash].scope_table_current_scope = scope_global_block;
    global_block_scope.entries[hash].scope_table_region = region;
    global_block_scope.entries[hash].scope_table_sector = sector;
    global_block_scope.entries[hash].scope_table_entry = entry;
    global_block_scope.entries[hash].scope_table_flags = scope_flag_active;
    
    global_block_scope.region_flags[region] = scope_flag_active;
    global_block_scope.sector_flags[region][sector] = scope_flag_active;
    
    return hash;
}

int search_global_block_scope(char *name) 
{
    int region = 0;
    int sector = 0;
    int entry = 0;
    
    while (region < scope_table_regions) {
        if (global_block_scope.region_flags[region] == scope_flag_empty) {
            region++;
            continue;
        }
        
        while (sector < scope_entries_sector) {
            if (global_block_scope.sector_flags[region][sector] == scope_flag_empty) {
                sector++;
                continue;
            }
            
            for (entry = 0; entry < scope_entries_sector; entry++) {
                int hash = (region * scope_entries_region) + (sector * scope_entries_sector) + entry;
                
                if (global_block_scope.entries[hash].scope_table_flags == scope_flag_active && 
                    strcmp(global_block_scope.entries[hash].scope_table_name, name) == 0) {
                    return hash;
                }
            }
            sector++;
        }
        sector = 0;
        region++;
    }
    return -1;
}

// Local parameter scope functions
int insert_local_param_scope(char *name, int tool_type, int data_type) 
{
    int region = 0;
    int sector = 0;
    int entry = 0;
    int hash = (region * scope_entries_region) + (sector * scope_entries_sector) + entry;
    
    while (local_param_scope.entries[hash].scope_table_flags != scope_flag_empty) {
        if (strcmp(local_param_scope.entries[hash].scope_table_name, name) == 0) {
            local_param_scope.sector_flags[region][sector] = scope_flag_collision;
            sector++;
            if (sector >= scope_entries_sector) {
                sector = 0;
                region++;
            }
            hash = (region * scope_entries_region) + (sector * scope_entries_sector) + entry;
            continue;
        }
        
        entry++;
        if (entry >= scope_entries_sector) {
            entry = 0;
            sector++;
            if (sector >= scope_entries_sector) {
                sector = 0;
                region++;
            }
        }
        hash = (region * scope_entries_region) + (sector * scope_entries_sector) + entry;
    }
    
    strncpy(local_param_scope.entries[hash].scope_table_name, name, max_scope_name);
    local_param_scope.entries[hash].scope_table_tool_type = tool_type;
    local_param_scope.entries[hash].scope_table_data_type = data_type;
    local_param_scope.entries[hash].scope_table_current_scope = scope_local_param;
    local_param_scope.entries[hash].scope_table_region = region;
    local_param_scope.entries[hash].scope_table_sector = sector;
    local_param_scope.entries[hash].scope_table_entry = entry;
    local_param_scope.entries[hash].scope_table_flags = scope_flag_active;
    
    local_param_scope.region_flags[region] = scope_flag_active;
    local_param_scope.sector_flags[region][sector] = scope_flag_active;
    
    return hash;
}

int search_local_param_scope(char *name) 
{
    int region = 0;
    int sector = 0;
    int entry = 0;
    
    while (region < scope_table_regions) {
        if (local_param_scope.region_flags[region] == scope_flag_empty) {
            region++;
            continue;
        }
        
        while (sector < scope_entries_sector) {
            if (local_param_scope.sector_flags[region][sector] == scope_flag_empty) {
                sector++;
                continue;
            }
            
            for (entry = 0; entry < scope_entries_sector; entry++) {
                int hash = (region * scope_entries_region) + (sector * scope_entries_sector) + entry;
                
                if (local_param_scope.entries[hash].scope_table_flags == scope_flag_active && 
                    strcmp(local_param_scope.entries[hash].scope_table_name, name) == 0) {
                    return hash;
                }
            }
            sector++;
        }
        sector = 0;
        region++;
    }
    return -1;
}

// Local scope functions
int insert_local_scope(char *name, int tool_type, int data_type) 
{
    int region = 0;
    int sector = 0;
    int entry = 0;
    int hash = (region * scope_entries_region) + (sector * scope_entries_sector) + entry;
    
    while (local_scope.entries[hash].scope_table_flags != scope_flag_empty) {
        if (strcmp(local_scope.entries[hash].scope_table_name, name) == 0) {
            local_scope.sector_flags[region][sector] = scope_flag_collision;
            sector++;
            if (sector >= scope_entries_sector) {
                sector = 0;
                region++;
            }
            hash = (region * scope_entries_region) + (sector * scope_entries_sector) + entry;
            continue;
        }
        
        entry++;
        if (entry >= scope_entries_sector) {
            entry = 0;
            sector++;
            if (sector >= scope_entries_sector) {
                sector = 0;
                region++;
            }
        }
        hash = (region * scope_entries_region) + (sector * scope_entries_sector) + entry;
    }
    
    strncpy(local_scope.entries[hash].scope_table_name, name, max_scope_name);
    local_scope.entries[hash].scope_table_tool_type = tool_type;
    local_scope.entries[hash].scope_table_data_type = data_type;
    local_scope.entries[hash].scope_table_current_scope = scope_local;
    local_scope.entries[hash].scope_table_region = region;
    local_scope.entries[hash].scope_table_sector = sector;
    local_scope.entries[hash].scope_table_entry = entry;
    local_scope.entries[hash].scope_table_flags = scope_flag_active;
    
    local_scope.region_flags[region] = scope_flag_active;
    local_scope.sector_flags[region][sector] = scope_flag_active;
    
    return hash;
}

int search_local_scope(char *name) 
{
    int region = 0;
    int sector = 0;
    int entry = 0;
    
    while (region < scope_table_regions) {
        if (local_scope.region_flags[region] == scope_flag_empty) {
            region++;
            continue;
        }
        
        while (sector < scope_entries_sector) {
            if (local_scope.sector_flags[region][sector] == scope_flag_empty) {
                sector++;
                continue;
            }
            
            for (entry = 0; entry < scope_entries_sector; entry++) {
                int hash = (region * scope_entries_region) + (sector * scope_entries_sector) + entry;
                
                if (local_scope.entries[hash].scope_table_flags == scope_flag_active && 
                    strcmp(local_scope.entries[hash].scope_table_name, name) == 0) {
                    return hash;
                }
            }
            sector++;
        }
        sector = 0;
        region++;
    }
    return -1;
}

// Local block scope functions
int insert_local_block_scope(char *name, int tool_type, int data_type) 
{
    int region = 0;
    int sector = 0;
    int entry = 0;
    int hash = (region * scope_entries_region) + (sector * scope_entries_sector) + entry;
    
    while (local_block_scope.entries[hash].scope_table_flags != scope_flag_empty) {
        if (strcmp(local_block_scope.entries[hash].scope_table_name, name) == 0) {
            local_block_scope.sector_flags[region][sector] = scope_flag_collision;
            sector++;
            if (sector >= scope_entries_sector) {
                sector = 0;
                region++;
            }
            hash = (region * scope_entries_region) + (sector * scope_entries_sector) + entry;
            continue;
        }
        
        entry++;
        if (entry >= scope_entries_sector) {
            entry = 0;
            sector++;
            if (sector >= scope_entries_sector) {
                sector = 0;
                region++;
            }
        }
        hash = (region * scope_entries_region) + (sector * scope_entries_sector) + entry;
    }
    
    strncpy(local_block_scope.entries[hash].scope_table_name, name, max_scope_name);
    local_block_scope.entries[hash].scope_table_tool_type = tool_type;
    local_block_scope.entries[hash].scope_table_data_type = data_type;
    local_block_scope.entries[hash].scope_table_current_scope = scope_local_block;
    local_block_scope.entries[hash].scope_table_region = region;
    local_block_scope.entries[hash].scope_table_sector = sector;
    local_block_scope.entries[hash].scope_table_entry = entry;
    local_block_scope.entries[hash].scope_table_flags = scope_flag_active;
    
    local_block_scope.region_flags[region] = scope_flag_active;
    local_block_scope.sector_flags[region][sector] = scope_flag_active;
    
    return hash;
}

int search_local_block_scope(char *name) 
{
    int region = 0;
    int sector = 0;
    int entry = 0;
    
    while (region < scope_table_regions) {
        if (local_block_scope.region_flags[region] == scope_flag_empty) {
            region++;
            continue;
        }
        
        while (sector < scope_entries_sector) {
            if (local_block_scope.sector_flags[region][sector] == scope_flag_empty) {
                sector++;
                continue;
            }
            
            for (entry = 0; entry < scope_entries_sector; entry++) {
                int hash = (region * scope_entries_region) + (sector * scope_entries_sector) + entry;
                
                if (local_block_scope.entries[hash].scope_table_flags == scope_flag_active && 
                    strcmp(local_block_scope.entries[hash].scope_table_name, name) == 0) {
                    return hash;
                }
            }
            sector++;
        }
        sector = 0;
        region++;
    }
    return -1;
}



int init_scope_table_system()
{
    // Initialize all scope tables
    memset(&universal_scope, 0, sizeof(struct scope_table));

    memset(&global_param_scope, 0, sizeof(struct scope_table));
    memset(&global_scope, 0, sizeof(struct scope_table));
    memset(&global_block_scope, 0, sizeof(struct scope_table));

    memset(&local_param_scope, 0, sizeof(struct scope_table));
    memset(&local_scope, 0, sizeof(struct scope_table));
    memset(&local_block_scope, 0, sizeof(struct scope_table));
    
    // Set initial flags
    for (int i = 0; i < scope_table_regions; i++)
    {
        universal_scope.region_flags[i] = scope_flag_empty;

        global_param_scope.region_flags[i] = scope_flag_empty;
        global_scope.region_flags[i] = scope_flag_empty;
        global_block_scope.region_flags[i] = scope_flag_empty;  // Added
        
        local_param_scope.region_flags[i] = scope_flag_empty;
        local_scope.region_flags[i] = scope_flag_empty;
        local_block_scope.region_flags[i] = scope_flag_empty;   // Added
    }
    return 1;
}
