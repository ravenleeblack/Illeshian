#include <stdio.h>

//first eight bits of color
void black(void)
{
	printf("\033[0;30m");
}

void sea_green(void)
{
	printf("\033[0;31m");
}

void keyword_dorange(void)
{
	printf("\033[0;32m");
}

void keyword_teal(void)
{
	printf("\033[0;33m");
}

void keyword_strand(void)
{
	printf("\033[0;34m");
}

void keyword_cyan(void)
{
	printf("\033[0;35m");
}

void keyword_blue(void)
{
	printf("\033[0;36m");
}

void keyword_dgray(void)
{
	printf("\033[0;37m");
}


//second eight bits of color
void keyword_lgray(void)
{
	printf("\033[1;30m");
}

void keyword_red(void)
{
	printf("\033[1;31m");
}

void keyword_slate(void)
{
	printf("\033[1;32m");
}

void keyword_yellow(void)
{
	printf("\033[1;33m");
}

void keyword_dblue(void)
{
	printf("\033[1;34m");
}

void keyword_rosy(void)
{
	printf("\033[1;35m");
}

void keyword_lorange(void)
{
	printf("\033[1;36m");
}

void keyword_white(void)
{
	printf("\033[1;37m");
}


void reset(void)
{
	printf("\033[0m");
}
