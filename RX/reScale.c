

#define PWM_MAX 255
#define PWM_MIN 0

#define ADC_HIGH_MAX 255
#define ADC_HIGH_MIN 130
#define ADC_LOW_MAX 124
#define ADC_LOW_MIN 0

uint8_t hightToLow(uint8_t a); // a > reserved_interval i.e. ADC = 129 convert to PWM = 2
uint8_t invert(uint8_t a);     // a < reserved_interval i.e. ADC = 0 convert to PWM = 255
uint8_t invertHigh(uint8_t a); //

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
