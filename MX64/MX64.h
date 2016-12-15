#ifndef MBED_AX12_H
#define MBED_AX12_H

#include "mbed.h"
#include "MX.h"
#include "SerialHalfDuplex.h"
#define MX64_WRITE_DEBUG 1
#define MX64_READ_DEBUG 1
#define MX64_TRIGGER_DEBUG 1
#define MX64_DEBUG 1

#define MX64_REG_ID 0x3
#define MX64_REG_CW_LIMIT 0x06
#define MX64_REG_CCW_LIMIT 0x08
#define MX64_REG_GOAL_POSITION 0x1E
#define MX64_REG_MOVING_SPEED 0x20
#define MX64_REG_VOLTS 0x2A
#define MX64_REG_CURRENT 0x44
#define MX64_REG_TEMP 0x2B
#define MX64_REG_MOVING 0x2E
#define MX64_REG_POSITION 0x24

#define MX64_MODE_POSITION  0
#define MX64_MODE_ROTATION  1

#define MX64_CW 1
#define MX64_CCW 1

class MX64 : public MX {

public:
    MX64(communication_1& com, int ID, float _gear_train);
    ~MX64();
};

#endif
