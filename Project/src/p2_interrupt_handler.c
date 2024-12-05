#include <msp430.h>
#include "switches.h"

void __interrupt_vec(PORT2_VECTOR) Port_2() {
    if (P2IFG & SWITCHES) {  // Check if a switch caused the interrupt
        P2IFG &= ~SWITCHES;  // Clear the interrupt flag
        switch_interrupt_handler();  // Call the switch handler
    }
}
