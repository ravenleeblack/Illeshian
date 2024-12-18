

//Toke nrepresentives for strands
enum
{
    // End and special tokens
    _enfi, _ident, _ident_ptr,
    
    // Operators (arithmetic, comparison, bitwise, logical)
    _assigner, _plus, _minus, _multi, _divi, _equal, _not_equal, _less_then, _great_then, _less_equal, _great_equal,
    _increment, _decrement, _invert, _xor, _lshift, _rshift, _or, _logic_and, _logic_not, _logic_or, _arrow, _address,
    
    // Delimiters (brackets, braces, parentheses, punctuation)
    _lbracket, _rbracket, _lbrace, _rbrace, _lparen, _rparen, _colon, _comma, _period, _semicolon, _ender, _larrow, _rarrow,
    
    // Control flow and structure keywords
    _check, _else, _set_loop, _loop, _compare, _line, _otherwise, _break, _bridge,
    
    // Function and scope related keywords
    _manager, _function, _call, _pass_arg, _yield, _universal, _global, _local, _private, _public, _show, _hide, _loop_func,
    
    // Basic data types
    _hollow, _num, _mark, _long_num, _deci, _decii, _deciv, _decviii, _strand,
    
    // Literal types (constants)
    _num_literal, _mark_literal, _deci_literal, _decii_literal, _deciv_literal, _decviii_literal, _strand_literal, _true_literal, _false_literal,
    
    // Complex data types
    _log, _list, _table, _pare, _tripare,
    
    // Stream and pipe types
    _vine, _vine_type, _passage, _passage_type,
    
    // Basic pointer types
    _ptr, _refer, _pointer, _num_ptr, _mark_ptr, _long_ptr, _deci_ptr, _decii_ptr, _deciv_ptr, _decviii_ptr, _strand_ptr,
    _mana_ptr, _func_ptr, _table_ptr, _vine_ptr, _passage_ptr, _hollow_ptr, _log_ptr, _list_ptr, _module_ptr, _mod_ptr, _ext_ptr, _fetch,
    
    // System pointer types
    _heap_ptr, _stack_ptr, _stack_base_ptr, _stack_pos_ptr, _stack_frame_ptr, _stack_limit_ptr,
    _file_ptr, _dir_ptr, _path_ptr, _env_ptr, _arg_ptr, _type_ptr, _macro_ptr,
    
    // Graphics pointer types
    _bit_ptr, _byte_ptr, _frambebuffer_ptr, _vector_ptr, _vertex_ptr, _polygon_ptr,
    _shader_ptr, _texture_ptr, _pixel_ptr, _bitmap_ptr,
    
    // File and module related keywords
    _header_file, _source_file, _mod_file, _data_manager, _use, _alter, _link,
    _proceed, _proto, _replace, _set, _transfer,
    
    // Scope modifiers
    _extern, _intern, _change_global, _change_local, _sibling,
    
    // Assignment and holding
    _hold, _assign,
    
    // 64-bit types
    _zone, _zones,
    _aisle, _aisles,
    _bay, _bays,
    _den, _dens,
    
    // Add pointer versions
    _zone_ptr, _zones_ptr,
    _aisle_ptr, _aisles_ptr,
    _bay_ptr, _bays_ptr,
    _den_ptr, _dens_ptr,

    _state, _sub_state, _step, _cycle, _next, _continue, _end_state,
    _read, _write, _connect, _network,  _convert, _retrieve, _port_hub, 

    _start_use, _get_use, _end_use, _line_use,
	_start_link, _get_link, _end_link, _line_link, _file_name, _use_file_type, _link_file_type, _at_sign, 
};


struct token                // Token representation of the token being tokenized from lexer
{
	int token_rep;			// access to the token's representer in the enum above
	int num_value;			// access to the int value of a token's num_literal representer
	int deci_value;       // access to the decimal value of a token's deci_literal representer
    long decii_value;       // access to the decimal value of a token's deci_literal representer
    long long deciv_value;       // access to the decimal value of a token's deci_literal representer

   
	int mark_value;         // access to the char value of a token's mark_literal representer
	int escape_value;       // access to the escape characters in a strand literal
	char *token_str;        // access to the actual string or strand literal of a token. To me the actual token from source.
    int bool_value; 
};


