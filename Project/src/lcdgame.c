#include "../lcdLib/lcddraw.h"
#include "../lcdLib/lcdutils.h"

// Initializes the LCD and clears the screen
void lcd_game_init() {
    configureClocks();           // Required for LCD operation
    lcd_init();                  // Initialize LCD
    clearScreen(COLOR_BLACK);    // Clear screen to black
}

// Draws a square in the center of the screen
void lcd_draw_square() {
    u_char topLeftX = screenWidth / 2 - 10;  // Center square horizontally
    u_char topLeftY = screenHeight / 2 - 10; // Center square vertically
    u_char sideLength = 20;                 // Define the square's size

    for (u_char y = 0; y < sideLength; y++) {
        for (u_char x = 0; x < sideLength; x++) {
            drawPixel(topLeftX + x, topLeftY + y, COLOR_GREEN);
        }
    }
}
