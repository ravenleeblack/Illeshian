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
        
        if(Token.token_rep == _end_section)
        {
            reject_token(&Token);
            break;
        }

        switch(Token.token_rep) 
        {
            case _push_radule: process_push_radule_instruction(current_scope); break;
            case _pop_radule:  process_pop_radule_instruction(current_scope);  break;
            case _push:        process_push_instruction(current_scope);        break;
            case _pop:         process_pop_instruction(current_scope);         break;
            case _move_aisle:  
                process_move_instruction(current_scope);
                fprintf(stderr, "Debug: Processing MOVE_AISLE instruction\n");
                break;
            case _compare:     process_compare_instruction(current_scope );    break;
            case _call:        process_call_instruction(current_scope );       break;

            case _jump:        process_jump_instruction(current_scope);        break;
            case _jump_less:   process_jump_less_instruction(current_scope);   break;
            case _jump_neg:    process_jump_neg_instruction(current_scope);    break;

            case _pass_arg:    process_pass_arg_instruction(current_scope);    break;
            case _set_flag:    
                process_set_flag_instruction(current_scope);
                fprintf(stderr, "Debug: Processing SET_FLAG instruction\n");
                break;
            case _test:        process_test_instruction(current_scope);        break;
            case _num:         
                process_lend_instruction(current_scope);
                fprintf(stderr, "Debug: Processing NUM instruction with value 0x%X\n", Token.num_value);
                break;

            default:
                fprintf(stderr, "Unknown token: %d\n", Token.token_rep);
                break;
        }
    }
}