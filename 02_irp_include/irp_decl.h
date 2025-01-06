// Add these declarations
#include <stdbool.h>



// Lexer function prototypes
int chrpos(char *s, int c);
int next(void);
void return_char(int c);
int skip(void);
int scanch(void);
int scanint(int c);
void copy_to_strand_buffer(char *strand_buffer, char *buf);
int scanstr(char *buf);
int scanident(int c, char *buf, int lim);
int keyword(char *s);
void reject_token(struct token *t);
int scan(struct token *t);




int process_file_manager_file(void);


// File processor function prototypes
void process_use_directive(void);
void process_link_directive(void);

// Output content handlers
void output_use_content(void);
void output_link_content(void);



// Comment and line processing
char* remove_comments(char* line);
bool is_empty_or_comment(const char* line);


bool is_valid_main_log(int type);
bool is_valid_sub_log(int type);


// Error handling function prototypes
void error_handler(int error_code);
void error(const char *message);
void errors(const char *message, const char *s);
void errorc(const char *message, int c);




// File management directives
void use(int t, char *expected);
void replace(int t, char *expected);
void link(int t, char *expected);
void match_log(int t, char *expected);

// Additional directives
void transfer(int t, char *expected);
void type_check(int t, char *expected);
void collect(int t, char *expected);

// Token matching function prototypes
void ident(int t, char *expected);
void colon(int t, char *expected);
void comma(int t, char *expected);
void semicolon(int t, char *expected);
