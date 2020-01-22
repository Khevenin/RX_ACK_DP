
#define X_LOW 120
#define X_HIGH 130
#define Y_LOW 120
#define Y_HIGH 130

bool checkForward(uint8_t x, uint8_t y);
bool checkRevers(uint8_t x, uint8_t y);
bool checkLeft(uint8_t x, uint8_t y);
bool checkRight(uint8_t x, uint8_t y);

bool xCheckStopPosition(uint8_t x);
bool yCheckStopPosition(uint8_t y);

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