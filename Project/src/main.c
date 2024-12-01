#include <msp430.h>
#include "lcdgame.h"  // For LCD screen functionality
#include "libTimer.h"
#include "switches.h" // For button handling
#include "buzzer.h"   // For sound effects


// Function to generate random prompts (e.g., arrows or "?")
char generate_prompt() {
    char prompts[] = {'↑', '↓', '←', '→', '?'}; // Possible prompts
    return prompts[rand() % 5];  // Randomly select one
}

// Function to get the player's input based on button presses
char get_player_input() {
    char p2val = P2IN;  // Read switch input
    if (!(p2val & SW1)) return '↑';
    if (!(p2val & SW2)) return '↓';
    if (!(p2val & SW3)) return '←';
    if (!(p2val & SW4)) return '→';
    return '\0';  // No input detected
}

// Main game loop
void play_game() {
    lcd_game_init();  // Initialize the LCD screen
    buzzer_init();    // Initialize the buzzer

    while (1) {
        char prompt = generate_prompt();  // Generate a random prompt
        lcd_display_prompt(prompt);       // Show the prompt on the screen

        if (prompt != '?') {
            // Play a tone corresponding to the prompt
            if (prompt == '↑') play_jingle1();
            if (prompt == '↓') play_jingle2();
            if (prompt == '←') play_jingle3();
            if (prompt == '→') play_jingle4();
        }

        char input = '\0';
        while (input == '\0') {  // Wait for player input
            input = get_player_input();
        }

        // Handle input
        if (input == prompt || (prompt == '?' && input == '↑')) { // Example: '?' is tied to '↑'
            lcd_correct_input();  // Show feedback for correct input
        } else {
            lcd_incorrect_input();  // Show feedback for incorrect input
        }

        if (lives <= 0) break;  // End game when lives reach 0
        __delay_cycles(500000); // Wait before next prompt (adjust for game speed)
    }

    lcd_game_over();  // Show the game-over screen
}

// Main function
void main() {
    configureClocks();        // Set up system clocks
    switch_init();            // Initialize the switches
    enableWDTInterrupts();    // Enable watchdog timer interrupts
    or_sr(0x8);               // Enable global interrupts (GIE)

    play_game();              // Start the game
}
