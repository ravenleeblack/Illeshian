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


// Modify main() to use the new dependency system
int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
        return 1;
    }

    int result = 0;
    char **filenames = malloc(argc * sizeof(char*));
    if (!filenames) {
        fprintf(stderr, "Error: Unable to allocate memory for filenames\n");
        return 1;
    }
    int file_count = 0;

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
                fprintf(stderr, "Failed to open scope_table.txt: %s\n", strerror(errno));
                cleanup_scope_table_system();
                free(filenames);
                return 1;
            }
        }
        else if (argv[i][0] != '-') {
            filenames[file_count++] = argv[i];
        }
    }

    // Initialize temp files if we're using NASM output
    if (nasm_flag) {
        clear_temp_files();
    }

    for (int i = 0; i < file_count; i++) {
        // Open input file
        seed_in = fopen(filenames[i], "r");
        if (seed_in == NULL) {
            fprintf(stderr, "Error: Unable to open input file %s: %s\n", filenames[i], strerror(errno));
            free(filenames);
            return 1;
        }

        if (nasm_flag) {
            clear_temp_files();
        }

        fprintf(stderr, "Processing input file: %s\n", filenames[i]);
        if (debug_flag) {
            fprintf(stderr, "Debug: Opened input file %s\n", filenames[i]);
        }

        result = begin_prog();

        fclose(seed_in);
        if (nasm_flag) {
            char output_filename[256];
            strncpy(output_filename, filenames[i], sizeof(output_filename) - 5);
            char *dot = strrchr(output_filename, '.');
            if (dot) *dot = '\0';
            strncat(output_filename, ".asm", sizeof(output_filename) - strlen(output_filename) - 1);

            write_nasm_sections(output_filename);
        }

        if (debug_flag) {
            fprintf(stderr, "Debug: Closed input file %s\n", filenames[i]);
        }
    }

    // Finalize NASM output
    if (nasm_flag) {
        finalize_nasm_output(nasm_out);
        if (debug_flag) {
            fprintf(stderr, "Debug: Finalized NASM output\n");
        }
    }

    if (scope_table_flag && scope_table_out) {
        print_all_scope_tables(scope_table_out);
        fclose(scope_table_out);
        if (debug_flag) {
            fprintf(stderr, "Debug: Printed all scope tables\n");
        }
    }

    cleanup_scope_table_system();
    free(filenames);

    fprintf(stderr, "Processing completed successfully\n");

    return result;
}

void clear_temp_files() {
    // List of temporary files to clear
    const char* temp_files[] = {
        "temp_data.asm",
        "temp_bss.asm",
        "temp_text.asm"
    };
    size_t num_temp_files = sizeof(temp_files) / sizeof(temp_files[0]);

    for (size_t i = 0; i < num_temp_files; i++) {
        if (remove(temp_files[i]) == 0) {
            fprintf(stderr, "Debug: Removed temporary file %s\n", temp_files[i]);
        } else {
            fprintf(stderr, "Warning: Failed to remove temporary file %s: %s\n", temp_files[i], strerror(errno));
        }
    }
}

// Function to write NASM sections to the final output file
void write_nasm_sections(const char* output_filename)
{
    FILE* output = fopen(output_filename, "w");
    if (!output) {
        fprintf(stderr, "Error: Unable to open output file %s: %s\n", output_filename, strerror(errno));
        return;
    }

    const char* sections[] = {"temp_data.asm", "temp_bss.asm", "temp_text.asm"};
    for (size_t i = 0; i < sizeof(sections) / sizeof(sections[0]); i++) {
        FILE* section = fopen(sections[i], "r");
        if (section) {
            char buffer[256];
            while (fgets(buffer, sizeof(buffer), section)) {
                fputs(buffer, output);
            }
            fclose(section);
        } else {
            fprintf(stderr, "Warning: Failed to open section file %s: %s\n", sections[i], strerror(errno));
        }
    }

    fclose(output);
}
