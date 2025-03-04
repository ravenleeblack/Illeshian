#include "comp_def.h"  
#include "comp_data.h"   
#include "comp_decl.h" 

struct scope_table_entry *internal_data_tool()
{
    int data_type;
    
    internal(_intern, "intern");

    scan(&Token);
    colon(_colon, ":");


    set_express_state(express_internal);
    struct scope_table_entry* result = parse_expressions();


    scan(&Token);
    semicolon(_semicolon, ";");

    return NULL;
}



struct scope_table_entry* parse_internal_express() {
    express_state_machine state = get_express_state();
    struct scope_table_entry* entry = NULL;
    
    if (state == express_internal) 
    {
        scan(&Token);
        hold(_hold, "hold");
        
        scan(&Token);
        parse_type();


        scan(&Token);
        colon(_colon, ":");

        scan(&Token);
        ident(_ident, Text);
    }
    return entry;
}
