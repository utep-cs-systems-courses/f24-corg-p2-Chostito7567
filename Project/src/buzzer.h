#ifndef buzzer_included
#define buzzer_included

void buzzer_init();
void buzzer_set_period(short cycles);
void buzzer_play_sound();
void play_jingle(int jingle[][2]);

// Declare jingles as extern so they can be used in other files
extern int jingle1[][2];
extern int jingle2[][2];
extern int jingle3[][2];
extern int jingle4[][2];

#endif
