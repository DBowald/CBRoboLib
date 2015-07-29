/*
*/

#include "Arduino.h"
#include "robot.h"

robot::robot()
{
  Serial.begin(9600);

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(12, OUTPUT);
}

void robot::auto_drive(){
  inChar = Serial.read();
  drive(inChar)
}

void robot::drive(int serialCommand){
  int pwmLeft = map(abs(velLeft), 0, 100, 0, 200);   //Limit PWM to max of 200/255 and min of 0/255
  int pwmRight = map(abs(velRight), 0, 100, 0, 200);
  
  update_buttons(serialCommand, pwmLeft, pwmRight)
}

void robot::update_buttons(int inChar, int pwmLeft, int pwmRight)
{  
   switch (inChar)
    {
    case '0': 
      analogWrite(9, 0);
      analogWrite(10, 0);
      break;
    case '1': //forward
      forward(pwmLeft, pwmRight);
      break;
    case '2': //reverse
      reverse(pwmLeft, pwmRight)
      break;
    case '3': //left
      left(pwmLeft, pwmRight)
      break;
    case '4': //right
      right(pwmLeft, pwmRight)
      break;
    case '5': //select
      digitalWrite(12, LOW);
      break;
    case '6': //start
      digitalWrite(12, HIGH);
      break;

    case '7': //triangle
      digitalWrite(12, HIGH);
      break;
      //8 is square
      //9 is x
    case 'A': //circle
      digitalWrite(12, HIGH);
      break;

    }
    
    void robot::forward(int pwmLeft, int pwmRight){
      analogWrite(9, pwmLeft);
      analogWrite(10, pwmRight);
      digitalWrite(2, 1);
      digitalWrite(3, 0);
      digitalWrite(4, 1);
      digitalWrite(5, 0);
    }
    
    void robot::reverse(){
      analogWrite(9, pwmLeft);
      analogWrite(10, pwmRight);
      digitalWrite(2, 0);
      digitalWrite(3, 1);
      digitalWrite(4, 0);
      digitalWrite(5, 1);
    }
    
    void robot::left(){
      analogWrite(9, pwmLeft);
      analogWrite(10, pwmRight);
      digitalWrite(2, 1);
      digitalWrite(3, 0);
      digitalWrite(4, 0);
      digitalWrite(5, 1);
    }
    
    void robot::right(){
      analogWrite(9, pwmLeft);
      analogWrite(10, pwmRight);
      digitalWrite(2, 0);
      digitalWrite(3, 1);
      digitalWrite(4, 1);
      digitalWrite(5, 0);  
    }
     
}
