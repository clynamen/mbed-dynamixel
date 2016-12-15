#include "communication_1.h"
#include "mbed.h"

#define READ_DEBUG 1
#define WRITE_DEBUG 1
#define TRIGGER_DEBUG 0

communication_1::communication_1(PinName tx, PinName rx, int baud_rate) 
  : _SerialHalfDuplex(tx,rx) {

    _SerialHalfDuplex.baud(baud_rate);
  }

int communication_1::read(int ID, int start, int bytes, char* data) {

  char PacketLength = 0x4;
  char TxBuf[16];
  char sum = 0;
  char Status[16];

  Status[4] = 0xFE; // return code

  TxBuf[0] = 0xff;
  TxBuf[1] = 0xff;

  // ID
  TxBuf[2] = ID;
  sum += TxBuf[2];

  // Packet Length
  TxBuf[3] = PacketLength;    // Length = 4 ; 2 + 1 (start) = 1 (bytes)
  sum += TxBuf[3];            // Accululate the packet sum

  // Instruction - Read
  TxBuf[4] = 0x2;
  sum += TxBuf[4];

  // Start Address
  TxBuf[5] = start;
  sum += TxBuf[5];

  // Bytes to read
  TxBuf[6] = bytes;
  sum += TxBuf[6];

  // Checksum
  TxBuf[7] = 0xFF - sum;

  // Transmit the packet in one burst with no pausing
  for (int i = 0; i<8 ; i++) {
    // printf("Inizio scrittura numero %d\n",i);
    _SerialHalfDuplex.putc(TxBuf[i]);
    //printf("Fine scrittura numero %d\n",i);
  }

  // Wait for the bytes to be transmitted
  wait (0.00002);

  // Skip if the read was to the broadcast address
  if (ID != 0xFE) {
    // Receive the Status packet 6+ number of bytes read
    for (int i=0; i<(6+bytes) ; i++) {
      Status[i] = _SerialHalfDuplex.getc();
    }

    // Copy the data from Status into data for return
    for (int i=0; i < Status[3]-2 ; i++) {
      data[i] = Status[5+i];
    }

    if (READ_DEBUG) {
      printf("\nStatus Packet\n");
      printf("  Header : 0x%x\n",Status[0]);
      printf("  Header : 0x%x\n",Status[1]);
      printf("  ID : 0x%x\n",Status[2]);
      printf("  Length : 0x%x\n",Status[3]);
      printf("  Error Code : 0x%x\n",Status[4]);

      for (int i=0; i < Status[3]-2 ; i++) {
        printf("  Data : 0x%x\n",Status[5+i]);
      }    
      printf("  Checksum : 0x%x\n",Status[5+(Status[3]-2)]);
    }            
  } // if (ID!=0xFE)

  return(Status[4]);
}


int communication_1::write(int ID, int start, int bytes, char* data, int flag) {
  // 0xff, 0xff, ID, Length, Intruction(write), Address, Param(s), Checksum

  char TxBuf[16];
  char sum = 0;
  char Status[6];

  TxBuf[0] = 0xff;
  TxBuf[1] = 0xff;

  // ID
  TxBuf[2] = ID;
  sum += TxBuf[2];

  // packet Length
  TxBuf[3] = 3+bytes;
  sum += TxBuf[3];

  // Instruction
  if (flag == 1) {
    TxBuf[4]=0x04;
    sum += TxBuf[4];
  } else {
    TxBuf[4]=0x03;
    sum += TxBuf[4];
  }

  // Start Address
  TxBuf[5] = start;
  sum += TxBuf[5];

  // data
  for (int i=0; i<bytes ; i++) {
    TxBuf[6+i] = data[i];
    sum += TxBuf[6+i];
  }

  // checksum
  TxBuf[6+bytes] = 0xFF - sum;

  // Transmit the packet in one burst with no pausing
  for (int i = 0; i < (7 + bytes) ; i++) {
    _SerialHalfDuplex.putc(TxBuf[i]);
  }

  // Wait for data to transmit
  wait (0.00002);

  // make sure we have a valid return
  Status[4]=0x00;

  // we'll only get a reply if it was not broadcast
  if (ID!=0xFE) {
    // response is always 6 bytes
    // 0xFF, 0xFF, ID, Length Error, Param(s) Checksum
    for (int i=0; i < 6 ; i++) {
      Status[i] = _SerialHalfDuplex.getc();
    }

    return(Status[4]); // return error code

  }
}

void communication_1::trigger(void) {

  char TxBuf[16];
  char sum = 0;

  if (TRIGGER_DEBUG) {
    printf("\nTriggered\n");
  }

  // Build the TxPacket first in RAM, then we'll send in one go
  if (TRIGGER_DEBUG) {
    printf("\nTrigger Packet\n  Header : 0xFF, 0xFF\n");
  }

  TxBuf[0] = 0xFF;
  TxBuf[1] = 0xFF;

  // ID - Broadcast
  TxBuf[2] = 0xFE;
  sum += TxBuf[2];

  if (TRIGGER_DEBUG) {
    printf("  ID : %d\n",TxBuf[2]);
  }

  // Length
  TxBuf[3] = 0x02;
  sum += TxBuf[3];
  if (TRIGGER_DEBUG) {
    printf("  Length %d\n",TxBuf[3]);
  }

  // Instruction - ACTION
  TxBuf[4] = 0x04;
  sum += TxBuf[4];
  if (TRIGGER_DEBUG) {
    printf("  Instruction 0x%X\n",TxBuf[5]);
  }

  // Checksum
  TxBuf[5] = 0xFF - sum;
  if (TRIGGER_DEBUG) {
    printf("  Checksum 0x%X\n",TxBuf[5]);
  }

  // Transmit the packet in one burst with no pausing
  for (int i = 0; i < 6 ; i++) {
    _SerialHalfDuplex.putc(TxBuf[i]);
  }

  // This is a broadcast packet, so there will be no reply

  return;
}
