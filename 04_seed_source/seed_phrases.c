#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"

/*functions to retrieve the first and second operand or phrase of an instruction during parsing. We create re-usuable functions like this
to cut down on code, provide better readability, and useablity.Not all instructions have two operand or phrases like the move instruction
so this allows us to be versitile as well.*/

phrase_retrievel parse_first_phrase(enum scope_type current_scope, int current_architecture)
{
    phrase_retrievel dest_result;

    switch (Token.token_rep)
    {
        case _ident:       dest_result = parse_search_ident(current_scope);  break;

        case _num_value: dest_result = parse_num_literal(current_scope); break;
        case _hex_value: dest_result = parse_hex_literal(current_scope, current_architecture); break;
        
        case _address:     dest_result = parse_address(current_scope, current_architecture);                    break;
        case _fetch:       dest_result = parse_fetch(current_scope);                      break;

        case _num_ptr:    dest_result = parse_pointer(current_scope); break;
        case _mark_ptr:   dest_result = parse_pointer(current_scope); break;
        case _deci_ptr:   dest_result = parse_pointer(current_scope); break;
        case _decii_ptr:  dest_result = parse_pointer(current_scope); break;

        case _den_ptr:    dest_result = parse_pointer(current_scope); break;
        case _bay_ptr:    dest_result = parse_pointer(current_scope); break;
        case _aisle_ptr:  dest_result = parse_pointer(current_scope); break;
        case _zone_ptr:   dest_result = parse_pointer(current_scope); break;
        
        case _dens_ptr:   dest_result = parse_pointer(current_scope); break;
        case _bays_ptr:   dest_result = parse_pointer(current_scope); break;
        case _aisles_ptr: dest_result = parse_pointer(current_scope); break;
        case _zones_ptr:  dest_result = parse_pointer(current_scope); break;
        default: 
        
        dest_result.type = phrase_register;   // Set the operand type

        switch(current_architecture)
        {
            case 8:    dest_result.phrase_reg_value = get_den_reg();    break;
            case 16:   dest_result.phrase_reg_value = get_bay_reg();    break;
            case 32:   dest_result.phrase_reg_value = get_aisle_reg();  break;
            case 64:   dest_result.phrase_reg_value = get_zone_reg();   break;
            default:   break;
        } 
         break;
    }

    return dest_result;  // Return the populated struct phrase
}

phrase_retrievel parse_second_phrase(enum scope_type current_scope, int current_architecture)
{
    phrase_retrievel src_result;

    switch (Token.token_rep)
    {
        case _ident:     src_result = parse_search_ident(current_scope);  break;

        case _num_value: src_result = parse_num_literal(current_scope); break;
        case _hex_value: src_result = parse_hex_literal(current_scope, current_architecture); break;

        case _address:    src_result = parse_address(current_scope, current_architecture);   break;
        case _fetch:      src_result = parse_fetch(current_scope);  break;

        case _num_ptr:    src_result = parse_pointer(current_scope); break;
        case _mark_ptr:   src_result = parse_pointer(current_scope); break;
        case _deci_ptr:   src_result = parse_pointer(current_scope); break;
        case _decii_ptr:  src_result = parse_pointer(current_scope); break;

        case _den_ptr:    src_result = parse_pointer(current_scope); break;
        case _bay_ptr:    src_result = parse_pointer(current_scope); break;
        case _aisle_ptr:  src_result = parse_pointer(current_scope); break;
        case _zone_ptr:   src_result = parse_pointer(current_scope); break;
        
        case _dens_ptr:   src_result = parse_pointer(current_scope); break;
        case _bays_ptr:   src_result = parse_pointer(current_scope); break;
        case _aisles_ptr: src_result = parse_pointer(current_scope); break;
        case _zones_ptr:  src_result = parse_pointer(current_scope); break;
        default: 
        
        src_result.type = phrase_register;   // Set the operand type

        switch(current_architecture)
        {
            case 8:    src_result.phrase_reg_value = get_den_reg();    break;
            case 16:   src_result.phrase_reg_value = get_bay_reg();    break;
            case 32:   src_result.phrase_reg_value = get_aisle_reg();  break;
            case 64:   src_result.phrase_reg_value = get_zone_reg();   break;
            default:   break;
        } 
         break;
    }

    return src_result;  // Return the populated struct phrase
}