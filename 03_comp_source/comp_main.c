#include "comp_def.h"  
#include "comp_data.h"   
#include "comp_decl.h" 



// Scope context flags
bool in_universal_scope = false;         // Universal scope (headers)
bool in_file_scope = false;             // File scope (manager name)
bool in_manager_param_scope = false;     // Manager parameter scope
bool in_manager_body = false;           // Manager body scope
bool in_function_param_scope = false;    // Function parameter scope
bool in_function_body = false;          // Function body scope
bool in_tool_body = false;              // Tool/block scope


int is_main_manager = 0;

int comp_line_pos = 1;
int putback_char = '\n';

int debug_flag = 0;
int scope_table_flag = 0;
int treemap_flag = 0;
int output_flag = 0;
int assembly_flag = 0;
int preprocess_flag = 0;

int seedling_flag = 0;
int nasm_flag = 0;

int first_pass = 0;
int second_pass = 0;
int first_pass_flag = 0;
int second_pass_flag = 0;

FILE *comp_in = NULL;
FILE *comp_out = NULL;
FILE *scope_table_out = NULL;
FILE *treemap_out = NULL;

#define MAX_FILES 256
char *input_files[MAX_FILES];
int file_count = 0;


int main(int argc, char *argv[]) 
{
    int result = 0;
    
    init_scope_table_system();

    char *header_files[MAX_FILES];  // Array for .i files
    char *source_files[MAX_FILES];  // Array for .p files
    int header_count = 0;
    int source_count = 0;

    // Parse command line arguments and separate files by type
    for (int i = 1; i < argc; i++) 
    {
        if (argv[i][0] == '-') {
            // Handle flags
            if (strcmp(argv[i], "-o") == 0) {
                output_flag = 1;
            } 
            if (strcmp(argv[i], "-p") == 0) {
                preprocess_flag = 1;
            } 
            if (strcmp(argv[i], "-s") == 0) {
                seedling_flag = 1;
            } 
            if (strcmp(argv[i], "-n") == 0) {
                nasm_flag = 1;
            } 
            else if (strcmp(argv[i], "-t") == 0) {
                scope_table_flag = 1;
                scope_table_out = fopen("scope_table.txt", "w");
                if (!scope_table_out) {
                    printf("Failed to open scope_table.txt: %s\n", strerror(errno));
                    cleanup_scope_table_system();
                    return 1;
                }
            }
        }
        else {
            char *ext = strrchr(argv[i], '.');
            if (!ext) {
                printf("Error: File %s has no extension\n", argv[i]);
                continue;
            }
            
            // Sort files by extension
            if (strcmp(ext, ".i") == 0) {
                header_files[header_count++] = argv[i];
            }
            else if (strcmp(ext, ".p") == 0) {
                source_files[source_count++] = argv[i];
            }
            else {
                printf("Error: File %s must have .p or .i extension\n", argv[i]);
                continue;
            }
        }
    }

    // Process header files first
    for (int i = 0; i < header_count; i++) {
        comp_in = fopen(header_files[i], "r");
        if (!comp_in) {
            printf("Failed to open %s: %s\n", header_files[i], strerror(errno));
            continue;
        }
        result = begin_prog();
        fclose(comp_in);
        comp_in = NULL;

        if (result != 0) {
            printf("Error processing header %s\n", header_files[i]);
            break;
        }
    }

    // Process source files
    if (result == 0) {  // Only if headers processed successfully
        // Process main.p first if it exists
        for (int i = 0; i < source_count; i++) {
            char *filename = strrchr(source_files[i], '/');  // Handle path separators
            if (filename == NULL) {
                filename = source_files[i];
            } else {
                filename++; // Skip the '/'
            }
            
            if (strcmp(filename, "main.p") == 0) {
                comp_in = fopen(source_files[i], "r");
                if (!comp_in) {
                    printf("Failed to open %s: %s\n", source_files[i], strerror(errno));
                    continue;
                }
                result = begin_prog();
                fclose(comp_in);
                comp_in = NULL;

                if (result != 0) {
                    printf("Error processing main source %s\n", source_files[i]);
                    break;
                }
                
                // Remove main.p from the list by shifting remaining files
                for (int j = i; j < source_count - 1; j++) {
                    source_files[j] = source_files[j + 1];
                }
                source_count--;
                break;
            }
        }

        // Then process remaining source files
        for (int i = 0; i < source_count; i++) {
            comp_in = fopen(source_files[i], "r");
            if (!comp_in) {
                printf("Failed to open %s: %s\n", source_files[i], strerror(errno));
                continue;
            }
            result = begin_prog();
            fclose(comp_in);
            comp_in = NULL;

            if (result != 0) {
                printf("Error processing source %s\n", source_files[i]);
                break;
            }
        }

        if(seedling_flag == 1)   //still working on getting these right 
        {
            seed_out = fopen("seed.fm", "a");
            if (!seed_out) {
            printf("Failed to open %s: %s\n", "seed.fm", strerror(errno));
                    
            }
        }
        if(nasm_flag == 1)    //still working on getting these right 
        {
            nasm_out = fopen("seed.fm", "a");
            if (!nasm_out) {
            printf("Failed to open %s: %s\n", "seed.fm", strerror(errno));
                    
            }
        }
    }

    // Safe cleanup
    if (comp_out) fclose(comp_out);
    if (scope_table_out) fclose(scope_table_out);
    if (seedling_flag) fclose(seed_out);
    if (nasm_flag) fclose(nasm_out);

    cleanup_scope_table_system();
    return result;
}

