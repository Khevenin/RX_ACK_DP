/**
 * @Autor: khevenin
 * @Date:23.01.2020
 * 
 * */
#include <Arduino.h>

#define ADC_HIGH 255
#define ADC_MID_HIGH 128
#define ADC_MID_LOW 127

/**
 * Rescale value from high interval of ADC output 
 * ie. 128-255 to 0-255
 * */
uint8_t highToLow(uint8_t a); // a > reserved_interval i.e. ADC = 129 convert to PWM = 2

/**
 * Invert scale of ADC output from 0 - 128 to 255 - 0.
 * This make it possible to use ADC value as PWM value
 * */
uint8_t invert(uint8_t a); // a < reserved_interval i.e. ADC = 0 convert to PWM = 255

/**
 * Invert scale's high interval of ADC output
 * from 128 - 255 to 255 - 0
 * */
uint8_t invertHigh(uint8_t a);
