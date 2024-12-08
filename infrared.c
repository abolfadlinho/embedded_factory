#include "infrared.h"
#include "pico/stdlib.h"
#include "hardware/adc.h"

// #include "hardware/adc.h"

// Initialize the IR sensor
void infrared_init(void) {
    // Initialize the digital output (DO) pin
    gpio_init(INFRARED_DO_PIN);
    gpio_set_dir(INFRARED_DO_PIN, GPIO_IN);

    // Initialize the analog input (AO) pin by enabling the ADC
    // adc_init();
    // adc_gpio_init(INFRARED_AO_PIN); // Initialize GPIO pin for ADC
}

// Read the digital value from the IR sensor's DO pin
bool infrared_read_digital(void) {
    return gpio_get(INFRARED_DO_PIN); // Returns true if high, false if low
}

// Read the analog value from the IR sensor's AO pin (0-4095 for 12-bit ADC)
uint16_t infrared_read_analog(void) {
    adc_select_input(0);              // Select ADC0 (assuming AO is connected to GPIO26/ADC0)
    return adc_read();                 // Read and return ADC value (0 to 4095)
}
