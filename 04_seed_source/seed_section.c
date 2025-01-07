#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"

void process_sections(enum scope_type current_scope)
{
    switch(Token.token_rep)
    {
        case _arch_16_section:  process_arch_16_section();                  break;
        case _arch_32_section:  process_arch_32_section();                  break;
        case _arch_64_section:  process_arch_64_section();                  break;
        case _pad_section:      process_pad_section();                      break;
        case _file_section:     process_file_section(current_scope);        break;
        case _log_section:      process_log_section(current_scope);         break; 
        case _declare_section:  process_declare_section(current_scope);     break;
        case _assign_section:   process_assign_section(current_scope);      break;
        case _literal_section:  process_literal_section(current_scope);     break;
        case _code_section:     process_code_section(current_scope);        break;
        default: break;
    }
}