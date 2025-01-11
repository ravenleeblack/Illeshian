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

    //we use common parse_ident function when we need to search an ident. Since we want to insert we manually create it. With a jump data tool
    //we normally wont know the label before hand, so we have to insert it into the scope table. WE cant use search for encode_jump_instruction()
    //because the label we want to jump hasnt been inserted into the scope table yet. So using parse_ident() would return an empty ident for the 
    //jump label in the nasm output.
    scan(&Token);
    ident(_ident, Text);    

    switch(current_scope) {
        case scope_universal:     insert_universal_scope(Text, scope_jump_tool, scope_jump_type);     break;
        case scope_global:        insert_global_scope(Text, scope_jump_tool, scope_jump_type);        break;
        case scope_global_block:  insert_global_block_scope(Text, scope_jump_tool, scope_jump_type);  break;
        case scope_local:         insert_local_scope(Text, scope_jump_tool, scope_jump_type);         break;
        case scope_local_block:   insert_local_block_scope(Text, scope_jump_tool, scope_jump_type);   break;
        default: error("seeding error: Invalid scope for strand literal"); break;
    }
    encode_jump_instruction(Text);

    scan(&Token);
    semicolon(_semicolon, ";");
}





