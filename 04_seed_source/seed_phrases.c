#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"

/*functions to retrieve the first and second operand or phrase of an instruction during parsing. We create re-usuable functions like this
to cut down on code, provide better readability, and useablity.Not all instructions have two operand or phrases like the move instruction
so this allows us to be versitile as well.*/

phrase_retrievel parse_first_phrase(enum scope_type current_scope, int current_architecture)
{
    phrase_retrievel result;

    switch (Token.token_rep)
    {
        case _num_literal: result = parse_num_literal(current_scope);                break;
        case _hex_literal_08: result = parse_hex_literal(current_architecture);                break;
        case _hex_literal_16: result = parse_hex_literal(current_architecture);                break;
        case _hex_literal_32: result = parse_hex_literal(current_architecture);                break;
        case _hex_literal_64: result = parse_hex_literal(current_architecture);                break;
        case _ident:       result = parse_ident(current_scope);                      break;

        case _address:     result = parse_address(current_scope);                    break;
        case _fetch:       result = parse_fetch(current_scope);                      break;

        case _num_ptr:    result = parse_pointer(current_scope); break;
        case _mark_ptr:   result = parse_pointer(current_scope); break;
        case _deci_ptr:   result = parse_pointer(current_scope); break;
        case _decii_ptr:  result = parse_pointer(current_scope); break;

        case _den_ptr:    result = parse_pointer(current_scope); break;
        case _bay_ptr:    result = parse_pointer(current_scope); break;
        case _aisle_ptr:  result = parse_pointer(current_scope); break;
        case _zone_ptr:   result = parse_pointer(current_scope); break;
        
        case _dens_ptr:   result = parse_pointer(current_scope); break;
        case _bays_ptr:   result = parse_pointer(current_scope); break;
        case _aisles_ptr: result = parse_pointer(current_scope); break;
        case _zones_ptr:  result = parse_pointer(current_scope); break;
        default: 
        
        result.type = phrase_register;   // Set the operand type
        switch(current_architecture)
        {
            case 8:    result.phrase = get_den_reg();    break;
            case 16:   result.phrase = get_bay_reg();    break;
            case 32:   result.phrase = get_aisle_reg();  break;
            case 64:   result.phrase = get_zone_reg();   break;
            default:   break;
        } 
         break;
    }

    return result;  // Return the populated struct phrase
}

phrase_retrievel parse_second_phrase(enum scope_type current_scope, int current_architecture)
{
    phrase_retrievel result;

    switch (Token.token_rep)
    {
        case _num_literal: result = parse_num_literal(current_scope);                break;
        case _hex_literal_08: result = parse_hex_literal(current_architecture);                break;
        case _hex_literal_16: result = parse_hex_literal(current_architecture);                break;
        case _hex_literal_32: result = parse_hex_literal(current_architecture);                break;
        case _hex_literal_64: result = parse_hex_literal(current_architecture);                break;
        case _ident:       result = parse_ident(current_scope);                      break;

        case _address:     result = parse_address(current_scope);                    break;
        case _fetch:       result = parse_fetch(current_scope);                      break;

        case _num_ptr:    result = parse_pointer(current_scope); break;
        case _mark_ptr:   result = parse_pointer(current_scope); break;
        case _deci_ptr:   result = parse_pointer(current_scope); break;
        case _decii_ptr:  result = parse_pointer(current_scope); break;

        case _den_ptr:    result = parse_pointer(current_scope); break;
        case _bay_ptr:    result = parse_pointer(current_scope); break;
        case _aisle_ptr:  result = parse_pointer(current_scope); break;
        case _zone_ptr:   result = parse_pointer(current_scope); break;
        
        case _dens_ptr:   result = parse_pointer(current_scope); break;
        case _bays_ptr:   result = parse_pointer(current_scope); break;
        case _aisles_ptr: result = parse_pointer(current_scope); break;
        case _zones_ptr:  result = parse_pointer(current_scope); break;
        default: 
        
        result.type = phrase_register;   // Set the operand type
        switch(current_architecture)
        {
            case 8:    result.phrase = get_den_reg();    break;
            case 16:   result.phrase = get_bay_reg();    break;
            case 32:   result.phrase = get_aisle_reg();  break;
            case 64:   result.phrase = get_zone_reg();   break;
            default:   break;
        } 
         break;
    }

    return result;  // Return the populated struct phrase
}