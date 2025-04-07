#include "comp_def.h"  
#include "comp_data.h"   
#include "comp_decl.h" 


struct scope_table_entry *manager_arg_param()
{
    struct scope_table_entry* result = NULL;

    scan(&Token);
    if (Token.token_rep == _ender) 
    {
        reject_token(&Token);
        return NULL;
    }
    else
    {
        set_express_state(express_manager_arg);
        result = parse_expressions();  
    }
    return result;
}


struct scope_table_entry *manager_data_tool()
{
    struct scope_table_entry * result;
    int data_type;

    data_type = parse_type();  // Store the type
    
    scan(&Token);
    ident(_ident, Text);

    // Check if this is the main manager
    if (strcmp(Text, "main") == 0)
    {
        is_main_manager = 1;
    } 

    scan(&Token);
    manager(_manager, "manager");

    scan(&Token);
    colon(_colon, ":");

      // Collect parameters
    result = manager_arg_param();

    scan(&Token);
    ender(_ender, "`");

    scan(&Token);
    lbracket(_lbracket, "{");

    result = global_compound();

    scan(&Token);
    rbracket(_rbracket, "}");

    if (is_main_manager == 1) 
    {
        result = yield_data_tool();
    } 
    else
    {
        result = pass_arg_data_tool();
    }
    
    return result;
}




// Modify parse_manager_args to collect parameter information
struct scope_table_entry* parse_manager_args()
{
    express_state_machine state = get_express_state();
    struct scope_table_entry* entry = NULL;
    struct manager_config* config = get_current_manager_config(); // You'll need to implement this

    if (state == express_manager_arg)
    {
        while(1 && config->param_count < MAX_MANAGER_PARAMS)
        {
            // Store parameter data type
            config->params[config->param_count].data_type = parse_type();

            scan(&Token);
            if(Token.token_rep == _ident)
            {
                ident(_ident, Text);
                // Store parameter name
                strncpy(config->params[config->param_count].name, Text, sizeof(config->params[config->param_count].name) - 1);
                config->param_count++;
            }
            
            if(Token.token_rep == _comma)
            {
                comma(_comma, ",");
                continue;
            }

            if(Token.token_rep == _ender)
            {
                reject_token(&Token);
                break;
            }
        }
    }
    return entry;
}







// Global manager config for current parsing
static struct manager_config current_manager = {0};

// Helper to get current manager config
struct manager_config* get_current_manager_config()
{
    return &current_manager;
}

// Helper to reset manager config before parsing new manager
void reset_manager_config()
{
    memset(&current_manager, 0, sizeof(struct manager_config));
}