#include "comp_def.h"  
#include "comp_data.h"   
#include "comp_decl.h" 


struct scope_table_entry *proto_data_tool()
{
    struct scope_table_entry *entry = NULL;
    proto(_proto, "proto");

    scan(&Token);
    colon(_colon, ":"); 
    
    set_express_state(express_proto);
    entry = parse_expressions();

    scan(&Token);
    semicolon(_semicolon, ";"); 

    return entry;
}



struct scope_table_entry* parse_proto() 
{
    express_state_machine state = get_express_state();
    struct scope_table_entry* entry = NULL;
    
    if (state == express_proto) 
    {
        scan(&Token);
        entry = parse_type();

        scan(&Token);
        ident(_ident, Text);
        insert_universal_scope(Text, tool_proto_direct, entry);

        scan(&Token);
        switch (Token.token_rep) 
        {
            case _period:
                period(_period, ".");

                scan(&Token);
                ident(_ident, Text);
                insert_universal_scope(Text, tool_proto_indirect, entry);

                scan(&Token);
                colon(_colon, ":");

                scan(&Token);
                if (Token.token_rep != _ender) 
                {
                    set_express_state(express_function_call_arg);
                    entry = parse_expressions();
                } 
                
                if (Token.token_rep == _ender) 
                {
                    ender(_ender, "`");
                }
                break;

            case _colon:
                colon(_colon, ":");

                scan(&Token);
                if (Token.token_rep != _ender) 
                {
                    set_express_state(express_manager_call_arg);
                    entry = parse_expressions();
                }
                
                if (Token.token_rep == _ender) 
                {
                    ender(_ender, "`");
                } 
                break;

            default: 
                break;
        }
    }
    return entry;
}