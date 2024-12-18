#include "ill_defs.h"  
#include "ill_data.h"   
#include "ill_decl.h" 

void process_seedling(const char* source_file) 
{
    char command[256];
    char seed_file[256];
    char mod_file[256];
    
    if (build_flag) {
        printf("Calling seedling assembler\n");
    }

    // Remove .fm extension and add .seed/.mod
    strncpy(seed_file, source_file, sizeof(seed_file)-1);
    char* dot = strrchr(seed_file, '.');
    if (dot) *dot = '\0';
    
    snprintf(mod_file, sizeof(mod_file), "%s.mod", seed_file);
    snprintf(seed_file, sizeof(seed_file), "%s.seed", seed_file);
    
    // Build command with proper input/output files
    snprintf(command, sizeof(command), "./bin/seed %s%s %s", 
             scope_table_flag ? "-t " : "",  // Add scope table flag if set
             seed_file, mod_file);
    
    int result = system(command);
    if (result != 0) {
        error("Assembly failed");
    }
}