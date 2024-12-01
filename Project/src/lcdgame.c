#include <msp430.h>
#include "lcdutils.h"
#include "lcddraw.h"

#define MAX_LIVES 3  // Maximum number of lives a player has

// Global variables to track the game state
static int score = 0  // The player's current score
static int lives = MAX_LIVES  // The player's remaining lives

// Initialize the LCD screen for the game. 
// Clears the screen and displays a "Game Start!" message.
void lcd_game_init() {
    lcd_init()  // Initialize the LCD hardware
    clearScreen(COLOR_BLACK)  // Set the background to black
    drawString5x7(10, 5, "Game Start!", COLOR_WHITE, COLOR_BLACK)  // Welcome message
}

// Display the player's current score on the LCD screen. 
// Updates the screen with "Score: X", where X is the player's score.
void lcd_display_score() {
    char scoreText[16]                  // Buffer to hold the score text
    sprintf(scoreText, "Score: %d", score)  // Format the score into the buffer
    drawString5x7(10, 20, scoreText, COLOR_WHITE, COLOR_BLACK)  // Display the score
}

// Display the player's remaining lives on the LCD screen. 
// Updates the screen with "Lives: X", where X is the number of lives left.
void lcd_display_lives() {
    char livesText[16]                   // Buffer to hold the lives text
    sprintf(livesText, "Lives: %d", lives)  // Format the lives into the buffer
    drawString5x7(10, 30, livesText, COLOR_WHITE, COLOR_BLACK)  // Display the lives
}

// Display a prompt on the screen (e.g., "↑", "↓", "←", "→", or "?"). 
// Clears the screen, shows the score, lives, and the prompt.
void lcd_display_prompt(char prompt) {
    clearScreen(COLOR_BLACK)  // Clear the screen for a fresh display
    lcd_display_score()       // Show the current score
    lcd_display_lives()       // Show the remaining lives

    // Display the prompt based on its type
    if (prompt == '↑') {
        drawString11x16(50, 50, "UP", COLOR_YELLOW, COLOR_BLACK)  // UP arrow
    } else if (prompt == '↓') {
        drawString11x16(50, 50, "DOWN", COLOR_YELLOW, COLOR_BLACK)  // DOWN arrow
    } else if (prompt == '←') {
        drawString11x16(50, 50, "LEFT", COLOR_YELLOW, COLOR_BLACK)  // LEFT arrow
    } else if (prompt == '→') {
        drawString11x16(50, 50, "RIGHT", COLOR_YELLOW, COLOR_BLACK)  // RIGHT arrow
    } else if (prompt == '?') {
        drawString11x16(50, 50, "?", COLOR_RED, COLOR_BLACK)  // Wildcard "?"
    }
}

// Handle a correct player input. 
// Increments the score and displays a "Correct!" message.
void lcd_correct_input() {
    score++  // Increase the player's score
    drawString5x7(10, 40, "Correct!", COLOR_GREEN, COLOR_BLACK)  // Feedback message
}

// Handle an incorrect player input. 
// Decreases the player's lives and displays an "Incorrect!" message.
void lcd_incorrect_input() {
    lives--  // Decrease the player's lives
    drawString5x7(10, 40, "Incorrect!", COLOR_RED, COLOR_BLACK)  // Feedback message
}

// Display the "Game Over" screen when the player loses all lives. 
// Shows the final score in the center of the screen.
void lcd_game_over() {
    clearScreen(COLOR_BLACK)  // Clear the screen for the final message
    drawString11x16(30, 50, "GAME OVER", COLOR_RED, COLOR_BLACK)  // Game over text
    char finalScore[16]                 // Buffer to hold the final score
    sprintf(finalScore, "Score: %d", score)  // Format the score into the buffer
    drawString5x7(40, 80, finalScore, COLOR_WHITE, COLOR_BLACK)  // Display the final score
}
