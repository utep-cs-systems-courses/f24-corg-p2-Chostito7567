#include <stdint.h>  // Provides uint8_t, uint16_t, etc.

// Define missing types expected by lcddraw.h
typedef unsigned char u_char;
typedef unsigned int u_int;

#include "../lcdLib/lcddraw.h"   // Correct path to lcddraw.h
#include "../lcdLib/lcdutils.h" // Correct path to lcdutils.h
#include "buzzer.h"
#include "libTimer.h"
#include "lcdgame.h"
#include "switches.h"

// Generate a random prompt from available options
char generate_prompt() {
    char prompts[] = {'w', 'a', 's', 'd', '?'};  // Available prompts
    return prompts[rand() % 5];                  // Return a random prompt
}

// Main game logic
void play_game() {
    lcd_game_init();  // Initialize the game display

    while (1) {
        char prompt = generate_prompt();  // Generate a random prompt
        lcd_display_prompt(prompt);       // Display the prompt on the screen

        char input = ' ';  // Placeholder for user input
        // Simulate getting user input (replace this with actual input handling)
        __delay_cycles(2500000);  // Wait for user input (simulate delay)

        if (input == prompt || (prompt == '?' && input != ' ')) {
            lcd_correct_input();  // If input is correct, update score
        } else {
            lcd_incorrect_input();  // If input is incorrect, decrement lives
        }

        if (lives <= 0) break;  // End the game when lives reach 0
    }

    lcd_game_over();  // Display game over screen
}

// Main program
void main() {
    configureClocks();      // Configure system clocks
    switch_init();          // Initialize switches
    enableWDTInterrupts();  // Enable watchdog interrupts
    or_sr(0x8);             // Enable low-power mode

    play_game();            // Start the game
}
