#include "comp_def.h"  
#include "comp_data.h"   
#include "comp_decl.h" 

struct scope_table_entry *vine_data_tool()
{
    vine(_vine, "vine");

    scan(&Token);
    colon(_colon, ":");

    set_express_state(express_vine);
    struct scope_table_entry* result = parse_expressions();

    scan(&Token);
    ender(_ender, "`");

    scan(&Token);
    lbracket(_lbracket, "{");

    block_compound();

    scan(&Token);
    rbracket(_lbracket, "}");

    pass_arg_data_tool();


    return NULL;
}



struct scope_table_entry* parse_vine()
 {
    express_state_machine state = get_express_state();
    struct scope_table_entry* entry = NULL;
    
    if (state == express_vine) {
        // Match tokens for vine pattern
        // vine: stream_name;
    }
    return entry;
}