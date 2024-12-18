#ifndef ILL_DECL_H
#define ILL_DECL_H

// Process function prototypes
void process_irp(const char* filename);


void process_compiler(const char** source_files, int num_files);


void process_seedling(const char* source_file);
void process_rootling(const char* source_file);

// Error handling prototypes
void error_handler(int error_code);
void error(const char* message);
void errors(const char* message, const char* s);
void errorc(const char* message, int c);

#endif