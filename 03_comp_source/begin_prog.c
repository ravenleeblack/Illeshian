#include "comp_def.h"  
#include "comp_data.h"   
#include "comp_decl.h" 


int begin_prog()
{
    while(1)
    { 
        scan(&Token);
  
        if(Token.token_rep == _enfi) {
            break;
        }

        switch(Token.token_rep)
        {
            case _start_use: process_start_use();   break;
            case _start_link: process_start_link(); break;
            default: printf("Unexpected token: %d\n", Token.token_rep);  break;
        }
    }
    return 0;
}


int process_start_use()
{
    start_use(_start_use, "start_use");

    scan(&Token);
    at_sign(_at_sign, "@");
    
    scan(&Token);
    irp_ident(_ident, Text);

    scan(&Token);
    at_sign(_at_sign, "@");

    scan(&Token);
    irp_line(_line, "line");

    scan(&Token);
    irp_num_literal(_num_literal, Token.num_value);

    while(1) 
    { 
        scan(&Token);
        
        if(Token.token_rep == _end_use)
        {
           reject_token(&Token);
           break;
        }

        switch (Token.token_rep)
        {
            case _proto: proto_data_tool();   break;  
            case _hold:  hold_data_tool();    break;
            case _extern: external_data_tool(); break;
            case _intern: internal_data_tool(); break;
            case _ident:
                ident(_ident, Text);

                scan(&Token);
                int data_type = parse_type();

                if (Token.token_rep == _log)
                {
                    log_data_tool();
                }
                if (Token.token_rep == _list)
                {
                    list_data_tool();
                }
            break;
            default: break;
        }

    }
    scan(&Token); 
    end_use(_end_use, "end_use");
    return 0;
}


int process_start_link()
{
    start_link(_start_link, "start_link");

    scan(&Token);
    at_sign(_at_sign, "@");
    
    scan(&Token);
    irp_ident(_ident, Text);


    scan(&Token);
    at_sign(_at_sign, "@");

    scan(&Token);
    irp_line(_line, "line");

    scan(&Token);
    irp_num_literal(_num_literal, Token.num_value);

    while(1) 
    { 
        scan(&Token);

        if(Token.token_rep == _end_link)
        {
            reject_token(&Token);
            break;
        }

        switch(Token.token_rep)
        {
            case _hollow:
            case _num:   manager_data_tool();  break;
        }

    }
    scan(&Token);
    end_link(_end_link, "end_link"); 

    return 0;
}
