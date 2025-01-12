#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"

void process_align_instruction(enum scope_type current_scope) 
{
    phrase_retrievel dest_index;
    phrase_retrievel src_index;
  
    /* or it can be said that we use den for 8 bit, bay for 16 bit, aisle for 32 bit, and zone fore for 64 bit*/
    switch(Token.token_rep)
    {
        case _move_den:    move_den(_move_den, "move_den");          current_architecture = 8;     break;   // 1 unsigned byte
        case _move_dens:   move_dens(_move_dens, "move_dens");       current_architecture = 8;     break;   // 1 signed byte
        case _move_bay:    move_bay(_move_bay, "move_bay");          current_architecture = 16;     break;   // 2 unsigned byte
        case _move_bays:   move_bays(_move_bays, "move_bays");       current_architecture = 16;     break;   // 2 signed byte
        case _move_aisle:  move_aisle(_move_aisle, "move_aisle");    current_architecture = 32;     break;   // 4 unsigned byte
        case _move_aisles: move_aisles(_move_aisles, "move_aisles"); current_architecture = 32;     break;   // 4 signed byte
        case _move_zone:   move_zone(_move_zone, "move_zone");       current_architecture = 64;     break;   // 8 unsigned byte
        case _move_zones:  move_zones(_move_zones, "move_zones");    current_architecture = 64;     break;   // 8 signed byte
        default: break;
    }

    scan(&Token);
    colon(_colon, ":");
  
    scan(&Token);
    dest_index = parse_first_phrase(current_scope, current_architecture);           // Handle destination operand or destination phrase

    scan(&Token);
    comma(_comma, ",");

    scan(&Token);
    src_index = parse_second_phrase(current_scope, current_architecture);           // Handle destination operand or destination phrase

    scan(&Token);
    semicolon(_semicolon, ";");

    encode_move_instruction("mov", current_architecture, dest_index, src_index);
}