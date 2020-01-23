/**
 * @Autor: khevenin
 * @Date:23.01.2020
 * 
 * */
#include "rescale.h"

#define ADC_HIGH 255
#define ADC_MID_HIGH 128
#define ADC_MID_LOW 127

uint8_t hightToLow(uint8_t a)
{
    return ((x - 128) * 2); // i.e.
}

uint8_t invert(uint8_t a)
{
    return (((-a) + 127) * 2); // i.e. a = 10, -10 + 127 = 117, 117*2 = 234
}

uint8_t invertHigh(uint8_t a)
{
    return (((-a) + 255) * 2); // i.e. a = 10, -10 + 127 = 117, 117*2 = 234
}