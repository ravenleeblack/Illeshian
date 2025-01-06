#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"

void process_universal_label(void)
{
    universal(_universal, "universal");

    scan(&Token);
    ident(_ident, Text);
    universal_id = insert_universal_scope(Text, scope_tool_none, scope_type_none);
    convert_universal_label(Text);
    
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

/* Here we match the universal scope keyword then scan for the label. We insert that label into
the scope table, we also use the ident, as the entry point seedling and the nasm output. We then
get the colon to end the line and start parsing the body of the scope label. We use a loop and we 
prcoess all sections until we hit a end_section. The end_section is our loop condition. Its how we
break out of the loop. So we can start parsing the global scope and its label.*/
