#include <msp430.h>
#include "switches.h"
#include "buzzer.h"  // Include buzzer.h to declare play_jingleX
#include "../lcdLib/lcddraw.h"
#include "../lcdLib/lcdutils.h"

// Initializes the switches
void switch_init() {
    P2REN |= SWITCHES;   // Enable resistors for switches
    P2IE |= SWITCHES;    // Enable interrupts for switches
    P2OUT |= SWITCHES;   // Set switches to pull-up
    P2DIR &= ~SWITCHES;  // Set switches as input
    P2IFG &= ~SWITCHES;  // Clear any pending interrupts
}

// Handles button press interrupts
void switch_interrupt_handler() {
    char p2val = P2IN;  // Read current state of P2 switches

    if (!(p2val & SW1)) {
        play_jingle1();  // Play Jingle 1 for Button 1
        drawString5x7(10, 50, "SW1 PRESSED", COLOR_GREEN, COLOR_BLACK);  // Debug on LCD
    } else if (!(p2val & SW2)) {
        play_jingle2();  // Play Jingle 2 for Button 2
        drawString5x7(10, 60, "SW2 PRESSED", COLOR_YELLOW, COLOR_BLACK);
    } else if (!(p2val & SW3)) {
        play_jingle3();  // Play Jingle 3 for Button 3
        drawString5x7(10, 70, "SW3 PRESSED", COLOR_BLUE, COLOR_BLACK);
    } else if (!(p2val & SW4)) {
        play_jingle4();  // Play Jingle 4 for Button 4
        drawString5x7(10, 80, "SW4 PRESSED", COLOR_RED, COLOR_BLACK);
    }
}
