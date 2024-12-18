#include "ill_defs.h"  
#include "ill_data.h"   
#include "ill_decl.h" 

// Flags for different processing stages
int irp_flag = 0;
int comp_flag = 0;
int seed_flag = 0;
int root_flag = 0;
int build_flag = 0;
int debug_flag = 0;
int mod_flag = 0;
int output_tokens_flag = 0;
int scope_table_flag = 0;

const char **input_files = NULL;
int num_files = 0;

int main(int argc, char *argv[])
{
    // Allocate space for input files
    input_files = malloc(sizeof(const char*) * argc);
    if (!input_files) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Parse arguments
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            // Handle flags
            if (strcmp(argv[i], "-p") == 0)
                irp_flag = 1;
            else if (strcmp(argv[i], "-c") == 0)
                comp_flag = 1;
            else if (strcmp(argv[i], "-s") == 0)
                seed_flag = 1;
            else if (strcmp(argv[i], "-mod") == 0)
                mod_flag = 1;
            else if (strcmp(argv[i], "-root") == 0)
                root_flag = 1;
            else if (strcmp(argv[i], "-b") == 0)
                build_flag = 1;
            else if (strcmp(argv[i], "-d") == 0)
                debug_flag = 1;
            else if (strcmp(argv[i], "-o") == 0)
                output_tokens_flag = 1;
            else if (strcmp(argv[i], "-t") == 0)
                scope_table_flag = 1;
        } else {
            // Store input file
            input_files[num_files++] = argv[i];
        }
    }

    if (num_files == 0) {
        fprintf(stderr, "ill: no input files\n");
        fprintf(stderr, "usage: ill [-p] [-c] [-s] [-mod] [-root] [-b] [-d] files...\n");
        free(input_files);
        return 1;
    }

    // Process through stages based on flags
    if (comp_flag) {
        // Verify file extensions for compiler stage
        for (int i = 0; i < num_files; i++) {
            char *ext = strrchr(input_files[i], '.');
            if (!ext || (strcmp(ext, ".p") != 0 && strcmp(ext, ".i") != 0)) {
                fprintf(stderr, "ill: compiler expects .p or .i files\n");
                free(input_files);
                return 1;
            }
        }
        process_compiler(input_files, num_files);
    }

    free(input_files);
    return 0;
}