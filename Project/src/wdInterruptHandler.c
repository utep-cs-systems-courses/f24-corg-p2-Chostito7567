#include <msp430.h>
#include "stateMachines.h"

// Watchdog Timer interrupt handler
void __interrupt_vec(WDT_VECTOR) WDT() {
    static char blink_count = 0;  // Counter for slow clock

    if (++blink_count == 125) {  // Slow clock updates every 125 interrupts
        sm_slow_clock();
        blink_count = 0;
    }
    sm_fast_clock();       // Fast clock updates every interrupt
    sm_update_led();       // Update LED brightness
    led_update();          // Apply LED changes
}
