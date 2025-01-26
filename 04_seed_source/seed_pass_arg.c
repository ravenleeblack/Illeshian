#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"


void process_pass_arg_instruction(enum scope_type current_scope) 
{
    phrase_retrievel src_index;

    pass_arg(_pass_arg, "pass_arg");

    scan(&Token);
    colon(_colon, ":");

    scan(&Token);
    if(Token.token_rep == _num_value)
    {
        src_index = parse_num_literal(current_scope);
    }
    else
    {
        eax(_eax, "eax");
        src_index = get_undetermined_reg();
        encode_pass_arg_label();
    }

    scan(&Token);
    semicolon(_semicolon, ";");
}


