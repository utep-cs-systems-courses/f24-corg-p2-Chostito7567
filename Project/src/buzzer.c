#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

#define MIN_SONG_LENGTH 900
#define MAX_SONG_LENGTH 90000
static unsigned int song_length = 2500;
static signed int change_rate = 250;

void buzzer_init()
{
    timerAUpmode();		    /* Used to drive speaker */
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6;		      /* Enable output to speaker (P2.6) */
    buzzer_play_sound();  // Make Some Noise on initialization
}

void buzzer_set_period(short cycles)
{
  CCR0 = cycles; 
  CCR1 = cycles >> 1;		/* One half cycle */
}

void buzzer_play_sound()
{
  buzzer_set_period(song_length);  // Use the global song_length
  __delay_cycles(1000); // Simple delay between jingle sounds
}
