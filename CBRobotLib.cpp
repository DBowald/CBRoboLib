//
//  CBRobotLib.cpp
//  
//
//  Created by Kyle Thompson on 7/22/14.
//
//

#include "CBRobotLib.h"
#include "Arduino.h"

int pwmStoreLeft = 0;                                   //PWM store for use in slow down loops
int pwmStoreRight = 0;

Robot::Robot()
{
    pinMode(7, OUTPUT);                                 //Right
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);                                 //Left
    pinMode(10, OUTPUT);
}

void Robot::drive(int velLeft, int velRight)
{
    int pwmLeft = map(abs(velLeft), 0, 100, 40, 200);   //Limit PWM to max of 200/255 and min of 40/255
    int pwmRight = map(abs(velRight), 0, 100, 40, 200);
    
    if((velLeft > 0) && (velRight > 0))                 //Forward
    {
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        digitalWrite(10, LOW);
        
        analogWrite(5, pwmLeft);
        analogWrite(6, pwmRight);
        
        pwmStoreLeft = pwmLeft;
        pwmStoreRight = pwmRight;
    }
    
    else if((velLeft <= 0) && (velRight > 0))           //Forward Left
    {
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, HIGH);
        
        analogWrite(5, pwmLeft);
        analogWrite(6, pwmRight);
        
        pwmStoreLeft = pwmLeft;
        pwmStoreRight = pwmRight;
    }
    
    else if((velLeft > 0) && (velRight <= 0))           //Forward Right
    {
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        digitalWrite(10, LOW);
        
        analogWrite(5, pwmLeft);
        analogWrite(6, pwmRight);
        
        pwmStoreLeft = pwmLeft;
        pwmStoreRight = pwmRight;
    }
    
    else if((velLeft >= 0) && (velRight < 0))           //Reverse Left
    {
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        digitalWrite(10, LOW);
        
        analogWrite(5, pwmLeft);
        analogWrite(6, pwmRight);
        
        pwmStoreLeft = pwmLeft;
        pwmStoreRight = pwmRight;
    }
    
    else if((velLeft < 0) && (velRight >= 0))           //Reverse Right
    {
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, HIGH);
        
        analogWrite(5, pwmLeft);
        analogWrite(6, pwmRight);
        
        pwmStoreLeft = pwmLeft;
        pwmStoreRight = pwmRight;
    }
    
    else if((velLeft < 0) && (velRight < 0))            //Backward
    {
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        digitalWrite(9, LOW);
        digitalWrite(10, HIGH);
        
        analogWrite(5, pwmLeft);
        analogWrite(6, pwmRight);
        
        pwmStoreLeft = pwmLeft;
        pwmStoreRight = pwmRight;
    }
    
    else                                                //Stop
    {
        for(int i = 0; i <= pwmStoreLeft; i++)          //Loops allow for a slower (less abrupt) stop
        {
            analogWrite(5, (pwmStoreLeft - i));
        }
        
        for(int j = 0; j <= pwmStoreRight; j++)
        {
            analogWrite(6, (pwmStoreRight - j));
        }

        analogWrite(5, 0);
        analogWrite(6, 0);
    }
}
