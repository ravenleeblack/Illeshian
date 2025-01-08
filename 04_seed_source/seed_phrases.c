#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"

/*functions to retrieve the first and second operand or phrase of an instruction during parsing. We create re-usuable functions like this
to cut down on code, provide better readability, and useablity.Not all instructions have two operand or phrases like the move instruction
so this allows us to be versitile as well.*/

struct phrase *parse_first_phrase(enum scope_type current_scope, int get_reg_by_type)
{
   struct phrase * get_op;

    switch (Token.token_rep)
    {
        case _num_literal: get_op = parse_num_literal(current_scope);                break;
        case _ident:       get_op = parse_ident(current_scope);                      break;

        case _address:     get_op = parse_address(current_scope);                    break;
        case _fetch:       get_op = parse_fetch(current_scope);                      break;

        case _num_ptr:    get_op = parse_pointer(current_scope); break;
        case _mark_ptr:   get_op = parse_pointer(current_scope); break;
        case _deci_ptr:   get_op = parse_pointer(current_scope); break;
        case _decii_ptr:  get_op = parse_pointer(current_scope); break;

        case _den_ptr:    get_op = parse_pointer(current_scope); break;
        case _bay_ptr:    get_op = parse_pointer(current_scope); break;
        case _aisle_ptr:  get_op = parse_pointer(current_scope); break;
        case _zone_ptr:   get_op = parse_pointer(current_scope); break;
      
        case _dens_ptr:   get_op = parse_pointer(current_scope); break;
        case _bays_ptr:   get_op = parse_pointer(current_scope); break;
        case _aisles_ptr: get_op = parse_pointer(current_scope); break;
        case _zones_ptr:  get_op = parse_pointer(current_scope); break;
        default: break;
    }
    
    /* Handle register type switch */
    switch (get_reg_by_type)
    {
        case _get_den_reg:   get_op = get_den_reg();    break;
        case _get_bay_reg:   get_op = get_bay_reg();    break;
        case _get_aisle_reg: get_op = get_aisle_reg();  break;
        case _get_zone_reg:  get_op = get_zone_reg();   break;
        default: break;
    }
    return get_op;  // Return the populated struct phrase
}

struct phrase *parse_second_phrase(enum scope_type current_scope, int get_reg_by_type)
{
   struct phrase * get_op;

    switch (Token.token_rep)
    {
        case _num_literal: get_op = parse_num_literal(current_scope);                break;
        case _ident:       get_op = parse_ident(current_scope);                      break;

        case _address:     get_op = parse_address(current_scope);                    break;
        case _fetch:       get_op = parse_fetch(current_scope);                      break;

        case _num_ptr:    get_op = parse_pointer(current_scope); break;
        case _mark_ptr:   get_op = parse_pointer(current_scope); break;
        case _deci_ptr:   get_op = parse_pointer(current_scope); break;
        case _decii_ptr:  get_op = parse_pointer(current_scope); break;

        case _den_ptr:    get_op = parse_pointer(current_scope); break;
        case _bay_ptr:    get_op = parse_pointer(current_scope); break;
        case _aisle_ptr:  get_op = parse_pointer(current_scope); break;
        case _zone_ptr:   get_op = parse_pointer(current_scope); break;
      
        case _dens_ptr:   get_op = parse_pointer(current_scope); break;
        case _bays_ptr:   get_op = parse_pointer(current_scope); break;
        case _aisles_ptr: get_op = parse_pointer(current_scope); break;
        case _zones_ptr:  get_op = parse_pointer(current_scope); break;
        default: break;
    }
    
    /* Handle register type switch */
    switch (get_reg_by_type)
    {
        case _get_den_reg:   get_op = get_den_reg();    break;
        case _get_bay_reg:   get_op = get_bay_reg();    break;
        case _get_aisle_reg: get_op = get_aisle_reg();  break;
        case _get_zone_reg:  get_op = get_zone_reg();   break;
        default: break;
    }
    return get_op;  // Return the populated struct phrase
}
