#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"

void process_universal_label(void)
{
    universal(_universal, "universal");

    scan(&Token);
    ident(_ident, Text);
    universal_id = insert_universal_scope(Text, scope_universal_tool, scope_universal_label);
    encode_universal_label(Text);
    
    scan(&Token);
    colon(_colon, ":");

    process_sections(scope_universal);
}

/* Here we match the universal scope keyword then scan for the label. We insert that label into
the scope table, we also use the ident, as the entry point seedling and the nasm output. We then
get the colon to end the line and start parsing the body of the scope label. We use a loop and we 
prcoess all sections until we hit a end_section. The end_section is our loop condition. Its how we
break out of the loop. So we can start parsing the global scope and its label.*/
