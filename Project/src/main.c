#include <msp430.h>
#include "led.h"
#include "stateMachines.h"
#include "buzzer.h"
#include "switches.h"
#include "libTimer.h"
#include "lcdgame.h"

void main() {
    // Timer
    configureClocks();          // Start Lib Timer

    // Initialize peripherals
    switch_init();              // Setup Switches
    buzzer_init();              // Call Speakers
    led_init();                 // Call LEDs
    lcd_game_init();            // Initialize LCD

    // Draw a square on the LCD
    lcd_draw_square();

    // Power off CPU
    enableWDTInterrupts();      // Enable Watchdog Timer
    or_sr(0x18);
}
