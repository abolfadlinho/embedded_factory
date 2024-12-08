#include "pico/multicore.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "infrared.h"
#include "lcd.h"
#include "relay.h"
#include "servo.h"
#include "touch.h"
#include "ultrasonic.h"

#include "hardware/adc.h"
#include "hardware/pwm.h"

uint trigPin = 15;
uint echoPin = 14;

int led_pin = 12;
int servo_pin_out = 13;
int touch_pin = 16;
int relay_pin = 17;
int infrared_pin = 18;

int servo_init_pos = 400;

bool motorOn = false;

int count = 0;

char str[9] = "Count: ";
char numStr[2];



void thread1(){
    setupUltrasonicPins(trigPin, echoPin);
    gpio_init(12);
    gpio_set_dir(12,GPIO_OUT);
    gpio_put(12,false);
    while(1) {
        uint64_t distance = getCm( trigPin, echoPin);
        if(distance < 20 && motorOn){
            //gpio_put(12, true);
            open();
            sleep_ms(1000);
            close();
            sleep_ms(1000);
        } else {
            //gpio_put(12, false);
            sleep_ms(100);
        }
    }
}   

int main() {
    stdio_init_all();

    infrared_init();
    relay_init(relay_pin);
    touch_init(touch_pin);
    servo_init(servo_pin_out, servo_init_pos);

    //LCD block working
    lcdSetup(0, 1, 2, 3, 4, 5);
    lcdInit();
    lcdSetCursor(0, 0);
    lcdString("Welcome To EMBEDDED");
    lcdSetCursor(1, 0);
    lcdString("Team 51");

    multicore_launch_core1(thread1);

    // gpio_init(12);
    // gpio_set_dir(12,GPIO_OUT);
    // gpio_put(12,false);

    while (1) {

        //display count
        lcdSetCursor(2, 0);
        size_t len = strlen(str);
        if (len > 8) { //is string already has two digits remove them before concat
            str[len - 2] = '\0';
        } else if (len > 7) { //is string already has 1 digit remove it before concat
            str[len - 1] = '\0';
        }
        sprintf(numStr, "%d", count);
        strcat(str, numStr);
        lcdString(str);

        lcdSetCursor(3,0);
        if (motorOn) {
            lcdString("           Motor ON!");
        } else {
            lcdString("           Motor OFF");
        }
        

        bool touchRead = touch_is_pressed(touch_pin);
        if(touchRead && !motorOn){
            relay_start(relay_pin); //start the motor
            motorOn = true;
            lcdSetCursor(2, 0);
            lcdString("                "); //clear
            count = 0; //reset count
            sleep_ms(500);
        } else if(touchRead && motorOn) {
            relay_stop(relay_pin);  //stop the motor
            motorOn = false;
            sleep_ms(500);
        }

        bool irRead = infrared_read_digital();
        if(!irRead  && motorOn){ //remember IR is negative logic
            count++; //increment count whenever ir senses object
            sleep_ms(1500);
        }

        sleep_ms(100);
    }

    return 0;
}