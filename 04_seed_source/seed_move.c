#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"

void process_move_instruction(enum scope_type current_scope) 
{
    struct phrase *dest_index;
    struct phrase *src_index;

    int move_type = 0;

    /* or it can be said that we use den for 8 bit, bay for 16 bit, aisle for 32 bit, and zone fore for 64 bit*/
    switch(Token.token_rep)
    {
        case _move_den:    move_den(_move_den, "move_den");          move_type = _get_den_reg;     break;   // 1 unsigned byte
        case _move_dens:   move_dens(_move_dens, "move_dens");       move_type = _get_den_reg;     break;   // 1 signed byte
        case _move_bay:    move_bay(_move_bay, "move_bay");          move_type = _get_bay_reg;     break;   // 2 unsigned byte
        case _move_bays:   move_bays(_move_bays, "move_bays");       move_type = _get_bay_reg;     break;   // 2 signed byte
        case _move_aisle:  move_aisle(_move_aisle, "move_aisle");    move_type = _get_aisle_reg;   break;   // 4 unsigned byte
        case _move_aisles: move_aisles(_move_aisles, "move_aisles"); move_type = _get_aisle_reg;   break;   // 4 signed byte
        case _move_zone:   move_zone(_move_zone, "move_zone");       move_type = _get_zone_reg;   break;   // 8 unsigned byte
        case _move_zones:  move_zones(_move_zones, "move_zones");    move_type = _get_zone_reg;   break;   // 8 signed byte
        default: break;
    }

    scan(&Token);
    colon(_colon, ":");

    scan(&Token);        
    dest_index = parse_first_phrase(current_scope, move_type);           // Handle destination operand or destination phrase
    
    scan(&Token);
    comma(_comma, ",");

    scan(&Token);
    src_index = parse_second_phrase(current_scope, move_type);          // Handle source operand or sorce phrase
    encode_move_instruction("mov", dest_index, src_index);

    scan(&Token);
    semicolon(_semicolon, ";");     
}