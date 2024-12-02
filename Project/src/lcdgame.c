#include "../lcdLib/lcddraw.h"  // Include drawing functions only (no lcdutils.h)

#define MAX_LIVES 3  // Maximum number of lives a player has

int lives = MAX_LIVES;  // Declare `lives` as a global variable
static int score = 0;   // The player's current score

/** Initialize the LCD for the game */
void lcd_game_init() {
    clearScreen(COLOR_BLACK);  // Set the screen to black
    drawString5x7(10, 5, "Game Start!", COLOR_WHITE, COLOR_BLACK);  // Display starting message
}

/** Display the player's score */
void lcd_display_score() {
    char scoreText[16];
    sprintf(scoreText, "Score: %d", score);  // Format score text
    drawString5x7(10, 20, scoreText, COLOR_WHITE, COLOR_BLACK);
}

/** Display remaining lives */
void lcd_display_lives() {
    char livesText[16];
    sprintf(livesText, "Lives: %d", lives);  // Format lives text
    drawString5x7(10, 30, livesText, COLOR_WHITE, COLOR_BLACK);
}

/** Display a prompt */
void lcd_display_prompt(char prompt) {
    clearScreen(COLOR_BLACK);  // Clear screen before showing prompt
    lcd_display_score();       // Update the score
    lcd_display_lives();       // Update lives

    // Show the prompt
    if (prompt == '↑') {
        drawString5x7(50, 50, "UP", COLOR_YELLOW, COLOR_BLACK);
    } else if (prompt == '↓') {
        drawString5x7(50, 50, "DOWN", COLOR_YELLOW, COLOR_BLACK);
    } else if (prompt == '←') {
        drawString5x7(50, 50, "LEFT", COLOR_YELLOW, COLOR_BLACK);
    } else if (prompt == '→') {
        drawString5x7(50, 50, "RIGHT", COLOR_YELLOW, COLOR_BLACK);
    } else if (prompt == '?') {
        drawString5x7(50, 50, "?", COLOR_RED, COLOR_BLACK);  // Wildcard
    }
}

/** Handle correct input */
void lcd_correct_input() {
    score++;  // Increment the player's score
    drawString5x7(10, 40, "Correct!", COLOR_GREEN, COLOR_BLACK);
}

/** Handle incorrect input */
void lcd_incorrect_input() {
    lives--;  // Decrement lives
    drawString5x7(10, 40, "Incorrect!", COLOR_RED, COLOR_BLACK);
}

/** Display the game over screen */
void lcd_game_over() {
    clearScreen(COLOR_BLACK);  // Clear the screen
    drawString5x7(30, 50, "GAME OVER", COLOR_RED, COLOR_BLACK);  // Game over message
    char finalScore[16];
    sprintf(finalScore, "Score: %d", score);  // Show the player's final score
    drawString5x7(40, 80, finalScore, COLOR_WHITE, COLOR_BLACK);
}
