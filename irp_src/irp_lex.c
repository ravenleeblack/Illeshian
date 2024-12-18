#include "irp_def.h"  
#include "irp_data.h"   
#include "irp_decl.h" 


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

	c = fgetc(irp_in);		// Read from input file


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
			errorc("Unknown escape sequence", c);
			return 0;
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

	return_char(c);
	return (val);
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


    switch (*s)
	{
        case 'l': 
		    if (!strcmp(s, "link")) return _link;
		    break;
        
        case 'u': 
		   if (!strcmp(s, "use")) return _use;
		   break;
    }
    return 0;
}

struct token *Rejtoken = NULL;

// Reject the token that we just scanned
void reject_token(struct token *t)
{
	if (Rejtoken != NULL)
	{
		error("Lexer error: cannot reject token twice");
	}
	Rejtoken = t;
}


// Scan and return the next token found in the input.
// Return 1 if token valid, 0 if no tokens left.
int scan(struct token *t) 
{
    int c = skip();
    
    switch (c)
    {
	    case '{':  t->token_rep = _lbracket;  break;
	    case '}':  t->token_rep = _rbracket;  break;
        case ':': t->token_rep = _colon;     break;
        case ';': t->token_rep = _semicolon; break;
        case ',': t->token_rep = _comma;     break;
		case '=': t->token_rep = _assigner;     break;
        case EOF: t->token_rep = _enfi;      return 0;
        default:
            // Handle numbers
            if (isdigit(c)) {
                t->num_value = scanint(c);
                t->token_rep = _num_literal;
                break;
            }
            // Handle hex numbers
            if (c == '0' && (next_ch() == 'x' || next_ch() == 'X')) {
                t->num_value = scanhex();
                t->token_rep = _hex_literal;
                break;
            }
            // Handle identifiers and keywords
            if (isalpha(c) || c == '_' || c == '.')  // Removed '.' from here
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
            
            // Handle other characters
            errorc("Unrecognized character", c);
            return 0;
    }

    return 1;
}

// Scan and return a hexadecimal number
int scanhex(void) {
    int c, h, val = 0;

    while (1) {
        c = next_ch();
        if (c >= '0' && c <= '9')
            h = c - '0';
        else if (c >= 'a' && c <= 'f')
            h = c - 'a' + 10;
        else if (c >= 'A' && c <= 'F')
            h = c - 'A' + 10;
        else {
            return_char(c);
            return val;
        }
        val = val * 16 + h;
    }
}
