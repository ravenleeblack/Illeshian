#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"

int global_architecture = 0;
/*nasm doest allow 8 bit arch so dont try the 8 bit in the source code otherwise it will fail. Only putting here
so I can have it for the re-write later. We want to set the arch first so that in later sections we can use it
to find the right sized registers and bytes. It should be cascading meaning that if we are in 64 then we have 64
bit options, 32 bit options, 16 bits options, and 8 bit options. If we are in 32 bit then we only have 32 bit, 
16 bit, and 8 bit options. If we are in 16 bit then 16 bit and 8 bit. 8 bit we only have 8 bit. The 8 bit im not
sure about yet but it does seem kind of cool to support so that we can use old code projects and have the option
to build 8 bit assembler and the likes from 8 bit and build up on it so that it makes it easier to learn things.*/
int process_arch_section(enum scope_type current_scope) 
{
    current_architecture = 0;
    
    switch(Token.token_rep)
    {
        case _arch_8_section:   arch_08(_arch_8_section, "arch_8");    current_architecture = 8;   break;
        case _arch_16_section:  arch_16(_arch_16_section, "arch_16");  current_architecture = 16;  break;
        case _arch_32_section:  arch_32(_arch_32_section, "arch_32");  current_architecture = 32;  break;
        case _arch_64_section:  arch_64(_arch_64_section, "arch_64");  current_architecture = 64;  break;
        default: break;
    }

    scan(&Token);
    period(_period, ".");
    
    scan(&Token);
    end(_end, "end");

    global_architecture = current_architecture;
    return global_architecture;
}

//encode_arch_instruction(current_architecture);  //process_origin(); 

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
 

        scan(&Token);
        semicolon(_semicolon, ";");
    } else {
        reject_token(&Token);
    }
}