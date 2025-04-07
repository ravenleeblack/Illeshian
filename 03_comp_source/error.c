#include "comp_def.h"  
#include "comp_data.h"   
#include "comp_decl.h" 



// Handles compiler errors with error codes
void error_handler(int error_code)
{
    fprintf(stderr, "error %d: ", error_code);
    switch(error_code) {
        case error_syntax:     fprintf(stderr, "syntax error\n"); break;
        case error_type:       fprintf(stderr, "type mismatch\n"); break;
        case error_undefined:  fprintf(stderr, "undefined identifier\n"); break;
        case error_redeclared: fprintf(stderr, "identifier redeclared\n"); break;
        case error_scope:      fprintf(stderr, "invalid scope\n"); break;
        case error_param:      fprintf(stderr, "parameter error\n"); break;
        case error_expression: fprintf(stderr, "invalid expression\n"); break;
        case error_memory:     fprintf(stderr, "memory allocation failed\n"); break;
        case error_file:       fprintf(stderr, "file operation failed\n"); break;
        case error_token:      fprintf(stderr, "invalid token\n"); break;
        case error_unexpected: fprintf(stderr, "unexpected token/symbol\n"); break;
        case error_limit:      fprintf(stderr, "limit exceeded\n"); break;
        case error_internal:   fprintf(stderr, "internal compiler error\n"); break;
        default:               fprintf(stderr, "unknown error\n");
    }
    exit(1);  // Add exit on error
}

// Reports a simple error message
void error(const char *message)
{   
    fprintf(stderr, "error: %s\n", message);
    exit(1);
}

// Reports an error with an additional string parameter
void errors(const char *message, const char *s) {
    fprintf(stderr, "error: %s: %s\n", message, s);
    exit(1);
}

// Reports an error with an additional character parameter
void errorc(const char *message, int c) {
    fprintf(stderr, "error: %s: %c\n", message, c);
    exit(1);
}
