#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"

/*functions to retrieve the first and second operand or phrase of an instruction during parsing. We create re-usuable functions like this
to cut down on code, provide better readability, and useablity.Not all instructions have two operand or phrases like the move instruction
so this allows us to be versitile as well.*/

char *parse_first_phrase(enum scope_type current_scope, int current_architecture)
{
   char * dest_index;

    switch (Token.token_rep)
    {
        case _num_literal: dest_index = parse_num_literal(current_scope);                break;
        case _ident:       dest_index = parse_ident(current_scope);                      break;

        case _address:     dest_index = parse_address(current_scope);                    break;
        case _fetch:       dest_index = parse_fetch(current_scope);                      break;

        case _num_ptr:    dest_index = parse_pointer(current_scope); break;
        case _mark_ptr:   dest_index = parse_pointer(current_scope); break;
        case _deci_ptr:   dest_index = parse_pointer(current_scope); break;
        case _decii_ptr:  dest_index = parse_pointer(current_scope); break;

        case _den_ptr:    dest_index = parse_pointer(current_scope); break;
        case _bay_ptr:    dest_index = parse_pointer(current_scope); break;
        case _aisle_ptr:  dest_index = parse_pointer(current_scope); break;
        case _zone_ptr:   dest_index = parse_pointer(current_scope); break;
        
        case _dens_ptr:   dest_index = parse_pointer(current_scope); break;
        case _bays_ptr:   dest_index = parse_pointer(current_scope); break;
        case _aisles_ptr: dest_index = parse_pointer(current_scope); break;
        case _zones_ptr:  dest_index = parse_pointer(current_scope); break;
        default: 
        
        switch(current_architecture)
        {
            case 8:    dest_index = get_den_reg();    break;
            case 16:   dest_index = get_bay_reg();    break;
            case 32:   dest_index = get_aisle_reg();  break;
            case 64:   dest_index = get_zone_reg();   break;
            default:   break;
        } 
         break;
    }
    return dest_index;  // Return the populated struct phrase
}

char *parse_second_phrase(enum scope_type current_scope, int current_architecture)
{
   char * src_index;

    switch (Token.token_rep)
    {
        case _num_literal: src_index = parse_num_literal(current_scope);                break;
        case _ident:       src_index = parse_ident(current_scope);                      break;

        case _address:     src_index = parse_address(current_scope);                    break;
        case _fetch:       src_index = parse_fetch(current_scope);                      break;

        case _num_ptr:    src_index = parse_pointer(current_scope); break;
        case _mark_ptr:   src_index = parse_pointer(current_scope); break;
        case _deci_ptr:   src_index = parse_pointer(current_scope); break;
        case _decii_ptr:  src_index = parse_pointer(current_scope); break;

        case _den_ptr:    src_index = parse_pointer(current_scope); break;
        case _bay_ptr:    src_index = parse_pointer(current_scope); break;
        case _aisle_ptr:  src_index = parse_pointer(current_scope); break;
        case _zone_ptr:   src_index = parse_pointer(current_scope); break;
        
        case _dens_ptr:   src_index = parse_pointer(current_scope); break;
        case _bays_ptr:   src_index = parse_pointer(current_scope); break;
        case _aisles_ptr: src_index = parse_pointer(current_scope); break;
        case _zones_ptr:  src_index = parse_pointer(current_scope); break;
        default: 
        
        switch(current_architecture)
        {
            case 8:    src_index = get_den_reg();    break;
            case 16:   src_index = get_bay_reg();    break;
            case 32:   src_index = get_aisle_reg();  break;
            case 64:   src_index = get_zone_reg();   break;
            default:   break;
        } 
         break;
    }

    return src_index;  // Return the populated struct phrase
}
