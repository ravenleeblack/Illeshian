#include "ill_defs.h"  
#include "ill_data.h"   
#include "ill_decl.h" 

void process_rootling(const char* source_file) 
{
    char command[256];
    char base_name[256];
    char mod_file[256];
    char exe_file[256];
    
    if (build_flag) {
        printf("Calling rootling linker\n");
    }

    // Get base name without extension
    strncpy(base_name, source_file, sizeof(base_name)-1);
    char* dot = strrchr(base_name, '.');
    if (dot) *dot = '\0';
    
    // Build filenames for .mod and output executable
    snprintf(mod_file, sizeof(mod_file), "%s.mod", base_name);
    snprintf(exe_file, sizeof(exe_file), "%s.elm", base_name);  // .elm is executable format
    
    // Build linker command
    snprintf(command, sizeof(command), "./bin/root -o %s %s", 
             exe_file, mod_file);
    
    // Execute linker
    int result = system(command);
    if (result != 0) {
        error("Linking failed");
    }
}