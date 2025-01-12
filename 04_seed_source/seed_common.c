#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"

/*We try to create re usuable functions as much as possible. So these are the more common function that will used
thorughout the parsing of the problem.*/


// Parses a numeric literal and returns a struct phrase containing the value.
phrase_retrievel parse_num_literal()
{
    phrase_retrievel result;
    result.type = phrase_number; // Set the operand type

    // match the number literal
    num_literal(_num_literal, Token.num_value);
    result.phrase_value = Token.num_value; 

    return result;
}

phrase_retrievel parse_hex_literal(int current_architecture)
{
    phrase_retrievel result;
    result.type = phrase_hex; // Set the operand type

    switch(current_architecture)
    {
        case 8:    
        hex_literal(_hex_literal_08, Token.hex_value_08); 
        result.phrase_value = Token.hex_value_08; 
        break;
        case 16:   
        hex_literal(_hex_literal_16, Token.hex_value_16);
        result.phrase_value = Token.hex_value_16; 
        break;
        case 32:   
        hex_literal(_hex_literal_32, Token.hex_value_32);
        result.phrase_value = Token.hex_value_32;  
        break;
        case 64:   
        hex_literal(_hex_literal_64, Token.hex_value_64);
        result.phrase_value = Token.hex_value_64; 
        break;
        default:   break;
    }  
    return result;
}

phrase_retrievel parse_ident(enum scope_type current_scope)
{
    phrase_retrievel result;
    result.type = phrase_ident; // Set the operand type

    ident(_ident, Text);  // Token contains the identifier name in `Text`
    result.phrase = Text;

    switch (current_scope)
    {
        case scope_universal:    search_universal_scope(Text);    break;
        case scope_global:       search_global_scope(Text);       break;
        case scope_global_block: search_global_block_scope(Text); break;
        case scope_local:        search_local_scope(Text);        break;
        case scope_local_block:  search_local_block_scope(Text);  break;
        default: error("ident error: invalid ident token"); break;
    }

    return result;
}


void process_increment_instruction(enum scope_type current_scope) 
{
    phrase_retrievel src_index;
    
    switch(Token.token_rep)
    {
        case _inc_den:     inc_den(_inc_den, "increment");      current_architecture = 8;   break;
        case _inc_dens:    inc_bay(_inc_dens, "add_bay");       current_architecture = 16;  break;
        case _inc_bay:     inc_aisle(_inc_bay, "add_aisle");    current_architecture = 32;  break;
        case _inc_bays:    inc_zone(_inc_bays, "add_zone");     current_architecture = 64;  break;
    
        case _inc_aisle:   inc_dens(_inc_aisle, "sub_den");     current_architecture = 8;   break;
        case _inc_aisles:  inc_bays(_inc_aisles, "sub_bay");    current_architecture = 16;  break;
        case _inc_zone:    inc_aisles(_inc_zone, "sub_aisle");  current_architecture = 32;  break;
        case _inc_zones:   inc_zones(_inc_zones, "sub_zone");   current_architecture = 64;  break;
        default: break;
    }

    scan(&Token);
    colon(_colon, ":");

    scan(&Token);        
    src_index = parse_first_phrase(current_scope, current_architecture);           // Handle destination operand or destination phrase
    
    encode_increment_instruction(src_index);

    scan(&Token);
    semicolon(_semicolon, ";"); 
}