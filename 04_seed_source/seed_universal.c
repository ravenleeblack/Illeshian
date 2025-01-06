#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"

void process_universal_label(void)
{
    universal(_universal, "universal");

    scan(&Token);
    ident(_ident, Text);
    universal_id = insert_universal_scope(Text, scope_tool_none, scope_type_none);
    encode_universal_scope_section(nasm_out, Text, scope_universal);
    
    // Example: Encode NASM for universal label
    encode_scope_to_nasm("text", Text);

    scan(&Token);
    colon(_colon, ":");

    while(1)
    {
        scan(&Token);
        process_sections(scope_universal);

        if(Token.token_rep == _end_section)
        {
            process_end_section();
            return;
        }
    }
}


