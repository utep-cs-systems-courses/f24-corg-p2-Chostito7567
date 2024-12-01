#ifndef LCDGAME_H
#define LCDGAME_H

// Initialize the LCD for the game
void lcd_game_init();

// Display the current score on the LCD
void lcd_display_score();

// Display the remaining lives on the LCD
void lcd_display_lives();

// Display a prompt (e.g., arrows or "?") on the LCD
void lcd_display_prompt(char prompt);

// Handle correct input (update score and display feedback)
void lcd_correct_input();

// Handle incorrect input (decrease lives and display feedback)
void lcd_incorrect_input();

// Display the "Game Over" screen
void lcd_game_over();

#endif // LCDGAME_H
