#include "lcd.h"
#include <stdio.h>
#include "pico/stdlib.h"

//Global variables for LCD
uint16_t lcdRsPin;
uint16_t lcdEnPin;
uint16_t lcdDataPin[4];

void lcdSetup(uint16_t RS, uint16_t En, uint16_t D4, uint16_t D5, uint16_t D6, uint16_t D7) {
    // Assign Pin values to global variables
    lcdRsPin = RS;
    lcdEnPin = En;
    lcdDataPin[0] = D4;
    lcdDataPin[1] = D5;
    lcdDataPin[2] = D6;
    lcdDataPin[3] = D7;

    // Initialize GPIO pins
    gpio_init(RS);
    gpio_init(En);
    gpio_set_dir(RS, GPIO_OUT);
    gpio_set_dir(En, GPIO_OUT);
    for (int i = 0; i < 4; i++) {
        gpio_init(lcdDataPin[i]);
        gpio_set_dir(lcdDataPin[i], GPIO_OUT);
    }
}

void lcdEnable() {
    // Give a small 0 to 1 and 1 to 0 pulse on Enable pin to transfer port data
    gpio_put(lcdEnPin, 1);
    sleep_us(1); // Small delay
    gpio_put(lcdEnPin, 0);
    sleep_us(50); // Ensure the command is latched
}

void lcdWrite(uint8_t data) {
    // Send the higher nibble (D7-D4)
    for (int i = 0; i < 4; i++) {
        gpio_put(lcdDataPin[i], (data >> (i + 4)) & 0x01);
    }
    lcdEnable();

    // Send the lower nibble (D3-D0)
    for (int i = 0; i < 4; i++) {
        gpio_put(lcdDataPin[i], (data >> i) & 0x01);
    }
    lcdEnable();
}

void lcdCommand(uint8_t command) {
    // Sends Command data to LCD
    gpio_put(lcdRsPin, 0); // Set RS to 0 for commands
    lcdWrite(command);
}

void lcdInit() {
    // Set to 4-bit mode
    lcdCommand(0x33); // Initialize LCD for 4-bit mode
    sleep_ms(5);
    lcdCommand(0x32); // Confirm 4-bit mode
    sleep_ms(5);

    lcdCommand(0x28); // Function Set: 4-bit mode, 2-line display, 5x8 dots
    lcdCommand(0x0C); // Display ON, Cursor OFF
    lcdCommand(0x06); // Entry Mode: Increment cursor, no shift
    lcdCommand(0x01); // Clear Display
    sleep_ms(2);      // Wait for the command to complete
}


void lcdChar(uint8_t ch) {
    // Display One Byte of Data to LCD
    gpio_put(lcdRsPin, 1); // Set RS Pin to 1 for Data
    lcdWrite(ch);
}

void lcdString(char *string) {
    // Display a String of characters
    while (*string)
        lcdChar(*string++);
}

void lcdStringCount(char *string, int count) { //TODO
    // Display a String of characters
    while (*string)
        lcdChar(*string++);
}

void lcdWriteInt(char *format, uint32_t number) {
    // Display integer numbers, format is standard C printf() like %d
    char buffer[20];
    sprintf(buffer, format, number);
    lcdString(buffer);
}

void lcdWriteFloat(char *format, double number) {
    // Display a floating point number
    char buffer[20];
    sprintf(buffer, format, number);
    lcdString(buffer);
}

void lcdSetCursor(uint8_t row, uint8_t col) {
    // Sets the cursor position
    gpio_put(lcdRsPin, 0); // RS=0;
    switch (row) {
    case 0:
        lcdWrite(0x80 + col);
        break;
    case 1:
        lcdWrite(0xC0 + col);
        break;
    case 2:
        lcdWrite(0x80 + 0x14 + col);
        break;
    case 3:
        lcdWrite(0xC0 + 0x14 + col);
        break;
    }
}
