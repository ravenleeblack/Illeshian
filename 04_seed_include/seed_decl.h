#ifndef SEED_DECL_H
#define SEED_DECL_H


//============================================================================================================================
//matching functions for the parser and its output flag

void arch_08(int t, char *expected);
void universal_scoper(int t, char *expected);
void file_scoper(int t, char *expected);
void global_scoper(int t, char *expected);
void global_param_scoper(int t, char *expected);
void global_block_scoper(int t, char *expected);
void local_scoper(int t, char *expected);
void local_param_scoper(int t, char *expected);
void local_block_scoper(int t, char *expected);
void ident(int t, char *expected);
void use(int t, char *expected);
void replace(int t, char *expected);
void link(int t, char *expected);
void out(int t, char *expected);
void transfer(int t, char *expected);
void type_check(int t, char *expected);
void collect(int t, char *expected);
void hollow(int t, char *expected);
void num(int t, char *expected);
void mark(int t, char *expected);
void strand(int t, char *expected);
void deci(int t, char *expected);
void decii(int t, char *expected);
void deciv(int t, char *expected);
void decviii(int t, char *expected);
void size(int t, char *expected);
void length(int t, char *expected);
void hold(int t, char *expected);
void list(int t, char *expected);
void table(int t, char *expected);
void pare(int t, char *expected);
void tripare(int t, char *expected);
void check(int t, char *expected);
void elser(int t, char *expected);
void loop(int t, char *expected);
void set_loop(int t, char *expected);
void compare(int t, char *expected);
void line(int t, char *expected);
void otherwise(int t, char *expected);
void manager(int t, char *expected);
void function(int t, char *expected);
void loop_func(int t, char *expected);
void logic_or(int t, char *expected);
void logic_and(int t, char *expected);
void logic_nor(int t, char *expected);
void logic_xor(int t, char *expected);
void less_equal(int t, char *expected);
void great_equal(int t, char *expected);
void less_then(int t, char *expected);
void great_then(int t, char *expected);
void equal(int t, char *expected);
void not_equal(int t, char *expected);
void num_literal(int t, int expected);
void strand_literal(int t, char *expected);
void mark_literal(int t, int expected);
void deci_literal(int t, int expected);
void decii_literal(int t, int expected);

void hex_literal(int t, int expected, int arch);
void true_literal(int t, int expected);
void false_literal(int t, int expected);
void colon(int t, char *expected);
void ender(int t, const char *expected);
void period(int t, char *expected);
void comma(int t, char *expected);
void semicolon(int t, char *expected);
void lparen(int t, char *expected);
void rparen(int t, char *expected);
void lbrace(int t, char *expected);
void rbrace(int t, char *expected);
void lbracket(int t, char *expected);
void rbracket(int t, char *expected);
void larrow(int t, char *expected);
void rarrow(int t, char *expected);
void hollow_ptr(int t, char *expected);
void num_ptr(int t, char *expected);
void mark_ptr(int t, char *expected);
void deci_ptr(int t, char *expected);
void decii_ptr(int t, char *expected);
void strand_ptr(int t, char *expected);
void table_ptr(int t, char *expected);
void mana_ptr_(int t, char *expected);
void func_ptr_(int t, char *expected);
void log_ptr_(int t, char *expected);
void list_ptr_(int t, char *expected);
void address(int t, char *expected);
void fetch(int t, char *expected);
void retrieve(int t, char *expected);
void convert(int t, char *expected);
void increment(int t, char *expected);
void decrement(int t, char *expected);
void zone(int t, char *expected);
void aisle(int t, char *expected);
void bay(int t, char *expected);
void den(int t, char *expected);
void zones(int t, char *expected);
void aisles(int t, char *expected);
void bays(int t, char *expected);
void dens(int t, char *expected);
void zone_ptr(int t, char *expected);
void aisle_ptr(int t, char *expected);
void bay_ptr(int t, char *expected);
void den_ptr(int t, char *expected);
void zones_ptr(int t, char *expected);
void aisles_ptr(int t, char *expected);
void bays_ptr(int t, char *expected);
void dens_ptr(int t, char *expected);
void passage(int t, char *expected);
void assigner(int t, char *expected);
void internal(int t, char *expected);
void external(int t, char *expected);
void proto(int t, char *expected);
void vine(int t, char *expected);
void port_hub(int t, char *expected);
void rax(int t, char *expected);
void rbx(int t, char *expected);
void rcx(int t, char *expected);
void rdx(int t, char *expected);
void rsi(int t, char *expected);
void rdi(int t, char *expected);
void rbp(int t, char *expected);
void rsp(int t, char *expected);
void r8(int t, char *expected);
void r9(int t, char *expected);
void r10(int t, char *expected);
void r11(int t, char *expected);
void r12(int t, char *expected);
void r13(int t, char *expected);
void r14(int t, char *expected);
void r15(int t, char *expected);
void eax(int t, char *expected);
void ebx(int t, char *expected);
void ecx(int t, char *expected);
void edx(int t, char *expected);
void esi(int t, char *expected);
void edi(int t, char *expected);
void ebp(int t, char *expected);
void esp(int t, char *expected);
void r8d(int t, char *expected);
void r9d(int t, char *expected);
void r10d(int t, char *expected);
void r11d(int t, char *expected);
void r12d(int t, char *expected);
void r13d(int t, char *expected);
void r14d(int t, char *expected);
void r15d(int t, char *expected);
void ax(int t, char *expected);
void bx(int t, char *expected);
void cx(int t, char *expected);
void dx(int t, char *expected);
void si(int t, char *expected);
void di(int t, char *expected);
void bp(int t, char *expected);
void sp(int t, char *expected);
void r8w(int t, char *expected);
void r9w(int t, char *expected);
void r10w(int t, char *expected);
void r11w(int t, char *expected);
void r12w(int t, char *expected);
void r13w(int t, char *expected);
void r14w(int t, char *expected);
void r15w(int t, char *expected);
void al(int t, char *expected);
void bl(int t, char *expected);
void cl(int t, char *expected);
void dl(int t, char *expected);
void sil(int t, char *expected);
void dil(int t, char *expected);
void bpl(int t, char *expected);
void spl(int t, char *expected);
void r8b(int t, char *expected);
void r9b(int t, char *expected);
void r10b(int t, char *expected);
void r11b(int t, char *expected);
void r12b(int t, char *expected);
void r13b(int t, char *expected);
void r14b(int t, char *expected);
void r15b(int t, char *expected);
void push_radule(int t, char *expected);
void pop_radule(int t, char *expected);
void universal(int t, char *expected);
void global(int t, char *expected);
void local(int t, char *expected);
void global_block(int t, char *expected);
void local_block(int t, char *expected);
void global_param(int t, char *expected);
void local_param(int t, char *expected);
void call(int t, char *expected);
void yield(int t, const char *expected);
void pass_arg(int t, const char *expected);
void match_log(int t, char *expected);
void declare(int t, char *expected);
void assign(int t, char *expected);
void literal(int t, char *expected);
void code(int t, char *expected);
void end_section(int t, char *expected);
void pad_section(int t, char *expected);
void arch_16(int t, char *expected);
void arch_32(int t, char *expected);
void arch_64(int t, char *expected);
void origin(int t, char *expected);
void load(int t, char *expected);
void sign(int t, char *expected);
void entry(int t, char *expected);
void start_use(int t, char *expected);
void end_use(int t, char *expected);
void start_link(int t, char *expected);
void end_link(int t, char *expected);
void end_log(int t, char *expected);
void scope(int t, char *expected);
void end_scope(int t, char *expected);
void move_aisle(int t, char *expected);
void jump(int t, char *expected);
void set_flag(int t, char *expected);
void jump_neg(int t, char *expected);
void test(int t, char *expected);
void file_section(int t, char *expected);
void push_den(int t, char *expected);
void push_bay(int t, char *expected);
void push_aisle(int t, char *expected);
void push_zone(int t, char *expected);
void push_dens(int t, char *expected);
void push_bays(int t, char *expected);
void push_aisles(int t, char *expected);
void push_zones(int t, char *expected);
void pop_den(int t, char *expected);
void pop_bay(int t, char *expected);
void pop_aisle(int t, char *expected);
void pop_zone(int t, char *expected);
void pop_dens(int t, char *expected);
void pop_bays(int t, char *expected);
void pop_aisles(int t, char *expected);
void pop_zones(int t, char *expected);
void add_den(int t, char *expected);
void add_bay(int t, char *expected);
void add_aisle(int t, char *expected);
void add_zone(int t, char *expected);
void sub_den(int t, char *expected);
void sub_bay(int t, char *expected);
void sub_aisle(int t, char *expected);
void sub_zone(int t, char *expected);
void mul_den(int t, char *expected);
void mul_bay(int t, char *expected);
void mul_aisle(int t, char *expected);
void mul_zone(int t, char *expected);
void div_den(int t, char *expected);
void div_bay(int t, char *expected);
void div_aisle(int t, char *expected);
void div_zone(int t, char *expected);
void add_dens(int t, char *expected);
void add_bays(int t, char *expected);
void add_aisles(int t, char *expected);
void add_zones(int t, char *expected);
void sub_dens(int t, char *expected);
void sub_bays(int t, char *expected);
void sub_aisles(int t, char *expected);
void sub_zones(int t, char *expected);
void mul_dens(int t, char *expected);
void mul_bays(int t, char *expected);
void mul_aisles(int t, char *expected);
void mul_zones(int t, char *expected);
void div_dens(int t, char *expected);
void div_bays(int t, char *expected);
void div_aisles(int t, char *expected);
void div_zones(int t, char *expected);
void start_section(int t, char *expected);
void end(int t, char *expected);
void call_system(int t, char *expected);
void align_den(int t, char *expected);
void align_bay(int t, char *expected);
void align_aisle(int t, char *expected);
void align_zone(int t, char *expected);
void align_dens(int t, char *expected);
void align_bays(int t, char *expected);
void align_aisles(int t, char *expected);
void align_zones(int t, char *expected);
void inc_den(int t, char *expected);
void inc_bay(int t, char *expected);
void inc_aisle(int t, char *expected);
void inc_zone(int t, char *expected);
void inc_dens(int t, char *expected);
void inc_bays(int t, char *expected);
void inc_aisles(int t, char *expected);
void inc_zones(int t, char *expected);
void jump_zero(int t, char *expected);

void hex(int t, char *expected);
void oct(int t, char *expected);
void bin(int t, char *expected);

void num_value(int t, char *expected);
void hex_value(int t, char *expected);
void oct_value(int t, char *expected);
void bin_value(int t, char *expected);



//============================================================================================================================
//Begin the program
void initialize();
int begin_prog(void);
void write_nasm_sections(const char* output_filename);
void open_temp_files();
void close_temp_files();
void reset_state();

//============================================================================================================================
//These functions are in the seed_encode file but they go with these file handling functions so I keep them close in header
void output_declare_section_header();
void output_assign_section_header();
void output_code_section_header();
void output_literal_section_header();

//============================================================================================================================
//lexer functions
int scanhex(int *size);
int scanint(int c);

float scandeci(int c);
int scan(struct token *t);
void error(const char *message);
void reject_token(struct token *t);

//============================================================================================================================
//error handling functions that I dont really use yet when I should
void error_handler(int error_code);
void error(const char *message);
void errors(const char *message, const char *s);
void errorc(const char *message, int c);

//============================================================================================================================
//Process the scope label header
int process_universal_label(void);
void process_global_label(void);
void process_global_block_label(int parent_global_id);
void process_local_label(int parent_global_id);
void process_local_block_label(int parent_global_id);

void process_global_child_labels(int parent_global_id);
void process_local_child_labels(int parent_global_id);
void process_global_block_child_labels(int parent_global_id);

//============================================================================================================================
//Process the sections under the scope label header, so we process the body
void process_sections(enum scope_type current_scope);


int process_arch_section(enum scope_type current_scope);

void process_log_section(enum scope_type current_scope);
void process_declare_section(enum scope_type current_scope);
void process_assign_section(enum scope_type current_scope);
void process_literal_section(enum scope_type current_scope);
void process_code_section(enum scope_type current_scope);
void process_end_section(void);
void process_origin();
void process_pad_section();

void comp_den(int t, char *expected);
void comp_bay(int t, char *expected);
void comp_aisle(int t, char *expected);
void comp_zone(int t, char *expected);

//============================================================================================================================
//Process the move instructions from under the code section
void process_move_instruction(enum scope_type current_scope);

//============================================================================================================================
//Process the jump instructions from under the code section
void process_jump_instruction(enum scope_type current_scope);


//============================================================================================================================
//Process the push and pop instructions from under the code section
void process_push_instruction(enum scope_type current_scope);
void process_pop_instruction(enum scope_type current_scope);

//============================================================================================================================
//Process the relational instructions
void process_set_flag_instruction(enum scope_type current_scope);
void process_compare_instruction(enum scope_type current_scope);



//============================================================================================================================
//Process the function related instructions
void process_call_instruction(enum scope_type scope);
void process_pass_arg_instruction(enum scope_type current_scope);
void process_system_instruction(enum scope_type current_scope);

//============================================================================================================================
//Process the alignment function
void process_align_instruction(enum scope_type current_scope);

phrase_retrievel process_hex_instruction(enum scope_type current_scope, int current_architecture);

/*functions that process the instructions in the code sections*/
void process_compare_instruction(enum scope_type current_scope);
void process_set_flag_instruction(enum scope_type current_scope);
void process_jump_instruction(enum scope_type current_scope);
void process_jump_less_instruction(enum scope_type current_scope);
void process_jump_neg_instruction(enum scope_type current_scope);
void process_test_instruction(enum scope_type current_scope);
void process_file_section(enum scope_type current_scope);

void process_literal_section(enum scope_type current_scope);
void process_arith_instruction(enum scope_type current_scope);

void process_increment_instruction(enum scope_type current_scope);

//============================================================================================================================
int parse_type(enum scope_type current_scope);
int get_byte_size(int declare_type);



phrase_retrievel parse_pointer(enum scope_type current_scope);
phrase_retrievel parse_address(enum scope_type current_scope, int current_arch);
phrase_retrievel parse_fetch(enum scope_type current_scope);

/*functions that help process the instructions in the code sections*/
phrase_retrievel parse_num_literal();
phrase_retrievel parse_hex_literal(enum scope_type current_scope, int current_architecture);
phrase_retrievel parse_search_ident(enum scope_type current_scope);

phrase_retrievel parse_first_phrase(enum scope_type current_scope, int current_architecture);
phrase_retrievel parse_second_phrase(enum scope_type current_scope, int current_architecture);

//============================================================================================================================
//Process the functions that convert or translate seedling into nasm

void encode_destination_phrase(int byte_size, phrase_retrievel dest);
void encode_source_phrase(int byte_size, phrase_retrievel src);


//============================================================================================================================
//Process the functions that convert or translate seedling into nasm
void encode_universal_label(const char* label);
void encode_global_label(const char* label_name);
void encode_global_block_label(const char* label);
void encode_local_label(const char* label_name);
void encode_local_block_label(const char* label_name);

void encode_pass_arg_label();
void encode_extern_label(const char* label_name);


void encode_align_instruction(int architecture);
void encode_assign_hold_instruction(char *ident, int byte_size, int num_to_be_assigned);
void encode_assign_table_instruction(char *ident, int byte_size, int num_to_be_assigned);
void encode_arch_instruction(int architecture);
void encode_arith_instruction(const char* operation, phrase_retrievel dest, phrase_retrievel src);


void encode_declare_instruction(const char* ident, int byte_size, int type);

void encode_literal_with_num_section(char * hold_name, char *src, phrase_retrievel num_value);
void encode_literal_with_hex_section(char *hold_name, char *src, phrase_retrievel hex_value);

void encode_file_section(const char* label_name, const char* label_strand, int length);
void encode_register(const char* reg, char* nasm_reg);



void encode_call_manager_instruction(const char* label);
void encode_call_function_instruction(const char* label_two);




void encode_set_flag_instruction(phrase_retrievel dest, phrase_retrievel src);
void encode_test_instruction(phrase_retrievel dest, phrase_retrievel src);
void encode_system_instruction();
void encode_fetch_reference(const char* dest, const char* src);

/*functions that process the conversion to nasm ouput*/
void encode_push_instruction(int byte_size, phrase_retrievel src);
void encode_pop_instruction(int byte_size, phrase_retrievel src);

//void encode_move_instruction(int byte_size, phrase_retrievel dest, phrase_retrievel src);
void encode_move_dest_instruction(int byte_size, phrase_retrievel dest);
void encode_move_src_instruction(int byte_size, phrase_retrievel src);

void encode_jump_instruction(int jump_value, const char* operation);

void encode_compare_instruction(int byte_size,  phrase_retrievel dest,  phrase_retrievel src);
void encode_register_instruction(phrase_retrievel src);


//void encode_arith_instruction(const char* operation,phrase_retrievel dest, phrase_retrievel src);
void encode_arith_dest_instruction(const char *operation, phrase_retrievel dest);
void encode_arith_src_instruction(phrase_retrievel src);


void encode_increment_instruction(phrase_retrievel src);


char *get_den_reg();   // 8-bit registers
char *get_bay_reg();   // 16-bit registers
char *get_aisle_reg(); // 32-bit registers
char *get_zone_reg();  // 64-bit registers
phrase_retrievel get_undetermined_reg();
char * get_a_reg();


#endif // SEED_DECL_H

