#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"


void process_global_label(void)
{
    global(_global, "global");

    scan(&Token);
    ident(_ident, Text);
    strcpy(global_to_local_buffer, Text);
    strcpy(global_to_global_block_buffer, Text);
    global_id = insert_global_scope(Text, scope_global_tool, scope_global_label);        // Add to scope table and save label
    encode_global_label(Text);
    
        // Set flag if this is main label
    if((strcmp(Text, "main") == 0))
    {
        is_main_entry = 1;
    }

    scan(&Token);
    colon(_colon, ":");

    process_sections(scope_global);

    process_global_child_labels(global_id);
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
            return 0;
        }
    }
}

/*There is alot going on here. We match the global scope keyword, then scan for our label name 
which is the ident, we insert into scope table so we can use later, we pass the ident over to 
nasm output function so that it can have the global label. Here we check if its the main label.
The reason fo this is so that we know when to use yield for the main when returning or pass_arg
for non main globals. In illeshian and seedling the main entry always returns to the os so main
is the only one that yields. Next we the end colon then begin parsing the sections again and 
breaking when end_section is found. THe difference here is that we add to add a function that
checks if the global label has any children. If it does then we process them otherwise we return.
Since we allow 2 kinds of scope in the body of global scope, we now have 2 options here, that we
need to parse. The difference here is in illeshian the body of check, loop, set_loop, compare, 
and state are global block scope if its parent is global. In Seedling this means that we jump to
the global block labels. These are relational tools that do not ness need a dedicated stack. So
we jump to a global block label and handle business. Next we have a local label. In illeshian 
local labels are for child functions and since we have a function we do need a stack this time.
So we make a call to local labels. So both global block and local scope are children scope labels
of global.FInally if we hit a end_section or enfi then we break out of the loop that processes
children scope labels. */