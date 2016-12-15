#include "MX64.h"
#include "mbed.h"
#include <cmath>

#define MX64_DEBUG 1
#define goal_resolution 0.08789

MX64::MX64(communication_1& com, int ID, float gear_train)
  : MX(com, ID, gear_train) {

}

MX64::~MX64() {
}

