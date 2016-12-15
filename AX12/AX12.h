/* mbed AX-12+ Servo Library
 *
 * Copyright (c) 2010, cstyles (http://mbed.org)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef MBED_AX12_H
#define MBED_AX12_H

#include "mbed.h"
#include "SerialHalfDuplex.h"
#include "MX.h"
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

#define AX12_MODE_POSITION  0
#define AX12_MODE_ROTATION  1

#define AX12_CW 1
#define AX12_CCW 1

/** Servo control class, based on a PwmOut
 *
 * Example:
 * @code
 * #include "mbed.h"
 * #include "AX12.h"
 * 
 * int main() {
 * 
 *   AX12 myax12 (p9, p10, 1);
 *
 *   while (1) {
 *       myax12.SetGoal(0);    // go to 0 degrees
 *       wait (2.0);
 *       myax12.SetGoal(300);  // go to 300 degrees
 *       wait (2.0);
 *   }
 * }
 * @endcode
 */
class AX12 : public MX {

public:

    AX12(communication_1& line, int ID, float gear_train);
    virtual void setMode(int mode);

};

#endif

