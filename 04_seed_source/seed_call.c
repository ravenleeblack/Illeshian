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
    parse_ident(current_scope);
    strcpy(dest, Text);

    scan(&Token);
    if(Token.token_rep == _period)
    {
        period(_period, ".");

        scan(&Token);
        parse_ident(current_scope);
        strcpy(src, Text);
        encode_call_function_instruction(dest, src);
    }
    else
    {
        encode_call_manager_instruction(dest);
        reject_token(&Token);                     //If it was not a period then we reject it.
    }

    scan(&Token);
    semicolon(_semicolon, ";");
}
