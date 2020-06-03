#include "motorsteuerung.h"
#include "neopixels.h"
#include "tcs230.h"
#include <Pixy2.h>        //Librarys
#include <Servo.h>

 
Pixy2 pixy;  //pixy-object

Servo Servo1;
Servo Servo2;
int La;
int Li;                     //Lightsensors
int Mi;
int Ri;
int Ra;
int R = 0;
int grenzLa = 320;         //set sensortresholds
int grenzLi = 320;         //set sensortresholds
int grenzMi = 300;
int grenzRi = 320;
int grenzRa = 320;  

void setup() {
  Setup();

}

void loop() {
  // put your main code here, to run repeatedly:

Line();         
green();
}
