#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"


void process_global_label(void)
{
    global(_global, "global");

    scan(&Token);
    ident(_ident, Text);
    global_id = insert_global_scope(Text, scope_tool_manager, scope_type_none);        // Add to scope table and save label
    encode_global_scope_section(nasm_out, Text, scope_global);
    
    // Set flag if this is main label
    if((strcmp(Text, "main") == 0))
    {
        is_main_entry = 1;
    }

    scan(&Token);
    colon(_colon, ":");

    while(1)
    {
        scan(&Token);

        if(Token.token_rep == _end_section)
        {
            process_end_section();
            process_global_child_labels(global_id);
            return;
        }
        if(Token.token_rep == _enfi)
        {
            return;
        }

        process_sections(scope_global);
    }
}

void process_global_child_labels(int parent_global_id)
{
    while(1)
    {
        scan(&Token);
        
        
        switch(Token.token_rep)
        {
            case _local:        process_local_label(parent_global_id);        break;
            case _global_block: process_global_block_label(parent_global_id); break;
            default: break;
        }

        // Check for end conditions first
        if(Token.token_rep == _end_section || Token.token_rep == _enfi)
        {
            reject_token(&Token);
            return;
        }
    }
}