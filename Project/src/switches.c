#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"

short sound;
char switch_state_down, period, switch_state_changed;

static char 
switch_update_interrupt_sense()
{
    char p2val = P2IN;
    P2IES |= (p2val & SWITCHES);    /* if switch up, sense down */
    P2IES &= (p2val | ~SWITCHES);   /* if switch down, sense up */
    return p2val;
}

// Initialize Switch Control
void switch_init() {  
    P2REN |= SWITCHES;      /* enables resistors for switches */
    P2IE = SWITCHES;        /* enable interrupts from switches */
    P2OUT |= SWITCHES;      /* pull-ups for switches */
    P2DIR &= ~SWITCHES;     /* set switches' bits for input */
    switch_update_interrupt_sense();
    switch_interrupt_handler();
}

// Button Interrupt Handler
void switch_interrupt_handler() {
    char p2val = switch_update_interrupt_sense();
    char sw_button_1 = (p2val & SW1) ? 0 : SW1;
    char sw_button_2 = (p2val & SW2) ? 0 : SW2;
    char sw_button_3 = (p2val & SW3) ? 0 : SW3;
    char sw_button_4 = (p2val & SW4) ? 0 : SW4;

    if (sw_button_1) {
        play_jingle(jingle1);
        led_pattern1();
    } else if (sw_button_2) {
        play_jingle(jingle2);
        led_pattern2();
    } else if (sw_button_3) {
        play_jingle(jingle3);
        led_pattern3();
    } else if (sw_button_4) {
        play_jingle(jingle4);
        led_pattern4();
    }
}
