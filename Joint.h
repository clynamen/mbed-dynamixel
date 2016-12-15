#include "communication_1/communication_1.h"

#ifndef JOINT_H
#define JOINT_H

class Joint
{
    public:
    virtual ~Joint() {};
    virtual void setID(int NewID) = 0;
    virtual int getID() = 0;
    // TODO: use enum instead of int
    virtual void setMode(int mode) = 0; 
    virtual void setCWLimit(float degrees) = 0;
    virtual void setCCWLimit(float degrees) = 0;
    virtual void setGoalPosition(float degrees) = 0;
    virtual float getPosition() = 0;
    virtual void setSpeed(float degreesS) = 0;
    virtual void setMaxSpeed(float degreeS) = 0;
    virtual float getTemp() = 0;
    virtual float getVolts() = 0;
    virtual float getCurrent () = 0;
    virtual void setMaxTorque(float torque) = 0 ;
    virtual void setMotorEnabled(bool enabled) = 0;
    virtual bool isMoving() = 0;
};

#endif
