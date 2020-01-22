x = 128;
y = 128;

#define MOTOR_EN_L 2 //line to enable H- bridge for left engine
#define MOTOR_EN_R 3 // - || - right engine

#define MOTOR_L_A 5  //PWM A for left engine
#define MOTOR_L_B 6  //PWM B for left engine
#define MOTOR_R_A 9  //PWM A for right engine
#define MOTOR_R_B 10 //PWM B for right engine

digitalWrite(MOTOR_EN_L, HIGH);
digitalWrite(MOTOR_EN_R, HIGH);

if ((x > 128) && (y == 128)) //go right
{
    x = (x - 129) * 2;
    analogWrite(MOTOR_R_A, 0);
    analogWrite(MOTOR_R_B, 0);

    analogWrite(MOTOR_L_A, x);
    analogWrite(MOTOR_L_B, 0);
}
else if ((x < 128) && (y == 128)) // go left
{
    x = ((-x) + 127) * 2;
    analogWrite(MOTOR_R_A, x);
    analogWrite(MOTOR_R_B, 0);

    analogWrite(MOTOR_L_A, 0);
    analogWrite(MOTOR_L_B, 0);
}
else if ((x == 128) && (x > 128)) // forward
{
    y = (y - 129) * 2;
    analogWrite(MOTOR_R_A, y);
    analogWrite(MOTOR_R_B, 0);

    analogWrite(MOTOR_L_A, y);
    analogWrite(MOTOR_L_B, 0);
}
else if ((x == 128) && (x < 128)) // revers
{
    y = ((-y) - 127) * 2;
    analogWrite(MOTOR_R_A, 0);
    analogWrite(MOTOR_R_B, y);

    analogWrite(MOTOR_L_A, 0);
    analogWrite(MOTOR_L_B, y);
}

else if ((y > 128) && (x > 128)) //go forward and right
{
    x = ((-x) + 128) * 2;
    y = (y - 128) * 2;
    analogWrite(MOTOR_R_A, x);
    analogWrite(MOTOR_R_B, 0); // for forward
    analogWrite(MOTOR_L_A, y);
    analogWrite(MOTOR_L_B, 0); // for right
}
else if ((y > 128) && (x < 128)) //go forward and left
{
    x = x * 2; //joystick goes the more left PWM for left engine is smaller
    y = (y - 128) * 2;
    analogWrite(MOTOR_R_A, y);
    analogWrite(MOTOR_R_B, 0); // for forward
    analogWrite(MOTOR_L_A, x);
    analogWrite(MOTOR_L_B, 0); // for right
}
else
{
    Serial.print("\nNothing to do.";)
}
