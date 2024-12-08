#include "relay.h"

#include "pico/stdlib.h"
#include <stdio.h>

// Initialize the touch sensor pin
void relay_init(int relay_pin) {
    gpio_init(relay_pin);
    gpio_set_dir(relay_pin, GPIO_OUT);
    //gpio_pull_down(relay_pin);
    gpio_put(relay_pin, true);
}

// Check if the touch sensor is pressed
void relay_start(int relay_pin) {
    gpio_put(relay_pin, false);
}

void relay_stop(int relay_pin) {
    gpio_put(relay_pin, true);
}