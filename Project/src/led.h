#ifndef led_included
#define led_included

#define LED_RED BIT0               // P1.0
#define LED_GREEN BIT6             // P1.6
#define LEDS (BIT0 | BIT6)

void led_init();
void led_update();
void led_pattern1();
void led_pattern2();
void led_pattern3();
void led_pattern4();

extern unsigned char led_changed, green_led_state, red_led_state, green_on, red_on, led_state;

#endif
