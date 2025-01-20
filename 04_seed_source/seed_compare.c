#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"



void process_compare_instruction(enum scope_type current_scope) 
{
    phrase_retrievel dest_index;
    phrase_retrievel src_index;

    switch(Token.token_rep)
    {
        case _comp_den:     comp_den(_comp_den, "comp_den");         current_architecture = 8;   break;
        case _comp_bay:     comp_bay(_comp_bay, "comp_bay");         current_architecture = 16;  break;
        case _comp_aisle:   comp_aisle(_comp_aisle, "comp_aisle");   current_architecture = 32;  break;
        case _comp_zone:    comp_zone(_comp_zone, "comp_zone");      current_architecture = 64;  break;
        default: break;
    }
    scan(&Token);
    colon(_colon, ":");

    scan(&Token);        
    dest_index = parse_first_phrase(current_scope, global_architecture);           // Handle destination operand or destination phrase
    
    scan(&Token);
    comma(_comma, ",");

    scan(&Token);
    src_index = parse_second_phrase(current_scope, global_architecture);          // Handle source operand or sorce phrase
    
    scan(&Token);
    semicolon(_semicolon, ";");

    encode_compare_instruction(current_architecture, dest_index, src_index);
}