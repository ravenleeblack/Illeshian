#include "seed_defs.h"  
#include "seed_data.h"   
#include "seed_decl.h" 

int comp_line_pos = 0;
int putback_char = '\n';

int debug_flag = 0;
int scope_table_flag = 0;
int treemap_flag = 0;
int output_flag = 0;
int assembly_flag = 0;

int nasm_flag = 0;
int rootling_flag = 0;

int first_pass = 0;
int second_pass = 0;
int first_pass_flag = 0;
int second_pass_flag = 0;

int is_main_entry = 0;

int global_id = 0;
int local_id = 0;
int global_block_id = 0;
int local_block_id = 0;

FILE* seed_in = NULL;
FILE* seed_out = NULL;
FILE* scope_table_out = NULL;
FILE* nasm_out = NULL;
FILE* root_out = NULL;

int entry_index = 0;
char dest[64] = {0};
char src[64] = {0};




static const char* current_filename = NULL;

const char* get_current_filename(void) {
    return current_filename;
}

void set_current_filename(const char* filename) {
    current_filename = filename;
}


// Add these declarations at the top
#define MAX_DEPENDENCIES 10

typedef struct {
    const char* filename;
    int processed;
    const char** dependencies;
    int dep_count;
} FileInfo;

// Add this function to initialize file dependencies
void init_file_info(FileInfo* info, const char* filename) {
    info->filename = filename;
    info->processed = 0;
    info->dependencies = malloc(sizeof(char*) * MAX_DEPENDENCIES);
    info->dep_count = 0;
}

// Add this function to set up dependencies
void setup_dependencies(FileInfo* files, int count) {
    for (int i = 0; i < count; i++) {
        if (strstr(files[i].filename, "main.seed")) {
            // Main depends on write and yield
            files[i].dependencies[files[i].dep_count++] = "write.seed";
            files[i].dependencies[files[i].dep_count++] = "yield.seed";
        }
        else if (strstr(files[i].filename, "write.seed")) {
            // Write has no dependencies
        }
        else if (strstr(files[i].filename, "yield.seed")) {
            // Yield has no dependencies
        }
    }
}

// Modify main() to use the new dependency system
int main(int argc, char *argv[]) {
    int result = 0;
    char *filename = NULL;
    int file_count = 0;
    FileInfo files[MAX_FILES];
    int overall_result = 0;

    // Initialize scope table system first
    cleanup_scope_table_system();
    init_scope_table_system();

    // Parse command line args and collect files
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-o") == 0) {
            output_flag = 1;
        }
        else if (strcmp(argv[i], "-d") == 0) {
            debug_flag = 1;
        }
        else if (strcmp(argv[i], "-n") == 0) {
            nasm_flag = 1;
        }
        else if (strcmp(argv[i], "-r") == 0) {
            rootling_flag = 1;
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
        else if (argv[i][0] != '-') {
            if (file_count >= MAX_FILES) {
                printf("Error: Too many input files\n");
                return 1;
            }
            init_file_info(&files[file_count], argv[i]);
            file_count++;
        }
    }

    // Set up dependencies
    setup_dependencies(files, file_count);

    // Initialize temp files if we're using NASM output
    if (nasm_flag) {
        clear_temp_files();
    }

    // Process files in dependency order
    int files_processed = 0;
    while (files_processed < file_count) {
        for (int i = 0; i < file_count; i++) {
            if (files[i].processed) continue;

            // Check if all dependencies are processed
            int can_process = 1;
            for (int j = 0; j < files[i].dep_count; j++) {
                int dep_processed = 0;
                for (int k = 0; k < file_count; k++) {
                    if (strcmp(files[k].filename, files[i].dependencies[j]) == 0) {
                        if (!files[k].processed) {
                            can_process = 0;
                            break;
                        }
                    }
                }
                if (!can_process) break;
            }

            if (!can_process) continue;
            
            // Process this file
            filename = (char*)files[i].filename;
            set_current_filename(filename);
            printf("Processing file: %s\n", filename);

            // Clear temp files before processing each new file
            if (nasm_flag) {
                clear_temp_files();
            }

            // Open input file
            seed_in = fopen(filename, "r");
            if (seed_in == NULL) {
                printf("Error: Unable to open input file %s: %s\n", filename, strerror(errno));
                continue;
            }

            if (nasm_flag) {
                char asmfile[256];
                strncpy(asmfile, filename, sizeof(asmfile) - 5);
                char *dot = strrchr(asmfile, '.');
                if (dot) *dot = '\0';
                strncat(asmfile, ".asm", sizeof(asmfile) - strlen(asmfile) - 1);
                
                nasm_out = fopen(asmfile, "w");
                if (nasm_out == NULL) {
                    printf("Error: Unable to open ASM output file %s: %s\n", asmfile, strerror(errno));
                    fclose(seed_in);
                    continue;
                }
            }

            result = begin_prog();
            if (result != 0) {
                printf("Error processing file: %s\n", filename);
                overall_result = 1;
            }

            // Cleanup file handles
            if (seed_in) {
                fclose(seed_in);
                seed_in = NULL;
            }

            if (nasm_out) {
                if (nasm_flag) {
                    finalize_nasm_output(nasm_out);
                }
                fclose(nasm_out);
                nasm_out = NULL;
            }

            files[i].processed = 1;
            files_processed++;
        }
    }

    // Cleanup
    if (scope_table_flag && scope_table_out) {
        print_all_scope_tables(scope_table_out);
        fclose(scope_table_out);
    }

    if (nasm_flag) {
        clear_temp_files();
    }

    // Free allocated memory
    for (int i = 0; i < file_count; i++) {
        free((void*)files[i].dependencies);
    }

    cleanup_scope_table_system();
    return overall_result;
}