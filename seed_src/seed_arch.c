#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"



void process_arch_16_section()
{
    arch_16(_arch_16_section, ".arch_16");


    scan(&Token);
    if(Token.token_rep == _origin)
    {
        origin(_origin, "origin");

        scan(&Token);
        colon(_colon, ":");

        scan(&Token);
        hex_literal(_hex_literal, Token.hex_value);

        scan(&Token);
        semicolon(_semicolon, ";");
    }
    else
    {
        reject_token(&Token);
    }
}

void process_arch_32_section()
{
    arch_32(_arch_32_section, ".arch_32");

}

void process_arch_64_section()
{
    arch_64(_arch_64_section, ".arch_64");

}