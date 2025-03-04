#include "seed_defs.h"  
#include "seed_data.h"   
#include "seed_decl.h" 

void initialize()
{

    comp_line_pos = 0;
    putback_char = '\n';

    debug_flag = 0;
    scope_table_flag = 0;
    treemap_flag = 0;
    output_flag = 0;
    assembly_flag = 0;

    nasm_flag = 0;
    rootling_flag = 0;

    first_pass = 0;
    second_pass = 0;
    first_pass_flag = 0;
    second_pass_flag = 0;

    is_main_entry = 0;

    global_id = 0;
    local_id = 0;
    global_block_id = 0;
    local_block_id = 0;

    seed_in = NULL;
    seed_out = NULL;
    scope_table_out = NULL;
    nasm_out = NULL;
    root_out = NULL;
    output = NULL;
}


typedef struct
{
    char** files;
    int count;
    int capacity;
} source_file_list;

source_file_list* create_file_list(int capacity) 
{
    source_file_list* list = malloc(sizeof(source_file_list));
    if (!list) return NULL;
    list->files = malloc(capacity * sizeof(char*));
    if (!list->files) {
        free(list);
        return NULL;
    }
    list->count = 0;
    list->capacity = capacity;
    return list;
}

void add_file_to_list(source_file_list* list, const char* filename)
{
    if (list->count >= list->capacity) {
        list->capacity *= 2;
        list->files = realloc(list->files, list->capacity * sizeof(char*));
        if (!list->files) {
            fprintf(stderr, "Error: Unable to allocate memory for file list\n");
            exit(1);
        }
    }
    list->files[list->count++] = strdup(filename);
}

void free_file_list(source_file_list* list) {
    for (int i = 0; i < list->count; i++) {
        free(list->files[i]);
    }
    free(list->files);
    free(list);
}

int main(int argc, char *argv[]) 
{
    if (argc < 2) 
    {
        fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
        return 1;
    }

    int result = 0;
    initialize();

    // Create the file list
    source_file_list* file_list = create_file_list(10); // Initial capacity of 10
    if (!file_list) {
        fprintf(stderr, "Error: Unable to create file list\n");
        return 1;
    }

    // Initialize scope table system first
    cleanup_scope_table_system();
    init_scope_table_system();

    // Parse command line args and collect files
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-o") == 0) {
            output_flag = 1;
        } else if (strcmp(argv[i], "-d") == 0) {
            debug_flag = 1;
        } else if (strcmp(argv[i], "-n") == 0) {
            nasm_flag = 1;
        } else if (strcmp(argv[i], "-t") == 0) {
            scope_table_flag = 1;
            scope_table_out = fopen("scope_table.txt", "w");
            if (!scope_table_out) {
                fprintf(stderr, "Failed to open scope_table.txt: %s\n", strerror(errno));
                free_file_list(file_list);
                return 1;
            }
        } else if (argv[i][0] != '-') {
            add_file_to_list(file_list, argv[i]);
        }
    }

    // Process each file in the list
    for (int i = 0; i < file_list->count; i++) {
        seed_in = fopen(file_list->files[i], "r"); // Start parsing the source file
        if (!seed_in) {
            fprintf(stderr, "Error: Unable to open input file %s: %s\n", file_list->files[i], strerror(errno));
            free_file_list(file_list);
            return 1;
        }

        open_temp_files();       //open the temp files so we can write nasm output to them

        result = begin_prog(); // Start parsing the seedling source code

        close_temp_files();      //close the temp folders we shouldnt need to append anymore. We also do after write_nasm_sections so that our sections get put int right.
        fclose(seed_in); // We are done parsing the file, so close it

        if (nasm_flag) {
            // Generate output filename based on the current source file
            strncpy(output_filename, file_list->files[i], sizeof(output_filename) - 5);
            char* dot = strrchr(output_filename, '.');
            if (dot) *dot = '\0';
            strncat(output_filename, ".asm", sizeof(output_filename) - strlen(output_filename) - 1);

            // Write NASM sections to the output file
            write_nasm_sections(output_filename);
        }
    }

    if (scope_table_flag && scope_table_out) {
        print_all_scope_tables(scope_table_out); // Print out the scope table to verify identifiers
        fclose(scope_table_out);                // Close the scope table output file
    }

    cleanup_scope_table_system();
    free_file_list(file_list); // Free memory allocated for the file list
    return result;
}


// Function to write NASM sections to the final output file
void write_nasm_sections(const char* output_filename)
{
    FILE* output = fopen(output_filename, "a");
    if (!output) {
        fprintf(stderr, "Error: Unable to open output file %s: %s\n", output_filename, strerror(errno));
        return;
    }

    const char* sections[] = {"temp_data.asm", "temp_bss.asm", "temp_text.asm"};
    for (size_t i = 0; i < sizeof(sections) / sizeof(sections[0]); i++) {
        FILE* section = fopen(sections[i], "r");

        if (section) {
            fseek(section, 0, SEEK_END);  // Move the file pointer to the end
            long file_size = ftell(section); // Get the file size

            if (file_size == 0) { // Check if the file is empty
                fclose(section);
                continue; // Skip this section if the file is empty
            }

            fseek(section, 0, SEEK_SET); // Reset file pointer to the beginning

            char buffer[256];

            // Check for data section and output header if the counter is greater than 0
            if (strcmp(sections[i], "temp_data.asm") == 0) {
                fprintf(output, "section .data\n");

                // Read and write the contents of the section to the output file
                while (fgets(buffer, sizeof(buffer), section)) {
                    fputs(buffer, output);
                }
                fclose(section);
            }

            // Check for BSS section and output header if the counter is greater than 0
            if (strcmp(sections[i], "temp_bss.asm") == 0) {
                fprintf(output, "\nsection .bss\n");

                // Read and write the contents of the section to the output file
                while (fgets(buffer, sizeof(buffer), section)) {
                    fputs(buffer, output);
                }
                fclose(section);
            }

            // Check for text section and output header if the counter is greater than 0
            if (strcmp(sections[i], "temp_text.asm") == 0) {
                fprintf(output, "\nsection .text\n");

                // Read and write the contents of the section to the output file
                while (fgets(buffer, sizeof(buffer), section)) {
                    fputs(buffer, output);
                }
                fclose(section);
            }
        } else {
            fprintf(stderr, "Warning: Failed to open section file %s: %s\n", sections[i], strerror(errno));
        }
    }

    fclose(output);
}


void open_temp_files()
{
    temp_data = fopen("temp_data.asm", "w");
    if (!temp_data) {
        fprintf(stderr, "Error: Unable to open temp_data.asm\n");
        return;
    }

    temp_bss = fopen("temp_bss.asm", "w");
    if (!temp_bss) {
        fprintf(stderr, "Error: Unable to open temp_bss.asm\n");
        return;
    }

    temp_text = fopen("temp_text.asm", "w");
    if (!temp_text) {
        fprintf(stderr, "Error: Unable to open temp_text.asm\n");
        return;
    }
}


void close_temp_files()
{
    fclose(temp_data);
    fclose(temp_bss);
    fclose(temp_text);
}