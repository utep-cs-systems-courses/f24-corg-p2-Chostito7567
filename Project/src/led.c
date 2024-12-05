#include <msp430.h>
#include "led.h"

// Global variables to track LED changes
unsigned char led_changed = 0, green_on = 0, red_on = 0, led_state = 0;

// Initialize LEDs
void led_init() {
    P1DIR |= LEDS;          // Set LED pins (P1.0 and P1.6) as outputs
    led_changed = 1;        // Mark the LEDs as needing an update
    led_update();           // Update the LED state immediately
}

// Update LEDs based on the current state
void led_update() {
    if (led_changed) {      // Only update if something has changed
        switch (led_state) {
        case 0:
            P1OUT = LED_RED;       // Turn on red LED only
            break;
        case 1:
            P1OUT = LED_GREEN;     // Turn on green LED only
            break;
        case 2:
            P1OUT = LEDS;          // Turn on both LEDs
            break;
        case 3:
            P1OUT = 0;             // Turn off both LEDs
            break;
        }
        led_changed = 0;    // Reset the flag after updating
    }
}
