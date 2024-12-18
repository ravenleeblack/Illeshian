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

// Token types
enum
{
    // Special tokens
    _enfi, _ident, _colon, _comma, _semicolon, _period, _lbracket, _rbracket, 
    
    // Numeric literals
    _num_lit, _hex_lit, _bin_lit,

    _assign, _log,


    // Sections - Keep these together
    _log_section,  _declare_section, _assign_section, _literal_section, _code_section,       

    _entry,        // Entry point marker
    _link,         // Link directive
    _import,       // Import directive (like extern but for modules)
    _export,       // Export directive (like global but for modules)
    _module,  

    // Data definition directives for each section
    _byte, _word, _dword, _qword,      // Size specifiers
    _db, _dw, _dd, _dq,                // Alternative size names
    _resb, _resw, _resd, _resq,        // For declare section
    
    //Scope
    _scope, _end_scope,
    // Symbol definitions
    _universal, _global, _local, _block, 

    _external, _internal, 
    _label,
    
    // Registers
    _reg8, _reg16, _reg32, _reg64,  // Register size types
    _rax, _rbx, _rcx, _rdx,         // 64-bit registers
    _eax, _ebx, _ecx, _edx,         // 32-bit registers
    _ax, _bx, _cx, _dx,             // 16-bit registers
    _al, _bl, _cl, _dl,             // 8-bit registers
    _rsp, _rbp, _rsi, _rdi,         // Special purpose registers
    _esp, _ebp, _esi, _edi,
    _sp, _bp, _si, _di,
    
    // Instructions
    _move, _push, _pop,              // Data movement
    _add, _sub, _mul, _div,         // Arithmetic
    _and, _or, _xor, _not,          // Logical

    _lshift, _rshift, _rotate_left, _rotate_right,         // Shifts and rotates
    _inc, _dec,                     // Increment/Decrement
    _compare, _test,                    // Comparison
    // Jump instructions
    _jump,              // Unconditional jump
    _jump_equal,        // Jump if equal
    _jump_not_equal,    // Jump if not equal
    _jump_greater,      // Instead of jg
    _jump_less,         // Instead of jl
    _call, _return,                    // Subroutine
    _nop,                           // No operation
    
    // Addressing modes
    _ptr, _offset, _rel,
    
    // Directives
    _align, _org, _bits,
    _equ, _times,
    
    // File management (keeping these from original)
    _use,  _replace,
    _start_use, _get_use, _end_use,
    _start_link, _get_link, _end_link,
    _start_log, _get_log, _end_log,
    _line_use, _line_link, _line_log,


    _hold, _assigner, _num_literal, _strand_literal,

    _num, _mark, _deci, _decii, _strand,
    _num_ptr, _mark_ptr, _deci_ptr, _decii_ptr, _strand_ptr, 

    _den, _bay, _aisle, _zone,
    _dens, _bays, _aisles, _zones,
    _den_ptr, _bay_ptr, _aisle_ptr, _zone_ptr,

    _vine, _vine_ptr, _passage, _passage_ptr, 

    // Instructions with size variants
    _move_den, _move_bay, _move_aisle, _move_zone,
    _move_dens, _move_bays, _move_aisles, _move_zones,
    
    _add_den, _add_bay, _add_aisle, _add_zone,
    _add_dens, _add_bays, _add_aisles, _add_zones,
    
    _sub_den, _sub_bay, _sub_aisle, _sub_zone,
    _sub_dens, _sub_bays, _sub_aisles, _sub_zones,

    _mul_den, _mul_bay, _mul_aisle, _mul_zone,
    _mul_dens, _mul_bays, _mul_aisles, _mul_zones,

    _div_den, _div_bay, _div_aisle, _div_zone,
    _div_dens, _div_bays, _div_aisles, _div_zones,

    _inc_den, _inc_bay, _inc_aisle, _inc_zone,
    _inc_dens, _inc_bays, _inc_aisles, _inc_zones,

    _dec_den, _dec_bay, _dec_aisle, _dec_zone, 
    _dec_dens, _dec_bays, _dec_aisles, _dec_zones,
};

// Token structure
struct token 
{
    int token_rep;          // Token type from enum
    int num_value;          // For numeric literals
    int token_str;          // For string literals
    int reg_size;          // For register size tracking
};

// Structure for replacements
typedef struct 
{
   char* original;
    char* replacement;
} replace_directive;

// Structure to hold FM file configuration
typedef struct file_manager_config
{
    char** headers;         // use: declarations
    char** sources;         // link: declarations
    char* log_file;         // log: declaration
    replace_directive* replace_token;  // replace: declarations

    int header_count;
    int source_count;
    int replace_count;
    int log_count;
} file_manager_config;

extern file_manager_config* config;

// Path definitions
#define MAX_PATH 256
extern char source_path[MAX_PATH];
extern char header_path[MAX_PATH];

// Assembly-specific definitions
#define MAX_LABEL_LENGTH 64
#define MAX_INSTRUCTION_LENGTH 16
#define MAX_OPERANDS 4
#define MAX_LINE_LENGTH 256




// data types 
enum {
    // Special type
    type_none = 0,
    
    // Basic data types
    type_hollow,    
    type_mark,      
    type_num,       
    type_long,      
    type_deci,      
    type_decii,     
    type_strand,    
    
    // Complex data types  
    type_table,     
    type_pare,      
    type_tripare,   
    type_log,       
    type_list,      
    type_prototype, 

    // Stream types
    type_vine,
    type_passage,
    
    // Basic pointer types
    type_hollow_ptr,
    type_mark_ptr,
    type_num_ptr,
    type_long_ptr,
    type_deci_ptr,
    type_decii_ptr,
    type_strand_ptr,
    
    // Complex pointer types
    type_log_ptr,    
    type_list_ptr,   
    type_table_ptr,  
    type_pare_ptr,
    type_tripare_ptr,
    
    // Stream pointer types
    type_vine_ptr,
    type_passage_ptr,
    
    // File types
    type_file,     
    type_header,   
    type_source,   
    type_module,   
    type_loop_func,
    
    // 64-bit types
    type_zone, type_zones,
    type_aisle, type_aisles,
    type_bay, type_bays,
    type_den, type_dens,
    
    // 64-bit pointer types
    type_zone_ptr, type_zones_ptr,
    type_aisle_ptr, type_aisles_ptr,
    type_bay_ptr, type_bays_ptr,
    type_den_ptr, type_dens_ptr,


    type_header_file,
    type_source_file,
    type_seed_file,
    type_mod_file,
    type_sibling,

    type_address,
    type_fetch,
};






