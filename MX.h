#ifndef MX_H
#define MX_H

#define MX_REG_ID 0x3
#define MX_REG_CW_LIMIT 0x06
#define MX_REG_CCW_LIMIT 0x08
#define MX_REG_GOAL_POSITION 0x1E
#define MX_REG_MOVING_SPEED 0x20
#define MX_REG_VOLTS 0x2A
#define MX_REG_AMPERE 0x44
#define MX_REG_TEMP 0x2B
#define MX_REG_PGAIN 0x1C
#define MX_REG_IGAIN 0x1B
#define MX_REG_DGAIN 0X1A
#define MX_REG_MOVING 0x2E
#define MX_REG_MAXTORQUE 0x22
#define MX_REG_POSITION 0x24
#define MX_RESOLUTION 0.088
//bit per degrees 4095/360°
#define MX_REG_MOTORONOFF 0x18
#define MX_BIT_DEG 11.375
#define MX_DEBUG 1
#define MX_TRIGGER_DEBUG 1
#define MX_REG_CURRENT 0x44
#define MX_REG_TEMP 0x2B

#define MX_READ_DEBUG 1
#define AX12_WRITE_DEBUG 1
#define AX12_READ_DEBUG 1
#define AX12_TRIGGER_DEBUG 1
#define AX12_DEBUG 1

#define AX12_REG_ID 0x3
#define AX12_REG_CW_LIMIT 0x06
#define AX12_REG_CCW_LIMIT 0x08
#define AX12_REG_GOAL_POSITION 0x1E
#define AX12_REG_MOVING_SPEED 0x20
#define AX12_REG_VOLTS 0x2A
#define AX12_REG_TEMP 0x2B
#define AX12_REG_MOVING 0x2E
#define AX12_REG_POSITION 0x24
#define AX12_REG_MAXTORQUE 0x22
#define AX12_REG_MOTORONOFF 0x18
#define AX12_MODE_POSITION  0
#define AX12_MODE_ROTATION  1

#define AX12_CW 1
#define AX12_CCW 1
#define goal_resolution 0.08789

#define READ_DEBUG 1

#include "Joint.h"

// TODO: spostare i metodi uguali da MX106, MX64 in questo file e in MX.cpp. 

class MX : public Joint
{

  public:
    MX(communication_1& line, int ID, float gear_train);
    virtual ~MX();
    void setID(int newID);
    int getID();

    /** Set the mode of the servo
     * @param mode
     *    0 = Positional, default
     *    1 = Continuous rotation
     */
    virtual void setMode(int mode);

    void setCWLimitUnits(short limit);
    void setCCWLimitUnits(short limit);

    /** Set the clockwise limit of the servo
     *
     * @param degrees, 0-300
     */
    void setCWLimit(float degrees);
    /** Set the counter-clockwise limit of the servo
     *
     * @param degrees, 0-300
     */
    void setCCWLimit(float degrees);

    /** Set the speed of the servo in continuous rotation mode
     *
     * @param speed, -1.0 to 1.0
     *   -1.0 = full speed counter clock wise
     *    1.0 = full speed clock wise
     */
    //void setCRSpeed(float speed);
    //
    void setGoalPosition(float degrees);
    float getPosition();

    /** Set goal angle in integer degrees, in positional mode
     *
     * @param degrees 0-300
     * @param flags, defaults to 0
     *    flags[0] = blocking, return when goal position reached 
     *    flags[1] = register, activate with a broadcast trigger
     *
     */
    int setGoal(float degrees, int flags = 0);
    void setMaxSpeed(float degreeS);
    void setCRSpeed(float degreeS);
    void setSpeed(float degreeS);
    float getTemp();
    float getCurrent();
    float getVolts();
    virtual float getPGain();
    virtual float getIGain();
    virtual float getDGain();
    virtual void setPGain(float gain);
    virtual void setIGain(float gain);
    virtual void setDGain(float gain);
    void setMaxTorque(float torque);
    void setMotorEnabled(bool enabled);
    bool isMoving();

  protected:
    communication_1& _line;
    float _gear_train;
    int _ID;
    int _mode;
    float maxSpeedDegreeS;
    float limitCWDegrees;
    float limitCCWDegrees;;
};

#endif 
