#include "AX12.h"
#include "mbed.h"
#include <cmath>
#define AX12_DEBUG 1

AX12::AX12(communication_1& line, int ID, float gear_train) 
  : MX(line, ID, gear_train) {
}

// Set the mode of the servo
//  0 = Positional (0-300 degrees)
//  1 = Rotational -1 to 1 speed
void AX12::setMode(int mode) {
    switch (mode) {
        //Wheel Mode
        case (0):
            setCWLimitUnits(0);
            setCCWLimitUnits(0);
            //setCRSpeed(0.0);
            break;
        //Joint Mode
        case (1):
            setCWLimit(360);
            setCCWLimit(360);
            //setCRSpeed(0.0);
            break;
        default:
            if (READ_DEBUG) {
                printf("Not valid mode for AX12");
                return;
            }
    }
    _mode = mode;
}

