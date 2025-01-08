#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"

/*We try to create re usuable functions as much as possible. So these are the more common function that will used
thorughout the parsing of the problem.*/

// Parses a numeric literal and returns a struct phrase containing the value.
struct phrase *parse_num_literal()
{
    // Allocate memory for num_op
    struct phrase *num_op = (struct phrase *)malloc(sizeof(struct phrase));
    if (num_op == NULL)
    {
        return NULL; // Return NULL if allocation fails
    }

    // match the number literal
    num_literal(_num_literal, Token.num_value);

    // Assign the number value to num_op->num_value
    num_op->num_value = Token.num_value;

    // Return the allocated and populated struct
    return num_op;
}

struct phrase *parse_ident(enum scope_type current_scope)
{
    struct phrase *ident_op;

    ident(_ident, Text);  // Token contains the identifier name in `Text`

    switch (current_scope)
    {
        case scope_universal:    ident_op = search_universal_scope(Text);    break;
        case scope_global:       ident_op = search_global_scope(Text);       break;
        case scope_global_block: ident_op = search_global_block_scope(Text); break;
        case scope_local:        ident_op = search_local_scope(Text);        break;
        case scope_local_block:  ident_op = search_local_block_scope(Text);  break;
        default: error("ident error: invalid ident token"); break;
    }

    return ident_op;
}