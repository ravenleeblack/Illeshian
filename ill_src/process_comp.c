#include "ill_defs.h"  
#include "ill_data.h"   
#include "ill_decl.h" 

void process_compiler(const char** source_files, int num_files) 
{
    char command[1024];
    
    // Start building compiler command
    snprintf(command, sizeof(command), "./bin/comp");

    // Add compiler flags
    if (output_tokens_flag)  strcat(command, " -o");
    if (scope_table_flag)    strcat(command, " -t");

    // Add all input files (both .p and .i)
    for (int i = 0; i < num_files; i++) {
        strcat(command, " ");
        strcat(command, source_files[i]);
    }
    
    // Execute compiler without extra debug output
    int result = system(command);
}