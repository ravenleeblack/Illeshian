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
    encode_pass_arg_label();

    scan(&Token);
    semicolon(_semicolon, ";");
}


