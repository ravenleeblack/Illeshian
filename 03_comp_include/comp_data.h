
// File handles
FILE *irp_in;                                   // The source file input
FILE *irp_out;                                  // The out.s file output
FILE *comp_in;                                  // The source file input
FILE *comp_out;                                 // The out.s file output
FILE *symbol_in;                                // Input source file
FILE *symbol_out;                               // Output source file
FILE *scope_table_out;
FILE *treemap_out;

FILE* nasm_out;
FILE* seed_out;

// Buffers and text storage
char Text[text_length + 1];                     // Last identifier scanned
char strand_buffer[text_length + 1];

// Core parsing variables
int comp_line_pos;                                       // Current comp_line_pos number
int putback_char;                               // Character put back by scanner


int first_pass;
int second_pass;
int first_pass_flag;
int second_pass_flag;

struct token Token;                             // Last token scanned

// Command-comp_line_pos and output flags
int run_flag_present;
int parse_flag_present;
int traverse_flag;                              // allow the dump of the traverse tree

int output_flag;                              // allow output of match functions
int scope_table_flag;                               // allow output to symtab.out
int treemap_flag;
int debug_flag;
int assembly_flag;
int preprocess_flag;

char current_expected_manager[256];
int is_main_manager;


// Function declarations
void error_handler(int error_code);

struct scope_table_entry * process_use_directive(void);
struct scope_table_entry *process_link_files(void);

int scan(struct token *t);
void reject_token(struct token *Token);
int chrpos(char *s, int c);
void set_putback(int c);
void return_char(int c);

extern int current_file_type;

// Error handling function prototypes
void error_handler(int error_code);
void error(const char *message);
void errors(const char *message, const char *s);
void errorc(const char *message, int c);


extern bool in_universal_scope;  // True when processing headers/universal declarations
extern bool in_file_scope;
extern bool in_manager_param_scope;
extern bool in_manager_body;    // True when inside a function body
extern bool in_function_param_scope;
extern bool in_function_body;    // True when inside a function body
extern bool in_tool_body;   