#ifndef LCDGAME_H
#define LCDGAME_H

#include "../lcdLib/lcdutils.h"  // Correct path to lcdutils.h
#include "../lcdLib/lcddraw.h"   // Correct path to lcddraw.h

extern int lives;  // Declare `lives` as a global variable

void lcd_game_init();
void lcd_display_score();
void lcd_display_lives();
void lcd_display_prompt(char prompt);
void lcd_correct_input();
void lcd_incorrect_input();
void lcd_game_over();

#endif // LCDGAME_H
