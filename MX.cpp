#include "MX.h"

#include <math.h>

#define MOVING_SPEED_UNIT_RPM 0.114

MX::MX(communication_1& line, int ID, float gear_train)
    : _line(line)
    , _ID(ID)
    , _gear_train(gear_train) {
      maxSpeedDegreeS = 360;
      limitCWDegrees = 0;
      limitCCWDegrees = 0;
}

MX::~MX() {
}

void MX::setID(int newID) {

    char data[1];
    data[0] = newID;

    if (MX_DEBUG) {
        printf("Setting ID from 0x%x to 0x%x\n", _ID, newID);
    }

    _line.write(_ID, MX_REG_ID, 1, data);
    _ID = newID;
}

int MX::getID() {
  return _ID;
}

void MX::setGoalPosition(float degrees) {
    setMode(2);
    setCRSpeed(maxSpeedDegreeS);
    setGoal(degrees);
}

int MX::setGoal(float degrees, int flags) {
    if ((_mode == 0) && ((degrees < 0) || (degrees > 360))) {
        if (MX_DEBUG == 1) {
            printf("Error, wheel mode ");
        }
        return (1);
    }

    if (_mode == 1) {
        if (MX_DEBUG == 1) {
            printf("Error, wheel mode ");
        }
        return (1);
    }

    //if ((_mode == 2) && ((degrees < 0) || (degrees > 360))) {
        //if (MX_DEBUG == 1) {
            //printf("Error, wheel mode ");
        //}
        //return (1);
    //}

    char reg_flag = 0;
    char data[2];

    // set the flag is only the register bit is set in the flag
    if (flags == 0x2) {
        reg_flag = 1;
    }

    if (degrees > limitCWDegrees && limitCWDegrees != 0) {
      degrees = limitCWDegrees;
    } else if (degrees < limitCCWDegrees && limitCCWDegrees != 0){
      degrees = limitCCWDegrees;
    }

    uint16_t goal = (int)(degrees * _gear_train / goal_resolution); 
    if (MX_DEBUG) {
        printf("SetGoal to 0x%x\n", goal);
    }

    data[0] = goal & 0xff; // bottom 8 bits
    data[1] = goal >> 8;   // top 8 bits

    // write the packet, return the error code
    int rVal = _line.write(_ID, MX_REG_GOAL_POSITION, 2, data, reg_flag);

    if (flags == 1) {
        // block until it comes to a halt
        while (isMoving()) {
        }
    }
}

float MX::getVolts(void) {
    if (MX_DEBUG) {
        printf("\nGetVolts(%d)", _ID);
    }
    char data[1];
    int ErrorCode = _line.read(_ID, MX_REG_VOLTS, 1, data);
    float volts = data[0] / 10.0;
    return (volts);
}

float MX::getCurrent(void) {
    if (MX_DEBUG) {
        printf("\nGetCurrent(%d)", _ID);
    }
    char data[1];
    int ErrorCode = _line.read(_ID, MX_REG_CURRENT, 1, data);
    float ampere = 4.5 * (data[0] - 2048);
    return (ampere);
}

float MX::getPGain() {
    char data[1];
    _line.read(_ID, MX_REG_PGAIN, 1, data);
    return (float) *data / 8;
}

float MX::getIGain() {
    char data[1];
    _line.read(_ID, MX_REG_IGAIN, 1, data);
    return (float) *data * 1000 / 2048;
}

float MX::getDGain() {
    char data[1];
    _line.read(_ID, MX_REG_DGAIN, 1, data);
    return (float) *data * 4 / 1000;
}

void MX::setPGain(float gain) {
    char data[1];
    *data = gain * 8;
    _line.write(_ID, MX_REG_PGAIN, 1, data);
}
void MX::setIGain(float gain) {
    char data[1];
    *data = gain / 1000 * 2048;
    _line.write(_ID, MX_REG_IGAIN, 1, data);
}
void MX::setDGain(float gain) {
    char data[1];
    *data = gain / 4 * 1000;
    _line.write(_ID, MX_REG_DGAIN, 1, data);
}

void MX::setMaxTorque(float maxTorque) {
    char data[2];
    short torqueValue = maxTorque * 0x3ff; 
    data[0] = torqueValue & 0xff; // bottom 8 bits
    data[1] = torqueValue >> 8;   // top 8 bits
    // write the packet, return the error code
    _line.write(_ID, MX_REG_MAXTORQUE, 2, data);
}

void MX::setMotorEnabled(bool enabled) {
    char data[1];
    data[0] = enabled; // bottom 8 bits
    // write the packet, return the error code
    _line.write(_ID, MX_REG_MOTORONOFF, 1, data);
}

float MX::getPosition(void) {
    if (MX_DEBUG) {
        printf("\nGetPosition(%d)", _ID);
    }

    char data[2];

    int ErrorCode = _line.read(_ID, MX_REG_POSITION, 2, data);
    short position = data[0] + (data[1] << 8);
    float angle = (float)position * 0.088;

    return (angle);
}


bool MX::isMoving() {
    char data[1];
    _line.read(_ID, MX_REG_MOVING, 1, data);
    return (data[0]);
}

void MX::setMode(int mode) {
    switch (mode) {
        //Wheel Mode
        case (0):
            setCWLimitUnits(0);
            setCCWLimitUnits(0);
            //setCRSpeed(0.0);
            break;
        //Joint Mode
        case (1):
            setCWLimitUnits(4000);
            setCCWLimitUnits(4000);
            //setCRSpeed(0.0);
            break;
        //Multi-turn Mode
        case (2):
            setCWLimitUnits(4095);
            setCCWLimitUnits(4095);
            //setCRSpeed(0.0);
            break;
        //other cases
        default:
            if (READ_DEBUG) {
                printf("Not valid mode");
                return;
            }
    }
    _mode = mode;
}

void MX::setCWLimitUnits(short limit) {
    char data[2];
    data[0] = limit & 0xff; // bottom 8 bits
    data[1] = limit >> 8;   // top 8 bits
    // write the packet, return the error code
    _line.write(_ID, MX_REG_CW_LIMIT, 2, data);
}
void MX::setCCWLimitUnits(short limit) {
    char data[2];
    data[0] = limit & 0xff; // bottom 8 bits
    data[1] = limit >> 8;   // top 8 bits
    // write the packet, return the error code
    _line.write(_ID, MX_REG_CCW_LIMIT, 2, data);
}

void MX::setCWLimit(float degrees) {
    limitCWDegrees = degrees;
    //short limit = (short)(MX_BIT_DEG * degrees * _gear_train);
    //setCWLimit(limit);
}

void MX::setCCWLimit(float degrees) {
    limitCCWDegrees = degrees;
    //short limit = (short)(MX_BIT_DEG * degrees * _gear_train);
    //setCCWLimit(limit);
}


void MX::setSpeed(float goalSpeedDegreeS) {
  setMode(0);
  setCRSpeed(goalSpeedDegreeS);
}

void MX::setMaxSpeed(float maxSpeedDegreeS) {
  this->maxSpeedDegreeS = maxSpeedDegreeS;
}

int min(int a, int b) {
    if(a < b) return a; else return b;
}

void MX::setCRSpeed(float goalSpeedDegreeS) {
    // bit 10     = direction, 0 = CCW, 1=CW
    // bits 9-0   = Speed
    char data[2];

    float rpm = std::abs(goalSpeedDegreeS * _gear_train) / 360 * 60;
    int goal = rpm / MOVING_SPEED_UNIT_RPM;
    goal = min(goal, 0x3ff);

    // Set direction CW if we have a negative speed
    if (goalSpeedDegreeS < 0) {
        goal |= (0x1 << 10);
    }

    data[0] = goal & 0xff; // bottom 8 bits
    data[1] = goal >> 8;   // top 8 bits

    // write the packet, return the error code
    _line.write(_ID, MX_REG_MOVING_SPEED, 2, data);
}

//void MX::setCRSpeed(float speed) {
    //// bit 10     = direction, 0 = CCW, 1=CW
    //// bits 9-0   = Speed
    //char data[2];

    //int goal = (0x3ff * std::abs(speed));

    //// Set direction CW if we have a negative speed
    //if (speed < 0) {
        //goal |= (0x1 << 10);
    //}

    //data[0] = goal & 0xff; // bottom 8 bits
    //data[1] = goal >> 8;   // top 8 bits

    //// write the packet, return the error code
    //int rVal = _line.write(_ID, 0x20, 2, data);
//}

float MX::getTemp(void) {
    char data[1];
    int ErrorCode = _line.read(_ID, MX_REG_TEMP, 1, data);
    float temp = data[0];
    return (temp);
}
