#ifndef MBED_MX106_H
#define MBED_MX106_H

#include "mbed.h"
#include "SerialHalfDuplex.h"
#include "communication_1.h"
#include "MX.h"

#define REG_ID 0x3
#define REG_CW_LIMIT 0x06
#define REG_CCW_LIMIT 0x08
#define REG_GOAL_POSITION 0x1E
#define REG_MOVING_SPEED 0x20
#define REG_VOLTS 0x2A
#define REG_TEMP 0x2B
#define REG_MOVING 0x2E
#define REG_POSITION 0x24

class MX106 : public MX {

    public:
    
        MX106(communication_1& _line, int ID, float gear_train);
    };
#endif
