#include <msp430.h>
#include "switches.h"

// Interrupt handler for Port 2
void __interrupt_vec(PORT2_VECTOR) Port_2() {
    if (P2IFG & SWITCHES) {      // Check if any switch caused the interrupt
        P2IFG &= ~SWITCHES;      // Clear the interrupt flag for switches
        switch_interrupt_handler();  // Handle the switch input
    }
}
