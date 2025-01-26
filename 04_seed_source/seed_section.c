#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"



void process_sections(enum scope_type current_scope)
{
    scan(&Token);
    //start_section(_start_section, ".start_section");
    lbracket(_lbracket, "{");

    
    while(1)
    {
        scan(&Token);
        if(Token.token_rep == _rbracket)
        {
            rbracket(_rbracket, "}");

            scan(&Token);
            if(Token.token_rep == _pass_arg)
            {
                 process_pass_arg_instruction(current_scope);
            }
            else
            {
                semicolon(_semicolon, ";");
            }
            return 0;
        }
        if(Token.token_rep == _period)
        {
            period(_period, ".");
            
            scan(&Token);
            switch(Token.token_rep)
            {
                case _file_section:     process_file_section(current_scope);        break; 
                case _declare_section:  process_declare_section(current_scope);     break;
                case _assign_section:   process_assign_section(current_scope);      break;
                case _literal_section:  process_literal_section(current_scope);     break;
                case _code_section:     process_code_section(current_scope);        break;

                case _arch_8_section:   process_arch_section(current_scope);        break;
                case _arch_16_section:  process_arch_section(current_scope);        break;
                case _arch_32_section:  process_arch_section(current_scope);        break;
                case _arch_64_section:  process_arch_section(current_scope);        break;
                default: break;
            }
        }
    }
    //end_section(_end_section, ".end_section");
}


        //case _pad_section:      process_pad_section();                      break;
        //case _log_section:      process_log_section(current_scope);         break;