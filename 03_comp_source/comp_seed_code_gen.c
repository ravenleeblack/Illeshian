#include "comp_def.h"  
#include "comp_data.h"   
#include "comp_decl.h" 

// File handle for output assembly
FILE* seed_out = NULL;

// Prototypes for basic section generation
void generate_seed_assign_section_body(void);
void generate_seed_declare_body(void);

// Prototypes for scope label generation
void generate_seed_univ_scope_label(void);
void generate_seed_global_scope_label(void);
void generate_seed_local_scope_label(void);
void generate_seed_global_block_scope_label(void);
void generate_seed_local_block_scope_label(void);

// Prototypes for label-related generation
void generate_seed_jump_label(const char *jump_label_name);
void generate_seed_call_label(const char *call_mana_name, const char *call_func_name, int index);

// Basic section generation
void generate_seed_assign_section_body(void)
{
    fprintf(seed_out, "    .assign\n");
    // Add any universal scope data (logs/lists) here
}

void generate_seed_declare_body(void)
{
    fprintf(seed_out, "    .declare\n");
    // Add any uninitialized data here
}

void generate_seed_univ_scope_label(void)
{
    fprintf(seed_out, "universal _start:\n");    // entry point for linker
}

void generate_seed_global_scope_label(void)
{
    fprintf(seed_out, "global %s:\n");          // output the name of a manager function into a global label
}

void generate_seed_local_scope_label(void)
{
    fprintf(seed_out, "local %s\n");           // output the name of a child function into a local label
}

void generate_seed_global_block_scope_label(void)
{
    fprintf(seed_out, "global %s:\n");          // output the name of a data tool in the body of a manager function into a global block label
}

void generate_seed_local_block_scope_label(void)
{
    fprintf(seed_out, "global %s:\n");          // output the name of a data tool in the body of a child function into a local block label
}

void generate_seed_jump_label(const char *jump_label_name)
{
    fprintf(seed_out, "    jump: %s;\n", jump_label_name);      // we always jump to main from universal
}

void generate_seed_call_label(const char *call_mana_name, const char *call_func_name, int index)
{
    if(index == 1)
    {
       call_func_name = NULL;                                    // help free pointer if there is no child name      
       fprintf(seed_out, "    call: %s;\n", call_mana_name);      // we always jump to main from universal
    }
    else if(index == 2)
    {
       fprintf(seed_out, "    call: %s.%s;\n", call_mana_name, call_func_name);      // we always jump to main from universal
    }
}