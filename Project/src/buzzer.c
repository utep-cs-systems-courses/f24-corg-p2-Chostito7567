#include <msp430.h>
#include "buzzer.h"
#include "libTimer.h"

// Initializes the buzzer
void buzzer_init() {
    timerAUpmode();  // Set up Timer A
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7;
    P2SEL |= BIT6;
    P2DIR |= BIT6;
}

// Sets the buzzer frequency
void buzzer_set_period(short cycles) {
    CCR0 = cycles;           // Set period
    CCR1 = cycles >> 1;      // Set 50% duty cycle
}
