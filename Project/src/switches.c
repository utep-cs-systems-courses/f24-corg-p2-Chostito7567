#include <msp430.h>
#include "switches.h"

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
    } else if (!(p2val & SW2)) {
        play_jingle2();  // Play Jingle 2 for Button 2
    } else if (!(p2val & SW3)) {
        play_jingle3();  // Play Jingle 3 for Button 3
    } else if (!(p2val & SW4)) {
        play_jingle4();  // Play Jingle 4 for Button 4
    }
}
