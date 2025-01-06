#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include "color.h"
#include <stdarg.h>

// Error codes
enum error_codes 
{
    error_syntax,         // syntax error
    error_type,          // type mismatch
    error_undefined,     // undefined identifier
    error_redeclared,    // identifier redeclared
    error_scope,         // invalid scope
    error_param,         // parameter error
    error_return,        // invalid return
    error_expression,    // invalid expression
    error_memory,        // memory allocation failed
    error_file,          // file operation failed
    error_token,         // invalid token
    error_unexpected,    // unexpected token/symbol
    error_limit,         // limit exceeded
    error_internal       // internal compiler error
};


enum
{
	_enfi, _ident, _colon, _comma, _semicolon,  _use, _link, _replace, _log, _period,
	_start_use, _get_use, _end_use,
	_start_link, _get_link, _end_link,
	_start_log, _get_log, _end_log,
	_line_use, _line_link, _line_log,

    _num_literal, _strand_literal, _hex_literal, 

    _lbracket, _rbracket, _assigner,
};

// tokens
struct token 
{
	int token_rep;			// Token type, from the enum list above
	int num_value;			// For T_INTLIT, the integer value
	int token_str;
};






