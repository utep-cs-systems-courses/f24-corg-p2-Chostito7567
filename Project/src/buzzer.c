#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

#define CLOCK_FREQUENCY 1000000  // Assuming 1 MHz clock frequency

// Define different jingles (frequency in Hz and duration in ms)
int jingle1[][2] = {{1000, 200}, {1200, 200}, {1400, 200}, {0, 0}};
int jingle2[][2] = {{1500, 300}, {1300, 300}, {1100, 300}, {0, 0}};
int jingle3[][2] = {{2000, 100}, {2200, 100}, {2400, 100}, {0, 0}};
int jingle4[][2] = {{2500, 400}, {2300, 400}, {2100, 400}, {0, 0}};

// Initialize the buzzer
void buzzer_init() {
    timerAUpmode();		    /* used to drive speaker */
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6;		      /* enable output to speaker (P2.6) */
}

// Set buzzer frequency
void buzzer_set_period(short cycles) {
    CCR0 = cycles; 
    CCR1 = cycles >> 1;  // one half cycle
}

// Plays a jingle based on the input array (frequency and duration pairs)
void play_jingle(int jingle[][2]) {
    for (int i = 0; jingle[i][0] != 0; i++) {
        buzzer_set_period(1000000 / jingle[i][0]); // Set frequency
        __delay_cycles((CLOCK_FREQUENCY / 1000) * jingle[i][1]); // Delay in cycles for milliseconds
    }
    buzzer_set_period(0); // Turn off the buzzer after playing
}

// Existing tone-shifting sound function
void buzzer_play_sound() {
    static unsigned int song_length = 2500;
    static signed int change_rate = 250;
    song_length = (song_length + change_rate);

    // Positive Change Rate
    if (change_rate > 0) {
        if (song_length > 90000) {
            change_rate = -change_rate; // Reverse the change
            song_length = song_length + (change_rate << 1);
        }
    }

    // Negative Change Rate
    if (change_rate < 0) {
        if (song_length < 900) {
            change_rate = -change_rate; // Reverse the change
            song_length = song_length + (change_rate << 1);
        }
    }
    buzzer_set_period(song_length);
}
