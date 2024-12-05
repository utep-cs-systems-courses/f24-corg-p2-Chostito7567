void play_jingle1() {
    short jingle1[] = {1000, 0, 1200, 0, 1400, 0, 1600, 0}; // Increasing pitch
    for (int i = 0; i < 8; i++) {
        buzzer_set_period(jingle1[i]);
        __delay_cycles(300000); // Shorter delay for faster rhythm
    }
    buzzer_set_period(0); // Turn off sound
}

void play_jingle2() {
    short jingle2[] = {2000, 1500, 2500, 0, 1800, 0, 1000, 0}; // High-low oscillation
    for (int i = 0; i < 8; i++) {
        buzzer_set_period(jingle2[i]);
        __delay_cycles(400000); // Moderate rhythm
    }
    buzzer_set_period(0);
}

void play_jingle3() {
    short jingle3[] = {300, 0, 600, 0, 900, 0, 1200, 0, 1500}; // Rising scale
    for (int i = 0; i < 9; i++) {
        buzzer_set_period(jingle3[i]);
        __delay_cycles(250000); // Fast rhythm
    }
    buzzer_set_period(0);
}

void play_jingle4() {
    short jingle4[] = {800, 0, 600, 0, 400, 0, 200, 0}; // Decreasing pitch
    for (int i = 0; i < 8; i++) {
        buzzer_set_period(jingle4[i]);
        __delay_cycles(500000); // Slower rhythm for emphasis
    }
    buzzer_set_period(0);
}
