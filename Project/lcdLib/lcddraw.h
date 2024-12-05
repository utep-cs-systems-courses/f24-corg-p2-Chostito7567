/** \file lcddraw.h
 *  \brief Adapted from RobG's EduKit
 */

#ifndef lcddraw_included
#define lcddraw_included

#include <stdint.h> // Use standard integer types

/** Draw single pixel at col, row 
 *
 *  \param col Column to draw to
 *  \param row Row to draw to
 *  \param colorBGR Color of pixel in BGR
 */
void drawPixel(uint8_t col, uint8_t row, uint16_t colorBGR);

/** Fill rectangle
 *
 *  \param colMin Column start
 *  \param rowMin Row start
 *  \param width Width of rectangle
 *  \param height height of rectangle
 *  \param colorBGR Color of rectangle in BGR
 */
void fillRectangle(uint8_t colMin, uint8_t rowMin, uint8_t width, uint8_t height, uint16_t colorBGR);

/** Clear screen (fill with color)
 *  
 *  \param colorBGR The color to fill screen
 */
void clearScreen(uint16_t colorBGR);

/** Draw string at col,row
 *  Type:
 *  FONT_SM - small (5x8,) FONT_MD - medium (8x12,) FONT_LG - large (11x16)
 *  FONT_SM_BKG, FONT_MD_BKG, FONT_LG_BKG - as above, but with background color
 *  Adapted from RobG's EduKit
 *
 *  \param col Column to start drawing string
 *  \param row Row to start drawing string
 *  \param string The string
 *  \param fgColorBGR Foreground color in BGR
 *  \param bgColorBGR Background color in BGR
 */
void drawString5x7(uint8_t col, uint8_t row, char *string, 
		   uint16_t fgColorBGR, uint16_t bgColorBGR);

/** 5x7 font - this function draws background pixels
 *  Adapted from RobG's EduKit
 */
void drawChar5x7(uint8_t col, uint8_t row, char c, 
		 uint16_t fgColorBGR, uint16_t bgColorBGR);

/** Draw rectangle outline
 *  
 *  \param colMin Column start
 *  \param rowMin Row start 
 *  \param width Width of rectangle
 *  \param height Height of rectangle
 *  \param colorBGR Color of rectangle in BGR
 */
void drawRectOutline(uint8_t colMin, uint8_t rowMin, uint8_t width, uint8_t height,
		     uint16_t colorBGR);

#endif // included
