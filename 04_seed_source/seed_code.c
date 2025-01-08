#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"
#include "scope_table.h"
#include <stdio.h>

void process_code_section(enum scope_type current_scope) 
{
    code(_code_section, ".code");
   
    while(1) 
    {
        scan(&Token);
        
        switch(Token.token_rep) 
        {
            case _compare:     process_compare_instruction(current_scope );    break;
            case _set_flag:    process_set_flag_instruction(current_scope);    break;
            case _test:        process_test_instruction(current_scope);        break;
            case _num:         process_lend_instruction(current_scope);        break;
            case _call:        process_call_instruction(current_scope );       break;
            case _pass_arg:    process_pass_arg_instruction(current_scope);    break;

            case _add_den:   process_arith_instruction(current_scope); break;
            case _add_bay:   process_arith_instruction(current_scope); break;
            case _add_aisle: process_arith_instruction(current_scope); break;
            case _add_zone:  process_arith_instruction(current_scope); break;
    
            case _sub_den:   process_arith_instruction(current_scope); break;
            case _sub_bay:   process_arith_instruction(current_scope); break;
            case _sub_aisle: process_arith_instruction(current_scope); break;
            case _sub_zone:  process_arith_instruction(current_scope); break;

            case _mul_den:   process_arith_instruction(current_scope); break;
            case _mul_bay:   process_arith_instruction(current_scope); break;
            case _mul_aisle: process_arith_instruction(current_scope); break;
            case _mul_zone:  process_arith_instruction(current_scope); break;

            case _div_den:   process_arith_instruction(current_scope); break;
            case _div_bay:   process_arith_instruction(current_scope); break;
            case _div_aisle: process_arith_instruction(current_scope); break;
            case _div_zone:  process_arith_instruction(current_scope); break;

            /*push instructions by byte size*/
            case _push_den:    process_push_instruction(current_scope);  break;
            case _push_dens:   process_push_instruction(current_scope);  break;
            case _push_bay:    process_push_instruction(current_scope);  break;
            case _push_bays:   process_push_instruction(current_scope);  break;
            case _push_aisle:  process_push_instruction(current_scope);  break;
            case _push_aisles: process_push_instruction(current_scope);  break;
            case _push_zone:   process_push_instruction(current_scope);  break;
            case _push_zones:  process_push_instruction(current_scope);  break;
            
            case _pop_den:     process_pop_instruction(current_scope);    break;
            case _pop_dens:    process_pop_instruction(current_scope);    break;
            case _pop_bay:     process_pop_instruction(current_scope);    break;
            case _pop_bays:    process_pop_instruction(current_scope);    break;
            case _pop_aisle:   process_pop_instruction(current_scope);    break;
            case _pop_aisles:  process_pop_instruction(current_scope);    break;
            case _pop_zone:    process_pop_instruction(current_scope);    break;
            case _pop_zones:   process_pop_instruction(current_scope);    break;

            /*move instructions by byte size*/
            case _move_den:     process_move_instruction(current_scope);  break;
            case _move_dens:    process_move_instruction(current_scope);  break;
            case _move_bay:     process_move_instruction(current_scope);  break;
            case _move_bays:    process_move_instruction(current_scope);  break;
            case _move_aisle:   process_move_instruction(current_scope);  break;
            case _move_aisles:  process_move_instruction(current_scope);  break;
            case _move_zone:    process_move_instruction(current_scope);  break;
            case _move_zones:   process_move_instruction(current_scope);  break;

            /*push instructions by byte size*/
            case _jump:           process_jump_instruction(current_scope);  break;
            case _jump_less:      process_jump_instruction(current_scope);  break;
            case _jump_neg:       process_jump_instruction(current_scope);  break;
            case _jump_great:     process_jump_instruction(current_scope);  break;
            case _jump_equal:     process_jump_instruction(current_scope);  break;
            case _jump_not_equal: process_jump_instruction(current_scope);  break;

            case _end_section: reject_token(&Token); return 0;
            default: return 0;  
            //break out of the loop since we do not have a known token for this section
        }
    }
}