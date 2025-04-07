#include "comp_def.h"  
#include "comp_data.h"   
#include "comp_decl.h" 

int current_file_type = NULL;

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

	c = fgetc(comp_in);      // Read from compiler input

	if ('\n' == c)
	{
		comp_line_pos++;			// Increment comp_line_pos count
	}
	return (c);
}

// Keep the original function name
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
			errorc("unknown escape sequence", c);
		}
	}
	return (c);			// Just an ordinary old character!
}

// Scan and return an integer literal
// value from the input file.
int scanint(int c)
 {
	int k, val = 0;

	// Convert each character into an int value
	while ((k = chrpos("0123456789", c)) >= 0) {
		val = val * 10 + k;
		c = next_ch();
	}

	// We hit a non-integer character, put it back.
	return_char(c);
	return (val);
}
// Function to copy contents of buf to strand_buffer
void copy_to_strand_buffer(char *strand_buffer, char *buf)
 {
	// Copy contents of buf to strand_buffer using strcpy
	strcpy(strand_buffer, buf);
}

// Scan in a string literal from the input file,
// and store it in buf[]. Return the length of
// the string. 
int scanstr(char *buf) 
{
	int i, c;

	// Loop while we have enough buffer space
	for (i = 0; i < text_length - 1; i++) {
		// Get the next char and append to buf
		// Return when we hit the ending double quote
		if ((c = scanch()) == '"') {
			buf[i] = 0;
			return (i);
		}
		buf[i] = c;
		copy_to_strand_buffer(strand_buffer, buf); // Copy contents of buf to strand_buffer
	}
	// Ran out of buf[] space
	error("String literal too long");
	return (0);
}

// Scan an identifier from the input file and
// store it in buf[]. Return the identifier's length
int scanident(int c, char *buf, int lim)
 {
	int i = 0;

	// Allow digits, alpha and underscores
	while (isalpha(c) || isdigit(c) || '_' == c) {
		if (lim - 1 == i) {
			error("Identifier too long");
		}
		buf[i++] = c;
		c = next_ch();
	}

	// If expecting filename, handle the extension
	if (c == '.') {
		if (lim - 1 == i) {
			error("Identifier too long");
		}
		buf[i++] = c;
		c = next_ch();
		
		// Read extension
		while (isalpha(c)) {
			if (lim - 1 == i) {
				error("Identifier too long");
			}
			buf[i++] = c;
			c = next_ch();
		}
	}

	return_char(c);
	buf[i] = '\0';
	return i;
}

// Given a word from the input, return the matching keyword token number or 0 if it's not a keyword.
// Switch on the first letter so that we don't have to waste time strcmp()ing against all the keywords.
int keyword(char *s)
{
	switch (*s)
	{
	case 'a': 
		if (!strcmp(s, "alter"))  return (_alter);
		if (!strcmp(s, "assign"))  return (_assign);
		if (!strcmp(s, "address"))  return (_address);
		if (!strcmp(s, "arg_ptr")) return (_arg_ptr);
		if (!strcmp(s, "aisle"))  return (_aisle);
		if (!strcmp(s, "aisles")) return (_aisles);
		if (!strcmp(s, "aisle_ptr")) return (_aisle_ptr);
		if (!strcmp(s, "aisles_ptr")) return (_aisles_ptr);

		break;
	case 'b':
		if (!strcmp(s, "break")) return (_break);
		if (!strcmp(s, "bridge")) return (_bridge);
		if (!strcmp(s, "bit_ptr")) return (_bit_ptr);
		if (!strcmp(s, "byte_ptr")) return (_byte_ptr);
		if (!strcmp(s, "bay"))  return (_bay);
		if (!strcmp(s, "bays")) return (_bays);
		if (!strcmp(s, "bay_ptr")) return (_bay_ptr);
		if (!strcmp(s, "bays_ptr")) return (_bays_ptr);
		break;
	case 'c':
		if (!strcmp(s, "compare"))   return (_compare);
		if (!strcmp(s, "check"))     return (_check);
		if (!strcmp(s, "call"))      return (_call);
		if (!strcmp(s, "cycle"))     return (_cycle);
		if (!strcmp(s, "change_global")) return (_change_global);
		if (!strcmp(s, "change_local")) return (_change_local);
		if (!strcmp(s, "continue")) return (_continue);	
		if (!strcmp(s, "cycle")) return (_cycle);
		if (!strcmp(s, "connect")) return (_connect);
        if (!strcmp(s, "convert")) return (_convert);
		break;
	case 'd':
		if (!strcmp(s, "deci")) return (_deci);
		if (!strcmp(s, "data_manager"))   return (_data_manager);
		if (!strcmp(s, "deci_ptr")) return (_deci_ptr);
		if (!strcmp(s, "decii_ptr")) return (_decii_ptr);
		if (!strcmp(s, "deciv_ptr")) return (_deciv_ptr);
		if (!strcmp(s, "decviii_ptr")) return (_decviii_ptr);
		if (!strcmp(s, "den"))  return (_den);
		if (!strcmp(s, "dens")) return (_dens);
		if (!strcmp(s, "den_ptr")) return (_den_ptr);
		if (!strcmp(s, "dens_ptr")) return (_dens_ptr);
		break;
	case 'e':
		if (!strcmp(s, "else"))    return (_else);
		if (!strcmp(s, "extern"))  return (_extern);
		if (!strcmp(s, "env_ptr")) return (_env_ptr);
		if (!strcmp(s, "end_state")) return (_end_state);
		if (!strcmp(s, "end_use")) return (_end_use);
		if (!strcmp(s, "end_link")) return (_end_link);

		break;
	case 'f':
		if (!strcmp(s, "function")) return (_function);
		if (!strcmp(s, "func_ptr")) return (_func_ptr);
		if (!strcmp(s, "file_ptr")) return (_file_ptr);
		if (!strcmp(s, "frambebuffer_ptr")) return (_frambebuffer_ptr);
		if (!strcmp(s, "false")) return (_false_literal);
		break;
	case 'g':
		if (!strcmp(s, "get_use")) return (_get_use);
		if (!strcmp(s, "get_link")) return (_get_link);
	    break;
	case 'h':
		if (!strcmp(s, "hollow")) return (_hollow);
		if (!strcmp(s, "hold"))   return (_hold);
		if (!strcmp(s, "header_file"))   return (_header_file);
		if (!strcmp(s, "heap_ptr")) return (_heap_ptr);
		if (!strcmp(s, "hollow_ptr")) return (_hollow_ptr);
	
		break;
	case 'i':
	    if (!strcmp(s, "intern")) return (_intern);
		break;
	case 'l':
		if (!strcmp(s, "long_num")) return (_long_num);
		if (!strcmp(s, "log"))  return (_log);
		if (!strcmp(s, "list")) return (_list);
		if (!strcmp(s, "line")) return (_line);
		if (!strcmp(s, "loop")) return (_loop);
		if (!strcmp(s, "link")) return (_link);
		if (!strcmp(s, "long_ptr")) return (_long_ptr);
		if(!strcmp(s, "loop_func")) return (_loop_func);
		if (!strcmp(s, "line_use")) return (_line_use);
		if (!strcmp(s, "line_link")) return (_line_link);

		break;
	case 'm':
		if (!strcmp(s, "mark"))      return (_mark);
		if (!strcmp(s, "manager"))      return (_manager);
		if (!strcmp(s, "mod_file"))      return (_mod_file);
		if (!strcmp(s, "mana_ptr")) return (_mana_ptr);
		if (!strcmp(s, "macro_ptr")) return (_macro_ptr);
		if (!strcmp(s, "mark_ptr")) return (_mark_ptr);

		break;
	case 'n':
		if (!strcmp(s, "num"))  return (_num);
		if (!strcmp(s, "next"))      return (_next);
		if (!strcmp(s, "num_ptr")) return (_num_ptr);
		if (!strcmp(s, "network")) return (_network);
		break;
	case 'o':
		if (!strcmp(s, "otherwise"))  return (_otherwise);
	    
		break;
	case 'p':
		if (!strcmp(s, "proceed"))   return (_proceed);
		if (!strcmp(s, "pass_arg"))  return (_pass_arg);
		if (!strcmp(s, "ptr"))       return (_ptr);
		if (!strcmp(s, "pare"))      return (_pare);
		if (!strcmp(s, "pixel_ptr")) return (_pixel_ptr);
		if (!strcmp(s, "polygon_ptr")) return (_polygon_ptr);
		if (!strcmp(s, "passage_ptr")) return (_passage_ptr);
		if (!strcmp(s, "passage")) return (_passage);
		if (!strcmp(s, "passage_type")) return (_passage_type);
		if (!strcmp(s, "port_hub")) return (_port_hub);
		if (!strcmp(s, "proto"))     return (_proto);
	
		break;
	case 'r':
		if (!strcmp(s, "replace")) return (_replace);
		if (!strcmp(s, "refer")) return (_refer);
		if (!strcmp(s, "read")) return (_read);
		if (!strcmp(s, "retrieve")) return (_retrieve);
		break;
	case 's':
		if (!strcmp(s, "set_loop")) return (_set_loop);
		if (!strcmp(s, "source_file")) return (_source_file);
		if (!strcmp(s, "strand")) return (_strand);
		if (!strcmp(s, "strand_ptr")) return (_strand_ptr);
		if (!strcmp(s, "stack_ptr")) return (_stack_ptr);
		if (!strcmp(s, "stack_base_ptr")) return (_stack_base_ptr);
		if (!strcmp(s, "stack_pos_ptr")) return (_stack_pos_ptr);
		if (!strcmp(s, "stack_frame_ptr")) return (_stack_frame_ptr);
		if (!strcmp(s, "stack_limit_ptr")) return (_stack_limit_ptr);
        if (!strcmp(s, "shader_ptr")) return (_shader_ptr);
		if (!strcmp(s, "step")) return (_step);
		if (!strcmp(s, "state")) return (_state);
		if (!strcmp(s, "sub_state")) return (_sub_state);
		if (!strcmp(s, "start_use")) return (_start_use);
		if (!strcmp(s, "start_link")) return (_start_link);

		break;
	case 't':
		if (!strcmp(s, "table"))      return (_table);
		if (!strcmp(s, "transfer"))   return (_transfer);
		if (!strcmp(s, "tripare"))    return (_tripare);
		if (!strcmp(s, "type_ptr")) return (_type_ptr);
		if (!strcmp(s, "texture_ptr")) return (_texture_ptr);
		if (!strcmp(s, "table_ptr")) return (_table_ptr);
		if (!strcmp(s, "true")) return (_true_literal);
		break;
	case 'u':
		if (!strcmp(s, "use"))   return (_use);

		break;
	case 'v':
		if (!strcmp(s, "vertex_ptr")) return (_vertex_ptr);
		if (!strcmp(s, "vector_ptr")) return (_vector_ptr);
		if (!strcmp(s, "vine_ptr")) return (_vine_ptr);
		if (!strcmp(s, "vine")) return (_vine);
		if (!strcmp(s, "vine_type")) return (_vine_type);

		break;
	case 'w':
		if (!strcmp(s, "write"))   return (_write);

		break;
	case 'y':
		if (!strcmp(s, "yield"))   return (_yield);

		break;
	case 'z':
		if (!strcmp(s, "zone"))  return (_zone);
		if (!strcmp(s, "zones")) return (_zones);
		if (!strcmp(s, "zone_ptr")) return (_zone_ptr);
		if (!strcmp(s, "zones_ptr")) return (_zones_ptr);
		break;
	}
	return (0);
}

struct token *Rejtoken = NULL;

// Reject the token that we just scanned
void reject_token(struct token *t)
{
	if (Rejtoken != NULL)
	{
		error(" lexer error: you can not reject the token twice");
	}
	Rejtoken = t;
}

// Add helper function to peek at next character without consuming it
int peek(void)
 {
    int c = next_ch();
    return_char(c);
    return c;
}

// Scan and return the next token found in the input.
// Return 1 if token valid, 0 if no tokens left.
int scan(struct token *t) 
{
	int c, tokentype;


	// If we have any rejected token, return it
	if (Rejtoken != NULL) 
	{
		t = Rejtoken;
		Rejtoken = NULL;
		return (1);
	}

	// Skip whitespace
	c = skip();

	// Determine the token based on the input character
	switch (c)
	{
	case '@':  t->token_rep = _at_sign;   break;
	case '[':  t->token_rep = _lbrace;    break;
	case ']':  t->token_rep = _rbrace;    break;
	case '(':  t->token_rep = _lparen;    break;
	case ')':  t->token_rep = _rparen;    break;
	case '{':  t->token_rep = _lbracket;  break;
	case '}':  t->token_rep = _rbracket;  break;
	case '~':  t->token_rep = _invert;    break;
	case '^':  t->token_rep = _xor;       break;


	case ':':  t->token_rep = _colon;      break;
	case '`':  t->token_rep = _ender;      break;

	case '.':  t->token_rep = _period;       break;
	case ',':  t->token_rep = _comma;     break;

	case ';':  t->token_rep = _semicolon;      break;

	case '+':
		if ((c = next_ch()) == '+') {
			t->token_rep = _increment;
		}
		else {
			return_char(c);
			t->token_rep = _plus;
		}
		break;
	case '-':
		if ((c = next_ch()) == '-') {
			t->token_rep = _decrement;
		}
		else if (c == '>') {
			t->token_rep = _arrow;
		}
		else {
			return_char(c);
			t->token_rep = _minus;
		}
		break;
	case '*': t->token_rep = _multi;   break;

	case '/': t->token_rep = _divi; break;
	case '=':
		if ((c = next_ch()) == '=') {
			t->token_rep = _equal;
		}
		else {
			return_char(c);
			t->token_rep = _assigner;
		}
		break;
	case '!':
		if ((c = next_ch()) == '=') {
			t->token_rep = _not_equal;
		}
		else {
			return_char(c);
			t->token_rep = _logic_not;
		}
		break;
	case '<':
		if ((c = next_ch()) == '=') {
			t->token_rep = _less_equal;
		}
		else if (c == '<') {
			t->token_rep = _lshift;
		}
		else {
			return_char(c);
			t->token_rep = _less_then;
		}
		break;
	case '>':
		if ((c = next_ch()) == '=') {
			t->token_rep = _great_equal;
		}
		else if (c == '>') {
			t->token_rep = _rshift;
		}
		else {
			return_char(c);
			t->token_rep = _great_then;
		}
		break;
	case '&':
		if ((c = next_ch()) == '&') {
			t->token_rep = _logic_and;
		}
		else {
			return_char(c);
			t->token_rep = _address;
		}
		break;
	case '|':
		if ((c = next_ch()) == '|') {
			t->token_rep = _logic_or;
		}
		else {
			return_char(c);
			t->token_rep = _or;
		}
		break;

	case '\'':
    // If it's a quote, scan in the literal character value and the trailing quote
    t->num_value = scanch();
    if (next_ch() != '\'') {
        error("Expected closing quote for mark literal");
    }
    t->token_rep = _mark_literal;  // Changed from _num_literal to _mark_literal
    break;  
	case '"':
		// Scan in a literal string
		scanstr(Text);
		t->token_rep = _strand_literal;
		break;

	case EOF: 
		t->token_rep = _enfi; 
		return (0);

	default:
        // If it's a digit, scan it as a whole number
        if (isdigit(c)) {
            t->num_value = scanint(c);
            t->token_rep = _num_literal;
        }
       else if (isalpha(c) || '_' == c) {
            // Read in a keyword or identifier
            scanident(c, Text, text_length);

            // Check if it's a keyword
            if ((tokentype = keyword(Text)) != 0) {
                t->token_rep = tokentype;
                break;
            }
            t->token_rep = _ident;
            break;
        } else {  errorc(" Unrecognised character", c);   // The character isn't part of any recognised token, error
        }
        break;
	}

	return (1);
}

