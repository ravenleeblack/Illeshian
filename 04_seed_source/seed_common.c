#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"

/*We try to create re usuable functions as much as possible. So these are the more common function that will used
thorughout the parsing of the problem.*/


// Parses a numeric literal and returns a struct phrase containing the value.
char *parse_num_literal() {
    char *num_op;
    
    // match the number literal
    num_literal(_num_literal, Token.num_value);

    // Check if num_str has been populated with the correct value
    num_op = Token.string_value; // This points to the number string in num_str buffer, could have used Token.string_value I think because it got put into token struct.

    // Ensure the string is not empty or null before returning
    if (num_op == NULL || *num_op == '\0') {
        error("Number string is empty or null");
        return NULL;  // Or handle error as appropriate
    }

    strcpy(pass_buffer, num_op);  // Copy the number string to the pass buffer
    // Return the allocated and populated struct
    return pass_buffer;
}

char *parse_ident(enum scope_type current_scope)
{
    char *ident_op;

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