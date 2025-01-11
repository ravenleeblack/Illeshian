#include "seed_defs.h"  
#include "seed_data.h"   
#include "seed_decl.h" 

// Return the position of character c in string s, or -1 if c not found
int chrpos(char *s, int c) 
{
	char *p;

	p = strchr(s, c);
	return (p ? p - s : -1);
}

// Get the next character from the input file.
int next_ch(void)
{
	int c;

	if (putback_char)
	{		// Use the character put
		c = putback_char;		// back if there is one
		putback_char = 0;
		return (c);
	}

	c = fgetc(seed_in);		// Read from input file


	if ('\n' == c)
	{
		comp_line_pos++;			// Increment comp_line_pos count
	}
	return (c);
}

// Put back an unwanted character
void return_char(int c) 
{
	putback_char = c;
}

// Skip past input that we don't need to deal with, 
// i.e. whitespace, newcomp_line_poss. Return the first
// character we do need to deal with.
int skip(void)
{
	int c;

	c = next_ch();
	while (1) 
	{
		// Skip whitespace and newcomp_line_poss
		while (isspace(c) || c == '\n' || c == '\r')
		{
			c = next_ch();
		}

		// Check for comments
		if (c == '/')
		{
			if ((c = next_ch()) == '/') 
			{
				// Single-comp_line_pos comment, skip until the end of comp_line_pos
				while (c != '\n' && c != EOF) {
					c = next_ch();
				}
			}
			else if (c == '*') 
			{
				// Multi-comp_line_pos comment, skip until the closing */
				while (1)
				{
					while (c != '*')
					{
						c = next_ch();
						if (c == EOF) {
							error("Comment not closed before EOF");
						}
					}
					c = next_ch();
					if (c == '/')
					{
						c = next_ch();
						break;
					}
				}
			}
			else 
			{
				// Not a comment, put back the character and break the loop
				return_char(c);
				break;
			}
		}
		else
		{
			// Not a comment, break the loop
			break;
		}
	}

	return c;
}


// Return the next character from a character
// or string literal
int scanch(void)
 {
	int c;

	// Get the next input character and interpret
	// metacharacters that start with a backslash
	c = next_ch();
    if (c == '\\') 
	{
        switch (c = next_ch())
		{
            case 'a':  return '\a';
            case 'b':  return '\b';
            case 'f':  return '\f';
            case 'n':  return '\n';
            case 'r':  return '\r';
            case 't':  return '\t';
            case 'v':  return '\v';
            case '\\': return '\\';
            case '"':  return '"';
            case '\'': return '\'';
            default:
            error("Unknown escape sequence");  // Changed from errorc to error
            return 0;
        }
    }
	return (c);			// Just an ordinary old character!
}

// Scan and return a hexadecimal number
int scanhex(int *size) 
{
    int c, h, val = 0;
    int digits = 0;

    while (1) 
    {
        c = next_ch();

        if (c >= '0' && c <= '9')
            h = c - '0';
        else if (c >= 'a' && c <= 'f')
            h = c - 'a' + 10;
        else if (c >= 'A' && c <= 'F')
            h = c - 'A' + 10;
        else {
            return_char(c);
            break;
        }

        val = (val << 4) | h;  // Use bitwise operations for hex
        digits++;

        // Determine the size based on the number of digits
        if (digits <= 2) 
            *size = 8;   // 8-bit hex
        else if (digits <= 4) 
            *size = 16;  // 16-bit hex
        else if (digits <= 8) 
            *size = 32;  // 32-bit hex
        else if (digits <= 16) 
            *size = 64;  // 64-bit hex
        else {
            error("Hex value exceeds 64-bit size");
            return 0;
        }
    }

    return val;
}

float scandeci(int c) {
    float val = 0;
    float factor = 1;
    
    // Handle whole part
    while (isdigit(c)) {
        val = val * 10 + (c - '0');
        c = next_ch();
    }
    
    // Handle decimal part
    if (c == '.') {
        c = next_ch();
        while (isdigit(c)) {
            factor = factor / 10;
            val = val + (c - '0') * factor;
            c = next_ch();
        }
    }
    
    return_char(c);
    return val;
}


// Scan and return an integer literal value from the input file
// along with the string version of the integer.
int scanint(int c, char *num_str) {
    int k, val = 0;
    int i = 0;

    // Ensure the input is valid before processing
    if (c < '0' || c > '9') {
        // Return an error or handle invalid input appropriately
        return -1; // Or some other error code
    }

    // Convert each character into an int value
    while ((k = chrpos("0123456789", c)) >= 0) {
        val = val * 10 + k;  // Update the numeric value

        // Store the string version of the number
        num_str[i++] = c;  // Add valid character to the string

        if((c = next_ch()) == ';')
        {
           return_char(c);  //if its a semicolon return were problems with the semicolon after num literals
        }
        else if (c < '0' || c > '9') // Stop if the character is no longer a number
        {
            break;  // Exit the loop if a non-numeric character is encountered
        }
    }

    // Null-terminate the string
    num_str[i] = '\0';

    return val;  // Return the integer value
}

// Function to copy contents of buf to strand_buffer
void copy_to_strand_buffer(char *strand_buffer, char *buf) {
	// Copy contents of buf to strand_buffer using strcpy
	strcpy(strand_buffer, buf);
}

// Scan in a string literal from the input file,
// and store it in buf[]. Return the length of
// the string. 
int scanstr(char *buf)
{
    int i = 0;
    int c;

    // Add bounds checking
    while (i < text_length - 1) {
        c = next_ch();
        
        // Check for end of string or EOF
        if (c == '"' || c == EOF) {
            break;
        }
        
        // Handle escape sequences
        if (c == '\\') {
            c = scanch();
        }
        
        // Store character with bounds check
        buf[i++] = c;
    }
    
    // Ensure null termination
    buf[i] = '\0';
    return i;
}

// Scan an identifier from the input file and
// store it in buf[]. Return the identifier's length
int scanident(int c, char *buf, int lim)
{
    int i = 0;

    // Handle period prefix first if present
    if (c == '.') {
        buf[i++] = c;
        c = next_ch();
    }

    // Allow digits, alpha, underscores
    while (isalpha(c) || isdigit(c) || c == '_' || c == '.') 
    {
        if (lim - 1 == i) {
            error("Identifier too long");
        }
        else if (i < lim - 1) {
            buf[i++] = c;
        }
        c = next_ch();
    }

    return_char(c);
    buf[i] = '\0';
    return (i);
}

// Given a word from the input, return the matching keyword token number or 0 if it's not a keyword.
int keyword(char *s)
{
	    // Handle period-prefixed keywords first
    if (s[0] == '.') {

        if (!strcmp(s, ".end"))            return _end; 
        if (!strcmp(s, ".arch_8"))         return _arch_8_section; 
		if (!strcmp(s, ".arch_16"))        return _arch_16_section; 
		if (!strcmp(s, ".arch_32"))        return _arch_32_section; 	
		if (!strcmp(s, ".arch_64"))        return _arch_64_section; 
		if (!strcmp(s, ".pad"))            return _pad_section;
        if (!strcmp(s, ".file"))           return _file_section;
        if (!strcmp(s, ".declare"))        return _declare_section;
        if (!strcmp(s, ".assign"))         return _assign_section;  // New token for .assign section
        if (!strcmp(s, ".literal"))        return _literal_section;
		if (!strcmp(s, ".log"))            return _log_section;
        if (!strcmp(s, ".code"))           return _code_section;
		if (!strcmp(s, ".end_section"))    return _end_section;
        if (!strcmp(s, ".start_section"))  return _start_section;
        return 0;
    }

    switch (*s)
	 {
        case 'a': 
            if (!strcmp(s, "add_den"))        return _add_den;
            if (!strcmp(s, "add_bay"))        return _add_bay;
            if (!strcmp(s, "add_aisle"))      return _add_aisle;
            if (!strcmp(s, "add_zone"))       return _add_zone;

            if (!strcmp(s, "add_dens"))       return _add_dens;
            if (!strcmp(s, "add_bays"))       return _add_bays;
            if (!strcmp(s, "add_aisles"))     return _add_aisles;
            if (!strcmp(s, "add_zones"))      return _add_zones;
		    if (!strcmp(s, "and")) return _and; 
		    if (!strcmp(s, "align")) return _align; 
		    if (!strcmp(s, "assign")) return _assign;
			if (!strcmp(s, "aisle")) return _aisle; 
			if (!strcmp(s, "aisles")) return _aisles; 
			if (!strcmp(s, "al")) return _al;
            if (!strcmp(s, "ax")) return _ax;	
			if (!strcmp(s, "address")) return _address;	
			if (!strcmp(s, "aisle_ptr")) return _aisle_ptr;	
			if (!strcmp(s, "aisles_ptr")) return _aisles_ptr;
		    break;
        
        case 'b': 
		    if (!strcmp(s, "bits"))        return _bits; 
			if (!strcmp(s, "bay"))         return _bay; 
            if (!strcmp(s, "bl"))          return _bl;
            if (!strcmp(s, "bx"))          return _bx;
            if (!strcmp(s, "bp"))          return _bp;
            if (!strcmp(s, "bpl"))         return _bpl;
			if (!strcmp(s, "bay_ptr"))     return _bay_ptr;	
			if (!strcmp(s, "bays_ptr"))    return _bays_ptr;	
		    break;
        
        case 'c': 
		    if (!strcmp(s, "call"))        return _call;
            if (!strcmp(s, "call_system")) return _call_system; 
		    if (!strcmp(s, "compare"))     return _compare;
			if (!strcmp(s, "cl"))          return _cl;
            if (!strcmp(s, "cx"))         return _cx;
		    break;
        
        case 'd': 
            if (!strcmp(s, "div_den"))        return _div_den;
            if (!strcmp(s, "div_bay"))        return _div_bay;
            if (!strcmp(s, "div_aisle"))      return _div_aisle;
            if (!strcmp(s, "div_zone"))       return _div_zone;

            if (!strcmp(s, "div_dens"))       return _div_dens;
            if (!strcmp(s, "div_bays"))       return _div_bays;
            if (!strcmp(s, "div_aisles"))     return _div_aisles;
            if (!strcmp(s, "div_zones"))      return _div_zones;

		    if (!strcmp(s, "dec"))         return _dec; 
			if (!strcmp(s, "den"))         return _den; 
			if (!strcmp(s, "dl"))          return _dl;
            if (!strcmp(s, "dx"))          return _dx;
            if (!strcmp(s, "dil"))         return _dil;
			if (!strcmp(s, "den_ptr"))     return _den_ptr;
			if (!strcmp(s, "dens_ptr"))    return _dens_ptr;
			if (!strcmp(s, "deci"))        return _deci;	
			if (!strcmp(s, "decii"))       return _decii;	
			if (!strcmp(s, "deci_ptr"))    return _deci_ptr;	
			if (!strcmp(s, "decii_ptr"))   return _decii_ptr;	
		    break;
        
        case 'e': 
		    if (!strcmp(s, "extern"))      return _extern; 
		    if (!strcmp(s, "equ"))         return _equ;
		    if (!strcmp(s, "end_scope"))   return _end_scope;
		    if (!strcmp(s, "end_log"))     return _end_log;
            if (!strcmp(s, "eax"))         return _eax;
            if (!strcmp(s, "ebx"))         return _ebx;
            if (!strcmp(s, "ecx"))         return _ecx;
            if (!strcmp(s, "edx"))         return _edx;
            if (!strcmp(s, "esi"))         return _esi;
            if (!strcmp(s, "edi"))         return _edi;
            if (!strcmp(s, "ebp"))         return _ebp;
            if (!strcmp(s, "esp"))         return _esp;
		    break;
        case 'f':
		 	if (!strcmp(s, "fetch")) return _fetch;	
			break;
        case 'g': 
		    if (!strcmp(s, "global")) return _global;
			if (!strcmp(s, "global_block")) return _global_block;
			if (!strcmp(s, "global_param")) return _global_param;
		    break;
		 
        case 'h':
		    if (!strcmp(s, "hold")) return _hold; 
		    break;

        case 'i':
		    if (!strcmp(s, "inc")) return _inc;
			if (!strcmp(s, "intern")) return _intern;
		    break;
        
        case 'j': 
            if (!strcmp(s, "jump")) return _jump;
            if (!strcmp(s, "jump_equal")) return _jump_equal;
            if (!strcmp(s, "jump_not_equal")) return _jump_not_equal;
            if (!strcmp(s, "jump_greater")) return _jump_great;
            if (!strcmp(s, "jump_less")) return _jump_less;
            if (!strcmp(s, "jump_neg")) return _jump_neg;
            break;
        
        case 'l': 
		    if (!strcmp(s, "log"))         return _log;
		    if (!strcmp(s, "lshift"))      return _lshift;
			if (!strcmp(s, "local"))       return _local;
			if (!strcmp(s, "local_block")) return _local_block;
		    if (!strcmp(s, "local_param")) return _local_param;
			if (!strcmp(s, "load"))        return _load;
			if (!strcmp(s, "lbrace"))      return _lbrace;
		    break;
        
        case 'm': 
            if (!strcmp(s, "move_den"))       return _move_den;
            if (!strcmp(s, "move_bay"))       return _move_bay;
            if (!strcmp(s, "move_aisle"))     return _move_aisle;
            if (!strcmp(s, "move_zone"))      return _move_zone;

            if (!strcmp(s, "move_dens"))      return _move_dens;
            if (!strcmp(s, "move_bays"))      return _move_bays;
            if (!strcmp(s, "move_aisles"))    return _move_aisles;
            if (!strcmp(s, "move_zones"))     return _move_zones;
            
			if (!strcmp(s, "mark"))          return _mark;
			if (!strcmp(s, "mark_ptr"))      return _mark_ptr;
			if (!strcmp(s, "mark_literal"))  return _mark_literal;

            if (!strcmp(s, "move_den"))      return _move_den;
            if (!strcmp(s, "move_bay"))      return _move_bay; 
            if (!strcmp(s, "move_aisle"))    return _move_aisle;
            if (!strcmp(s, "move_zone"))     return _move_zone;
            
            if (!strcmp(s, "move_dens"))     return _move_dens;
            if (!strcmp(s, "move_bays"))     return _move_bays;
            if (!strcmp(s, "move_aisles"))   return _move_aisles;
            if (!strcmp(s, "move_zones"))    return _move_zones;
            break;
        
        case 'n': 
		    if (!strcmp(s, "nop"))          return _nop; 
		    if (!strcmp(s, "not"))          return _not;
			if (!strcmp(s, "num"))          return _num;
			if (!strcmp(s, "num_ptr"))      return _num_ptr;
			if (!strcmp(s, "num_literal"))  return _num_literal;
		    break;
        
        case 'o':
		    if (!strcmp(s, "or")) return _or;
		    if (!strcmp(s, "offset")) return _offset; 
			if (!strcmp(s, "origin")) return _origin; 
			break;
        
        case 'p': 
            if (!strcmp(s, "ptr"))            return _ptr;
            if (!strcmp(s, "pass_arg"))       return _pass_arg;
            if (!strcmp(s, "passage"))        return _passage;
    
            // New Push/Pop Variants
            if (!strcmp(s, "push_den"))       return _push_den;
            if (!strcmp(s, "pop_den"))        return _pop_den;
            if (!strcmp(s, "push_bay"))       return _push_bay;
            if (!strcmp(s, "pop_bay"))        return _pop_bay;
            if (!strcmp(s, "push_aisle"))     return _push_aisle;
            if (!strcmp(s, "pop_aisle"))      return _pop_aisle;
            if (!strcmp(s, "push_zone"))      return _push_zone;
            if (!strcmp(s, "pop_zone"))       return _pop_zone;

            if (!strcmp(s, "push_dens"))       return _push_den;
            if (!strcmp(s, "pop_dens"))        return _pop_den;
            if (!strcmp(s, "push_bays"))       return _push_bay;
            if (!strcmp(s, "pop_bays"))        return _pop_bay;
            if (!strcmp(s, "push_aisles"))     return _push_aisle;
            if (!strcmp(s, "pop_aisles"))      return _pop_aisle;
            if (!strcmp(s, "push_zones"))      return _push_zone;
            if (!strcmp(s, "pop_zones"))       return _pop_zone;
            break;
        
        case 'r': 
            if (!strcmp(s, "return"))       return _return;
            if (!strcmp(s, "rshift"))       return _rshift;
            if (!strcmp(s, "rotate_left"))  return _rotate_left;
            if (!strcmp(s, "rotate_right")) return _rotate_right;
		    if (!strcmp(s, "rax"))          return _rax;
            if (!strcmp(s, "rbx")) return _rbx;
            if (!strcmp(s, "rcx")) return _rcx;
            if (!strcmp(s, "rdx")) return _rdx;
            if (!strcmp(s, "rsi")) return _rsi;
            if (!strcmp(s, "rdi")) return _rdi;
            if (!strcmp(s, "rbp")) return _rbp;
            if (!strcmp(s, "rsp")) return _rsp;
            // R8-R15 registers
            if (!strcmp(s, "r8")) return _r8;
            if (!strcmp(s, "r9")) return _r9;
            if (!strcmp(s, "r10")) return _r10;
            if (!strcmp(s, "r11")) return _r11;
            if (!strcmp(s, "r12")) return _r12;
            if (!strcmp(s, "r13")) return _r13;
            if (!strcmp(s, "r14")) return _r14;
            if (!strcmp(s, "r15")) return _r15;
            // R8D-R15D registers
            if (!strcmp(s, "r8d")) return _r8d;
            if (!strcmp(s, "r9d")) return _r9d;
            if (!strcmp(s, "r10d")) return _r10d;
            if (!strcmp(s, "r11d")) return _r11d;
            if (!strcmp(s, "r12d")) return _r12d;
            if (!strcmp(s, "r13d")) return _r13d;
            if (!strcmp(s, "r14d")) return _r14d;
            if (!strcmp(s, "r15d")) return _r15d;
            // R8W-R15W registers
            if (!strcmp(s, "r8w")) return _r8w;
            if (!strcmp(s, "r9w")) return _r9w;
            if (!strcmp(s, "r10w")) return _r10w;
            if (!strcmp(s, "r11w")) return _r11w;
            if (!strcmp(s, "r12w")) return _r12w;
            if (!strcmp(s, "r13w")) return _r13w;
            if (!strcmp(s, "r14w")) return _r14w;
            if (!strcmp(s, "r15w")) return _r15w;
            // R8B-R15B registers
            if (!strcmp(s, "r8b")) return _r8b;
            if (!strcmp(s, "r9b")) return _r9b;
            if (!strcmp(s, "r10b")) return _r10b;
            if (!strcmp(s, "r11b")) return _r11b;
            if (!strcmp(s, "r12b")) return _r12b;
            if (!strcmp(s, "r13b")) return _r13b;
            if (!strcmp(s, "r14b")) return _r14b;
            if (!strcmp(s, "r15b")) return _r15b;
			if (!strcmp(s, "rbrace")) return _rbrace;
            break;

        case 's':
            if (!strcmp(s, "sub_den"))        return _sub_den;
            if (!strcmp(s, "sub_bay"))        return _sub_bay;
            if (!strcmp(s, "sub_aisle"))      return _sub_aisle;
            if (!strcmp(s, "sub_zone"))       return _sub_zone;

            if (!strcmp(s, "sub_dens"))       return _sub_dens;
            if (!strcmp(s, "sub_bays"))       return _sub_bays;
            if (!strcmp(s, "sub_aisles"))     return _sub_aisles;
            if (!strcmp(s, "sub_zones"))      return _sub_zones;

		    if (!strcmp(s, "scope"))           return _scope;  
			if (!strcmp(s, "sign"))            return _sign;
		    if (!strcmp(s, "si"))              return _si;
            if (!strcmp(s, "sp"))              return _sp;
            if (!strcmp(s, "sil"))             return _sil;
            if (!strcmp(s, "spl"))             return _spl;
			if (!strcmp(s, "strand"))          return _strand;
			if (!strcmp(s, "strand_ptr"))      return _strand_ptr;
			if (!strcmp(s, "strand_literal"))  return _strand_literal;
			if (!strcmp(s, "set_flag"))        return _set_flag;
			break;
        case 't':
			if (!strcmp(s, "table"))           return _table;
			if (!strcmp(s, "table_ptr"))       return _table_ptr;
            if (!strcmp(s, "test"))            return _test;
		   break;
        case 'u': 
		   if (!strcmp(s, "universal")) return _universal;
		   if (!strcmp(s, "use")) return _use;
		   break; 
        case 'x': 
		    if (!strcmp(s, "xor")) return _xor;
		    break;
		case 'z':
		   if (!strcmp(s, "zone")) return _zone; 
		   if (!strcmp(s, "zone_ptr")) return _zone_ptr;
		   if (!strcmp(s, "zones_ptr")) return _zones_ptr;	
		   break;
    }
    return 0;
}

// Add a token buffer to store multiple rejected tokens
#define MAX_REJECT_TOKENS 8
struct token RejTokens[MAX_REJECT_TOKENS];
int RejCount = 0;

// Modified reject_token to handle multiple tokens
void reject_token(struct token *t) 
{
    if (RejCount >= MAX_REJECT_TOKENS)
    {
        error("Lexer error: reject token buffer full");
        return;
    }
    RejTokens[RejCount++] = *t;
}

// Modified scan to handle multiple rejected tokens
int scan(struct token *t) 
{
    if (RejCount > 0)
    {
        *t = RejTokens[--RejCount];
        return 1;
    }

    int c = skip();
    
    switch (c)
    {
		case '+': t->token_rep = _add;   break;
        case '-': t->token_rep = _sub;   break;
        case '*': t->token_rep = _mul;   break;
        case '/': t->token_rep = _div;   break;


        case '{':  t->token_rep = _lbracket;   break;
        case '}':  t->token_rep = _rbracket;   break;
		case '[':  t->token_rep = _lbrace;     break;
        case ']':  t->token_rep = _rbrace;     break;
        case ':':  t->token_rep = _colon;      break;
        case ';':  t->token_rep = _semicolon;  break;
        case ',':  t->token_rep = _comma;      break;
        case '=':  t->token_rep = _assigner;   break;
        case EOF:  t->token_rep = _enfi;       return 0;
       
        case '"':  // Handle string literals
            t->token_rep = _strand_literal;
            
            // Ensure Text is not NULL or improperly sized
            if (!Text) {
                error("Text buffer is NULL");
                return 0;
            }
            if (strlen(Text) == 0) {
                error("Text buffer is empty");
                return 0;
            }
            
            t->token_str = strdup(Text); // Store the last scanned identifier
            if (!t->token_str) {
                error("Failed to allocate memory for string identifier");
                return 0;
            }
            
            // Scan the actual string content
            scanstr(Text);
            
            // Store the string content
            t->string_value = strdup(Text);
            if (!t->string_value) {
                free(t->token_str);
                error("Failed to allocate memory for string literal value");
                return 0;
            }
        break;
        default:
            // Handle numbers (both hex and decimal)
            if (isdigit(c)) 
            {
                // Handle as regular number
                t->num_value = scanint(c, num_str);
                t->token_rep = _num_literal;

                // Store the string version of the number
                t->string_value = strdup(num_str);
                if (!t->string_value) {
                    error("Failed to allocate memory for string version of number");
                    return 0;
                }
                break;
            }

            // Handle identifiers and keywords
            if (isalpha(c) || c == '_' || c == '.') 
            {
                scanident(c, Text, text_length);
                int tokentype = keyword(Text);
                if (tokentype) {
                    t->token_rep = tokentype;
                } else {
                    t->token_rep = _ident;
                }
                break;
            }
            
            errorc("Unrecognized character", c);
            return 0;
    }

    return 1;
}
