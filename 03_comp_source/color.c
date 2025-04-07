#include <stdio.h>







//first eight bits of color (dark colors)
void black(void)           // 0;30 - correct
{
    printf("\033[0;30m");
}

void dark_red(void)        // 0;31 - was sea_green
{
    printf("\033[0;31m");
}

void dark_green(void)      // 0;32 - was keyword_dorange
{
    printf("\033[0;32m");
}

void dark_yellow(void)     // 0;33 - was keyword_teal
{
    printf("\033[0;33m");
}

void dark_blue(void)       // 0;34 - was keyword_strand
{
    printf("\033[0;34m");
}

void dark_magenta(void)    // 0;35 - was keyword_cyan
{
    printf("\033[0;35m");
}

void dark_cyan(void)       // 0;36 - was keyword_blue
{
    printf("\033[0;36m");
}

void dark_gray(void)       // 0;37 - was keyword_dgray
{
    printf("\033[0;37m");
}


//second eight bits of color (bright colors)
void light_gray(void)      // 1;30 - was keyword_lgray
{
    printf("\033[1;30m");
}

void light_red(void)       // 1;31 - was keyword_red
{
    printf("\033[1;31m");
}

void light_green(void)     // 1;32 - was keyword_slate
{
    printf("\033[1;32m");
}

void light_yellow(void)    // 1;33 - was keyword_yellow
{
    printf("\033[1;33m");
}

void light_blue(void)      // 1;34 - was keyword_dblue
{
    printf("\033[1;34m");
}

void light_magenta(void)   // 1;35 - was keyword_rosy
{
    printf("\033[1;35m");
}

void light_cyan(void)      // 1;36 - was keyword_lorange
{
    printf("\033[1;36m");
}

void white(void)           // 1;37 - was keyword_white
{
    printf("\033[1;37m");
}


void reset(void)           // correct
{
    printf("\033[0m");
}
