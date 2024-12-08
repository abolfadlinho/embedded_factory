#ifndef touch_h
#define touch_h

#define TOUCH_PIN 16

#include "pico/stdlib.h"

void touch_init(int touch_pin);

bool touch_is_pressed(int touch_pin);

#endif