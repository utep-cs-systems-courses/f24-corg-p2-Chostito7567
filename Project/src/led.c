#include <msp430.h>
#include "led.h"
#include "stateMachines.h"

// Definition of ledFlags in led.c
static char ledFlags = 0; // Define and initialize ledFlags. `static` makes it private to this file.

unsigned char led_changed = 0, green_on=0, red_on=0, led_state=0;

void led_init() {
  P1DIR |= LEDS;  // Set LED pins as output
  led_changed = 1;
  led_update();
}

void led_update() {
  if (led_changed) {
    if (!(led_state)) {
      ledFlags |= LED_RED;
    } else {
      ledFlags |= LED_GREEN;
    }
    
    P1OUT &= (0xff ^ LEDS) | ledFlags; // Clear bits for off LEDs
    P1OUT |= ledFlags; // Set bits for on LEDs
    led_changed = 0;
  }
}

void led_advance() {
  led_state += 1;
  led_changed = 1;
}
