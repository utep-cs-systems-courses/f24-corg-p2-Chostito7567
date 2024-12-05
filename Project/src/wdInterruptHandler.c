#include <msp430.h>

void __interrupt_vec(WDT_VECTOR) WDT() {
    // This is for the watchdog timer (optional, can remain empty for now)
}
