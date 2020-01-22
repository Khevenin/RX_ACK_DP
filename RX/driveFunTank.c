

//OK! let's go

void moveDecide(uint8_t x, uint8_t);

void forward(uint8_t y);
void reverse(uint8_t y);
void left(uint8_t x);
void right(uint8_t x);
void stop();

void forwardRight(uint8_t x, uint8_t y);
void forwardLeft(uint8_t x, uint8_t y);

void reversRight(uint8_t x, uint8_t y);
void reversLeft(uint8_t x, uint8_t y);

//
void moveDecide(uint8_t x, uint8_t y)
{
    if (checkForward(x, y)) // forward
    {
        forward(y);
    }
    if (checkRevers(x, y)) //revers
    {
        revers(y);
    }
    if (checkLeft(x, y)) // left
    {
        left(x);
    }
    if (checkRight(x, y)) // right
    {
        right(y);
    }
    if (checkForwardLeft(x, y)) //forward and left
    {
        forwardLeft(x, y);
    }
    if (checkForwardRight(x,y) //forward and right
    {
        forwardRight(x, y);
    }
    if (checkReversLeft(x,y)) //revers and left
    {
        reversLeft(x, x);
    }
    if (checkReversRight(x,y)) //revers and right
    {
        reversRight(x, y);
    }
    if (checkStop(x, y))
    {
        stop();
    }
}

//basic movment functions
void forward(uint8_t y)
{

    analogWrite(MOTOR_R_A, invert(y));
    analogWrite(MOTOR_R_B, 0);

    analogWrite(MOTOR_L_A, invert(y));
    analogWrite(MOTOR_L_B, 0);
}

void reverse(uint8_t y)
{
    analogWrite(MOTOR_R_A, 0);
    analogWrite(MOTOR_R_B, highToLow(y));

    analogWrite(MOTOR_L_A, 0);
    analogWrite(MOTOR_L_B, highToLow(y));
}

void left(uint8_t x)
{
    analogWrite(MOTOR_R_A, invert(x));
    analogWrite(MOTOR_R_B, 0);

    analogWrite(MOTOR_L_A, 0);
    analogWrite(MOTOR_L_B, 0);
}

void right(uint8_t x)
{
    analogWrite(MOTOR_R_A, 0);
    analogWrite(MOTOR_R_B, 0);

    analogWrite(MOTOR_L_A, highToLow(x));
    analogWrite(MOTOR_L_B, 0);
}

void stop()
{
    analogWrite(MOTOR_R_A, 0);
    analogWrite(MOTOR_R_B, 0);
    analogWrite(MOTOR_L_A, 0);
    analogWrite(MOTOR_L_B, 0);
}

//turn while driving
void forwardRight(uint8_t x, uint8_t y)
{
    analogWrite(MOTOR_R_A, invert(x)); // for right
    analogWrite(MOTOR_R_B, 0);
    analogWrite(MOTOR_L_A, invertHigh(y)); // for forward
    analogWrite(MOTOR_L_B, 0);
}

void forwardLeft(uint8_t x, uint8_t y)
{
    analogWrite(MOTOR_R_A, invert(y)); // for forward
    analogWrite(MOTOR_R_B, 0);
    analogWrite(MOTOR_L_A, 2 * x); // for left
    analogWrite(MOTOR_L_B, 0);
}

void reversLeft(uint8_t x, uint8_t y)
{
    analogWrite(MOTOR_R_A, 0);
    analogWrite(MOTOR_R_B, highToLow(y)); // for revers
    analogWrite(MOTOR_L_A, 0);
    analogWrite(MOTOR_L_B, 2 * x); //for left
}

void reversRight(uint8_t x, uint8_t y)
{
    analogWrite(MOTOR_R_A, 0);
    analogWrite(MOTOR_R_B, invertHigh(x)); // for right - x smaller - turn right is stronger
    analogWrite(MOTOR_L_A, 0);
    analogWrite(MOTOR_L_B, highToLow(y)); //for revers
}
