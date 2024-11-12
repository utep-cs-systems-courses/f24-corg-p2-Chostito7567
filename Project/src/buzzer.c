#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "stateMachines.h"
#include "buzzer.h"

short sound;
char switch_state_down, period, switch_state_changed; /* effectively boolean */

static char 
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  P2IES |= (p2val & SWITCHES);    /* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);    /* if switch down, sense up */
  return p2val;
}

// Initialize Switch Control
void switch_init()
{  
  P2REN |= SWITCHES;    /* enables resistors for switches */
  P2IE = SWITCHES;      /* enable interrupts from switches */
  P2OUT |= SWITCHES;    /* pull-ups for switches */
  P2DIR &= ~SWITCHES;   /* set switches' bits for input */
  switch_update_interrupt_sense();
  switch_interrupt_handler();
  led_update();  // Update LEDs at startup
}

// Change Button States
void switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  char sw_button_1 = (p2val & SW1) ? 0 : SW1;
  char sw_button_2 = (p2val & SW2) ? 0 : SW2;
  char sw_button_3 = (p2val & SW3) ? 0 : SW3;
  char sw_button_4 = (p2val & SW4) ? 0 : SW4;

  // Button 1: Jingle 1 (set frequency, change LEDs)
  if(sw_button_1)
  {
    led_state = 0;  // Example LED pattern for button 1
    sound = 1000;
    period = 10;
    buzzer_play_sound();
    led_changed = 1;
    led_advance();
    led_update();
    switch_state_down = 1;
  }

  // Button 2: Jingle 2
  if(sw_button_2)
  {
    led_state = 1;  // Another LED pattern for button 2
    sound = 2000;
    period = 20;
    buzzer_play_sound();
    led_changed = 1;
    led_advance();
    led_update();
    switch_state_down = 1;
  }

  // Button 3: Jingle 3
  if(sw_button_3)
  {
    led_state = 2;  // Another LED pattern for button 3
    sound = 3000;
    period = 30;
    buzzer_play_sound();
    led_changed = 1;
    led_advance();
    led_update();
    switch_state_down = 1;
  }

  // Button 4: Jingle 4
  if(sw_button_4)
  {
    led_state = 3;  // Another LED pattern for button 4
    sound = 4000;
    period = 40;
    buzzer_play_sound();
    led_changed = 1;
    led_advance();
    led_update();
    switch_state_down = 1;
  }
}
