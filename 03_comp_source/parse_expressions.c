#include "comp_def.h"
#include "comp_data.h"
#include "comp_decl.h"





struct scope_table_entry* process_condition(const char* left, int operator, const char* right)
{
    struct scope_table_entry* entry = NULL;
    

    switch(operator)
    {
        case _equal:        equal(_equal, "==");             break;
        case _not_equal:    not_equal(_not_equal, "!=");     break;
        case _less_then:    less_then(_less_then, "<");      break;
        case _great_then:   great_then(_great_then, ">");    break;
        case _less_equal:   less_equal(_less_equal, "<=");   break;
        case _great_equal:  great_equal(_great_equal, ">="); break;
    }
    
    return entry;
}

struct scope_table_entry* process_increment_decrement(const char* operand, int operator)
{
    struct scope_table_entry* entry = NULL;
    
    switch(operator)
    {
        case _increment:    increment(_increment, "++");      break;
        case _decrement:    decrement(_decrement, "--");     break;
    }
    
    return entry;
}

