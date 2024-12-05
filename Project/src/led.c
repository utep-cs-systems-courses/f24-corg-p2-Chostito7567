#include <msp430.h>
#include "led.h"

unsigned char led_state = 0;   // Current LED state
unsigned char led_changed = 0; // Flag for changes in LED state

void led_init() {
    P1DIR |= LEDS;  // Set LED pins as outputs
    led_changed = 1;
    led_update();
}

void led_update() {
    if (led_changed) {
        char ledFlags = 0;  // Default: LEDs off
        if (led_state == 0) {
            ledFlags |= LED_RED;  // Red LED on
        } else if (led_state == 1) {
            ledFlags |= LED_GREEN;  // Green LED on
        }
        P1OUT &= ~LEDS;  // Clear LEDs
        P1OUT |= ledFlags;
        led_changed = 0;
    }
}
