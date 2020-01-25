/**
 * @Autor: khevenin
 * @Date:23.01.2020
 * 
 * */
#include "rescale.h"

uint8_t highToLow(uint8_t a)
{
    return ((a - ADC_MID_HIGH) * 2); // i.e.
}

uint8_t invert(uint8_t a)
{
    return (((-a) + ADC_MID_LOW) * 2); // i.e. a = 10, -10 + 127 = 117, 117*2 = 234
}

uint8_t invertHigh(uint8_t a)
{
    return (((-a) + ADC_HIGH) * 2); // i.e. a = 10, -10 + 127 = 117, 117*2 = 234
}
