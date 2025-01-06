#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"




void process_pass_arg_instruction(enum scope_type current_scope) 
{
    pass_arg(_pass_arg, "pass_arg");

    scan(&Token);
    colon(_colon, ":");

    scan(&Token);
    eax(_eax, "eax");

    scan(&Token);
    semicolon(_semicolon, ";");

    if (nasm_flag)
    {
        // Only generate ret for non-main functions
        if (!is_main_entry) {
           // fprintf(nasm_state.temp_text, "\tret\n");
        }
    }
}


