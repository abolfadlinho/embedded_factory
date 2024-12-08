#ifndef LCD_H
#define LCD_H

#include <stdint.h>

// Function Prototypes
void lcdSetup(uint16_t RS, uint16_t En, uint16_t D4, uint16_t D5, uint16_t D6, uint16_t D7);

void lcdEnable(void);
void lcdWrite(uint8_t data);
void lcdCommand(uint8_t command);
void lcdInit(void);
void lcdChar(uint8_t ch);
void lcdString(char *string);
void lcdStringCount(char *string, int count);
void lcdWriteInt(char *format, uint32_t number);
void lcdWriteFloat(char *format, double number);
void lcdSetCursor(uint8_t row, uint8_t col);

#endif // LCD_H
