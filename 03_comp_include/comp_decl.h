//============================================================================================================================
// HEADER DATA TOOLS
struct scope_table_entry *external_data_tool(void);
struct scope_table_entry *internal_data_tool(void);

struct scope_table_entry *list_data_tool(void);
struct scope_table_entry *log_data_tool(void);
struct scope_table_entry *proto_data_tool(void);

//============================================================================================================================
// SOURCE DATA TOOLS
struct scope_table_entry *manager_data_tool(void);
struct scope_table_entry *manager_arg_param(void);
struct scope_table_entry* parse_manager_call_args(void);
struct manager_config* get_current_manager_config();
void reset_manager_config();

struct scope_table_entry *global_compound(void);

struct scope_table_entry *function_data_tool(void);
struct scope_table_entry *function_arg_param(void);
struct scope_table_entry* parse_function_call_args(void);
struct scope_table_entry *local_compound(void);

struct scope_table_entry *call_data_tool(void);
struct scope_table_entry *pass_arg_data_tool(void);
struct scope_table_entry *yield_data_tool(void);

struct scope_table_entry *block_compound(void);



struct scope_table_entry *hold_data_tool(void);
struct scope_table_entry *assign_data_tool(void);
struct scope_table_entry *convert_data_tool(void);
struct scope_table_entry *pare_data_tool(void);
struct scope_table_entry *retrieve_data_tool(void);
struct scope_table_entry *strand_data_tool(void);
struct scope_table_entry *table_data_tool(void);
struct scope_table_entry *tripare_data_tool(void);

struct scope_table_entry *check_data_tool(void);
struct scope_table_entry *loop_data_tool(void);
struct scope_table_entry *set_loop_data_tool(void);

struct scope_table_entry *compare_data_tool(void);
struct scope_table_entry *compare_compound(void);
struct scope_table_entry *compare_line_data_tool(void);
struct scope_table_entry *compare_otherwise_data_tool(void);
struct scope_table_entry *compare_line_end_compound(void);
struct scope_table_entry *compare_cycle_data_tool(void);

struct scope_table_entry* cycle_data_tool(void);
struct scope_table_entry* step_end_compound(void);
struct scope_table_entry* sub_state_data_tool(void);
struct scope_table_entry* step_data_tool(void);
struct scope_table_entry* state_compound(void);
struct scope_table_entry* state_data_tool(void);


struct scope_table_entry *passage_data_tool(void);
struct scope_table_entry *port_hub_data_tool(void);
struct scope_table_entry *vine_data_tool(void);
//============================================================================================================================
//EXPRESSION PARSER
void set_express_state(express_state_machine state);
express_state_machine get_express_state(void);
struct scope_table_entry* parse_expressions(void);



// Manager and Function Parsing
struct scope_table_entry* parse_manager_args(void);
struct scope_table_entry* parse_manager_call(void);
struct scope_table_entry* parse_function_args(void);
struct scope_table_entry* parse_function_call(void);
struct scope_table_entry* parse_pass_arg(void);
struct scope_table_entry* parse_yield(void);

// Data Tool Parsing
struct scope_table_entry* parse_assign(void);
struct scope_table_entry* parse_pare(void);
struct scope_table_entry* parse_tripare(void);
struct scope_table_entry* parse_table(void);
struct scope_table_entry* parse_log(void);
struct scope_table_entry* parse_list(void);

// Control Flow Parsing
struct scope_table_entry* parse_check(void);
struct scope_table_entry* parse_loop(void);

struct scope_table_entry* parse_set_loop_init(void);
struct scope_table_entry* parse_set_loop_condition(void);
struct scope_table_entry* parse_set_loop_increment(void);


struct scope_table_entry* parse_compare(void);
struct scope_table_entry* parse_compare_line(void);
struct scope_table_entry* parse_compare_otherwise(void);
struct scope_table_entry* parse_compare_cycle(void);

// State Machine Parsing
struct scope_table_entry* parse_state(void);
struct scope_table_entry* parse_sub_state(void);
struct scope_table_entry* parse_step(void);
struct scope_table_entry* parse_end_state(void);
struct scope_table_entry* parse_state_cycle(void);

// Pointer and Memory Parsing
struct scope_table_entry* parse_ptr_arg(void);
struct scope_table_entry* parse_address(void);
struct scope_table_entry* parse_fetch(void);

// Expression Parsing
struct scope_table_entry* parse_expression_list(void);
struct scope_table_entry* parse_expression_condition(void);
struct scope_table_entry* parse_expression_expression(void);
struct scope_table_entry* parse_expression_statement(void);
struct scope_table_entry* parse_external_express(void);
struct scope_table_entry* parse_internal_express(void);

// Utility Parsing
struct scope_table_entry* parse_convert(void);
struct scope_table_entry* parse_retrieve(void);
struct scope_table_entry* parse_vine(void);
struct scope_table_entry* parse_passage(void);
struct scope_table_entry* parse_port_hub(void);
struct scope_table_entry* parse_strand(void);
struct scope_table_entry* parse_proto(void);




struct scope_table_entry* process_condition(const char* left, int operator, const char* right);
struct scope_table_entry* process_increment_decrement(const char* operand, int operator);

// Add these declarations
struct scope_table_entry* insert_condition(const char* left, const char* operator, const char* right);
struct scope_table_entry* insert_unary_operation(const char* operand, const char* operator);




//============================================================================================================================
//TYPE CONVERSION
int parse_type(void);
int get_address(void);
int fetch_value(void);
int convert_to_ptr(int prev_type);
int convert_to_type(int prev_type);




//============================================================================================================================




//============================================================================================================================


//============================================================================================================================
//MATCH FUNCTIONS

void ident(int t, char *expected);
void increment(int t, char *expected);
void decrement(int t, char *expected);

// File Management Directives
void use(int token, char *expected);
void replace(int token, char *expected);
void link(int token, char *expected);
void out(int token, char *expected);
void transfer(int token, char *expected);
void type_check(int token, char *expected);
void collect(int token, char *expected);

// Core Language Types
void hollow(int token, char *expected);
void num(int token, char *expected);
void mark(int token, char *expected);
void strand(int token, char *expected);
void deci(int token, char *expected);
void decii(int token, char *expected);
void deciv(int token, char *expected);
void decviii(int token, char *expected);

// Size Types
void size(int token, char *expected);
void length(int token, char *expected);

// Unsigned Size-Specific Types
void zone(int t, char *expected);
void aisle(int t, char *expected);
void bay(int t, char *expected);
void den(int t, char *expected);

// Signed Size-Specific Types
void zones(int t, char *expected);
void aisles(int t, char *expected);
void bays(int t, char *expected);
void dens(int t, char *expected);

// Scope Functions
void universal_scoper(int token, char *expected);
void file_scoper(int token, char *expected);
void global_scoper(int token, char *expected);
void global_param_scoper(int token, char *expected);
void global_block_scoper(int token, char *expected);
void local_scoper(int token, char *expected);
void local_param_scoper(int token, char *expected);
void local_block_scoper(int token, char *expected);

// Data Tools
void hold(int token, char *expected);
void assign(int token, char *expected);
void list(int token, char *expected);
void match_log(int token, char *expected);
void table(int token, char *expected);
void pare(int token, char *expected);
void tripare(int token, char *expected);

// Control Flow
void check(int token, char *expected);
void elser(int token, char *expected);
void loop(int token, char *expected);
void set_loop(int token, char *expected);
void compare(int token, char *expected);
void line(int token, char *expected);
void otherwise(int token, char *expected);

// Function System
void manager(int token, char *expected);
void function(int token, char *expected);
void loop_func(int token, char *expected);
void call(int token, char *expected);
void yield(int token, const char *expected);
void pass_arg(int token, const char *expected);

// Operators
void logic_or(int token, char *expected);
void logic_and(int token, char *expected);
void logic_nor(int token, char *expected);
void logic_xor(int token, char *expected);

// Arithmetic Operators
void arith(int token, char *expected);
void addition(int token, char *expected);
void subtraction(int token, char *expected);
void divide(int token, char *expected);
void multi(int token, char *expected);

// Comparison Operators
void less_equal(int token, char *expected);
void great_equal(int token, char *expected);
void less_then(int token, char *expected);
void great_then(int token, char *expected);
void equal(int token, char *expected);
void not_equal(int token, char *expected);

// Literals
void num_literal(int token, int expected);
void strand_literal(int token, char *expected);
void mark_literal(int token, int expected);
void deci_literal(int token, int expected);
void decii_literal(int token, int expected);
void true_literal(int token, int expected);
void false_literal(int token, int expected);

// Special Characters
void colon(int token, char *expected);
void ender(int token, const char *expected);
void period(int token, char *expected);
void comma(int token, char *expected);
void semicolon(int token, char *expected);
void lparen(int token, char *expected);
void rparen(int token, char *expected);
void lbrace(int token, const char *expected);
void rbrace(int token, const char *expected);
void lbracket(int token, char *expected);
void rbracket(int token, char *expected);
void larrow(int token, char *expected);
void rarrow(int token, char *expected);

// Additional Types
void long_num(int token, char *expected);

// State System
void state(int token, const char *expected);
void sub_state(int token, const char *expected);
void end_state(int token, const char *expected);
void step(int token, const char *expected);
void cycle(int token, const char *expected);
void next(int token, const char *expected);
void breaker(int t, const char *expected);

// Pointer Types
void hollow_ptr(int token, char *expected);
void num_ptr(int token, char *expected);
void mark_ptr(int token, const char *expected);
void deci_ptr(int token, char *expected);
void strand_ptr(int token, const char *expected);
void table_ptr(int token, char *expected);

// Special Purpose Pointers
void mana_ptr_(int token, char *expected);
void func_ptr_(int token, char *expected);
void log_ptr_(int token, char *expected);
void list_ptr_(int token, char *expected);

// Additional Functions
void address(int token, char *expected);
void fetch(int token, const char *expected);
void retrieve(int token, char *expected);
void convert(int token, const char *expected);
void port_hub(int token, const char *expected);

// Size-Specific Pointer Types
void zone_ptr(int token, char *expected);
void aisle_ptr(int token, char *expected);
void bay_ptr(int token, char *expected);
void den_ptr(int token, char *expected);
void zones_ptr(int token, char *expected);
void aisles_ptr(int token, char *expected);
void bays_ptr(int token, char *expected);
void dens_ptr(int token, char *expected);

// Modifiers and Additional Functions
void passage(int token, char *expected);
void assigner(int token, char *expected);
void internal(int token, char *expected);
void external(int token, char *expected);
void proto(int token, char *expected);
void vine(int token, char *expected);
void change_global(int token, char *expected);
void change_local(int token, char *expected);

// Use directive matching functions
void start_use(int t, char *expected);
void get_use(int t, char *expected);
void line_use(int t, char *expected); 
void end_use(int t, char *expected);

// Link directive matching functions
void start_link(int t, char *expected);
void get_link(int t, char *expected);
void line_link(int t, char *expected);
void end_link(int t, char *expected);

void at_sign(int t, char *expected);

void irp_ident(int t, char *expected);
void irp_line(int t, char *expected);
void irp_num_literal(int t, int expected);

void list_ident(int t, char *expected);

//============================================================================================================================
// SUPPORT FUNCTIONS


int get_match_num_flag(int expected);
int get_match_strand_flag(const char *expected);



//============================================================================================================================
// Code generation functions
int init_code_gen(const char* output_file);
void close_code_gen(void);
void generate_section_data(void);
void generate_section_bss(void);
void generate_section_text(void);
void generate_universal_scope(void);
void generate_universal_entry(struct scope_table_entry* entry);
void generate_manager_entry(struct scope_table_entry* entry);
void generate_manager_prologue(const char* name);
void generate_manager_epilogue(void);
void generate_log(struct scope_table_entry* entry);
void generate_list(struct scope_table_entry* entry);
void generate_function(struct scope_table_entry* entry);

// Code generation functions
void generate_file_scope(void);
void generate_manager_body(struct scope_table_entry* manager_entry);
void generate_global_entry(struct scope_table_entry* entry);
void generate_hold(struct scope_table_entry* entry);
void generate_assign(struct scope_table_entry* entry);

// Scope table functions
void insert_file_scope(const char* name, int tool_type, int data_type);
int insert_universal_scope(char* name, int tool_type, int data_type);







