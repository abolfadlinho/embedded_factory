#ifndef INFRARED_H
#define INFRARED_H

#include <stdint.h>
#include <stdbool.h>
#include <hardware/adc.h>

// Define pins
#define INFRARED_DO_PIN 18       // GPIO pin for digital output (DO)
#define INFRARED_AO_PIN 26      // ADC pin for analog output (AO, ADC0)

// Function prototypes
void infrared_init(void);
bool infrared_read_digital(void);
uint16_t infrared_read_analog(void);

#endif // IR_SENSOR_H
