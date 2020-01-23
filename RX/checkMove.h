#define X_LOW 120
#define X_HIGH 130
#define Y_LOW 120
#define Y_HIGH 130

/**
 *  x value below 120 means left
 * x value above 130 means right
 * y value below 120 means forward
 * y value above 130 means revers 
*/

/* check basic movments */
bool checkForward(uint8_t x, uint8_t y);
bool checkRevers(uint8_t x, uint8_t y);
bool checkLeft(uint8_t x, uint8_t y);
bool checkRight(uint8_t x, uint8_t y);
bool checkStop(uint8_t x, uint8_t y);

/* check advanced movments */
bool checkForwardLeft(uint8_t x, uint8_t y);
bool checkForwardRight(uint8_t x, uint8_t y);
bool checkReversLeft(uint8_t x, uint8_t y);
bool checkReversRight(uint8_t x, uint8_t y);

/* auxiliary functions */
bool xCheckStopPosition(uint8_t x);
bool yCheckStopPosition(uint8_t y);
