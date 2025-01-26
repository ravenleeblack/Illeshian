#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"

/*Here we can either call another global label or we can call another global's child which is local. If
we call another global then the synatx is call parent_label; if we call another globals child then the synatx
is call parent_label.child_label;  where the period is an accesser to the child.*/
void process_call_instruction(enum scope_type current_scope)
{
    call(_call, "call");
    
    scan(&Token);
    ident(_ident, Text);
    strcpy(manager_call_buffer, Text);

    switch (current_scope)
    {
        case scope_universal:    search_universal_scope(Text);    break;
        case scope_global:       search_global_scope(Text);       break;
        case scope_global_block: search_global_block_scope(Text); break;
        case scope_local:        search_local_scope(Text);        break;
        case scope_local_block:  search_local_block_scope(Text);  break;
        default: error("ident error: invalid ident token"); break;
    }

    scan(&Token);
    if(Token.token_rep == _period)
    {
        period(_period, ".");

        scan(&Token);
        ident(_ident, Text);
        strcpy(function_call_buffer, Text);

        switch (current_scope)
        {
            case scope_universal:    search_universal_scope(Text);    break;
            case scope_global:       search_global_scope(Text);       break;
            case scope_global_block: search_global_block_scope(Text); break;
            case scope_local:        search_local_scope(Text);        break;
            case scope_local_block:  search_local_block_scope(Text);  break;
            default: error("ident error: invalid ident token"); break;
        }

        encode_call_function_instruction(function_call_buffer);
    }
    else if(Token.token_rep != _period)
    {
        encode_call_manager_instruction(manager_call_buffer);
        reject_token(&Token);                     //If it was not a period then we reject it.
    }

    scan(&Token);
    semicolon(_semicolon, ";");
}
