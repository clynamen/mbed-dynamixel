#include "mbed.h"
#include "communication_1.h"
#include "MX106.h"
#include "MX64.h"
#include <stdio.h>
#include <string.h>

#define MAX_JOINT 3 

/*Connessioni jupers millefori/nucleo: 
    - rosso 5V
    - nero GND
    - marrone D2
    - verde D8 
  Il connettore va stacato dal dynamixel e non dalla millefori per non scambiare il verso!*/
  
Serial pc(USBTX, USBRX);
communication_1 wire(PA_9, PA_10, 9600);
MX106 motor_21(wire, 21, 1);
MX106 motor_22(wire, 22, 1);
MX106 motor_14(wire, 14, 1);
   
int main() {  
   //pc.printf("Start run! \n");
   wire.trigger();
   wire.trigger();
   wire.trigger();
   wire.trigger();
   
   //printf("asking volts\n");
   //float volts = motor_21.getVolts();
   //printf("volts: %f\n", volts);
   
   motor_21.setMotorEnabled(1);

   //printf("set continuous rotation mode\n");
   //motor_21.setMode(0);
   //printf("set speed\n");
   //motor_21.setSpeed(180);
   //printf("speed set\n");


   //printf("set multiturn mode\n");
   //motor_21.setMode(2);
   //printf("asking pos\n");
   //float pos = motor_21.getPosition();
   //printf(" pos : %f \n", pos);
   //motor_21.setSpeed(90);
   //float wait_time = 5;
   //motor_21.setGoalPosition(0);
   //wait(10);
   //float targets[7] = {0, 90, 180, 270, 180, 360, 720};
   //for (int i = 0; i < 7; i++) {
     //motor_21.setGoalPosition(targets[i]);
     //wait(wait_time);
   //}
   //printf("asking pos after move\n");
   //pos = motor_21.getPosition();
   //printf(" pos : %f \n", pos);

   Joint* joint_21 = &motor_21;

   float pos;
   //joint_21->setMaxSpeed(360*3/2);
   //joint_21->setSpeed(90);
   //wait(3);
   //joint_21->setSpeed(0);
   //wait(1);
   //pos = motor_21.getPosition();
   //printf(" pos : %f \n", pos);
   

   //joint_21->setCWLimit(90);
   //joint_21->setCCWLimit(-90);
   //joint_21->setGoalPosition(0); 
   //wait(5);
   //pos = motor_21.getPosition();
   //printf(" pos : %f \n", pos);

   //joint_21->setGoalPosition(80); 
   //wait(5);
   //pos = motor_21.getPosition();
   //printf(" pos : %f \n", pos);

   //joint_21->setGoalPosition(130); 
   //wait(5);
   //pos = motor_21.getPosition();
   //printf(" pos : %f \n", pos);

   //joint_21->setGoalPosition(-130); 
   //wait(5);
   //pos = motor_21.getPosition();
   //printf(" pos : %f \n", pos);
   //
   //
   
   Joint* joints[MAX_JOINT];
   joints[0] = &motor_21;
   joints[1] = &motor_22;
   joints[2] = &motor_14;

   // comandi
   char buf[200];
   uint8_t current_motor = 0; 

   while(1) {
     printf("\n insert command: \n");
     if(pc.gets(buf, 200)) {
       char command[3];
       strncpy(command, buf, 2);
       command[2]='\0';

       if(strcmp(command, "ID")  == 0) {
         int id;
         if(sscanf(buf, "ID %d", &id) != 1) {
           printf("\n bad ID command \n");
         };
         bool found = false;
         for(int i =0; i< MAX_JOINT && !found; i++) {
           int nid = joints[i]->getID();
           printf("found motor with id %d\n", nid);
           if(id == nid) {
             printf("\nusing motor %d - ID: %d", i, id);
             current_motor = i;
             found = true;
             break;
           } 
         }
         if(!found) {
           printf("\nmotor with ID: %d not found", id);
         }
       } else if(strcmp(command, "GO") == 0) {
         float posDegrees;
         if(sscanf(buf, "GO %f", &posDegrees) != 1) {
           printf("\n bad GO command \n");
           break;
         }
         joints[current_motor]->setGoalPosition(posDegrees);
       } else if(strcmp(command, "SP") == 0) {
         float speed;
         if(sscanf(buf, "SP %f", &speed) != 1) {
           printf("\n bad SP command \n");
           break;
         }
         joints[current_motor]->setSpeed(speed);
       } else {
         printf("\n unknown command: \"\s\" \n", buf);
       }


     };
   }

}
