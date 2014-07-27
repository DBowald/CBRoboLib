//
//  CBRobotLib.cpp
//  
//
//  Created by Kyle Thompson on 7/22/14.
//
//

#include "CBRobotLib.h"
#include "Arduino.h"

int pwmStoreLeft = 0;
int pwmStoreRight = 0;

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
    {                                                   //Do we want it to be velLeft > 0 && velLeft == velRight?
        digitalWrite(3, HIGH);                          //Adjust HIGH/LOW at a later date
        digitalWrite(4, LOW);
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        
        analogWrite(5, pwmLeft);
        analogWrite(6, pwmRight);
        
        pwmStoreLeft = pwmLeft;
        pwmStoreRight = pwmRight;
    }
    
    else if((velLeft <= 0) && (velRight > 0))           //Left
    {                                                   //To add to above comment, lets make it velRight > velLeft, so that way robot can still move forward and turn?
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        
        analogWrite(5, pwmLeft);
        analogWrite(6, pwmRight);
        
        pwmStoreLeft = pwmLeft;
        pwmStoreRight = pwmRight;
    }
    
    else if((velLeft > 0) && (velRight <= 0))           //Right (same suggestions as above)
    {
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        
        analogWrite(5, pwmLeft);
        analogWrite(6, pwmRight);
        
        pwmStoreLeft = pwmLeft;
        pwmStoreRight = pwmRight;
    }
    
    else if((velLeft < 0) && (velRight < 0))            //Backward
    {                                                   //Try velLeft < 0 && velLeft = velRight?
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        
        analogWrite(5, pwmLeft);
        analogWrite(6, pwmRight);
        
        pwmStoreLeft = pwmLeft;
        pwmStoreRight = pwmRight;
    }
    
    else                                                //Stop
    {
        for(int i = 0; i <= pwmStoreLeft; i++)          // this -> analogWrite(6, (pwmStoreRight - j)); should be able to go in the same loop as pwmStore Left ??
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
