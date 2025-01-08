#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"


// Function to process the lend instruction
void process_lend_instruction(enum scope_type current_scope) 
{
    // Allocate and initialize the lend_op structure
    struct phrase lend_op;

    // Parse and set the numerical operation field
    num(_num, "num");

    scan(&Token);
    colon(_colon, ":");

    // Parse the hex value
    scan(&Token);
    hex_literal(_hex_literal, Token.hex_value);

    // Convert Token.hex_value to a string
    snprintf(lend_op.src_buffer, sizeof(lend_op.src_buffer), "%x", Token.hex_value);

    // Set the strand_op to the converted hex value string
    lend_op.strand_op = lend_op.src_buffer;

    // Encode the lend instruction using strand_op as the argument
    encode_lend_instruction(lend_op.strand_op);

    scan(&Token);
    semicolon(_semicolon, ";");
}