#define text_length 60
#define MAX_FILES 250

// File handles for different stages
extern FILE* irp_in;       // Input .fm file
extern FILE* irp_out;      // Output from IRP (.p file for source files) and (.i for header files)

extern FILE* comp_in;      // input from irp (.p or .i files that need to be compiled)
extern FILE* comp_out;     // Output from compiler (.seed file)

extern FILE* seed_in;      // input from compiler (.seed file)
extern FILE* seed_out;     // Output from seedling (.mod file)


extern FILE* root_in;      // Final input (.mod file from seedling and other libraries)
extern FILE* root_out;     // Final output (.elm file)

struct token Token;		                         
char Text[text_length + 1];		                
char strand_buffer[text_length + 1];

// Processing flags
extern int irp_flag;       // IRP processing flag
extern int comp_flag;      // Compilation flag
extern int seed_flag;      // Assembly flag
extern int root_flag;      // Linking flag
extern int build_flag;    // Output verbose information
extern int debug_flag;     // Debug information
extern int mod_flag;
extern int output_tokens_flag;
extern int scope_table_flag;

// Core parsing variables
extern int comp_line_pos;  // Current comp_line_pos number
extern int putback_char;   // Character put back by scanner

// Configuration
extern file_manager_config* config;