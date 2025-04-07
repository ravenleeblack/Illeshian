#include "comp_def.h"  
#include "comp_data.h"   
#include "comp_decl.h" 


struct scope_table_entry *retrieve_data_tool()
{
    retrieve(_retrieve, "retrieve");

    scan(&Token);
    colon(_colon, ":");

    set_express_state(express_retrieve);
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




struct scope_table_entry* parse_retrieve() {
    express_state_machine state = get_express_state();
    struct scope_table_entry* entry = NULL;
    
    if (state == express_retrieve) {
        // Match tokens for retrieve pattern
        // retrieve[function_name]: args;
    }
    return entry;
}