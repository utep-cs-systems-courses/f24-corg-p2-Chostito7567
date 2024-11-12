#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"  // Include the buzzer header for jingle handling

// Enum to define LED modes
static enum {off = 0, dim = 1, bright = 2} ledMode;
static char pwmCount = 0;  // For PWM control

// Function to cycle LED brightness slowly
void sm_slow_clock()  // Slowly cycle through {off, dim, bright}
{
  ledMode = (ledMode + 1) % 3;
}

// Function to cycle LED brightness quickly
void sm_fast_clock()  // Quickly cycle through 0...3
{
  pwmCount = (pwmCount + 1) & 3; 
}

// Function to update the LED state
void sm_update_led()
{
  char new_red_on;
  switch (ledMode) {
  case off:
    new_red_on = 0; break;
  case bright:
    new_red_on = 1; break;
  case dim:
    new_red_on = (pwmCount < 1); break;  // 25% duty cycle
  }
  if (red_on != new_red_on) {
    red_on = new_red_on;
    led_changed = 1;
  }
}

// Function to toggle the red LED (always toggles)
char toggle_red()
{
  static char state = 0;

  switch (state) {
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  return 1;  // Always changes an LED
}

// Function to toggle the green LED (only when red is on)
char toggle_green()
{
  char changed = 0;
  if (red_on) {
    green_on ^= 1;
    changed = 1;
  }
  return changed;
}

// Function to alternate between toggling red & green LEDs
void state_advance()  
{
  char changed = 0;  

  static enum {R = 0, G = 1} color = G;
  switch (color) {
  case R: 
    changed = toggle_red(); 
    color = G; 
    break;
  case G: 
    changed = toggle_green(); 
    color = R; 
    break;
  }

  led_changed = changed;  // Update the LED change status
  led_update();
}

// Function to handle the LED behavior and jingles based on button presses
void handle_button_press(char button) 
{
  if (button == 1) {  // Button S1
    led_state = 0; 
    play_jingle(jingle1);  // Play jingle 1
    led_changed = 1;
    sm_update_led();  // Update LED state
    led_update();
  }
  else if (button == 2) {  // Button S2
    led_state = 0;
    play_jingle(jingle2);  // Play jingle 2
    led_changed = 1;
    sm_update_led();
    led_update();
  }
  else if (button == 3) {  // Button S3
    led_state = 0;
    play_jingle(jingle3);  // Play jingle 3
    led_changed = 1;
    sm_update_led();
    led_update();
  }
  else if (button == 4) {  // Button S4
    led_state = 0;
    play_jingle(jingle4);  // Play jingle 4
    led_changed = 1;
    sm_update_led();
    led_update();
  }
}
