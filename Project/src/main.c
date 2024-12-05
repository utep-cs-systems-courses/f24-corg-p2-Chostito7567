#include <msp430.h>
#include "buzzer.h"
#include "switches.h"
#include "libTimer.h"

void main() {
    configureClocks();     // Set up system clocks
    buzzer_init();         // Initialize buzzer
    switch_init();         // Initialize buttons

    enableWDTInterrupts(); // Enable watchdog timer interrupts
    or_sr(0x18);           // Enter low-power mode with interrupts enabled

    while (1) {
        // Main loop remains empty; interrupts handle the logic
    }
}
