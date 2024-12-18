#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"

void process_end_section(void)
{
    end_section(_end_section, ".end_section");
    printf("\n");
}
