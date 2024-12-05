void play_jingle1() {
    short jingle1[] = {1000, 0, 800, 0, 600, 0, 400, 0};
    for (int i = 0; i < 8; i++) {
        buzzer_set_period(jingle1[i]);
        __delay_cycles(500000);
    }
    buzzer_set_period(0); // Turn off sound
}

void play_jingle2() {
    short jingle2[] = {500, 0, 700, 0, 900, 0, 1100, 0};
    for (int i = 0; i < 8; i++) {
        buzzer_set_period(jingle2[i]);
        __delay_cycles(500000);
    }
    buzzer_set_period(0);
}

void play_jingle3() {
    short jingle3[] = {1200, 0, 1000, 0, 800, 0, 600, 0};
    for (int i = 0; i < 8; i++) {
        buzzer_set_period(jingle3[i]);
        __delay_cycles(500000);
    }
    buzzer_set_period(0);
}

void play_jingle4() {
    short jingle4[] = {1500, 0, 1300, 0, 1100, 0, 900, 0};
    for (int i = 0; i < 8; i++) {
        buzzer_set_period(jingle4[i]);
        __delay_cycles(500000);
    }
    buzzer_set_period(0);
}
