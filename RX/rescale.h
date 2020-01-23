/**
 * @Autor: khevenin
 * @Date:23.01.2020
 * 
 * */

#define ADC_HIGH 255
#define ADC_MID_HIGH 128
#define ADC_MID_LOW 127

uint8_t hightToLow(uint8_t a); // a > reserved_interval i.e. ADC = 129 convert to PWM = 2
uint8_t invert(uint8_t a);     // a < reserved_interval i.e. ADC = 0 convert to PWM = 255
uint8_t invertHigh(uint8_t a);
