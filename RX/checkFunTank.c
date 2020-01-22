
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

/* check basic movments */
bool checkForward(uint8_t x, uint8_t y)
{
    if ((y < Y_LOW) && (xCheckStopPosition(x)))
    {
        return true; //forward
    }
    return false; //not forward
}

bool checkRevers(uint8_t x, uint8_t y)
{
    if ((y > Y_HIGH) && (xCheckStopPosition(x)))
    {
        return true; //revers
    }
    return false; //not revers
}

bool checkLeft(uint8_t x, uint8_t y)
{
    if ((yCheckStopPosition(y)) && (x < X_LOW))
    {
        return true; //left
    }
    return false; //not left
}

bool checkRight(uint8_t x, uint8_t y)
{
    if ((yCheckStopPosition(y)) && (x > X_LOW))
    {
        return true; //right
    }
    return false; //not right
}

bool checkStop(uint8_t x, uint8_t y)
{
    if (yCheckStopPosition(y) && xCheckStopPosition(x))
    {
        return true;
    }
    return false;
}

/* check advanced movments */
bool checkForwardLeft(uint8_t x, uint8_t y)
{
    if ((y < Y_LOW) && (x < X_LOW))
    {
        return true;
    }
    return false;
}

bool checkForwardRight(uint8_t x, uint8_t y)
{
    if ((y < Y_LOW) && (x > X_HIGH))
    {
        return true;
    }
    return false;
}

bool checkReversLeft(uint8_t x, uint8_t y)
{
    if ((y > Y_HIGH) && (x < X_LOW))
    {
        return true;
    }
    return false;
}
bool checkReversRight(uint8_t x, uint8_t y)
{
    if ((y > Y_HIGH) && (x > X_HIGH))
    {
        return true;
    }
    return false;
}

/* auxiliary functions */
/**
 * Check that x is in stop position 
 * */
bool xCheckStopPosition(uint8_t x)
{
    if ((x > X_LOW) && (x < X_HIGH))
    {
        return true;
    }
    return false;
}

/**
 * Check that y is in stop position 
 * */
bool yCheckStopPosition(uint8_t y)
{
    if ((y > Y_LOW) && (y < Y_HIGH))
    {
        return true;
    }
    return false;
}