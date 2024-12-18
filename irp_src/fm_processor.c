#include "irp_def.h"  
#include "irp_data.h"   
#include "irp_decl.h" 



void process_use_directive(void) 
{
    while(1)
    {
        scan(&Token);
        if(Token.token_rep == _ident) {
            output_use_content();
        }
        else if(Token.token_rep == _semicolon) {
            semicolon(_semicolon, ";");
            break;
        }
        else if(Token.token_rep == _comma) {
            comma(_comma, ",");
            continue;
        }
    }
}

void process_link_directive(void) 
{
    while(1)
    {
        scan(&Token);
        if(Token.token_rep == _ident) {
            output_link_content();
        }
        else if(Token.token_rep == _semicolon) {
            semicolon(_semicolon, ";");
            break;
        }
        else if(Token.token_rep == _comma) {
            comma(_comma, ",");
            continue;
        }
    }
}


// Helper function to change the file extension
void change_extension(char *filename, const char *new_extension) {
    char *dot = strrchr(filename, '.');
    if (dot) {
        *dot = '\0';  // Remove the existing extension
    }
    strcat(filename, new_extension);  // Append the new extension
}

void output_use_content(void) 
{
    FILE *prev_file, *new_file;
    char first_name[100] = {0};
    char second_name[100] = {0};

    ident(_ident, Text);
    strcpy(first_name, Text);
    change_extension(first_name, ".h");

    prev_file = fopen(first_name, "r");
    if (!prev_file) {
        return;
    }

    strcpy(second_name, Text);
    change_extension(second_name, ".i");

    new_file = fopen(second_name, "w");
    if (!new_file) {
        fclose(prev_file);
        return;
    }

    fprintf(new_file, "start_use @%s @line 0\n", second_name);

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), prev_file)) {
        fputs(buffer, new_file);
    }

    fprintf(new_file, "\nend_use\n");

    fclose(prev_file);
    fclose(new_file);
}

void output_link_content(void)
{
    FILE *prev_file, *new_file;
    char first_name[100] = {0};
    char second_name[100] = {0};

    ident(_ident, Text);
    strcpy(first_name, Text);
    change_extension(first_name, ".ill");

    prev_file = fopen(first_name, "r");
    if (!prev_file) {
        return;
    }

    strcpy(second_name, Text);
    change_extension(second_name, ".p");

    new_file = fopen(second_name, "w");
    if (!new_file) {
        fclose(prev_file);
        return;
    }

    fprintf(new_file, "start_link @%s @line 0\n", second_name);

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), prev_file)) {
        fputs(buffer, new_file);
    }

    fprintf(new_file, "\nend_link\n");

    fclose(prev_file);
    fclose(new_file);
}


char* remove_comments(char* line) {
    static char cleaned[1024];
    char* p = cleaned;
    char* s = line;
    static bool in_multiline = false;
    
    // If we're inside a multi-line comment, look for the end
    if (in_multiline) {
        while (*s) {
            if (s[0] == '*' && s[1] == '/') {
                in_multiline = false;
                s += 2;
                break;
            }
            s++;
        }
        if (in_multiline) {
            cleaned[0] = '\0';
            return NULL;
        }
    }

    // Process the rest of the line
    while (*s) {
        // Check for single-line comment
        if (s[0] == '/' && s[1] == '/') {
            *p = '\0';  // End the line at the start of a single-line comment
            return cleaned;
        }
        // Check for multi-line comment start
        if (s[0] == '/' && s[1] == '*') {
            in_multiline = true;
            s += 2;
            while (*s) {
                if (s[0] == '*' && s[1] == '/') {
                    in_multiline = false;
                    s += 2;
                    break;
                }
                s++;
            }
            continue;
        }
        if (!in_multiline) {
            *p++ = *s;
        }
        s++;
    }
    *p = '\0';
    
    return cleaned[0] ? cleaned : NULL;
}

bool is_empty_or_comment(const char* line) {
    while (*line) {
        if (!isspace(*line)) return false;
        line++;
    }
    return true;
}