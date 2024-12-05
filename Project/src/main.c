#include <msp430.h>
#include "led.h"
#include "stateMachines.h"
#include "buzzer.h"
#include "switches.h"
#include "libTimer.h"

// Main function
void main() {
    configureClocks();          // Set up the system clocks
    switch_init();              // Initialize the switches
    buzzer_init();              // Initialize the buzzer
    led_init();                 // Initialize the LEDs
    enableWDTInterrupts();      // Enable the watchdog timer interrupts

    or_sr(0x18);                // Enter low-power mode with interrupts enabled
}
