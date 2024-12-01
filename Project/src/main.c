#include <msp430.h>
#include "lcdgame.h"  // Include LCD screen functions
#include "libTimer.h"
#include "switches.h" // Include button handling
#include "buzzer.h"   // Include buzzer functionality

char generate_prompt() {
    char prompts[] = {'↑', '↓', '←', '→', '?'};  // Possible prompts
    return prompts[rand() % 5];  // Randomly select one
}

char get_player_input() {
    char p2val = P2IN;  // Read switch input
    if (!(p2val & SW1)) return '↑';
    if (!(p2val & SW2)) return '↓';
    if (!(p2val & SW3)) return '←';
    if (!(p2val & SW4)) return '→';
    return '\0';  // No input detected
}

void play_game() {
    lcd_game_init();  // Initialize the LCD
    buzzer_init();    // Initialize the buzzer

    while (lives > 0) {  // Continue the game until lives reach 0
        char prompt = generate_prompt();  // Generate a random prompt
        lcd_display_prompt(prompt);       // Display the prompt on the screen

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

        if (input == prompt || (prompt == '?' && input == '↑')) {  // Example: '?' requires UP
            lcd_correct_input();  // Show correct feedback
        } else {
            lcd_incorrect_input();  // Show incorrect feedback
        }

        __delay_cycles(500000);  // Wait before the next prompt
    }

    lcd_game_over();  // Display the game-over screen
}

void main() {
    configureClocks();  // Set up the clocks
    switch_init();      // Initialize switches
    enableWDTInterrupts();  // Enable interrupts
    or_sr(0x8);         // Enable low-power mode

    play_game();  // Start the game
}
