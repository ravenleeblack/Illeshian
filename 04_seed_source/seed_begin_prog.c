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
        else
        {
            fprintf(stderr, "Unknown token trying to become a scoped label: %d\n", Token.token_rep);
        }
    }

    return 0;
}

/*Here is the beginning of our program. We always process universal scope first because its the
entry point for assembly and the linker. Then we prococess global scope. If it isnt one of these
two scopes then we must have reached and enfi. Since we hit the end of file. break and exit.*/

