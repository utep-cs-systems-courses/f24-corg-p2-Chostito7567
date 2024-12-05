#include <msp430.h>
#include "led.h"

unsigned char red_on = 0, green_on = 0, led_changed = 0;

void led_init() {
    P1DIR |= LEDS;    // Set LED pins as output
    P1OUT &= ~LEDS;   // Initialize LEDs to be off
    led_changed = 1;
    led_update();
}

void led_update() {
    if (led_changed) {
        char ledFlags = 0; // Reset LED flags

        if (red_on) {
            ledFlags |= LED_RED;  // Turn on red LED
        }
        if (green_on) {
            ledFlags |= LED_GREEN; // Turn on green LED
        }

        P1OUT = (P1OUT & ~LEDS) | ledFlags; // Update LEDs
        led_changed = 0;
    }
}
