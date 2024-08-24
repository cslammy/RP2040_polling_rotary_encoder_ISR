/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <pico/stdlib.h>
#include "stdio.h"
#include <stdint.h>

#include "CCJEncoder.h"
#include "encoder.h"


//assumes PICO with built in LED PIN.
#define BUTTON_PIN 5
#define LED_PIN 25 //LED pin on PICO dev board

CCJISREncoder <1> encoder1;
uint64_t blinkTime = 300000;
bool ledState = 0;

 
    
int main() {
   int count = 0;
   stdio_init_all();
   encoder1.init(10,15);
   gpio_init(LED_PIN);
   gpio_set_dir(LED_PIN, GPIO_OUT);

absolute_time_t lastBlink = get_absolute_time();



while (2) {
        absolute_time_t curTime = get_absolute_time(); // current time
        // Check time since last blink, if time since last blink is larger than blinkTime, then blink.
        if ((absolute_time_diff_us(lastBlink, curTime)) > blinkTime)
        {
            lastBlink = get_absolute_time(); // update blink time
            ledState = 1-ledState;                 // Flip ledState between 0 and 1
            gpio_put(LED_PIN, ledState);    // update led
        }
 

        if (encoder1.check())  // we call CCJ algo
            {
               int a = encoder1.value();     
               printf("Value is: %d \n",a);  // print out value via uart.
            }

        }   

}