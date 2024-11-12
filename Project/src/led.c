#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "buzzer.h"

unsigned char led_changed = 0, green_on = 0, red_on = 0, led_state = 0;

// Initialize LEDs on the board
void led_init()
{
  P1DIR |= LEDS;                      // Set LED pins as outputs
  led_changed = 1;                    // Trigger an update to set initial LED state
  led_update();
}

void led_update()
{
  if (led_changed)
  {
    // Turn off both LEDs initially
    P1OUT &= ~LEDS; 

    // Set the LED state based on led_state variable
    switch (led_state)
    {
      case 0:
        P1OUT |= LED_RED;  // Turn on RED LED
        break;
      case 1:
        P1OUT |= LED_GREEN; // Turn on GREEN LED
        break;
    }
    led_changed = 0; // Reset the flag after updating LEDs
  }
}

// Toggle between Red and Green LED
void led_toggle()
{
  led_state = 1 - led_state; // Toggle between 0 (Red) and 1 (Green)
  led_changed = 1;           // Mark change for update
}

// Advance the LED state in a cyclic manner
void led_advance()
{
  led_state = (led_state + 1) % 2; // Cycle between 0 and 1
  led_changed = 1;                 // Mark change for update
}
