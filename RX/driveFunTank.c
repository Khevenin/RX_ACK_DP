

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
    1 else if ((y > 124) && ((x > 120) && (x < 130))) //revers
    {
        revers(y);
    }
    else if (((y > 120) && (y < 130)) && (x < 124)) // left
    {
        left(x);
    }
    else if (((y > 120) && (y < 130)) && (x > 124)) // right
    {
        right(y);
    }
    else if ((y < 124) && (x < 124)) //forward and left
    {
        forwardLeft(x, y);
    }
    else if ((y < 124) && (x > 124)) //forward and right
    {
        forwardRight(x, y);
    }
    else if ((y > 124) && (x < 124)) //revers and left
    {
        reversLeft(x, x);
    }
    else if ((y < 124) && (x > 124)) //revers and right
    {
        reversRight(x, y);
    }
    else //stop
    {
        //(((y > 120) && (y < 130)) && ((x > 120) && (x < 130)))
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
