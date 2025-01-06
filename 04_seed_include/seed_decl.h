#ifndef SEED_DECL_H
#define SEED_DECL_H


int begin_prog(void);


void process_universal_label(void);

void process_global_label(void);
void process_global_block_label(int parent_global_id);

void process_local_label(int parent_global_id);
void process_local_block_label(int parent_global_id);




void process_sections(enum scope_type current_scope);
void process_log_section(enum scope_type current_scope);
void process_declare_section(enum scope_type current_scope);
void process_assign_section(enum scope_type current_scope);
void process_literal_section(enum scope_type current_scope);
void process_code_section(enum scope_type current_scope);
void process_end_section(void);
void process_arch_16_section();
void process_arch_32_section();
void process_arch_64_section();
void process_pad_section();


void process_global_child_labels(int parent_global_id);
void process_local_child_labels(int parent_global_id);
void process_global_block_child_labels(int parent_global_id);

// Register phrase processing
void process_left_phrase(enum scope_type current_scope);
void process_right_phrase(enum scope_type current_scope);


void process_one_phrase(int instruction, enum scope_type current_scope);
void process_two_phrase(int instruction, enum scope_type current_scope);
void process_three_phrase(int instruction, enum scope_type current_scope);








// Move instructions
void move(int t, char *expected);
void process_move_den(void);
void process_move_dens(void);
void process_move_bay(void);
void process_move_bays(void);
void process_move_aisle(void);
void process_move_aisles(void);
void process_move_zone(void);
void process_move_zones(void);

// Jump instructions
void process_jump(void);
void process_jump_equal(void);
void process_jump_not_equal(void);
void process_jump_less(void);
void process_jump_great(void);




// Call instructions


// Arithmetic instructions
void process_add_instruction(void);
void process_sub_instruction(void);
void process_mul_instruction(void);
void process_div_instruction(void);

void process_move_instruction(enum scope_type current_scope);

void process_jump_instruction(enum scope_type current_scope);
void process_jump_less_instruction(enum scope_type current_scope) ;

void process_push_radule_instruction(enum scope_type current_scope);
void process_pop_radule_instruction(enum scope_type current_scope);

// Stack instructions
void process_push_instruction(enum scope_type current_scope);
void process_pop_instruction(enum scope_type current_scope);

void process_pass_arg_instruction(enum scope_type current_scope);

void process_set_flag_instruction(enum scope_type current_scope);

void process_compare_instruction(enum scope_type current_scope);

void process_lend_instruction(enum scope_type current_scope);




//============================================================================================================================
//MATCH FUNCTIONS


// Scope prototypes
void universal_scoper(int t, char *expected);
void file_scoper(int t, char *expected);
void global_scoper(int t, char *expected);
void global_param_scoper(int t, char *expected);
void global_block_scoper(int t, char *expected);
void local_scoper(int t, char *expected);
void local_param_scoper(int t, char *expected);
void local_block_scoper(int t, char *expected);

// Core language prototypes
void ident(int t, char *expected);
void use(int t, char *expected);
void replace(int t, char *expected);
void link(int t, char *expected);
void out(int t, char *expected);
void transfer(int t, char *expected);
void type_check(int t, char *expected);
void collect(int t, char *expected);

// Data type prototypes
void hollow(int t, char *expected);
void num(int t, char *expected);
void mark(int t, char *expected);
void strand(int t, char *expected);
void deci(int t, char *expected);
void decii(int t, char *expected);
void deciv(int t, char *expected);
void decviii(int t, char *expected);

// Data operation prototypes
void size(int t, char *expected);
void length(int t, char *expected);
void hold(int t, char *expected);
void list(int t, char *expected);
void table(int t, char *expected);
void pare(int t, char *expected);
void tripare(int t, char *expected);

// Control flow prototypes
void check(int t, char *expected);
void elser(int t, char *expected);
void loop(int t, char *expected);
void set_loop(int t, char *expected);
void compare(int t, char *expected);
void line(int t, char *expected);
void otherwise(int t, char *expected);

// Function prototypes
void manager(int t, char *expected);
void function(int t, char *expected);
void loop_func(int t, char *expected);

// Logic prototypes
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

// Literal prototypes
void num_literal(int t, int expected);
void strand_literal(int t, char *expected);
void mark_literal(int t, int expected);
void deci_literal(int t, int expected);
void decii_literal(int t, int expected);
void hex_literal(int t, int expected);
void true_literal(int t, int expected);
void false_literal(int t, int expected);

// Syntax prototypes
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

// Pointer prototypes
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

// Memory operation prototypes
void address(int t, char *expected);
void fetch(int t, char *expected);
void retrieve(int t, char *expected);
void convert(int t, char *expected);
void increment(int t, char *expected);
void decrement(int t, char *expected);

// System type prototypes
void zone(int t, char *expected);
void aisle(int t, char *expected);
void bay(int t, char *expected);
void den(int t, char *expected);
void zones(int t, char *expected);
void aisles(int t, char *expected);
void bays(int t, char *expected);
void dens(int t, char *expected);

// System pointer prototypes
void zone_ptr(int t, char *expected);
void aisle_ptr(int t, char *expected);
void bay_ptr(int t, char *expected);
void den_ptr(int t, char *expected);
void zones_ptr(int t, char *expected);
void aisles_ptr(int t, char *expected);
void bays_ptr(int t, char *expected);
void dens_ptr(int t, char *expected);

// System operation prototypes
void passage(int t, char *expected);
void assigner(int t, char *expected);
void internal(int t, char *expected);
void external(int t, char *expected);
void proto(int t, char *expected);
void vine(int t, char *expected);
void port_hub(int t, char *expected);

// Register prototypes (64-bit)
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

// Register prototypes (32-bit)
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

// Register prototypes (16-bit)
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

// Register prototypes (8-bit)
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

// Special operation prototypes
void push_radule(int t, char *expected);
void pop_radule(int t, char *expected);

// Section prototypes
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

//============================================================================================================================
// Section handling





//============================================================================================================================
// SUPPORT FUNCTIONS


int get_match_num_flag(int expected);
int get_match_strand_flag(const char *expected);

int scanhex(void);
float scandeci(int c);
int scan(struct token *t);
void error(const char *message);
void reject_token(struct token *t);


int parse_type(enum scope_type current_scope);


void process_call_instruction(enum scope_type scope);

void error_handler(int error_code);
void error(const char *message);
void errors(const char *message, const char *s);
void errorc(const char *message, int c);


//============================================================================================================================


// Update the function declarations (make sure they end with semicolons)
void clear_temp_files(void);

void encode_universal_scope_section(FILE* output, const char* label, enum scope_type scope);
void encode_global_scope_section(FILE* output, const char* label);
void encode_global_block_scope_section(FILE* output, const char* label);
void encode_local_scope_section(FILE* output, const char* label);

void encode_manager_to_nasm(FILE* output, const char* label_name);

void finalize_scope_section(FILE* output, enum scope_type scope);
void copy_temp_file_contents(FILE* temp, FILE* output);
void finalize_nasm_output(FILE* output);

void encode_instruction(const char* instr, const char* dest, const char* src);

const char* get_current_filename(void);
void set_current_filename(const char* filename);


void output_declare_section_header();
void output_assign_section_header();
void output_code_section_header();

void output_declare_section_body(const char* ident, int type);
void output_assign_section_body(const char* ident, int type);
void encode_literal_section(const char* value, int length);


void encode_register(const char* reg, char* nasm_reg);
void encode_memory_reference(const char* base, const char* offset, char* nasm_ref);

// Add these declarations
void encode_push_instruction(const char* reg);
void encode_pop_instruction(const char* reg);

void encode_call_manager_instruction(const char* label);
void encode_call_function_instruction(const char* label_one, const char* label_two);


void encode_jump_instruction(const char* label);
void encode_jump_less_instruction(const char* label);
void encode_numeric_instruction(const char* value);
void encode_pass_arg_instruction(const char* reg);
void encode_set_flag_instruction(const char* reg1, const char* reg2);
void encode_jump_neg_instruction(const char* label);

void encode_file_section(const char* ident);

void encode_test_instruction(const char* reg1, const char* reg2);

void encode_lend_instruction(const char* reg1);
void encode_fetch_reference(const char* dest, const char* src);

void process_compare_instruction(enum scope_type current_scope);
void process_set_flag_instruction(enum scope_type current_scope);
void process_jump_instruction(enum scope_type current_scope);
void process_jump_less_instruction(enum scope_type current_scope);
void process_jump_great_instruction(enum scope_type current_scope);
void process_jump_equal_instruction(enum scope_type current_scope);
void process_jump_not_equal_instruction(enum scope_type current_scope);
void process_jump_neg_instruction(enum scope_type current_scope);
void process_test_instruction(enum scope_type current_scope);
void process_file_section(enum scope_type current_scope);




int get_architecture(void);
void set_architecture(int bits);

// External flags
extern int nasm_flag;
extern int rootling_flag;


#endif // SEED_DECL_H

