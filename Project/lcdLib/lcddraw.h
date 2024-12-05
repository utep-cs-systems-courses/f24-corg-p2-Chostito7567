#ifndef lcdDraw_included
#define lcdDraw_included

#include "lcdutils.h"

// Define types if they aren't already
typedef unsigned char u_char;
typedef unsigned int u_int;

// Function prototypes
void drawPixel(u_char col, u_char row, u_int colorBGR);
void drawString5x7(u_char col, u_char row, const char *string, u_int fgColorBGR, u_int bgColorBGR);
void drawChar5x7(u_char col, u_char row, char c, u_int fgColorBGR, u_int bgColorBGR);
void fillRectangle(u_char colMin, u_char rowMin, u_char width, u_char height, u_int colorBGR);
void drawRectOutline(u_char colMin, u_char rowMin, u_char width, u_char height, u_int colorBGR);

#endif // lcdDraw_included
