#include "ill_defs.h"  
#include "ill_data.h"   
#include "ill_decl.h" 

void process_irp(const char* source_file) 
{
    char command[256];
    char base_name[256];
    
    if (build_flag) {
        printf("Calling IRP processor\n");
    }

    // Get base name without extension
    strncpy(base_name, source_file, sizeof(base_name)-1);
    char* dot = strrchr(base_name, '.');
    if (dot) *dot = '\0';
    
    // Build command with source file
    snprintf(command, sizeof(command), "./bin/irp %s", source_file);
    
    // Execute IRP program
    int result = system(command);
    if (result != 0) {
        errors("IRP processing failed", source_file);
    }
}