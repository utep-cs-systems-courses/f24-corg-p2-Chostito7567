#include <msp430.h>
#include "buzzer.h"
#include "libTimer.h"

void buzzer_init() {
    timerAUpmode();        // Initialize Timer A
    P2SEL2 &= ~(BIT6 | BIT7); // Set buzzer pin function
    P2SEL &= ~BIT7;
    P2SEL |= BIT6;
    P2DIR |= BIT6;         // Set buzzer pin as output
}

void buzzer_set_period(short cycles) {
    CCR0 = cycles;         // Set buzzer period
    CCR1 = cycles >> 1;    // 50% duty cycle
}

void play_jingle1() {
    short notes[] = {1000, 0, 800, 0, 600, 0, 400, 0};
    for (int i = 0; i < 8; i++) {
        buzzer_set_period(notes[i]);
        __delay_cycles(500000);
    }
    buzzer_set_period(0);  // Turn off buzzer
}

void play_jingle2() {
    short notes[] = {500, 0, 700, 0, 900, 0, 1100, 0};
    for (int i = 0; i < 8; i++) {
        buzzer_set_period(notes[i]);
        __delay_cycles(500000);
    }
    buzzer_set_period(0);
}

void play_jingle3() {
    short notes[] = {1200, 0, 1000, 0, 800, 0, 600, 0};
    for (int i = 0; i < 8; i++) {
        buzzer_set_period(notes[i]);
        __delay_cycles(500000);
    }
    buzzer_set_period(0);
}

void play_jingle4() {
    short notes[] = {1500, 0, 1300, 0, 1100, 0, 900, 0};
    for (int i = 0; i < 8; i++) {
        buzzer_set_period(notes[i]);
        __delay_cycles(500000);
    }
    buzzer_set_period(0);
}
