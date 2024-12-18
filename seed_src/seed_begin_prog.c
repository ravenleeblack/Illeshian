#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"



int begin_prog(void)
{
    while(1)
    {
        scan(&Token);

        if(Token.token_rep == _enfi)
        {
            break;
        }
        
        if(Token.token_rep == _universal)
        {
            process_universal_label();  
        }
        else if(Token.token_rep == _global)
        {
           process_global_label();
        }
    }
    return 0;
}
