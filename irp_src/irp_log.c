#include "irp_def.h"  
#include "irp_data.h"   
#include "irp_decl.h" 
#include "irp_log.h"

const char* get_irp_main_log_str(int type) 
{
    switch(type) {
        case irp_log_main_none:     return "main_none";
        case irp_log_main_system:   return "main_system";
        case irp_log_main_irp:      return "main_irp";
        case irp_log_main_comp:     return "main_comp";
        case irp_log_main_seedling: return "main_seedling";
        case irp_log_main_rootling: return "main_rootling";
        default:                    return "unknown_main_type";
    }
}

const char* get_irp_sub_log_str(int type)
{
    switch(type) {
        case irp_log_sub_none:     return "sub_none";
        case irp_log_sub_system:   return "sub_system";
        case irp_log_sub_irp:      return "sub_irp";
        case irp_log_sub_comp:     return "sub_comp";
        case irp_log_sub_seedling: return "sub_seedling";
        case irp_log_sub_rootling: return "sub_rootling";
        default:                   return "unknown_sub_type";
    }
}

// Helper function to check if a main log type is valid
bool is_valid_main_log(int type)
{
    return (type >= irp_log_main_none && 
            type <= irp_log_main_rootling);
}

// Helper function to check if a sub log type is valid
bool is_valid_sub_log(int type)
{
    return (type >= irp_log_sub_none && 
            type <= irp_log_sub_rootling);
}