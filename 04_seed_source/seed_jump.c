#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"


void process_jump_instruction(enum scope_type current_scope) 
{
    jump(_jump, "jump");

    scan(&Token);
    colon(_colon, ":");

    scan(&Token);
    ident(_ident, Text);

    switch(current_scope)
    {
        case scope_universal:    entry_index = search_universal_scope(Text);    break;  
        case scope_global:       entry_index = search_global_scope(Text);       break;
        case scope_global_block: entry_index = search_global_block_scope(Text); break;
        case scope_local:        entry_index = search_local_scope(Text);        break;
        case scope_local_block:  entry_index = search_local_block_scope(Text);  break;
        default: error("seeding error: assign error: Invalid scope");           break;
    }
    encode_jump_instruction(Text);

    scan(&Token);
    semicolon(_semicolon, ";");
}

void process_jump_less_instruction(enum scope_type current_scope) 
{
    jump_less(_jump_less, "jump_less");

    scan(&Token);
    colon(_colon, ":");

    scan(&Token);
    ident(_ident, Text);

    switch(current_scope)
    {
        case scope_universal:    entry_index = search_universal_scope(Text);    break;  
        case scope_global:       entry_index = search_global_scope(Text);       break;
        case scope_global_block: entry_index = search_global_block_scope(Text); break;
        case scope_local:        entry_index = search_local_scope(Text);        break;
        case scope_local_block:  entry_index = search_local_block_scope(Text);  break;
        default: error("seeding error: assign error: Invalid scope");           break;
    }
    encode_jump_less_instruction(Text);

    scan(&Token);
    semicolon(_semicolon, ";");

}


void process_jump_neg_instruction(enum scope_type current_scope) 
{
    jump_neg(_jump_neg, "jump_neg");

    scan(&Token);
    colon(_colon, ":");

    scan(&Token);
    ident(_ident, Text);

    switch(current_scope)
    {
        case scope_universal:    entry_index = search_universal_scope(Text);    break;  
        case scope_global:       entry_index = search_global_scope(Text);       break;
        case scope_global_block: entry_index = search_global_block_scope(Text); break;
        case scope_local:        entry_index = search_local_scope(Text);        break;
        case scope_local_block:  entry_index = search_local_block_scope(Text);  break;
        default: error("seeding error: assign error: Invalid scope");           break;
    }
    encode_jump_neg_instruction(Text);

    scan(&Token);
    semicolon(_semicolon, ";");

}

void process_jump_great_instruction() 
{

}   

void process_jump_equal_instruction() 
{

}

void process_jump_not_equal_instruction() 
{

}





