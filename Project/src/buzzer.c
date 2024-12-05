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

// Play Jingle 1
void play_jingle1() {
    short jingle1[] = {1000, 0, 800, 0, 600, 0, 400, 0};
    for (int i = 0; i < 8; i++) {
        buzzer_set_period(jingle1[i]);
        __delay_cycles(500000);
    }
    buzzer_set_period(0); // Turn off sound
}

// Play Jingle 2
void play_jingle2() {
    short jingle2[] = {500, 0, 700, 0, 900, 0, 1100, 0};
    for (int i = 0; i < 8; i++) {
        buzzer_set_period(jingle2[i]);
        __delay_cycles(500000);
    }
    buzzer_set_period(0); // Turn off sound
}

// Play Jingle 3
void play_jingle3() {
    short jingle3[] = {1200, 0, 1000, 0, 800, 0, 600, 0};
    for (int i = 0; i < 8; i++) {
        buzzer_set_period(jingle3[i]);
        __delay_cycles(500000);
    }
    buzzer_set_period(0); // Turn off sound
}

// Play Jingle 4
void play_jingle4() {
    short jingle4[] = {1500, 0, 1300, 0, 1100, 0, 900, 0};
    for (int i = 0; i < 8; i++) {
        buzzer_set_period(jingle4[i]);
        __delay_cycles(500000);
    }
    buzzer_set_period(0); // Turn off sound
}
