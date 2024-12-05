#include <msp430.h>
#include "switches.h"

// Handles button press interrupts
void __interrupt_vec(PORT2_VECTOR) Port_2() {
    if (P2IFG & SWITCHES) {  // Check if a button caused the interrupt
        P2IFG &= ~SWITCHES;  // Clear interrupt flags
        switch_interrupt_handler();  // Handle button press
    }
}
