#ifndef COLOR_H
#define COLOR_H




// Dark colors (first eight bits)
void black(void);           // 0;30
void dark_red(void);        // 0;31
void dark_green(void);      // 0;32
void dark_yellow(void);     // 0;33
void dark_blue(void);       // 0;34
void dark_magenta(void);    // 0;35
void dark_cyan(void);       // 0;36
void dark_gray(void);       // 0;37

// Light colors (second eight bits)
void light_gray(void);      // 1;30
void light_red(void);       // 1;31
void light_green(void);     // 1;32
void light_yellow(void);    // 1;33
void light_blue(void);      // 1;34
void light_magenta(void);   // 1;35
void light_cyan(void);      // 1;36
void white(void);           // 1;37

// Reset color
void reset(void);           // 0m

#endif // COLOR_H
