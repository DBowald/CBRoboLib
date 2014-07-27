//
//  CBRobotLib.h
//  
//
//  Created by Kyle Thompson on 7/22/14.
//
//

#ifndef ____CBRobotLib__
#define ____CBRobotLib__

#include "Arduino.h"

class Robot
{
public:
    Robot();
    void drive(int velLeft, int velRight);
};

#endif /* defined(____CBRobotLib__) */
