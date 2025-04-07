#include "comp_def.h"  
#include "comp_data.h"   
#include "comp_decl.h" 
#include "color.h"



void ident(int t, char *expected) { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();printf(" %s\n", expected);  reset(); }  } }

// File Management Directives
void use(int t, char *expected) { if (Token.token_rep == t) { get_match_strand_flag(expected); } }
void replace(int t, char *expected) { if (Token.token_rep == t) { get_match_strand_flag(expected); } }
void link(int t, char *expected) { if (Token.token_rep == t) { get_match_strand_flag(expected); } }
void out(int t, char *expected) { if (Token.token_rep == t) { get_match_strand_flag(expected); } }
void transfer(int t, char *expected) { if (Token.token_rep == t) { get_match_strand_flag(expected); } }
void type_check(int t, char *expected) { if (Token.token_rep == t) { get_match_strand_flag(expected); } }
void collect(int t, char *expected) { if (Token.token_rep == t) { get_match_strand_flag(expected); } }

void proto(int t, char *expected)          { if (Token.token_rep == t) { if (output_flag) {  dark_blue();printf(" %s\n", expected);  reset(); }  } }
void internal(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) {  dark_blue();printf(" %s\n", expected);  reset(); }  } }
void external(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) {  dark_blue();printf(" %s\n", expected);  reset(); }  } }

void vine(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  dark_blue();printf(" %s\n", expected);  reset(); }  } }
void port_hub(int t, const char *expected) { if (Token.token_rep == t) { if (output_flag) {  dark_blue();printf(" %s\n", expected);  reset(); }  } }


// Core Language Types
void hollow(int t, char *expected)  { if (Token.token_rep == t) { if (output_flag) {  light_red();printf(" %s\n", expected);  reset(); }  } }
void num(int t, char *expected)     { if (Token.token_rep == t) { if (output_flag) {  light_red();printf(" %s\n", expected);  reset(); }  } }
void mark(int t, char *expected)    { if (Token.token_rep == t) { if (output_flag) {  light_red();printf(" %s\n", expected);  reset(); }  } }
void strand(int t, char *expected)  { if (Token.token_rep == t) { if (output_flag) {  light_red();printf(" %s\n", expected);  reset(); }  } }
void deci(int t, char *expected)    { if (Token.token_rep == t) { if (output_flag) {  light_red();printf(" %s\n", expected);  reset(); }  } }
void decii(int t, char *expected)   { if (Token.token_rep == t) { if (output_flag) {  light_red();printf(" %s\n", expected);  reset(); }  } }
void deciv(int t, char *expected)   { if (Token.token_rep == t) { if (output_flag) {  light_red();printf(" %s\n", expected);  reset(); }  } }
void decviii(int t, char *expected) { if (Token.token_rep == t) { if (output_flag) {  light_red();printf(" %s\n", expected);  reset(); }  } }

// Size Types
void size(int t, char *expected)    { if (Token.token_rep == t) { if (output_flag) {  light_red();printf(" %s\n", expected);  reset(); }  } }
void length(int t, char *expected)  { if (Token.token_rep == t) { if (output_flag) {  light_red();printf(" %s\n", expected);  reset(); }  } }

// Unsigned Size-Specific Types
void zone(int t, char *expected)    { if (Token.token_rep == t) { if (output_flag) {  light_red();printf(" %s\n", expected);  reset(); }  } }
void aisle(int t, char *expected)   { if (Token.token_rep == t) { if (output_flag) {  light_red();printf(" %s\n", expected);  reset(); }  } }
void bay(int t, char *expected)     { if (Token.token_rep == t) { if (output_flag) {  light_red();printf(" %s\n", expected);  reset(); }  } }
void den(int t, char *expected)     { if (Token.token_rep == t) { if (output_flag) {  light_red();printf(" %s\n", expected);  reset(); }  } }

// Signed Size-Specific Types
void zones(int t, char *expected)   { if (Token.token_rep == t) { if (output_flag) {  light_red();printf(" %s\n", expected);  reset(); }  } }
void aisles(int t, char *expected)  { if (Token.token_rep == t) { if (output_flag) {  light_red();printf(" %s\n", expected);  reset(); }  } }
void bays(int t, char *expected)    { if (Token.token_rep == t) { if (output_flag) {  light_red();printf(" %s\n", expected);  reset(); }  } }
void dens(int t, char *expected)    { if (Token.token_rep == t) { if (output_flag) {  light_red();printf(" %s\n", expected);  reset(); }  } } 




// Data Tools
void hold(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) {  dark_red();printf(" %s\n", expected);  reset(); }  } }
void assign(int t, char *expected)    { if (Token.token_rep == t) { if (output_flag) {  dark_red();printf(" %s\n", expected);  reset(); }  } }

void table(int t, char *expected)     { if (Token.token_rep == t) { if (output_flag) {  dark_red();printf(" %s\n", expected);  reset(); }  } }
void pare(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) {  dark_red();printf(" %s\n", expected);  reset(); }  } }
void tripare(int t, char *expected)   { if (Token.token_rep == t) { if (output_flag) {  dark_red();printf(" %s\n", expected);  reset(); }  } }



// Control Flow
void check(int t, char *expected)     { if (Token.token_rep == t) { if (output_flag) {  dark_red(); printf(" %s\n", expected);  reset(); }  } }
void elser(int t, char *expected)     { if (Token.token_rep == t) { if (output_flag) {  dark_red(); printf(" %s\n", expected);  reset(); }  } }
void loop(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) {  dark_red(); printf(" %s\n", expected);  reset(); }  } }
void set_loop(int t, char *expected)  { if (Token.token_rep == t) { if (output_flag) {  dark_red(); printf(" %s\n", expected);  reset(); }  } }
void compare(int t, char *expected)   { if (Token.token_rep == t) { if (output_flag) {  dark_red(); printf(" %s\n", expected);  reset(); }  } }
void line(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) {  dark_red(); printf(" %s\n", expected);  reset(); }  } }
void otherwise(int t, char *expected) { if (Token.token_rep == t) { if (output_flag) {  dark_red(); printf(" %s\n", expected);  reset(); }  } }

// State System
void state(int t, const char *expected)     { if (Token.token_rep == t) { if (output_flag) {  dark_red(); printf(" %s\n", expected);  reset(); }  } }
void sub_state(int t, const char *expected) { if (Token.token_rep == t) { if (output_flag) {  dark_red(); printf(" %s\n", expected);  reset(); }  } }
void end_state(int t, const char *expected) { if (Token.token_rep == t) { if (output_flag) {  dark_red(); printf(" %s\n", expected);  reset(); }  } }
void step(int t, const char *expected)      { if (Token.token_rep == t) { if (output_flag) {  dark_red(); printf(" %s\n", expected);  reset(); }  } }


void cycle(int t, const char *expected)   { if (Token.token_rep == t) { if (output_flag) {  dark_blue(); printf(" %s\n", expected);  reset(); }  } }
void next(int t, const char *expected)    { if (Token.token_rep == t) { if (output_flag) {  dark_blue(); printf(" %s\n", expected);  reset(); }  } }
void breaker(int t, const char *expected) { if (Token.token_rep == t) { if (output_flag) {  dark_blue(); printf(" %s\n", expected);  reset(); }  } }


void list_ident(int t, char *expected)     { if (Token.token_rep == t) { if (output_flag) {  dark_green();printf(" %s\n", expected);  reset(); }  } }
void list(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  dark_cyan();  printf(" %s\n", expected);  reset(); } } }
void match_log(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) {  dark_cyan();  printf(" %s\n", expected);  reset(); } } }

// Function System
void manager(int t, char *expected)        { if (Token.token_rep == t) { if (output_flag) {  dark_cyan();  printf(" %s\n", expected);  reset(); } } }
void function(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) {  dark_cyan();  printf(" %s\n", expected);  reset(); } } }
void loop_func(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) {  dark_cyan();  printf(" %s\n", expected);  reset(); } } }
void call(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  dark_cyan();  printf(" %s\n", expected);  reset(); } } }
void yield(int t, const char *expected)    { if (Token.token_rep == t) { if (output_flag) {  dark_cyan();  printf(" %s\n", expected);  reset(); } } }
void pass_arg(int t, const char *expected) { if (Token.token_rep == t) { if (output_flag) {  dark_cyan();  printf(" %s\n", expected);  reset(); } } }


void assigner(int t, char *expected)    { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();  printf(" %s\n", expected);  reset(); } } }

void increment(int t, char *expected)   { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();  printf(" %s\n", expected);  reset(); } } }
void decrement(int t, char *expected)   { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();  printf(" %s\n", expected);  reset(); } } }

// Operators
void logic_or(int t, char *expected)    { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();  printf(" %s\n", expected);  reset(); } } }
void logic_and(int t, char *expected)   { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();  printf(" %s\n", expected);  reset(); } } }
void logic_nor(int t, char *expected)   { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();  printf(" %s\n", expected);  reset(); } } }
void logic_xor(int t, char *expected)   { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();  printf(" %s\n", expected);  reset(); } } }

// Arithmetic Operators
void arith(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();  printf(" %s\n", expected);  reset(); } } }
void addition(int t, char *expected)    { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();  printf(" %s\n", expected);  reset(); } } }
void subtraction(int t, char *expected) { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();  printf(" %s\n", expected);  reset(); } } }
void divide(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();  printf(" %s\n", expected);  reset(); } } }
void multi(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();  printf(" %s\n", expected);  reset(); } } }

// Comparison Operators
void less_equal(int t, char *expected)  { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();  printf(" %s\n", expected);  reset(); } } }
void great_equal(int t, char *expected) { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();  printf(" %s\n", expected);  reset(); } } }
void less_then(int t, char *expected)   { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();  printf(" %s\n", expected);  reset(); } } }
void great_then(int t, char *expected)  { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();  printf(" %s\n", expected);  reset(); } } }
void equal(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();  printf(" %s\n", expected);  reset(); } } }
void not_equal(int t, char *expected)   { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();  printf(" %s\n", expected);  reset(); } } }




// Literals
void num_literal(int t, int expected)      { if (Token.token_rep == t) { if (output_flag) {  dark_red();  printf(" %d\n", expected);  reset(); } } }
void strand_literal(int t, char *expected) { if (Token.token_rep == t) { if (output_flag) {  black();  printf(" %s\n", expected);  reset(); } } }
void mark_literal(int t, int expected)     { if (Token.token_rep == t) { if (output_flag) {  black();  printf(" %s\n", expected);  reset(); } } }
void deci_literal(int t, int expected)     { if (Token.token_rep == t) { if (output_flag) {  dark_red();  printf(" %s\n", expected);  reset(); } } }
void decii_literal(int t, int expected)    { if (Token.token_rep == t) { if (output_flag) {  dark_red();  printf(" %s\n", expected);  reset(); } } }
void true_literal(int t, int expected)     { if (Token.token_rep == t) { if (output_flag) {  dark_blue();  printf(" %s\n", expected);  reset(); } } }
void false_literal(int t, int expected)    { if (Token.token_rep == t) { if (output_flag) {  dark_blue();  printf(" %s\n", expected);  reset(); } } }





// Special Characters
void colon(int t, char *expected)        { if (Token.token_rep == t) { if (output_flag) {  black();  printf(" %s\n", expected);  reset(); } } }
void ender(int t, const char *expected)  { if (Token.token_rep == t) { if (output_flag) {  black();  printf(" %s\n", expected);  reset(); } } }
void period(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) {  black();  printf(" %s\n", expected);  reset(); } } }
void comma(int t, char *expected)        { if (Token.token_rep == t) { if (output_flag) {  black();  printf(" %s\n", expected);  reset(); } } }
void semicolon(int t, char *expected)    { if (Token.token_rep == t) { if (output_flag) {  black();  printf(" %s\n", expected);  reset(); } } }
void lparen(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) {  black();  printf(" %s\n", expected);  reset(); } } }
void rparen(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) {  black();  printf(" %s\n", expected);  reset(); } } }
void lbrace(int t, const char *expected) { if (Token.token_rep == t) { if (output_flag) {  black();  printf(" %s\n", expected);  reset(); } } }
void rbrace(int t, const char *expected) { if (Token.token_rep == t) { if (output_flag) {  black();  printf(" %s\n", expected);  reset(); } } }
void lbracket(int t, char *expected)     { if (Token.token_rep == t) { if (output_flag) {  black();  printf(" %s\n", expected);  reset(); } } }
void rbracket(int t, char *expected)     { if (Token.token_rep == t) { if (output_flag) {  black();  printf(" %s\n", expected);  reset(); } } }
void larrow(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) {  black();  printf(" %s\n", expected);  reset(); } } }
void rarrow(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) {  black();  printf(" %s\n", expected);  reset(); } } }





// Pointer Types
void hollow_ptr(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) {  dark_magenta();  printf(" %s\n", expected);  reset(); } } }
void num_ptr(int t, char *expected)          { if (Token.token_rep == t) { if (output_flag) {  dark_magenta();  printf(" %s\n", expected);  reset(); } } }
void mark_ptr(int t, const char *expected)   { if (Token.token_rep == t) { if (output_flag) {  dark_magenta();  printf(" %s\n", expected);  reset(); } } }
void deci_ptr(int t, char *expected)         { if (Token.token_rep == t) { if (output_flag) {  dark_magenta();  printf(" %s\n", expected);  reset(); } } }
void strand_ptr(int t, const char *expected) { if (Token.token_rep == t) { if (output_flag) {  dark_magenta();  printf(" %s\n", expected);  reset(); } } }
void table_ptr(int t, char *expected)        { if (Token.token_rep == t) { if (output_flag) {  dark_magenta();  printf(" %s\n", expected);  reset(); } } }

// Special Purpose Pointers
void mana_ptr_(int t, char *expected)     { if (Token.token_rep == t) { if (output_flag) {  dark_blue();  printf(" %s\n", expected);  reset(); } } }
void func_ptr_(int t, char *expected)     { if (Token.token_rep == t) { if (output_flag) {  dark_blue();  printf(" %s\n", expected);  reset(); } } }
void log_ptr_(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) {  dark_blue();  printf(" %s\n", expected);  reset(); } } }
void list_ptr_(int t, char *expected)     { if (Token.token_rep == t) { if (output_flag) {  dark_blue();  printf(" %s\n", expected);  reset(); } } }

// Pointer Operations
void address(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) {  dark_magenta();  printf(" %s\n", expected);  reset(); } } }
void fetch(int t, const char *expected)   { if (Token.token_rep == t) { if (output_flag) {  dark_magenta();  printf(" %s\n", expected);  reset(); } } }
void retrieve(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) {  dark_magenta();  printf(" %s\n", expected);  reset(); } } }
void convert(int t, const char *expected) { if (Token.token_rep == t) { if (output_flag) {  dark_magenta();  printf(" %s\n", expected);  reset(); } } }

// Size-Specific Pointer Types
void zone_ptr(int t, char *expected) { if (Token.token_rep == t) { get_match_strand_flag(expected); } }
void aisle_ptr(int t, char *expected) { if (Token.token_rep == t) { get_match_strand_flag(expected); } }
void bay_ptr(int t, char *expected) { if (Token.token_rep == t) { get_match_strand_flag(expected); } }
void den_ptr(int t, char *expected) { if (Token.token_rep == t) { get_match_strand_flag(expected); } }
void zones_ptr(int t, char *expected) { if (Token.token_rep == t) { get_match_strand_flag(expected); } }
void aisles_ptr(int t, char *expected) { if (Token.token_rep == t) { get_match_strand_flag(expected); } }
void bays_ptr(int t, char *expected) { if (Token.token_rep == t) { get_match_strand_flag(expected); } }
void dens_ptr(int t, char *expected) { if (Token.token_rep == t) { get_match_strand_flag(expected); } }

// Additional Functions
void passage(int t, char *expected) { if (Token.token_rep == t) { get_match_strand_flag(expected); } }





// Change Modifiers
void change_global(int t, char *expected) { if (Token.token_rep == t) { get_match_strand_flag(expected); } }
void change_local(int t, char *expected) { if (Token.token_rep == t) { get_match_strand_flag(expected); } }



// Use Directives
void start_use(int t, char *expected) { if (Token.token_rep == t) { if (preprocess_flag) {  printf(" %s\n", expected); }  } }
void end_use(int t, char *expected) { if (Token.token_rep == t) { if (preprocess_flag) {  printf(" %s\n", expected); }  } }

// Link Directives
void start_link(int t, char *expected) { if (Token.token_rep == t) { if (preprocess_flag) {  printf(" %s\n", expected); }  } }
void end_link(int t, char *expected) { if (Token.token_rep == t) { if (preprocess_flag) {  printf(" %s\n", expected); }  } }

void at_sign(int t, char *expected) { if (Token.token_rep == t) { if (preprocess_flag) {  printf(" %s\n", expected); }  } }
void irp_ident(int t, char *expected) {if (Token.token_rep == t) { if (preprocess_flag) {  printf(" %s\n", expected); }  } }
void irp_line(int t, char *expected) { if (Token.token_rep == t) { if (preprocess_flag) {  printf(" %s\n", expected); }  } }
void irp_num_literal(int t, int expected) { if (Token.token_rep == t) { if (preprocess_flag) {  printf(" %d\n", expected); }  } }




int get_match_strand_flag(const char *expected)
{
    if (output_flag) 
    { 
        printf(" %s\n", expected); 
    } 
    if (first_pass_flag) 
    { 
        fprintf(comp_out, " %s\n", expected);
    } 
    return 0; // Added return value
}


int get_match_num_flag(int expected)
{
    if (output_flag) 
    { 
        printf(" %d\n", expected); 
    } 
    if (first_pass_flag) 
    { 
        fprintf(comp_out, " %d\n", expected);
    } 

    return 0;
}