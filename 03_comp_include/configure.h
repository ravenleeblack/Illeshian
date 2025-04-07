#define MAX_MANAGER_PARAMS 20
#define MAX_FUNCTION_PARAMS 20
#define MAX_CALL_MANAGER_PARAMS 20
#define MAX_CALL_FUNCTION_PARAMS 20




struct manager_config {
    char name[256];           // Manager name
    int tool_type;           // tool_manager
    int data_type;          // Return data type
    int param_count;        // Number of parameters
    struct {
        char name[256];     // Parameter name
        int data_type;      // Parameter data type
    } params[MAX_MANAGER_PARAMS];
    int is_main;           // Flag for main manager
};


struct function_head_config 
{
  char * name;
};

struct function_param_config
{
  char * name;
};

struct function_body_config 
{
  char * name;
};

struct function_foot_config 
{
  char * name;
};


struct assembly_head_config
{
  char * name;
};

struct assembly_param_config
{
  char * name;
};

struct assembly_body_config
{
  char * name;
};

struct assembly_foot_config
{
  char * name;
};



struct pass_arg_config 
{
  char * name;
};
struct yield_config
{
  char * name;
};

struct hold_config {
  char * name;
};

struct assign_config {
  char * name;
};

struct table_config {
  char * name;
};

struct pare_config {
  char * name;
};

struct tripare_config {
  char * name;
};



struct log_config {
 char * name;

};

struct list_config {
 char * name;
};

struct check_config {
 char * name;
};

struct loop_config {
 char * name;
};

struct set_loop_config {
 char * name;
};

struct compare_config {
 char * name;
};

struct state_config {
 char * name;
};
