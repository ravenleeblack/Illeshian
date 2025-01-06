#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"


void process_call_instruction(enum scope_type scope)
{
    call(_call, "call");
    
    scan(&Token);
    ident(_ident, Text);     /// get a global label

    switch(scope) {
        case scope_universal:     search_universal_scope(Text);     break;
        case scope_global:        search_global_scope(Text);        break;
        case scope_global_block:  search_global_block_scope(Text);  break;
        case scope_local:         search_local_scope(Text);         break;
        case scope_local_block:   search_local_block_scope(Text);   break;
        default: error("seeding error: Invalid scope for strand literal"); break;
    }
    strcpy(dest, Text);

    scan(&Token);
    if(Token.token_rep == _period)
    {
        period(_period, ".");

        scan(&Token);
        ident(_ident, Text);      //get a local label

        switch(scope) {
            case scope_universal:     search_universal_scope(Text);     break;
            case scope_global:        search_global_scope(Text);        break;
            case scope_global_block:  search_global_block_scope(Text);  break;
            case scope_local:         search_local_scope(Text);         break;
            case scope_local_block:   search_local_block_scope(Text);   break;
            default: error("seeding error: Invalid scope for strand literal"); break;
        }
        strcpy(src, Text);
        encode_call_function_instruction(dest, src);
    }
    else
    {
        encode_call_manager_instruction(dest);
        reject_token(&Token);
    }

    scan(&Token);
    semicolon(_semicolon, ";");
}
