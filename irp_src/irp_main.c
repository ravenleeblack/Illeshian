#include "irp_def.h"  
#include "irp_data.h"   
#include "irp_decl.h" 

char * input_file = NULL;
char * output_file = NULL;

                 
int comp_line_pos = 0;
int putback_char = '\n';
int output_flag = 0;

FILE* irp_out = NULL;
FILE* irp_in = NULL;

int process_file_manager_file(void)
{
    while(1)
    {
        scan(&Token);
        if(Token.token_rep == _enfi)
        {
            break;
        }
        switch (Token.token_rep)
        {
            case _use:   
                use(_use, "use");

                scan(&Token);
                colon(_colon, ":");
                process_use_directive();
                break;
            case _link:  
                link(_link, "link");

                scan(&Token);
                colon(_colon, ":");
                process_link_directive();
                break;
            default: break;
        }
    }

    return 0;
}

int main(int argc, char *argv[])
{
    int result = 0;

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-o") == 0)
         {
            output_flag = 1;
            //printf("Output flag enabled\n");               suppose to be quite like gcc
        } else 
        {
            input_file = argv[i];
            //printf("Input file: %s\n", input_file);   suppose to be quite like gcc
        }
    }


    irp_in = fopen(input_file, "r");
    if (!irp_in) {
        printf("Failed to open %s: %s\n", input_file, strerror(errno));
        return 1;
    }

    result = process_file_manager_file();

    if (irp_in) fclose(irp_in);
    if (irp_out) fclose(irp_out);

    return result;
}