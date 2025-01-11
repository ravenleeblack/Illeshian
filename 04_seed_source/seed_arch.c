#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"


/*nasm doest allow 8 bit arch so dont try the 8 bit in the source code otherwise it will fail. Only putting here
so I can have it for the re-write later. We want to set the arch first so that in later sections we can use it
to find the right sized registers and bytes. It should be cascading meaning that if we are in 64 then we have 64
bit options, 32 bit options, 16 bits options, and 8 bit options. If we are in 32 bit then we only have 32 bit, 
16 bit, and 8 bit options. If we are in 16 bit then 16 bit and 8 bit. 8 bit we only have 8 bit. The 8 bit im not
sure about yet but it does seem kind of cool to support so that we can use old code projects and have the option
to build 8 bit assembler and the likes from 8 bit and build up on it so that it makes it easier to learn things.*/
void process_arch_section(enum scope_type current_scope) 
{
    current_architecture = 0;
    
    switch(Token.token_rep)
    {
        case _arch_8_section: 
        arch_08(_arch_8_section, ".arch_8");             // match arch token
        current_architecture = 8;                       // Set architecture. 

        /*
        Need to figure out how to insert the arch for each label. So that the rest of the scope label block
        we can search for it and use it in the rest of the block.
        */

        switch(current_scope) {
            case scope_universal:     insert_universal_scope(Text, scope_arch_08_tool, scope_arch_08_type);     break;
            case scope_global:        insert_global_scope(Text, scope_arch_08_tool, scope_arch_08_type);        break;
            case scope_global_block:  insert_global_block_scope(Text, scope_arch_08_tool, scope_arch_08_type);  break;
            case scope_local:         insert_local_scope(Text, scope_arch_08_tool, scope_arch_08_type);         break;
            case scope_local_block:   insert_local_block_scope(Text, scope_arch_08_tool, scope_arch_08_type);   break;
            default: error("seeding error: Invalid scope for strand literal"); break;
        }
     
        encode_arch_instruction(current_architecture);  // send nasm the architecture
        process_origin();                               // process the origin if there is one
        break;

        case _arch_16_section:
        arch_16(_arch_16_section, ".arch_16");
        current_architecture = 16;

        switch(current_scope) {
            case scope_universal:     insert_universal_scope(Text, scope_arch_16_tool, scope_arch_16_type);     break;
            case scope_global:        insert_global_scope(Text, scope_arch_16_tool, scope_arch_16_type);        break;
            case scope_global_block:  insert_global_block_scope(Text, scope_arch_16_tool, scope_arch_16_type);  break;
            case scope_local:         insert_local_scope(Text, scope_arch_16_tool, scope_arch_16_type);         break;
            case scope_local_block:   insert_local_block_scope(Text, scope_arch_16_tool, scope_arch_16_type);   break;
            default: error("seeding error: Invalid scope for strand literal"); break;
        }

        encode_arch_instruction(current_architecture); 
        process_origin(); 
        break;

        case _arch_32_section:
        arch_32(_arch_32_section, ".arch_32");
        current_architecture = 32;

        switch(current_scope) {
            case scope_universal:     insert_universal_scope(Text, scope_arch_32_tool, scope_arch_32_type);     break;
            case scope_global:        insert_global_scope(Text, scope_arch_32_tool, scope_arch_32_type);        break;
            case scope_global_block:  insert_global_block_scope(Text, scope_arch_32_tool, scope_arch_32_type);  break;
            case scope_local:         insert_local_scope(Text, scope_arch_32_tool, scope_arch_32_type);         break;
            case scope_local_block:   insert_local_block_scope(Text, scope_arch_32_tool, scope_arch_32_type);   break;
            default: error("seeding error: Invalid scope for strand literal"); break;
        }

        encode_arch_instruction(current_architecture);
        process_origin(); 
        break;

        case _arch_64_section:
        arch_64(_arch_64_section, ".arch_64");
        current_architecture = 64;

        switch(current_scope) {
            case scope_universal:     insert_universal_scope(Text, scope_arch_64_tool, scope_arch_64_type);     break;
            case scope_global:        insert_global_scope(Text, scope_arch_64_tool, scope_arch_64_type);        break;
            case scope_global_block:  insert_global_block_scope(Text, scope_arch_64_tool, scope_arch_64_type);  break;
            case scope_local:         insert_local_scope(Text, scope_arch_64_tool, scope_arch_64_type);         break;
            case scope_local_block:   insert_local_block_scope(Text, scope_arch_64_tool, scope_arch_64_type);   break;
            default: error("seeding error: Invalid scope for strand literal"); break;
        }

        encode_arch_instruction(current_architecture); 
        process_origin();
        break;
        default: break;
    }
}

void process_origin() 
{
    scan(&Token);
    if (Token.token_rep == _origin) 
    {
        origin(_origin, "origin");

        scan(&Token);
        colon(_colon, ":");

        /*based off byte size we need to make sure the origin gets the right size address in hex. There is no 8 bit arch in nasm so it
        will be fun introducing it into the assembler after the initial bootstrap when we re-write seedling assembler translator into assembler.*/
        switch(current_architecture)
        {
            case 8:  scan(&Token); hex_literal(_hex_literal_08, Token.hex_value_08); break;
            case 16: scan(&Token); hex_literal(_hex_literal_16, Token.hex_value_16); break;
            case 32: scan(&Token); hex_literal(_hex_literal_32, Token.hex_value_32); break;
            case 64: scan(&Token); hex_literal(_hex_literal_64, Token.hex_value_64); break;
            default: break;
        }

        scan(&Token);
        semicolon(_semicolon, ";");
    } else {
        reject_token(&Token);
    }
}