#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"

/*functions to retrieve the first and second operand or phrase of an instruction during parsing. We create re-usuable functions like this
to cut down on code, provide better readability, and useablity.Not all instructions have two operand or phrases like the move instruction
so this allows us to be versitile as well.*/

int parse_first_phrase(enum scope_type current_scope, int get_reg_by_type)
{
    int data_type = 0;

    switch (Token.token_rep)
    {
        case _num_literal: data_type = parse_num_literal(); break;
        case _ident:       data_type = parse_ident(current_scope); break;
        case _address:     data_type = parse_address(current_scope); break;
        case _fetch:       data_type = parse_fetch(current_scope); break;
        case _den_ptr:
        case _bay_ptr:
        case _aisle_ptr:
        case _zone_ptr:  data_type = parse_type(current_scope); break;
        default: break;
    }

    /* Handle register type switch */
    switch (get_reg_by_type)
    {
        case _get_den_reg:   get_den_reg(); break;
        case _get_bay_reg:   get_bay_reg(); break;
        case _get_aisle_reg: get_aisle_reg(); break;
        case _get_zone_reg:  get_zone_reg(); break;
        default: break;
    }

    return data_type;
}

int parse_second_phrase(enum scope_type current_scope, int get_reg_by_type)
{
    int data_type = 0;

    switch (Token.token_rep)
    {
        case _num_literal: data_type = parse_num_literal(); break;
        case _ident:       data_type = parse_ident(current_scope); break;
        case _address:     data_type = parse_address(current_scope); break;
        case _fetch:       data_type = parse_fetch(current_scope); break;
        case _den_ptr:
        case _bay_ptr:
        case _aisle_ptr:
        case _zone_ptr:  data_type = parse_type(current_scope); break;
        default: break;
    }

    /* Handle register type switch */
    switch (get_reg_by_type)
    {
        case _get_den_reg:   get_den_reg(); break;
        case _get_bay_reg:   get_bay_reg(); break;
        case _get_aisle_reg: get_aisle_reg(); break;
        case _get_zone_reg:  get_zone_reg(); break;
        default: break;
    }

    return data_type;
}
