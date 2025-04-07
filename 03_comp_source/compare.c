#include "comp_def.h"  
#include "comp_data.h"   
#include "comp_decl.h" 


// Define control state enum
enum control_state {
    control_none,
    control_break,
    control_next,
    control_cycle
};

// Declare global control state variable
static enum control_state current_control = control_none;




struct scope_table_entry *compare_cycle_data_tool()
{
    cycle(_cycle, "cycle");
    
    scan(&Token);
    colon(_colon, ":");
    
    // Parse cycle condition
    set_express_state(express_compare_cycle);
    struct scope_table_entry* result = parse_expressions();
    
    scan(&Token);
    ender(_ender, "`");
    
 // Handle else clause
        scan(&Token);
        if(Token.token_rep == _else)
        {
            elser(_else, "else");

            scan(&Token);
            if(Token.token_rep == _break) 
            {
                breaker(_break, "break");
                current_control = control_break;
            }
            else if(Token.token_rep == _next)
            {
                next(_next, "next");
                current_control = control_next;  // This will trigger next line in compare_compound
                return NULL;  // Exit cycle processing
            }
        }
    return NULL;
}


struct scope_table_entry *compare_line_end_compound()
{
    scan(&Token);
    switch(Token.token_rep)
    {
        case _break:  breaker(_break, "break");  current_control = control_break; break;
        case _next:   next(_next, "next");       current_control = control_next;  break;  
        case _cycle:  current_control = control_cycle; compare_cycle_data_tool(); break;  
        default: break;
    }

    scan(&Token);
    semicolon(_semicolon, ";");

    return NULL;
}


struct scope_table_entry *compare_otherwise_data_tool()
{
    otherwise(_otherwise, "otherwise");

    set_express_state(express_compare_otherwise);
    struct scope_table_entry* result = parse_expressions();

    scan(&Token);
    lbracket(_lbracket, "{");

    block_compound();


    scan(&Token);
    rbracket(_lbracket, "}");

    compare_line_end_compound();
    return NULL;
}


struct scope_table_entry *compare_line_data_tool()
{
    // Store position before line processing
    long line_start = ftell(comp_in);
    
    line(_line, "line");

    set_express_state(express_compare_line);
    struct scope_table_entry* result = parse_expressions();

    scan(&Token);
    lbracket(_lbracket, "{");

    block_compound();   

    scan(&Token);
    rbracket(_lbracket, "}");

    compare_line_end_compound();
    
    // If cycle, return to start of this line
    if(current_control == control_cycle) {
        fseek(comp_in, line_start, SEEK_SET);
        current_control = control_none;
    }
    return NULL;
}

struct scope_table_entry *compare_compound()
{
    while(1)
    {
        scan(&Token);

        if(Token.token_rep == _rbracket || Token.token_rep == _colon)
        {
            reject_token(&Token);
            break;
        }

        switch(Token.token_rep)
        {
            case _line:       
                compare_line_data_tool();
                if(current_control == control_break) {
                    return NULL;  // Exit compare
                }
                if(current_control == control_next) {
                    current_control = control_none;
                    continue;     // Next case
                }
                break;

            case _otherwise:  
                compare_otherwise_data_tool();
                if(current_control == control_break) {
                    return NULL;
                }
                break;  

            default: break;
        }
    }
    return NULL;
}


struct scope_table_entry *compare_data_tool()
{
    compare(_compare, "compare");

    scan(&Token);
    colon(_colon, ":");

    set_express_state(express_compare);
    struct scope_table_entry* result = parse_expressions();

    scan(&Token);
    ender(_ender, "`");

    scan(&Token);
    lbracket(_lbracket, "{");


    compare_compound();


    scan(&Token);
    rbracket(_lbracket, "}");

    return NULL;
}









struct scope_table_entry* parse_compare(void) {
    express_state_machine state = get_express_state();
    struct scope_table_entry* entry = NULL;
    
    if (state == express_compare) {
        // Match tokens for compare pattern
        // compare colon value back_tick
    }
    return entry;
}

struct scope_table_entry* parse_compare_line(void) {
    express_state_machine state = get_express_state();
    struct scope_table_entry* entry = NULL;
    
    if (state == express_compare_line) {
        // Match tokens for compare pattern
        // compare colon value back_tick
    }
    return entry;
}

struct scope_table_entry* parse_compare_otherwise(void) {
    express_state_machine state = get_express_state();
    struct scope_table_entry* entry = NULL;
    
    if (state == express_compare_otherwise) {
        // Match tokens for compare pattern
        // compare colon value back_tick
    }
    return entry;
}

struct scope_table_entry* parse_compare_cycle(void) {
    express_state_machine state = get_express_state();
    struct scope_table_entry* entry = NULL;
    
    if (state == express_compare_cycle) {
        // Match tokens for compare pattern
        // compare colon value back_tick
    }
    return entry;
}
