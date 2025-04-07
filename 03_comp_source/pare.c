#include "comp_def.h"  
#include "comp_data.h"   
#include "comp_decl.h" 



struct scope_table_entry *pare_data_tool()
{
    pare(_pare, "pare");

    scan(&Token);
    colon(_colon, ":");

    set_express_state(express_pare);
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



struct scope_table_entry* parse_pare()
 {
    express_state_machine state = get_express_state();
    struct scope_table_entry* entry = NULL;
    
    if (state == express_pare) {
        // Match tokens for pare pattern
        // pare condition
    }
    return entry;
}
