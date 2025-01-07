#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include "color.h"
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>

#include "scope_types.h"
#include "scope_api.h"
#include "scope_table.h"




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
enum {
    // Special tokens
    _enfi, _ident, _colon, _comma, _semicolon, _period, _lbracket, _rbracket, _assigner, _lbrace, _rbrace,

    // Literals
    _num_literal, _mark_literal, _strand_literal, _hex_literal, _binary_literal, _deci_literal, _decii_literal,

     _table, _table_ptr,

    // Data types
    _num, _mark, _deci, _decii, _strand,                                     // Regular types
    _den, _bay, _aisle, _zone, _dens, _bays, _aisles, _zones,              // System types
    _vine, _passage,                                                        // Stream types

    // Pointers
    _num_ptr, _mark_ptr, _deci_ptr, _decii_ptr, _strand_ptr,               // Regular pointers
    _den_ptr, _bay_ptr, _aisle_ptr, _zone_ptr,                             // System pointers
    _dens_ptr, _bays_ptr, _aisles_ptr, _zones_ptr,                             // System pointers
    _vine_ptr, _passage_ptr,                                               // Stream pointers
    _address, _fetch,

    // Sections
    _log_section, _declare_section, _assign_section, _literal_section, _code_section, 
    _arch_16_section, _arch_32_section, _arch_64_section, _pad_section, 

    // Scope and structure
    _scope, _end_scope, _end_section, _log, _assign, _hold,
    _universal, _global, _local, _global_block, _local_block, _global_param, _local_param,
    _extern, _intern, _external, _internal, _label,

    // Module directives
    _entry, _link, _import, _export, _module, _load, _sign, _origin, _write, 

    // Registers (grouped by size)
    _reg8, _reg16, _reg32, _reg64,                                         // Register types
    _rax, _rbx, _rcx, _rdx, _rsi, _rdi, _rbp, _rsp,                       // 64-bit
    _r8,  _r9,  _r10, _r11, _r12, _r13, _r14, _r15,
    _eax, _ebx, _ecx, _edx, _esi, _edi, _ebp, _esp,                       // 32-bit
    _r8d, _r9d, _r10d, _r11d, _r12d, _r13d, _r14d, _r15d,
    _ax,  _bx,  _cx,  _dx,  _si,  _di,  _bp,  _sp,                        // 16-bit
    _r8w, _r9w, _r10w, _r11w, _r12w, _r13w, _r14w, _r15w,
    _al,  _bl,  _cl,  _dl,  _sil, _dil, _bpl, _spl,                       // 8-bit
    _r8b, _r9b, _r10b, _r11b, _r12b, _r13b, _r14b, _r15b,
    _ah, _bh, _ch, _dh,
    // Basic instructions
    _move, _push, _pop, _add, _sub, _mul, _div,                           // Core operations
    _and, _or, _xor, _not, _lshift, _rshift, _rotate_left, _rotate_right, // Logical/Shifts
    _inc, _dec, _compare, _test,                                          // Arithmetic/Compare

    
    _jump, _jump_equal, _jump_not_equal, _jump_great, _jump_less, _jump_neg,        // Jumps
    _call, _return, _nop, _yield, _pass_arg,                              // Flow control

    // Sized instructions
    _move_den, _move_bay, _move_aisle, _move_zone,                        // Move variants
    _move_dens, _move_bays, _move_aisles, _move_zones,
    _add_den, _add_bay, _add_aisle, _add_zone,                           // Add variants
    _add_dens, _add_bays, _add_aisles, _add_zones,
    _sub_den, _sub_bay, _sub_aisle, _sub_zone,                          // Sub variants
    _sub_dens, _sub_bays, _sub_aisles, _sub_zones,
    _mul_den, _mul_bay, _mul_aisle, _mul_zone,                          // Mul variants
    _mul_dens, _mul_bays, _mul_aisles, _mul_zones,
    _div_den, _div_bay, _div_aisle, _div_zone,                          // Div variants
    _div_dens, _div_bays, _div_aisles, _div_zones,
    _inc_den, _inc_bay, _inc_aisle, _inc_zone,                          // Inc variants
    _inc_dens, _inc_bays, _inc_aisles, _inc_zones,
    _dec_den, _dec_bay, _dec_aisle, _dec_zone,                          // Dec variants
    _dec_dens, _dec_bays, _dec_aisles, _dec_zones,
    _push_radule, _pop_radule, _push_sadule, _pop_sadule,               // Stack variants
    _push_dadule, _pop_dadule,

    _push_den,    // 1 unsigned byte
    _push_dens,   // 1 signed byte
    _push_bay,    // 2 unsigned byte
    _push_bays,   // 2 signed byte
    _push_aisle,  // 4 unsigned byte
    _push_aisles, // 4 signed byte
    _push_zone,   // 8 unsigned byte
    _push_zones,   // 8 signed byte

    _pop_den,    // 1 unsigned byte
    _pop_dens,   // 1 signed byte
    _pop_bay,    // 2 unsigned byte
    _pop_bays,   // 2 signed byte
    _pop_aisle,  // 4 unsigned byte
    _pop_aisles, // 4 signed byte
    _pop_zone,   // 8 unsigned byte
    _pop_zones,   // 8 signed byte
    // Addressing and directives
    _ptr, _offset, _rel, _align, _org, _bits, _equ, _times,

    // File management
    _use, _replace, _start_use, _get_use, _end_use,
    _start_link, _get_link, _end_link, _start_log, _get_log, _end_log,
    _line_use, _line_link, _line_log,

    _int,  // Add int instruction token
    _set_flag, 

    _file_section, 

    _get_den_reg, _get_bay_reg, _get_aisle_reg, _get_zone_reg, _get_dens_reg, _get_bays_reg, _get_aisles_reg, _get_zones_reg,
};

// Token structure
struct token 
{
    int token_rep;          
    int num_value;      // For decimal integers
    unsigned int hex_value;  // For hex values
    float deci_value;   // For floats
    double decii_value; // For doubles
    char *token_str;    // For identifier names
    char *string_value; // For actual string literal values
    int reg_size;          
};

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

    type_extern,
    type_intern,

    type_function,
    type_seedling,
};



// DATA TOOL REPRESENTIVES
enum data_tool_type {
    tool_none = 0,
    
    // Function tools
    tool_manager,
    tool_function,
    tool_call,
    tool_prototype,
    tool_proto_direct,
    tool_proto_indirect,
    tool_manager_param,
    tool_function_param,
    // Data structure tools
    tool_log,
    tool_list,
    tool_seedling,

    // Data handling tools
    tool_hold,
    tool_assign,
    tool_table,
    tool_pare,
    tool_tripare,
    tool_strand,
    // Control flow tools
    tool_check,
    tool_else,
    tool_loop,
    tool_set_loop,
    tool_compare,
    tool_state,

    tool_comp_line_pos,
    tool_otherwise,
    tool_step,
    tool_end_state,
    
    // Return tools
    tool_pass_arg,
    tool_yield,
    
    // Scope tools
    tool_extern,
    tool_intern,
    tool_change_global,
    tool_change_local,
    
    // File tools
    tool_use,
    tool_link,
    tool_alter,
    tool_replace,
    tool_transfer,
 
    tool_file,
    tool_member,

    tool_cycle, 
    tool_next,
    tool_continue,
    
    tool_aisle,


    tool_mark_ptr,
    tool_num_ptr,
    tool_deci_ptr,
    tool_decii_ptr,

    tool_den_ptr,
    tool_bay_ptr,
    tool_aisle_ptr,
    tool_zone_ptr,

    tool_dens_ptr,
    tool_bays_ptr,
    tool_aisles_ptr,
    tool_zones_ptr,

    tool_log_ptr,
    tool_list_ptr,

    tool_expression = 300, 
    tool_passage = 301,
    tool_sibling = 400,

    tool_extern_flag = 0x1000,  // Use this as a bit flag with tool_extern
};
