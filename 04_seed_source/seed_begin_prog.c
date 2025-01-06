#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"

int begin_prog(void)
{
    fprintf(stderr, "Begin processing program\n");

    // Example: Encode NASM for program start
    encode_scope_to_nasm("text", "program_start");

    while(1)
    {
        scan(&Token);

        if(Token.token_rep == _enfi)
        {
            fprintf(stderr, "End of file encountered\n");
            break;
        }
        
        if(Token.token_rep == _universal)
        {
            fprintf(stderr, "Processing universal label\n");
            process_universal_label();  
        }
        else if(Token.token_rep == _global)
        {
            fprintf(stderr, "Processing global label\n");
            process_global_label();
        }
        else
        {
            fprintf(stderr, "Unknown token trying to become a scoped label: %d\n", Token.token_rep);
        }
    }

    fprintf(stderr, "End processing program\n");
    return 0;
}
