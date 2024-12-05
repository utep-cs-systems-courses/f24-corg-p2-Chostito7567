#include <msp430.h>
#include "buzzer.h"
#include "libTimer.h"

void buzzer_init() {
    // Configure P2.6 for buzzer output
    timerAUpmode();
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7;
    P2SEL |= BIT6;
    P2DIR |= BIT6;
}

void buzzer_set_period(short cycles) {
    CCR0 = cycles;
    CCR1 = cycles >> 1; // 50% duty cycle
}

// Define different jingles for each button
void play_jingle1() {
    short jingle1[] = {1200, 0, 1000, 0, 800, 0, 600, 0}; // Higher frequency range
    for (int i = 0; i < 8; i++) {
        buzzer_set_period(jingle1[i]);
        __delay_cycles(500000);
    }
    buzzer_set_period(0); // Turn off sound
}

void play_jingle2() {
    short jingle2[] = {1000, 0, 1200, 0, 1400, 0, 1600, 0}; // Mid-range with increasing pitch
    for (int i = 0; i < 8; i++) {
        buzzer_set_period(jingle2[i]);
        __delay_cycles(500000);
    }
    buzzer_set_period(0);
}

void play_jingle3() {
    short jingle3[] = {3000, 0, 2600, 0, 2200, 0, 1800, 0}; // Low-frequency descending tones
    for (int i = 0; i < 8; i++) {
        buzzer_set_period(jingle3[i]);
        __delay_cycles(500000);
    }
    buzzer_set_period(0);
}

void play_jingle4() {
    short jingle4[] = {1900, 0, 1700, 0, 1500, 0, 1300, 0}; // Mixed range, starting high and dipping lower
    for (int i = 0; i < 8; i++) {
        buzzer_set_period(jingle4[i]);
        __delay_cycles(500000);
    }
    buzzer_set_period(0);
}
