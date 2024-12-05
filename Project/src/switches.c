#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"

char switch_state_down, switch_state_changed;

// Update the interrupt sense for switches
static char switch_update_interrupt_sense() {
    char p2val = P2IN;            // Read the current state of P2
    P2IES |= (p2val & SWITCHES);  // Set edge detect for high-to-low transitions
    P2IES &= (p2val | ~SWITCHES); // Set edge detect for low-to-high transitions
    return p2val;
}

// Initialize switches
void switch_init() {
    P2REN |= SWITCHES;  // Enable resistors for switches
    P2IE |= SWITCHES;   // Enable interrupts for switches
    P2OUT |= SWITCHES;  // Set pull-up resistors
    P2DIR &= ~SWITCHES; // Set switches as inputs
    switch_update_interrupt_sense();
}

// Handle switch interrupts
void switch_interrupt_handler() {
    char p2val = switch_update_interrupt_sense(); // Get switch state

    if (!(p2val & SW1)) {
        play_jingle1();
        led_state = 0;
    } else if (!(p2val & SW2)) {
        play_jingle2();
        led_state = 1;
    } else if (!(p2val & SW3)) {
        play_jingle3();
        led_state = 2;
    } else if (!(p2val & SW4)) {
        play_jingle4();
        led_state = 3;
    }
    led_changed = 1;   // Mark LEDs as changed
    led_update();      // Update the LEDs
}
