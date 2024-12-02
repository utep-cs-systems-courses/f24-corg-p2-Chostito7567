#include <msp430.h>
#include "buzzer.h"    // For play_jingle1, play_jingle2, etc.
#include "libTimer.h"  // For configureClocks, enableWDTInterrupts, or_sr
#include "lcdgame.h"   // LCD handling functions
#include "switches.h"  // Button handling

// Function to generate random prompts
char generate_prompt() {
    char prompts[] = {'w', 's', 'a', 'd', '?'};  // w=UP, s=DOWN, a=LEFT, d=RIGHT
    return prompts[rand() % 5];  // Return a random prompt
}

// Function to get player's input from buttons
char get_player_input() {
    char p2val = P2IN;  // Read switch input
    if (!(p2val & SW1)) return 'w';  // SW1 for UP
    if (!(p2val & SW2)) return 's';  // SW2 for DOWN
    if (!(p2val & SW3)) return 'a';  // SW3 for LEFT
    if (!(p2val & SW4)) return 'd';  // SW4 for RIGHT
    return '\0';  // No input detected
}

void play_game() {
    lcd_game_init();  // Initialize the LCD
    buzzer_init();    // Initialize the buzzer

    while (lives > 0) {  // Game runs until lives reach 0
        char prompt = generate_prompt();  // Generate random prompt
        lcd_display_prompt(prompt);       // Display the prompt on the LCD

        if (prompt != '?') {
            if (prompt == 'w') play_jingle1();
            if (prompt == 's') play_jingle2();
            if (prompt == 'a') play_jingle3();
            if (prompt == 'd') play_jingle4();
        }

        char input = '\0';
        while (input == '\0') {  // Wait for player input
            input = get_player_input();
        }

        if (input == prompt || (prompt == '?' && input == 'w')) {  // Example: '?' is UP
            lcd_correct_input();
        } else {
            lcd_incorrect_input();
        }

        __delay_cycles(500000);  // Delay before the next prompt
    }

    lcd_game_over();  // Show Game Over screen
}

void main() {
    configureClocks();  // Configure system clocks
    switch_init();      // Initialize switches
    enableWDTInterrupts();  // Enable watchdog interrupts
    or_sr(0x8);         // Enable low-power mode

    play_game();        // Start the game
}
