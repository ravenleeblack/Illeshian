#define text_length 60
#define MAX_FILES 250
#define MAX_EXTERNS 64

FILE * seed_in;                                  
FILE * seed_out;                                 
FILE* nasm_out;
FILE* root_out;
FILE* output;
FILE* temp_data;
FILE* temp_bss;
FILE* temp_text;
FILE* temp_rodata;
FILE* scope_table_out;

struct token Token;		                         
char Text[text_length + 1];		                
char strand_buffer[text_length + 1];

// Core parsing variables
int comp_line_pos;                                       // Current comp_line_pos number
int putback_char;                               // Character put back by scanner


int run_flag_present;
int parse_flag_present;
int traverse_flag;                              // allow the dump of the traverse tree

int output_flag;                              // allow output of match functions
int scope_table_flag;                               // allow output to symtab.out
int treemap_flag;
int debug_flag;
int assembly_flag;                               

int nasm_flag;
int rootling_flag;


int first_pass;
int second_pass;
int first_pass_flag;
int second_pass_flag;


int is_entry_point;
int is_main_entry;


int universal_id;
int global_id;
int local_id;
int global_block_id;
int local_block_id;


char dest[64];
char src[64];

char pass_buffer[64]; // Shared buffer for all pass_arg functions
char reg_buffer[32]; // Shared buffer for all register retrieval functions
char num_str[256]; // Buffer to hold the string representation of the number
char literal_buffer[256]; // Buffer to hold the literal value
char file_buffer[64]; // Buffer to hold the file name
char declare_buffer[64]; // Buffer to hold the file name
char assign_buffer[64]; // Buffer to hold the file name

char ptr_buffer[64]; // Shared buffer for all pass_arg functions
char address_buffer[64]; // Shared buffer for all pass_arg functions
char fetch_buffer[64]; // Shared buffer for all pass_arg functions

char ident_buffer[64];

int byte_size_buffer[64]; // Buffer to hold the file name

char global_to_local_buffer[64]; // Buffer to hold the file name
char global_to_global_block_buffer[64]; // Buffer to hold the file name
char local_to_local_block_buffer[64]; // Buffer to hold the file name


int declare_type;
int byte_size;

int assign_flag;
int global_architecture;
int current_architecture; // Global variable to track the current architecture.

char output_filename[256];

char manager_call_buffer[64];
char function_call_buffer[64];

