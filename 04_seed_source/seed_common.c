#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"

/*We try to create re usuable functions as much as possible. So these are the more common function that will used
thorughout the parsing of the problem.*/

int parse_num_literal()
{
    num_literal(_num_literal, Token.num_value); 
    snprintf(src, sizeof(src), "%d", Token.num_value); 

    return src;
}

int parse_ident(enum scope_type current_scope)
{
    int current_index = 0;

    ident(_ident, Text);                     // Token contains the identifier name in `Text`

    switch(current_scope)
    {
        case scope_universal:    current_index = search_universal_scope(Text);    break;  
        case scope_global:       current_index = search_global_scope(Text);       break;
        case scope_global_block: current_index = search_global_block_scope(Text); break;
        case scope_local:        current_index = search_local_scope(Text);        break;
        case scope_local_block:  current_index = search_local_block_scope(Text);  break;
        default: error("ident error: invalid ident token");                       break;
    }

    return current_index;
}