#include "MX106.h"
#include "mbed.h"
#include "communication_1.h"
#include <cmath>
//360°/4095
#define RESOLUTION 0.088
//bit per degrees 4095/360°
#define BIT_DEG 11.375

#define READ_DEBUG 1

MX106::MX106(communication_1& line, int ID, float gear_train) : MX(line, ID, gear_train) {
}

