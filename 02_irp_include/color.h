#ifndef COLOR_H
#define COLOR_H

// function color prototypes
void black(void);
void sea_green(void);
void keyword_dorange(void);
void keyword_teal(void);
void keyword_strand(void);
void keyword_cyan(void);
void keyword_blue(void);
void keyword_dgray(void);

void keyword_lgray(void);
void keyword_red(void);
void keyword_slate(void);
void keyword_yellow(void);
void keyword_dblue(void);
void keyword_rosy(void);
void keyword_lorange(void);
void keyword_white(void);


void reset(void);                 // Reset the color so that other printfs coming won't be forced to take the color, especially the console default text.

#endif // COLOR_H
