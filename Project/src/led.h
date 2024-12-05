#ifndef led_included
#define led_included

#define LED_RED BIT0       // P1.0
#define LED_GREEN BIT6     // P1.6
#define LEDS (BIT0 | BIT6) // Both LEDs

void led_init();           // Initialize LEDs
void led_update();         // Update LEDs

extern unsigned char red_on, green_on, led_changed;

#endif // led_included
