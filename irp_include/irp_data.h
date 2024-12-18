#define text_length 60
#define MAX_FILES 250

int comp_line_pos;		     	                         
int putback_char;		     	                    

FILE * irp_in;                                  
FILE * irp_out;                                 

struct token Token;		                         
char Text[text_length + 1];		                
char strand_buffer[text_length + 1];


int output_flag;

