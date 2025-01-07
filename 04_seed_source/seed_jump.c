#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"

/*here we have no byte size, so we just get the label, were jumping to*/
void process_jump_instruction(enum scope_type current_scope) 
{
    switch(Token.token_rep)
    {
        case _jump:           jump(_jump, "jump");                               break;
        case _jump_less:      jump_less(_jump_less, "jump_less");                break;
        case _jump_neg:       jump_neg(_jump_neg, "jump_neg");                   break;
        case _jump_great:     jump_great(_jump_great, "jump_great");             break;
        case _jump_equal:     jump_equal(_jump_equal, "jump_equal");             break;
        case _jump_not_equal: jump_not_equal(_jump_not_equal, "jump_not_equal"); break;
        default: break;
    }

    scan(&Token);
    colon(_colon, ":");

    scan(&Token);
    parse_ident(current_scope);
    encode_jump_instruction(Text);

    scan(&Token);
    semicolon(_semicolon, ";");
}





