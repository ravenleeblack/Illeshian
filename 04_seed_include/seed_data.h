#define text_length 60
#define MAX_FILES 250
#define MAX_EXTERNS 64



FILE * seed_in;                                  
FILE * seed_out;                                 
FILE* nasm_out;
FILE* root_out;

FILE* temp_data;
FILE* temp_bss;
FILE* temp_text;
FILE* temp_rodata;

struct token Token;		                         
char Text[text_length + 1];		                
char strand_buffer[text_length + 1];


// Command-comp_line_pos flags

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


int is_main_entry;

int universal_id;
int global_id;
int local_id;
int global_block_id;
int local_block_id;

int entry_index;

char dest[64];
char src[64];


 extern int declare_type;

