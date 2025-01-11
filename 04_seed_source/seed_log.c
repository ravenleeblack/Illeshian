#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"



void process_log_section(enum scope_type current_scope)
{
    match_log(_log_section, ".log");
}


