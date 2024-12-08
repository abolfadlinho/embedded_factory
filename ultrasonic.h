// #ifndef ULTRASONIC_H
// #define ULTRASONIC_H

// #include "pico/stdlib.h"
// #include "pico/time.h"
// #include <stdint.h>

// // Define the GPIO pins for TRIG and ECHO
// #define TRIG_PIN     15 // OUTPUT Analogue yellow
// #define ECHO_PIN     14 // INPUT green

// void ultrasonic_init(void);
// void ultrasonic_trigger(void);
// uint32_t ultrasonic_measure_echo_time(void);
// float ultrasonic_calculate_distance_cm(void);

// #ifndef ULTRASONIC_H
// #define ULTRASONIC_H

// void setupUltrasonicPins(int trigPin, int echoPin);
// int getCm(int trigPin, int echoPin);
// int getInch(int trigPin, int echoPin);

// #endif // ULTRASONIC_H

// #endif // ULTRASONIC_H
#ifndef ULTRASONIC_H
#define ULTRASONIC_H

void setupUltrasonicPins(uint trigPin, uint echoPin);
int getCm(uint trigPin, uint echoPin);
int getInch(uint trigPin, uint echoPin);

#endif // ULTRASONIC_H
