#include "comp_def.h"  
#include "comp_data.h"   
#include "comp_decl.h" 

struct scope_table_entry *passage_data_tool()
{
    passage(_passage, "passage");

    scan(&Token);
    colon(_colon, ":");

    set_express_state(express_passage);
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


struct scope_table_entry* parse_passage() {
    express_state_machine state = get_express_state();
    struct scope_table_entry* entry = NULL;
    
    if (state == express_passage) {
        // Match tokens for passage pattern
        // passage: pipe_name;
    }
    return entry;
}