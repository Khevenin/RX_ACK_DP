#include "checkMove.h"

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