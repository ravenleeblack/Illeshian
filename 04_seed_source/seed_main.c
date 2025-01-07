#include "seed_defs.h"  
#include "seed_data.h"   
#include "seed_decl.h" 
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

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

char output_filename[256];

// Flags to track if the section header has been printed
int data_header_printed = 0;
int bss_header_printed = 0;
int text_header_printed = 0;

void reset_header_flags();


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

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
        return 1;
    }

    int result = 0;

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

        fclose(seed_in); // We are done parsing the file, so close it
        close_temp_files();      //close the temp folders we shouldnt need to append anymore

        if (nasm_flag) {
            // Generate output filename based on the current source file
            strncpy(output_filename, file_list->files[i], sizeof(output_filename) - 5);
            char* dot = strrchr(output_filename, '.');
            if (dot) *dot = '\0';
            strncat(output_filename, ".asm", sizeof(output_filename) - strlen(output_filename) - 1);

            // Write NASM sections to the output file
            write_nasm_sections(output_filename);

            // Reset state for the next file
            reset_state();
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
        if (section)
        {
            char buffer[256];

            while (fgets(buffer, sizeof(buffer), section)) 
            {
                fputs(buffer, output);
            }
            fclose(section);
        } 
        else 
        {
            fprintf(stderr, "Warning: Failed to open section file %s: %s\n", sections[i], strerror(errno));
        }
    }

    fclose(output);
}

void reset_state() {
    data_header_printed = 0;
    bss_header_printed = 0;
    text_header_printed = 0;
}

void open_temp_files()
{
    temp_data = fopen("temp_data.asm", "w");
    if (!temp_data) {
        fprintf(stderr, "Error: Unable to open temp_data.asm\n");
        return;
    }
    output_assign_section_header();

    temp_bss = fopen("temp_bss.asm", "w");
    if (!temp_bss) {
        fprintf(stderr, "Error: Unable to open temp_bss.asm\n");
        return;
    }
    output_declare_section_header();

    temp_text = fopen("temp_text.asm", "w");
    if (!temp_text) {
        fprintf(stderr, "Error: Unable to open temp_text.asm\n");
         return;
    }
    output_code_section_header();
}

void close_temp_files()
{
    fclose(temp_data);
    fclose(temp_bss);
    fclose(temp_text);
}