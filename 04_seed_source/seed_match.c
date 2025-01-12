#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"
#include "color.h"

void universal_scoper(int t, char *expected)    { if (Token.token_rep == t) { if (output_flag) {  dark_yellow(); printf(" %s\n", expected);  reset(); } } }
void file_scoper(int t, char *expected)         { if (Token.token_rep == t) { if (output_flag) {  dark_yellow(); printf(" %s\n", expected);  reset(); } } }
void global_scoper(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) {  dark_yellow(); printf(" %s\n", expected);  reset(); } } }
void global_param_scoper(int t, char *expected) { if (Token.token_rep == t) { if (output_flag) {  dark_yellow(); printf(" %s\n", expected);  reset(); } } }
void global_block_scoper(int t, char *expected) { if (Token.token_rep == t) { if (output_flag) {  dark_yellow(); printf(" %s\n", expected);  reset(); } } }
void local_scoper(int t, char *expected)        { if (Token.token_rep == t) { if (output_flag) {  dark_yellow(); printf(" %s\n", expected);  reset(); } } }
void local_param_scoper(int t, char *expected)  { if (Token.token_rep == t) { if (output_flag) {  dark_yellow(); printf(" %s\n", expected);  reset(); } } }
void local_block_scoper(int t, char *expected)  { if (Token.token_rep == t) { if (output_flag) {  dark_yellow(); printf(" %s\n", expected);  reset(); } } }

void ident(int t, char *expected)          { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void use(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void replace(int t, char *expected)        { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void link(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void out(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void transfer(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void type_check(int t, char *expected)     { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void collect(int t, char *expected)        { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }


void hollow(int t, char *expected)         { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void num(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void mark(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void strand(int t, char *expected)         { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void deci(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void decii(int t, char *expected)          { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void deciv(int t, char *expected)          { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void decviii(int t, char *expected)        { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }


void size(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void length(int t, char *expected)         { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }


void hold(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  dark_gray();    printf(" %s\n", expected);  reset(); } } }
void list(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  dark_gray();    printf(" %s\n", expected);  reset(); } } }
void table(int t, char *expected)          { if (Token.token_rep == t) { if (output_flag) {  dark_gray();    printf(" %s\n", expected);  reset(); } } }
void pare(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  dark_gray();    printf(" %s\n", expected);  reset(); } } }
void tripare(int t, char *expected)        { if (Token.token_rep == t) { if (output_flag) {  dark_gray();    printf(" %s\n", expected);  reset(); } } }
void check(int t, char *expected)          { if (Token.token_rep == t) { if (output_flag) {  dark_gray();    printf(" %s\n", expected);  reset(); } } }
void elser(int t, char *expected)          { if (Token.token_rep == t) { if (output_flag) {  dark_gray();    printf(" %s\n", expected);  reset(); } } }
void loop(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  dark_gray();    printf(" %s\n", expected);  reset(); } } }
void set_loop(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) {  dark_gray();    printf(" %s\n", expected);  reset(); } } }
void compare(int t, char *expected)        { if (Token.token_rep == t) { if (output_flag) {  dark_gray();    printf(" %s\n", expected);  reset(); } } }
void line(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  dark_gray();    printf(" %s\n", expected);  reset(); } } }
void otherwise(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) {  dark_gray();    printf(" %s\n", expected);  reset(); } } }


void manager(int t, char *expected)        { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void function(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void loop_func(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }


void logic_or(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void logic_and(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void logic_nor(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void logic_xor(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void less_equal(int t, char *expected)     { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void great_equal(int t, char *expected)    { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void less_then(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void great_then(int t, char *expected)     { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void equal(int t, char *expected)          { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void not_equal(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }


void num_literal(int t, int expected)      { if (Token.token_rep == t) { if (output_flag) {  light_blue();      printf(" %d\n", expected);  reset(); } } }
void strand_literal(int t, char *expected) { if (Token.token_rep == t) { if (output_flag) {  light_blue();      printf(" %s\n", expected);  reset(); } } }
void mark_literal(int t, int expected)     { if (Token.token_rep == t) { if (output_flag) {  light_blue();      printf(" %c\n", expected);  reset(); } } }
void deci_literal(int t, int expected)     { if (Token.token_rep == t) { if (output_flag) {  light_blue();      printf(" %f\n", expected);  reset(); } } }
void decii_literal(int t, int expected)    { if (Token.token_rep == t) { if (output_flag) {  light_blue();      printf(" %lf\n", expected); reset(); } } }


/*we also want to make the hex output color to the same as the right size registers so 64 bit to 64 bit. guess all registers the same
right now for console output? That should be right. red for 64, light blue for 32, */
void hex_literal(int t, int expected) 
{
    if (Token.token_rep == t) 
    {
        if (output_flag) 
        {
            light_blue();
            switch (t) 
            {
                case _hex_literal_08:  light_red(); printf(" 0x%02X\n", Token.hex_value_08);                   break;
                case _hex_literal_16:  light_red(); printf(" 0x%04X\n", Token.hex_value_16);                  break;
                case _hex_literal_32:  light_red(); printf(" 0x%08X\n", Token.hex_value_32);                  break;
                case _hex_literal_64:  light_red(); printf(" 0x%016lX\n", (unsigned long)Token.hex_value_64); break;
                default:
                    printf(" Unknown hex type\n");
            }
            reset();
        }
    }
}

void true_literal(int t, int expected)     { if (Token.token_rep == t) { if (output_flag) {  light_blue();      printf(" %s\n", expected ? "true" : "false");  reset(); } } }
void false_literal(int t, int expected)    { if (Token.token_rep == t) { if (output_flag) {  light_blue();      printf(" %s\n", expected ? "true" : "false");  reset(); } } }


void colon(int t, char *expected)          { if (Token.token_rep == t) { if (output_flag) {  black();          printf(" %s\n", expected);  reset(); } } }
void ender(int t, const char *expected)    { if (Token.token_rep == t) { if (output_flag) {  black();          printf(" %s\n", expected);  reset(); } } }
void period(int t, char *expected)         { if (Token.token_rep == t) { if (output_flag) {  black();          printf(" %s\n", expected);  reset(); } } }
void comma(int t, char *expected)          { if (Token.token_rep == t) { if (output_flag) {  black();          printf(" %s\n", expected);  reset(); } } }
void semicolon(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) {  black();          printf(" %s\n", expected);  reset(); } } }
void lparen(int t, char *expected)         { if (Token.token_rep == t) { if (output_flag) {  black();          printf(" %s\n", expected);  reset(); } } }
void rparen(int t, char *expected)         { if (Token.token_rep == t) { if (output_flag) {  black();          printf(" %s\n", expected);  reset(); } } }
void lbrace(int t, char *expected)         { if (Token.token_rep == t) { if (output_flag) {  black();          printf(" %s\n", expected);  reset(); } } }
void rbrace(int t, char *expected)         { if (Token.token_rep == t) { if (output_flag) {  black();          printf(" %s\n", expected);  reset(); } } }
void lbracket(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) {  black();          printf(" %s\n", expected);  reset(); } } }
void rbracket(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) {  black();          printf(" %s\n", expected);  reset(); } } } 
void larrow(int t, char *expected)         { if (Token.token_rep == t) { if (output_flag) {  black();          printf(" %s\n", expected);  reset(); } } }
void rarrow(int t, char *expected)         { if (Token.token_rep == t) { if (output_flag) {  black();          printf(" %s\n", expected);  reset(); } } }


void hollow_ptr(int t, char *expected)     { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void num_ptr(int t, char *expected)        { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void mark_ptr(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void deci_ptr(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void decii_ptr(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }

void strand_ptr(int t, char *expected)     { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }

void table_ptr(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void mana_ptr_(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void func_ptr_(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void log_ptr_(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void list_ptr_(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }



void address(int t, char *expected)        { if (Token.token_rep == t) { if (output_flag) {  light_green();    printf(" %s\n", expected);  reset(); } } }
void fetch(int t, char *expected)          { if (Token.token_rep == t) { if (output_flag) {  light_green();    printf(" %s\n", expected);  reset(); } } }
void retrieve(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) {  light_green();    printf(" %s\n", expected);  reset(); } } }
void convert(int t, char *expected)        { if (Token.token_rep == t) { if (output_flag) {  light_green();    printf(" %s\n", expected);  reset(); } } }


void increment(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void decrement(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }

void inc_den(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  light_gray();  printf(" %s\n", expected);  reset(); } } }
void inc_bay(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  light_gray();  printf(" %s\n", expected);  reset(); } } }
void inc_aisle(int t, char *expected)          { if (Token.token_rep == t) { if (output_flag) {  light_gray();  printf(" %s\n", expected);  reset(); } } }
void inc_zone(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  light_gray();  printf(" %s\n", expected);  reset(); } } }

void inc_dens(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  light_gray();  printf(" %s\n", expected);  reset(); } } }
void inc_bays(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  light_gray();  printf(" %s\n", expected);  reset(); } } }
void inc_aisles(int t, char *expected)          { if (Token.token_rep == t) { if (output_flag) {  light_gray();  printf(" %s\n", expected);  reset(); } } }
void inc_zones(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  light_gray();  printf(" %s\n", expected);  reset(); } } }



void den(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  light_gray();  printf(" %s\n", expected);  reset(); } } }
void bay(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  light_gray();  printf(" %s\n", expected);  reset(); } } }
void aisle(int t, char *expected)          { if (Token.token_rep == t) { if (output_flag) {  light_gray();  printf(" %s\n", expected);  reset(); } } }
void zone(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  light_gray();  printf(" %s\n", expected);  reset(); } } }

void dens(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  light_gray();  printf(" %s\n", expected);  reset(); } } }
void bays(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  light_gray();  printf(" %s\n", expected);  reset(); } } }
void aisles(int t, char *expected)          { if (Token.token_rep == t) { if (output_flag) {  light_gray();  printf(" %s\n", expected);  reset(); } } }
void zones(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  light_gray();  printf(" %s\n", expected);  reset(); } } }



void zone_ptr(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) {  light_magenta();  printf(" %s\n", expected);  reset(); } } }
void aisle_ptr(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) {  light_magenta();  printf(" %s\n", expected);  reset(); } } }
void bay_ptr(int t, char *expected)        { if (Token.token_rep == t) { if (output_flag) {  light_magenta();  printf(" %s\n", expected);  reset(); } } }
void den_ptr(int t, char *expected)        { if (Token.token_rep == t) { if (output_flag) {  light_magenta();  printf(" %s\n", expected);  reset(); } } }
void zones_ptr(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) {  light_magenta();  printf(" %s\n", expected);  reset(); } } }
void aisles_ptr(int t, char *expected)     { if (Token.token_rep == t) { if (output_flag) {  light_magenta();  printf(" %s\n", expected);  reset(); } } }
void bays_ptr(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) {  light_magenta();  printf(" %s\n", expected);  reset(); } } }
void dens_ptr(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) {  light_magenta();  printf(" %s\n", expected);  reset(); } } }

void passage(int t, char *expected)        { if (Token.token_rep == t) { if (output_flag) {  light_red();    printf(" %s\n", expected);  reset(); } } }
void assigner(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }

void internal(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) {  light_yellow();    printf(" %s\n", expected);  reset(); } } }
void external(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) {  light_yellow();    printf(" %s\n", expected);  reset(); } } }

void proto(int t, char *expected)          { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void vine(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void port_hub(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void state(int t, char *expected)          { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void sub_state(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void end_state(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void step(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void cycle(int t, char *expected)          { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void next(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void breaker(int t, char *expected)        { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void change_global(int t, char *expected)  { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void change_local(int t, char *expected)   { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }


void move(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  light_gray();     printf(" %s\n", expected);  reset(); } } }
void move_den(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) {  light_gray();     printf(" %s\n", expected);  reset(); } } }
void move_bay(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) {  light_gray();     printf(" %s\n", expected);  reset(); } } }
void move_aisle(int t, char *expected)     { if (Token.token_rep == t) { if (output_flag) {  light_gray();     printf(" %s\n", expected);  reset(); } } }
void move_zone(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) {  light_gray();     printf(" %s\n", expected);  reset(); } } }
void move_dens(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) {  light_gray();     printf(" %s\n", expected);  reset(); } } }
void move_bays(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) {  light_gray();     printf(" %s\n", expected);  reset(); } } }
void move_aisles(int t, char *expected)    { if (Token.token_rep == t) { if (output_flag) {  light_gray();     printf(" %s\n", expected);  reset(); } } }
void move_zones(int t, char *expected)     { if (Token.token_rep == t) { if (output_flag) {  light_gray();     printf(" %s\n", expected);  reset(); } } }


void add(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  black();          printf(" %s\n", expected);  reset(); } } }
void sub(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  black();          printf(" %s\n", expected);  reset(); } } }
void mul(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  black();          printf(" %s\n", expected);  reset(); } } }
void division(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) {  black();          printf(" %s\n", expected);  reset(); } } }


void align_den(int t, char *expected)        { if (Token.token_rep == t) { if (output_flag) { black(); printf(" %s\n", expected); reset(); } } }
void align_bay(int t, char *expected)        { if (Token.token_rep == t) { if (output_flag) { black(); printf(" %s\n", expected); reset(); } } }
void align_aisle(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) { black(); printf(" %s\n", expected); reset(); } } }
void align_zone(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) { black(); printf(" %s\n", expected); reset(); } } }

void align_dens(int t, char *expected)        { if (Token.token_rep == t) { if (output_flag) { black(); printf(" %s\n", expected); reset(); } } }
void align_bays(int t, char *expected)        { if (Token.token_rep == t) { if (output_flag) { black(); printf(" %s\n", expected); reset(); } } }
void align_aisles(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) { black(); printf(" %s\n", expected); reset(); } } }
void align_zones(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) { black(); printf(" %s\n", expected); reset(); } } }


void add_den(int t, char *expected)        { if (Token.token_rep == t) { if (output_flag) { black(); printf(" %s\n", expected); reset(); } } }
void add_bay(int t, char *expected)        { if (Token.token_rep == t) { if (output_flag) { black(); printf(" %s\n", expected); reset(); } } }
void add_aisle(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) { black(); printf(" %s\n", expected); reset(); } } }
void add_zone(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) { black(); printf(" %s\n", expected); reset(); } } }

void sub_den(int t, char *expected)        { if (Token.token_rep == t) { if (output_flag) { black(); printf(" %s\n", expected); reset(); } } }
void sub_bay(int t, char *expected)        { if (Token.token_rep == t) { if (output_flag) { black(); printf(" %s\n", expected); reset(); } } }
void sub_aisle(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) { black(); printf(" %s\n", expected); reset(); } } }
void sub_zone(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) { black(); printf(" %s\n", expected); reset(); } } }

void mul_den(int t, char *expected)        { if (Token.token_rep == t) { if (output_flag) { black(); printf(" %s\n", expected); reset(); } } }
void mul_bay(int t, char *expected)        { if (Token.token_rep == t) { if (output_flag) { black(); printf(" %s\n", expected); reset(); } } }
void mul_aisle(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) { black(); printf(" %s\n", expected); reset(); } } }
void mul_zone(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) { black(); printf(" %s\n", expected); reset(); } } }

void div_den(int t, char *expected)        { if (Token.token_rep == t) { if (output_flag) { black(); printf(" %s\n", expected); reset(); } } }
void div_bay(int t, char *expected)        { if (Token.token_rep == t) { if (output_flag) { black(); printf(" %s\n", expected); reset(); } } }
void div_aisle(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) { black(); printf(" %s\n", expected); reset(); } } }
void div_zone(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) { black(); printf(" %s\n", expected); reset(); } } }

void add_dens(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) { black(); printf(" %s\n", expected); reset(); } } }
void add_bays(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) { black(); printf(" %s\n", expected); reset(); } } }
void add_aisles(int t, char *expected)     { if (Token.token_rep == t) { if (output_flag) { black(); printf(" %s\n", expected); reset(); } } }
void add_zones(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) { black(); printf(" %s\n", expected); reset(); } } }
void sub_dens(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) { black(); printf(" %s\n", expected); reset(); } } }
void sub_bays(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) { black(); printf(" %s\n", expected); reset(); } } }
void sub_aisles(int t, char *expected)     { if (Token.token_rep == t) { if (output_flag) { black(); printf(" %s\n", expected); reset(); } } }
void sub_zones(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) { black(); printf(" %s\n", expected); reset(); } } }
void mul_dens(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) { black(); printf(" %s\n", expected); reset(); } } }
void mul_bays(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) { black(); printf(" %s\n", expected); reset(); } } }
void mul_aisles(int t, char *expected)     { if (Token.token_rep == t) { if (output_flag) { black(); printf(" %s\n", expected); reset(); } } }
void mul_zones(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) { black(); printf(" %s\n", expected); reset(); } } }
void div_dens(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) { black(); printf(" %s\n", expected); reset(); } } }
void div_bays(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) { black(); printf(" %s\n", expected); reset(); } } }
void div_aisles(int t, char *expected)     { if (Token.token_rep == t) { if (output_flag) { black(); printf(" %s\n", expected); reset(); } } }
void div_zones(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) { black(); printf(" %s\n", expected); reset(); } } }


void jump(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  light_yellow();     printf(" %s\n", expected);  reset(); } } }
void jump_equal(int t, char *expected)     { if (Token.token_rep == t) { if (output_flag) {  light_yellow();     printf(" %s\n", expected);  reset(); } } }
void jump_not_equal(int t, char *expected) { if (Token.token_rep == t) { if (output_flag) {  light_yellow();     printf(" %s\n", expected);  reset(); } } }
void jump_less(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) {  light_yellow();     printf(" %s\n", expected);  reset(); } } }
void jump_great(int t, char *expected)     { if (Token.token_rep == t) { if (output_flag) {  light_yellow();     printf(" %s\n", expected);  reset(); } } }
void jump_neg(int t, char *expected)     { if (Token.token_rep == t) { if (output_flag) {  light_yellow();     printf(" %s\n", expected);  reset(); } } }

void test(int t, char *expected)     { if (Token.token_rep == t) { if (output_flag) {  light_yellow();     printf(" %s\n", expected);  reset(); } } }

void universal(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) {  dark_cyan();      printf(" %s\n", expected);  reset(); } } }
void global(int t, char *expected)         { if (Token.token_rep == t) { if (output_flag) {  dark_cyan();      printf(" %s\n", expected);  reset(); } } }
void local(int t, char *expected)          { if (Token.token_rep == t) { if (output_flag) {  dark_cyan();      printf(" %s\n", expected);  reset(); } } }
void global_block(int t, char *expected)   { if (Token.token_rep == t) { if (output_flag) {  dark_cyan();      printf(" %s\n", expected);  reset(); } } }
void local_block(int t, char *expected)    { if (Token.token_rep == t) { if (output_flag) {  dark_cyan();      printf(" %s\n", expected);  reset(); } } }
void global_param(int t, char *expected)   { if (Token.token_rep == t) { if (output_flag) {  dark_cyan();      printf(" %s\n", expected);  reset(); } } }
void local_param(int t, char *expected)    { if (Token.token_rep == t) { if (output_flag) {  dark_cyan();      printf(" %s\n", expected);  reset(); } } }
void call(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  dark_cyan();      printf(" %s\n", expected);  reset(); } } }
void yield(int t, const char *expected)    { if (Token.token_rep == t) { if (output_flag) {  dark_cyan();      printf(" %s\n", expected);  reset(); } } }
void pass_arg(int t, const char *expected) { if (Token.token_rep == t) { if (output_flag) {  light_cyan();      printf(" %s\n", expected);  reset(); } } }

void call_system(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  dark_cyan();      printf(" %s\n", expected);  reset(); } } }

void match_log(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) {  dark_cyan();      printf(" %s\n", expected);  reset(); } } }
void declare(int t, char *expected)        { if (Token.token_rep == t) { if (output_flag) {  dark_cyan();      printf(" %s\n", expected);  reset(); } } }
void assign(int t, char *expected)         { if (Token.token_rep == t) { if (output_flag) {  dark_cyan();      printf(" %s\n", expected);  reset(); } } }
void literal(int t, char *expected)        { if (Token.token_rep == t) { if (output_flag) {  dark_cyan();      printf(" %s\n", expected);  reset(); } } }
void code(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  dark_cyan();      printf(" %s\n", expected);  reset(); } } }
void pad_section(int t, char *expected)    { if (Token.token_rep == t) { if (output_flag) {  dark_cyan();      printf(" %s\n", expected);  reset(); } } }
void file_section(int t, char *expected)        { if (Token.token_rep == t) { if (output_flag) {  dark_cyan();      printf(" %s\n", expected);  reset(); } } }

void start_section(int t, char *expected)    { if (Token.token_rep == t) { if (output_flag) {  dark_cyan();      printf(" %s\n", expected);  reset(); } } }
void end_section(int t, char *expected)    { if (Token.token_rep == t) { if (output_flag) {  dark_cyan();      printf(" %s\n", expected);  reset(); } } }
void end(int t, char *expected)    { if (Token.token_rep == t) { if (output_flag) {  dark_cyan();      printf(" %s\n", expected);  reset(); } } }


void arch_08(int t, char *expected)        { if (Token.token_rep == t) { if (output_flag) {  dark_cyan();      printf(" %s\n", expected);  reset(); } } }
void arch_16(int t, char *expected)        { if (Token.token_rep == t) { if (output_flag) {  dark_cyan();      printf(" %s\n", expected);  reset(); } } }
void arch_32(int t, char *expected)        { if (Token.token_rep == t) { if (output_flag) {  dark_cyan();      printf(" %s\n", expected);  reset(); } } }
void arch_64(int t, char *expected)        { if (Token.token_rep == t) { if (output_flag) {  dark_cyan();      printf(" %s\n", expected);  reset(); } } }


void origin(int t, char *expected)         { if (Token.token_rep == t) { if (output_flag) {  light_cyan();     printf(" %s\n", expected);  reset(); } } }
void load(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  light_cyan();     printf(" %s\n", expected);  reset(); } } }
void sign(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  light_cyan();     printf(" %s\n", expected);  reset(); } } }


void entry(int t, char *expected)          { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void start_use(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void end_use(int t, char *expected)        { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void start_link(int t, char *expected)     { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void end_link(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void end_log(int t, char *expected)        { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void scope(int t, char *expected)          { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }
void end_scope(int t, char *expected)      { if (Token.token_rep == t) { if (output_flag) {  dark_yellow();    printf(" %s\n", expected);  reset(); } } }


void push_radule(int t, char *expected)    { if (Token.token_rep == t) { if (output_flag) {  light_cyan();     printf(" %s\n", expected);  reset(); } } }
void pop_radule(int t, char *expected)     { if (Token.token_rep == t) { if (output_flag) {  light_cyan();     printf(" %s\n", expected);  reset(); } } }
void push(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  light_cyan();     printf(" %s\n", expected);  reset(); } } }
void pop(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  light_cyan();     printf(" %s\n", expected);  reset(); } } }

void push_den(int t, char *expected) { if (Token.token_rep == t) { if (output_flag) { light_cyan(); printf(" %s\n", expected); reset(); } } }
void pop_den(int t, char *expected)  { if (Token.token_rep == t) { if (output_flag) { light_cyan(); printf(" %s\n", expected); reset(); } } }

void push_bay(int t, char *expected) { if (Token.token_rep == t) { if (output_flag) { light_cyan(); printf(" %s\n", expected); reset(); } } }
void pop_bay(int t, char *expected)  { if (Token.token_rep == t) { if (output_flag) { light_cyan(); printf(" %s\n", expected); reset(); } } }

void push_aisle(int t, char *expected) { if (Token.token_rep == t) { if (output_flag) { light_cyan(); printf(" %s\n", expected); reset(); } } }
void pop_aisle(int t, char *expected)  { if (Token.token_rep == t) { if (output_flag) { light_cyan(); printf(" %s\n", expected); reset(); } } }

void push_zone(int t, char *expected) { if (Token.token_rep == t) { if (output_flag) { light_cyan(); printf(" %s\n", expected); reset(); } } }
void pop_zone(int t, char *expected)  { if (Token.token_rep == t) { if (output_flag) { light_cyan(); printf(" %s\n", expected); reset(); } } }

void push_dens(int t, char *expected) { if (Token.token_rep == t) { if (output_flag) { light_cyan(); printf(" %s\n", expected); reset(); } } }
void pop_dens(int t, char *expected)  { if (Token.token_rep == t) { if (output_flag) { light_cyan(); printf(" %s\n", expected); reset(); } } }

void push_bays(int t, char *expected) { if (Token.token_rep == t) { if (output_flag) { light_cyan(); printf(" %s\n", expected); reset(); } } }
void pop_bays(int t, char *expected)  { if (Token.token_rep == t) { if (output_flag) { light_cyan(); printf(" %s\n", expected); reset(); } } }

void push_aisles(int t, char *expected) { if (Token.token_rep == t) { if (output_flag) { light_cyan(); printf(" %s\n", expected); reset(); } } }
void pop_aisles(int t, char *expected)  { if (Token.token_rep == t) { if (output_flag) { light_cyan(); printf(" %s\n", expected); reset(); } } }

void push_zones(int t, char *expected) { if (Token.token_rep == t) { if (output_flag) { light_cyan(); printf(" %s\n", expected); reset(); } } }
void pop_zones(int t, char *expected)  { if (Token.token_rep == t) { if (output_flag) { light_cyan(); printf(" %s\n", expected); reset(); } } }



void rax(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void rbx(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void rcx(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void rdx(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void rsi(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void rdi(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void rbp(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void rsp(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void r8(int t, char *expected)             { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void r9(int t, char *expected)             { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void r10(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void r11(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void r12(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void r13(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void r14(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void r15(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }

void eax(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void ebx(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void ecx(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void edx(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void esi(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void edi(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void ebp(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void esp(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void r8d(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  light_red();    printf(" %s\n", expected);  reset(); } } }
void r9d(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  light_red();    printf(" %s\n", expected);  reset(); } } }
void r10d(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  light_red();    printf(" %s\n", expected);  reset(); } } }
void r11d(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  light_red();    printf(" %s\n", expected);  reset(); } } }
void r12d(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  light_red();    printf(" %s\n", expected);  reset(); } } }
void r13d(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  light_red();    printf(" %s\n", expected);  reset(); } } }
void r14d(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  light_red();    printf(" %s\n", expected);  reset(); } } }
void r15d(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  light_red();    printf(" %s\n", expected);  reset(); } } }

void ax(int t, char *expected)             { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void bx(int t, char *expected)             { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void cx(int t, char *expected)             { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void dx(int t, char *expected)             { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void si(int t, char *expected)             { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void di(int t, char *expected)             { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void bp(int t, char *expected)             { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void sp(int t, char *expected)             { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void r8w(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void r9w(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void r10w(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void r11w(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void r12w(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void r13w(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void r14w(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void r15w(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }

void al(int t, char *expected)             { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void bl(int t, char *expected)             { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void cl(int t, char *expected)             { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void dl(int t, char *expected)             { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void sil(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void dil(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void bpl(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void spl(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void r8b(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void r9b(int t, char *expected)            { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void r10b(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void r11b(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void r12b(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void r13b(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void r14b(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void r15b(int t, char *expected)           { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }

void ah(int t, char *expected)             { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void bh(int t, char *expected)             { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void ch(int t, char *expected)             { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }
void dh(int t, char *expected)             { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }

void int_instr(int t, char *expected) { 
    if (Token.token_rep == t) { 
        if (output_flag) {  
            light_cyan();     
            printf(" %s\n", expected);  
            reset(); 
        } 
    } 
}

void set_flag(int t, char *expected)       { if (Token.token_rep == t) { if (output_flag) {  light_red();     printf(" %s\n", expected);  reset(); } } }

