#include <stdint.h>
#include <stdlib.h>   // For rand()
#include <stdio.h>    // For debugging and sprintf
#include "../lcdLib/lcddraw.h"
#include "../lcdLib/lcdutils.h"
#include "buzzer.h"
#include "libTimer.h"
#include "lcdgame.h"
#include "switches.h"

// Typedefs for compatibility with lcdLib
typedef unsigned char u_char;
typedef unsigned int u_int;

extern int lives;  // Global variable for lives

// Generates a random prompt (e.g., 'w', 'a', 's', 'd', '?')
char generate_prompt() {
    char prompts[] = {'w', 'a', 's', 'd', '?'};
    return prompts[rand() % 5];
}

// Game logic
void play_game() {
    lcd_game_init();

    while (1) {
        char prompt = generate_prompt();
        lcd_display_prompt(prompt);

        char input = ' ';  // Placeholder for input
        __delay_cycles(2500000);  // Simulate delay for testing

        // For demo purposes, assume correct input
        if (input == prompt || (prompt == '?' && input != ' ')) {
            lcd_correct_input();
        } else {
            lcd_incorrect_input();
        }

        if (lives <= 0) break;  // Exit if lives run out
    }

    lcd_game_over();
}

// Main function
void main() {
    configureClocks();     // Initialize system clocks
    lcd_init();            // Initialize LCD
    buzzer_init();         // Initialize buzzer
    switch_init();         // Initialize buttons

    enableWDTInterrupts(); // Enable watchdog timer interrupts
    or_sr(0x8);            // Enter low-power mode with interrupts

    play_game();           // Start the game
}
