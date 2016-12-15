#ifndef MBED_communication_1_H
#define MBED_communication_1_H
#include "mbed.h"
#include "SerialHalfDuplex.h"


class communication_1{

public:
   
    communication_1(PinName tx, PinName rx, int baud_rate);
    
    int read(int ID, int start, int length, char* data);
    int write(int ID, int start, int length, char* data, int flag=0);
    void trigger();

private :

    SerialHalfDuplex _SerialHalfDuplex;
    
};
#endif
