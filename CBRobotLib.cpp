//
//  CBRobotLib.cpp
//  
//
//  Created by Kyle Thompson on 7/22/14.
//
//

#include "CBRobotLib.h"

Robot::Robot()
{
    pinMode(3, OUTPUT);                                 //Left
    pinMode(4, OUTPUT);
    pinMode(7, OUTPUT);                                 //Right
    pinMode(8, OUTPUT);
}

void Robot::drive(int velLeft, int velRight)
{
    int pwmLeft = map(abs(velLeft), 0, 100, 40, 200);   //Limit PWM to max of 200/255 and min of 40/255
    int pwmRight = map(abs(velRight), 0, 100, 40, 200);
    
    if((velLeft > 0) && (velRight > 0))                 //Forward
    {
        digitalWrite(3, HIGH);                          //Adjust HIGH/LOW at a later date
        digitalWrite(4, LOW);
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        
        analogWrite(5, pwmLeft);
        analogWrite(6, pwmRight);
        
        int pwmStoreLeft = pwmLeft;
        int pwmStoreRight = pwmRight;
    }
    
    else if((velLeft <= 0) && (velRight > 0))           //Left
    {
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        
        analogWrite(5, pwmLeft);
        analogWrite(6, pwmRight);
        
        int pwmStoreLeft = pwmLeft;
        int pwmStoreRight = pwmRight;
    }
    
    else if((velLeft > 0) && (velRight <= 0))           //Right
    {
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        
        analogWrite(5, pwmLeft);
        analogWrite(6, pwmRight);
        
        int pwmStoreLeft = pwmLeft;
        int pwmStoreRight = pwmRight;
    }
    
    else if((velLeft < 0) && (velRight < 0))            //Backward
    {
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        
        analogWrite(5, pwmLeft);
        analogWrite(6, pwmRight);
        
        int pwmStoreLeft = pwmLeft;
        int pwmStoreRight = pwmRight;
    }
    
    else                                                //Stop
    {
        for(int i = 0, i <= pwmStoreLeft, i++)
        {
            analogWrite(5, (pwmStoreLeft - i));
        }
        
        for(int j = 0, j <= pwmStoreRight, j++)
        {
            analogWrite(6, (pwmStoreRight - j));
        }

        analogWrite(5, 0);
        analogWrite(6, 0);
    }
}