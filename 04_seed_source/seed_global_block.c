#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"



void process_global_block_label(int parent_global_id)
{
    global_block(_global_block, "global_block");

    scan(&Token);
    ident(_ident, Text);
    global_block_id = insert_global_block_scope(Text, scope_tool_none, scope_type_none);
    convert_global_block_label(Text);
    
    scan(&Token);
    colon(_colon, ":");

    while(1) 
    {
        scan(&Token);

        if(Token.token_rep == _end_section) 
        {
            process_end_section();
            convert_label_pass_arg();
            
            process_global_block_child_labels(global_block_id);
            return;
        }

        if(Token.token_rep == _enfi)
        {
            return;
        }

        process_sections(scope_global_block);
    }
}


void process_global_block_child_labels(int parent_global_id)   
{
    while(1)
    {
        scan(&Token);
        
        // Check for end conditions first
        if(Token.token_rep == _local || Token.token_rep == _end_section || Token.token_rep == _enfi)
        {
            reject_token(&Token);
            return;
        }

        if(Token.token_rep == _global_block)
        {
            process_global_block_label(parent_global_id);
        } 
    }
}
