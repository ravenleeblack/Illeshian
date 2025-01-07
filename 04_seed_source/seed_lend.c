#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"

void process_lend_instruction(enum scope_type current_scope) 
{
    num(_num, "num");
                
    scan(&Token);
    colon(_colon, ":");

    scan(&Token);
    hex_literal(_hex_literal, Token.hex_value);
    encode_lend_instruction(Text);
          
    scan(&Token);
    semicolon(_semicolon, ";");
}