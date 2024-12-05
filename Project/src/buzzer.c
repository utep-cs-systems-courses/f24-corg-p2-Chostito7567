#include <msp430.h>
#include "buzzer.h"
#include "libTimer.h"

// Initialize the buzzer
void buzzer_init() {
    timerAUpmode();       // Configure Timer A in up mode
    P2SEL2 &= ~(BIT6 | BIT7);  // Set P2.6 for peripheral function
    P2SEL &= ~BIT7;
    P2SEL |= BIT6;         // Select Timer A output for P2.6
    P2DIR |= BIT6;         // Set P2.6 as an output
}

// Set the buzzer frequency (number of cycles per second)
void buzzer_set_period(short cycles) {
    CCR0 = cycles;          // Set the period of the PWM signal
    CCR1 = cycles >> 1;     // Set a 50% duty cycle (on for half the time)
}

// Play a predefined jingle (array of frequencies)
void play_jingle1() {
    short jingle1[] = {1000, 0, 800, 0, 600, 0, 400, 0};  // Frequencies and pauses
    for (int i = 0; i < 8; i++) {
        buzzer_set_period(jingle1[i]);  // Set the buzzer frequency
        __delay_cycles(500000);        // Delay for half a second
    }
    buzzer_set_period(0);              // Turn off the buzzer at the end
}
