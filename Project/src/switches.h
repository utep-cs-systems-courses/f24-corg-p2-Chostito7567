#ifndef switches_included
#define switches_included

#define SW1 BIT0       // Button 1
#define SW2 BIT1       // Button 2
#define SW3 BIT2       // Button 3
#define SW4 BIT3       // Button 4
#define SWITCHES (SW1 | SW2 | SW3 | SW4)

void switch_init();               // Initialize switches
void switch_interrupt_handler();  // Handle switch interrupts

#endif // switches_included
