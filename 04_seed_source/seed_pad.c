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
            switch(current_architecture)
            {
                case 8:    
                hex_literal(_hex_literal_08, Token.hex_value_08); 
                //snprintf(lend_op.src_buffer, sizeof(lend_op.src_buffer), "%x", Token.hex_value_08);   // Convert Token.hex_value to a string
                break;

                case 16:   
                hex_literal(_hex_literal_16, Token.hex_value_16);
                //snprintf(lend_op.src_buffer, sizeof(lend_op.src_buffer), "%x", Token.hex_value_16);   // Convert Token.hex_value to a string
                break;

                case 32:   
                hex_literal(_hex_literal_32, Token.hex_value_32); 
                //snprintf(lend_op.src_buffer, sizeof(lend_op.src_buffer), "%x", Token.hex_value_32);   // Convert Token.hex_value to a string
                break;

                case 64:   
                hex_literal(_hex_literal_64, Token.hex_value_64); 
                //snprintf(lend_op.src_buffer, sizeof(lend_op.src_buffer), "%x", Token.hex_value_64);   // Convert Token.hex_value to a string
                break;
                default: break;
            }
            
            scan(&Token);
            semicolon(_semicolon, ";");
        }
    }
}