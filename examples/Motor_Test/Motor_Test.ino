/*
*
*  Motor Test.ino
*
*  Purpose: Test for proper wiring of H-Bridge
*
*  If a motor is going the wrong way, flip the black and red motor leads
*
*/

#include <CBRobotLib.h>

Robot myRobot;

void setup()
{
}

void loop()
{
  myRobot.drive(100, 100);        //full speed forward for 1 second
  delay(1000);
  
  myRobot.drive(-100, -100);      //full speed reverse for 1 second
  delay(1000);
}
