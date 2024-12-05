#include <msp430.h>
#include "switches.h"

// Interrupt handler for buttons
void __interrupt_vec(PORT2_VECTOR) Port_2() {
    if (P2IFG & SWITCHES) {  // Check if a button caused the interrupt
        P2IFG &= ~SWITCHES;  // Clear pending interrupts
        switch_interrupt_handler();  // Handle button press
    }
}
