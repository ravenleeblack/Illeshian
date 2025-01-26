#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"

void process_local_label(int parent_global_id)
{
    local(_local, "local");

    scan(&Token);
    ident(_ident, Text);
    strcpy(local_to_local_block_buffer, Text);
    local_id = insert_local_scope(Text, scope_local_tool, scope_local_label);
    encode_local_label(Text);
        
    scan(&Token);
    colon(_colon, ":");

    process_sections(scope_local);

    process_local_child_labels(local_id);
}


void process_local_child_labels(int parent_global_id)   
{
    while(1)
    {
        scan(&Token);

        // Check for end conditions first
        if(Token.token_rep == _end_section || Token.token_rep == _enfi)
        {
            reject_token(&Token);
            return 0;
        }

        if(Token.token_rep == _local_block)     //the only thing allowed to be a child of a function or local is check, loop, set_loop, compare, state data tool unless its a assembly funciton so child blocks.
        {
            process_local_block_label(parent_global_id);
        }
    }
}