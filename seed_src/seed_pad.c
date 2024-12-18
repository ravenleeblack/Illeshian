#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"



void process_pad_section()
{
    pad_section(_pad_section, ".pad");

    
    while(1) 
    {
        scan(&Token);
        
        // If not load or sign, break out
        if(Token.token_rep != _load && Token.token_rep != _sign)
        {
            reject_token(&Token);
            break;
        }
        
        // Process load directive
        if(Token.token_rep == _load)
        {
            load(_load, "load");
            scan(&Token);
            colon(_colon, ":");
            scan(&Token);
            num_literal(_num_literal, Token.num_value);
            scan(&Token);
            semicolon(_semicolon, ";");
        }
        
        // Process sign directive
        if(Token.token_rep == _sign)
        {
            sign(_sign, "sign");
            scan(&Token);
            colon(_colon, ":");
            scan(&Token);
            hex_literal(_hex_literal, Token.hex_value);
            scan(&Token);
            semicolon(_semicolon, ";");
        }
    }
}