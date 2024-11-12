#include <msp430.h>
#include "led.h"

void led_init() {
    P1DIR |= LEDS;            // Set LED pins as outputs
    led_update();
}

void led_update() {
    P1OUT &= ~LEDS; // Turn off both LEDs initially
    if (led_state) {
        P1OUT |= LED_GREEN;
    } else {
        P1OUT |= LED_RED;
    }
}

void led_pattern1() {
    for (int i = 0; i < 3; i++) {
        P1OUT |= LED_RED;
        __delay_cycles(500000);
        P1OUT &= ~LED_RED;
        __delay_cycles(500000);
    }
}

void led_pattern2() {
    for (int i = 0; i < 5; i++) {
        P1OUT ^= LED_GREEN;
        __delay_cycles(300000);
    }
}

void led_pattern3() {
    for (int i = 0; i < 2; i++) {
        P1OUT |= LED_RED;
        __delay_cycles(700000);
        P1OUT &= ~LED_RED;
    }
}

void led_pattern4() {
    P1OUT |= LED_GREEN;
    __delay_cycles(200000);
    P1OUT &= ~LED_GREEN;
    __delay_cycles(200000);
}
