#include "touch.h"

#include "pico/stdlib.h"
#include <stdio.h>

// Initialize the touch sensor pin
void touch_init(int touch_pin) {
    gpio_init(touch_pin);
    gpio_set_dir(touch_pin, GPIO_IN);
    gpio_pull_down(touch_pin);
}

// Check if the touch sensor is pressed
bool touch_is_pressed(int touch_pin) {
    return gpio_get(touch_pin);
}