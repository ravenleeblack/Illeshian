#include "irp_def.h"  
#include "irp_data.h"   
#include "irp_decl.h" 


// File management directives
void use(int t, char *expected)
 { 
    if (Token.token_rep == t) { 
         if (output_flag) 
        { 
            keyword_cyan();
            printf(" %s\n", expected); 
            reset();
        } 
    } 
}

void replace(int t, char *expected) { 
    if (Token.token_rep == t) { 
        if (output_flag) { 
            keyword_dorange(); 
            printf(" %s\n", expected); 
            reset(); 
        } 
    } 
}

void link(int t, char *expected) { 
    if (Token.token_rep == t) { 
        if (output_flag) { 
            keyword_cyan(); 
            printf(" %s\n", expected); 
            reset(); 
        } 
    } 
}

void match_log(int t, char *expected) { 
    if (Token.token_rep == t) { 
        if (output_flag) { 
            keyword_dorange(); 
            printf(" %s\n", expected); 
            reset(); 
        } 
    } 
}

// Token matching functions
void ident(int t, char *expected) { 
    if (Token.token_rep == t) { 
        if (output_flag) { 
            keyword_strand(); 
            printf(" %s\n", expected); 
            reset(); 
        } 
    } 
}

void colon(int t, char *expected) { 
    if (Token.token_rep == t) { 
        if (output_flag) { 
            keyword_lgray(); 
            printf(" %s\n", expected); 
            reset(); 
        } 
    } 
}

void comma(int t, char *expected) { 
    if (Token.token_rep == t) { 
        if (output_flag) { 
            keyword_dgray(); 
            printf(" %s\n", expected); 
            reset(); 
        } 
    } 
}

void semicolon(int t, char *expected) { 
    if (Token.token_rep == t) { 
        if (output_flag) { 
            keyword_lgray(); 
            printf(" %s\n", expected); 
            reset(); 
        } 
    } 
}

