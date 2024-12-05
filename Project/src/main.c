#include <stdint.h>
#include <stdlib.h>   // For rand()
#include "../lcdLib/lcddraw.h"
#include "../lcdLib/lcdutils.h"
#include "buzzer.h"
#include "libTimer.h"
#include "lcdgame.h"
#include "switches.h"

typedef unsigned char u_char;
typedef unsigned int u_int;

extern int lives;  // Global variable for lives

char generate_prompt() {
    char prompts[] = {'w', 'a', 's', 'd', '?'};
    return prompts[rand() % 5];
}

void play_game() {
    lcd_game_init();

    while (1) {
        char prompt = generate_prompt();
        lcd_display_prompt(prompt);

        char input = ' ';  // Placeholder for input
        __delay_cycles(2500000);  // Simulate delay

        if (input == prompt || (prompt == '?' && input != ' ')) {
            lcd_correct_input();
        } else {
            lcd_incorrect_input();
        }

        if (lives <= 0) break;
    }

    lcd_game_over();
}

void main() {
    configureClocks();
    lcd_init();       // Initialize LCD
    buzzer_init();    // Initialize buzzer
    switch_init();    // Initialize switches

    enableWDTInterrupts();  // Enable watchdog
    or_sr(0x8);             // Low-power mode

    play_game();  // Start the game
}
