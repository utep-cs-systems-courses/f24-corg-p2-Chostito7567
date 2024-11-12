#ifndef led_included
#define led_included

extern char ledFlags; // Declare ledFlags as external to be defined in led.c

void led_init();
void led_update();
void led_advance();

#endif // led_included
