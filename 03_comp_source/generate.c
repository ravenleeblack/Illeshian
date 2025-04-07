#include "comp_def.h"  
#include "comp_data.h"   
#include "comp_decl.h" 

int label_counter = 0;
int mana_counter = 0;
int func_counter = 0;
int mana_jmp = 0;
int func_jmp = 0;

// Generate and return a new label number
int generate_head_label(void)
{
    return (label_counter++);
}

int generate_foot_label(void)
{
    return (label_counter++);
}
