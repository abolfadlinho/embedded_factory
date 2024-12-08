#ifndef servo_h
#define servo_h

#define SERVO_PIN 13

void setMillis(int servoPin, float millis);
void servo_init(int servoPin, float startMillis);
void sweep();
void open();
void close();

#endif