#include "comp_def.h"  
#include "comp_data.h"   
#include "comp_decl.h" 

// State and step types
enum state_types {
    state_type_main,
    state_type_sub
};

enum step_types {
    step_type_normal,
    step_type_named,
    step_type_numbered
};


// Define control state enum
enum control_state {
    control_none,
    control_break,
    control_next,
    control_cycle,
    control_step
};

// Declare global control state variable
static enum control_state current_control = control_none;



struct scope_table_entry *cycle_data_tool()
{
    cycle(_cycle, "cycle");
    
    scan(&Token);
    colon(_colon, ":");
    
    set_express_state(express_state_cycle);
    struct scope_table_entry* result = parse_expressions();
    
    scan(&Token);
    ender(_ender, "`");
    
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
                current_control = control_next;
                return NULL;
            }
            else if(Token.token_rep == _step)
            {
                step(_step, "step");
                scan(&Token);
                current_control = control_step;
                return NULL;
            }
        }
    
    return NULL;
}

struct scope_table_entry *step_end_compound()
{
    scan(&Token);
    switch(Token.token_rep)
    {
        case _break:  breaker(_break, "break");  current_control = control_break; break;
        case _next:   next(_next, "next");       current_control = control_next;  break;  
        case _cycle:  current_control = control_cycle; cycle_data_tool(); break;
        case _end_state: end_state(_end_state, "end_state"); current_control = control_break; break;
        default: break;
    }

    scan(&Token);
    semicolon(_semicolon, ";");

    return NULL;
}

struct scope_table_entry *sub_state_data_tool()
{
    sub_state(_sub_state, "sub_state");

    scan(&Token);
    colon(_colon, ":");

    set_express_state(express_sub_state);
    struct scope_table_entry* result = parse_expressions();

    scan(&Token);
    ender(_ender, "`");

    scan(&Token);
    lbracket(_lbracket, "{");

    state_compound();  // Recursive state processing

    scan(&Token);
    rbracket(_lbracket, "}");

    return NULL;
}

struct scope_table_entry *step_data_tool()
{
    // Store position before step processing
    long step_start = ftell(comp_in);
    
    step(_step, "step");

    set_express_state(express_state_step);
    struct scope_table_entry* result = parse_expressions();

    scan(&Token);
    lbracket(_lbracket, "{");

    block_compound();   


    scan(&Token);
    rbracket(_lbracket, "}");

    step_end_compound();
    
    // If cycle, return to start of this step
    if(current_control == control_cycle) {
        fseek(comp_in, step_start, SEEK_SET);
        current_control = control_none;
    }
    return NULL;
}

struct scope_table_entry *state_compound()
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
            case _step:       
                step_data_tool();
                if(current_control == control_break) {
                    return NULL;  // Exit state
                }
                if(current_control == control_next) {
                    current_control = control_none;
                    continue;     // Next step
                }
                if(current_control == control_step) {
                    // Handle specific step jump
                    current_control = control_none;
                    // Jump to named step logic here
                }
                break;

            case _sub_state:  
                sub_state_data_tool();
                if(current_control == control_break) {
                    return NULL;
                }
                break;

            case _end_state:  
                current_control = control_break;
                return NULL;
                break;  

            default: break;
        }
    }
    return NULL;
}

struct scope_table_entry *state_data_tool()
{
    state(_state, "state");

    scan(&Token);
    colon(_colon, ":");

    set_express_state(express_state);
    struct scope_table_entry* result = parse_expressions();

    scan(&Token);
    ender(_ender, "`");

    scan(&Token);
    lbracket(_lbracket, "{");

    state_compound();


    scan(&Token);
    rbracket(_lbracket, "}");

    return NULL;
}






struct scope_table_entry* parse_state()
 {
    express_state_machine state = get_express_state();
    struct scope_table_entry* entry = NULL;
    
    if (state == express_state) {
 
     
    }
    return entry;
}

struct scope_table_entry* parse_sub_state(void) {
    express_state_machine state = get_express_state();
    struct scope_table_entry* entry = NULL;
    
    if (state == express_sub_state)
    {

    }
    return entry;
}

struct scope_table_entry* parse_step(void) {
    express_state_machine state = get_express_state();
    struct scope_table_entry* entry = NULL;
    
    if (state == express_state_step)
     {

    }
    return entry;
}

struct scope_table_entry* parse_end_state(void) {
    express_state_machine state = get_express_state();
    struct scope_table_entry* entry = NULL;
    
    if (state == express_end_state) {

    }
    return entry;
}

struct scope_table_entry* parse_state_cycle(void) {
    express_state_machine state = get_express_state();
    struct scope_table_entry* entry = NULL;
    
    if (state == express_state_cycle) 
    {

    }
    return entry;
}



