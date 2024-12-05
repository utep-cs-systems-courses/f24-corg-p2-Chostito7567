#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"

// Enum for LED modes
static enum {off=0, dim=1, bright=2} ledMode;
static char pwmCount = 0;  // Counter for PWM duty cycle

// Slowly cycle through LED modes
void sm_slow_clock() {
    ledMode = (ledMode + 1) % 3;  // Cycle through off, dim, and bright
}

// Quickly cycle through PWM levels
void sm_fast_clock() {
    pwmCount = (pwmCount + 1) & 3;  // Cycle through 0 to 3
}

// Update the LED based on the mode
void sm_update_led() {
    char new_red_on;
    switch (ledMode) {
    case off:
        new_red_on = 0; break;       // Red LED off
    case bright:
        new_red_on = 1; break;       // Red LED fully on
    case dim:
        new_red_on = (pwmCount < 1); break; // 25% duty cycle
    }
    if (red_on != new_red_on) {
        red_on = new_red_on;         // Update LED state
        led_changed = 1;             // Mark LEDs as changed
    }
}
