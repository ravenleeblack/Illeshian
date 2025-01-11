#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"



void process_compare_instruction(enum scope_type current_scope) 
{
    char *dest_index;
    char *src_index;

    compare(_compare, "compare");

    scan(&Token);
    colon(_colon, ":");

    scan(&Token);        
    dest_index = parse_first_phrase(current_scope, NULL);           // Handle destination operand or destination phrase
    
    scan(&Token);
    comma(_comma, ",");

    scan(&Token);
    src_index = parse_second_phrase(current_scope, NULL);          // Handle source operand or sorce phrase
    encode_compare_instruction("cmp", dest_index, src_index);

    scan(&Token);
    semicolon(_semicolon, ";");

}