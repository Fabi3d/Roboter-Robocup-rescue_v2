/*
 * 
 * Fabian Klotz (Team Dance, Robotics-AG Gymnasium Weingarten
 * Date: 29.05.20
 * 
 */



#include "motorsteuerung.h"
#include "neopixels.h"
#include "tcs230.h"
#include <Pixy2.h>        //Librarys
#include <Servo.h>

Pixy2 pixy;  //pixy-object
int L1;
int L2;                     //lightsensors (Adafruit ALS PT19)
int L3;
int L4;
int L5;
int R = 0;
int sensorTreshold = 320;
Servo Servo1;
Servo Servo2;

void setup() {
  // put your setup code here, to run once:
          pinMode(SENSOR_S0, OUTPUT);
          pinMode(SENSOR_S1, OUTPUT);
          pinMode(SENSOR_S2, OUTPUT);
          pinMode(SENSOR_S3, OUTPUT);
          pinMode(SENSOR_OUT, INPUT);
   // Setting frequency-scaling to 20%
digitalWrite(SENSOR_S0, HIGH);
digitalWrite(SENSOR_S1, LOW);
                              pinMode(leftF, OUTPUT);
                              pinMode(leftB, OUTPUT);
                              pinMode(rightF, OUTPUT);
                              pinMode(rightB, OUTPUT);
                              
  pinMode(A0, INPUT);           //sensoren als input definieren
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);

   pixels.begin();
  
  Serial.begin(115200);
  Serial.print("Starting...\n");
 
  // initiaL2ze the pixy object 
              pixy.init();
              // using the color connected components progL5m
              pixy.changeProg("color_connected_components");
              pixy.setLamp(1, 1);         //activate the led´s
              delay(1000);

}

void loop() {
  // put your main code here, to run repeatedly:
  setPixelBlue();
        readout();
                    static int i = 0;
                    int j;
                    char buf[64]; 
                    int32_t panOffset, tiltOffset;

                    /*
                     * 
                     * The following part ist the very basic line following task. 
                     * 
                     */
  
              if(L1>sensorTreshold && L2>sensorTreshold  && L3>sensorTreshold && L4>sensorTreshold && L5>sensorTreshold)                //if all of the lightsensors are over the sensortreshold
            {  
            unsigned long  Nowtime = millis();
            
              readout();
              while((L1>sensorTreshold && L2>sensorTreshold  && L3>sensorTreshold && L4>sensorTreshold && L5>sensorTreshold))      
              {
                Serial.println(Nowtime);
                readout();
                gerade();
                tcs();
              /*  if( f1+f2+f3 < 4500)
            {
            //  Raum();
            }*/
                if(millis() - Nowtime >= 1000)
                {
                
                  while(L1>sensorTreshold && L2>sensorTreshold  && L3>sensorTreshold && L4>sensorTreshold && L5>sensorTreshold)
                  {
                    readout();
                  back();
                  Serial.println("back");
                  delay(100);
                  }
                  
                }
              }
            }
       readout();
   if((L1>sensorTreshold && L2>sensorTreshold && L3<sensorTreshold && L4>sensorTreshold && L5>sensorTreshold)  || (L1>sensorTreshold && L2<sensorTreshold && L3<sensorTreshold && L4<sensorTreshold && L5>sensorTreshold) ) //alle bedingungen für geL5de geL5de aus
  {
      gerade();
   }
   readout();
if((L1>sensorTreshold && L2<sensorTreshold && L3>sensorTreshold && L4>sensorTreshold && L5>sensorTreshold) || (L1>sensorTreshold && L2<sensorTreshold && L3<sensorTreshold && L4>sensorTreshold && L5>sensorTreshold))          //wenn der seonsor L2/L2+L3 auf schwarz ist
  {
      readout();
      dreheLinks();
  }
readout();
  if((L1>sensorTreshold && L2>sensorTreshold && L3>sensorTreshold && L4<sensorTreshold && L5>sensorTreshold) || (L1>sensorTreshold && L2>sensorTreshold && L3<sensorTreshold && L4<sensorTreshold && L5>sensorTreshold))        //wenn der sensor L4/L4+L3 schwarz ist
  {
      readout();
      dreheRechts();
  }

readout();
 if((L1<sensorTreshold && L2>sensorTreshold && L3>sensorTreshold && L4>sensorTreshold && L5>sensorTreshold) || (L1<sensorTreshold && L2<sensorTreshold && L3>sensorTreshold && L4>sensorTreshold && L5>sensorTreshold))          //wenn der seonsor L1/L1+L2 auf schwarz ist
      {
      readout();
      dreheStarkLinks();
      }
readout();
  if((L1>sensorTreshold && L2>sensorTreshold && L3>sensorTreshold && L4>sensorTreshold && L5<sensorTreshold) || (L1>sensorTreshold && L2>sensorTreshold && L3>sensorTreshold && L4<sensorTreshold && L5<sensorTreshold))        //wenn der sensor L5/L5+L4 schwarz ist
  {
    

      readout();
      dreheStarkRechts();
    
  }
  readout();

                    if(L1<sensorTreshold && L2<sensorTreshold && L3<sensorTreshold && L4>sensorTreshold && L5>sensorTreshold)     //90degree turn to the left
                    {
                      gerade();
                      delay(200);
                      dreheStarkLinks();
                      delay(150);
                      readout();
                      while(L3>sensorTreshold)
                      {
                        readout();
                        dreheStarkLinks();
                      }
                     back();
                     delay(30);
                    }
  readout();
                    if(L1>sensorTreshold && L2>sensorTreshold && L3<sensorTreshold && L4<sensorTreshold && L5<sensorTreshold)     //90 degree turn to the right
                  {
                    gerade();
                    delay(200);
                    dreheStarkRechts();
                    delay(150);
                    readout();
                    while(L3>sensorTreshold)
                    {
                      readout();
                      dreheStarkRechts();
                    }
                    back();
                    delay(30);
                  }
  readout();


  /*
   * the following part is the main part for the green dots.
   * The pixycam ist calculating a position of the center of the detected object (in this case the green dot on the floor
   * The robot is checking if there is a green dot if there also is a black line directly behind this.
   *  
   */

                                            pixy.ccc.getBlocks();
                                      
                                        if (pixy.ccc.numBlocks)
                                        {        
                                          i++;
                                         
                                          panOffset = (int32_t)pixy.frameWidth/2 - (int32_t)pixy.ccc.blocks[0].m_x;
                                          tiltOffset = (int32_t)pixy.ccc.blocks[0].m_y - (int32_t)pixy.frameHeight/2;  
                                          pixy.ccc.getBlocks();
                                      int   panOffset2 = (int32_t)pixy.frameWidth/2 - (int32_t)pixy.ccc.blocks[1].m_x;
                                      int    tiltOffset2 = (int32_t)pixy.ccc.blocks[1].m_y - (int32_t)pixy.frameHeight/2;  
                                         
                                      Serial.print(panOffset);
                                          Serial.print("       ");
                                          Serial.println(tiltOffset);
                                          if(panOffset<0&&tiltOffset>40)
                                          {
                                            back();
                                            delay(10);
                                            Stop();
                                            delay(500);
                                            readout();
                                            if(L5<sensorTreshold&&L4<sensorTreshold)
                                            {
                                              gerade();
                                              delay(700);
                                              readout();
                                              return;
                                            }
                                            gerade();
                                            delay(550);
                                            dreheStarkRechts();
                                            delay(800);
                                            readout();
                                           while(L3>sensorTreshold && L2>sensorTreshold && L1>sensorTreshold)
                                              {
                                                      readout();
                                                      dreheStarkRechts();
                                              }
                                              gerade();
                                              delay(250);
                                              return;
                                          }
                                           if(panOffset>0&&tiltOffset>40)
                                          {
                                            back();
                                            delay(10);
                                            Stop();
                                            delay(500);
                                            
                                            
                                            readout();
                                            if(L1<sensorTreshold&&L2<sensorTreshold)
                                            {
                                              gerade();
                                              delay(700);
                                              readout();
                                             return;
                                            }
                                            gerade();
                                            delay(550);
                                            dreheStarkLinks();
                                            delay(800);
                                            readout();
                                            while(L3>sensorTreshold&& L4>sensorTreshold && L5>sensorTreshold)
                                              {
                                                      readout();
                                                      dreheStarkLinks();
                                              }
                                              gerade();
                                              delay(250);
                                            return;
                                            
                                          }
                                          if(pixy.ccc.numBlocks==2)
                                          {
                                              if(tiltOffset>0&&tiltOffset2>0)
                                      {
                                             turn();
                                            delay(800);
                                            readout();
                                            while(L3>sensorTreshold)
                                            {
                                              dreheStarkRechts();
                                              readout();
                                            } 
                                      }
                                      else
                                      {
                                        return;
                                      }
                                      }
                                      }
}


void readout()
{
    
    L5 = analogRead(A4);
   L4 = analogRead(A3);
   L3 = analogRead(A2);
   L2 = analogRead(A1);
   L1= analogRead(A0);
//   irVal=  analogRead(A5);
    Serial.print(L1);
    Serial.print("---");
    Serial.print(L2);
    Serial.print("---");
    Serial.print(L3);
    Serial.print("---");
    Serial.print(L4);
    Serial.print("---");
    Serial.println(L5);
    Serial.print("           ");
//    Serial.println(irVal);
 
    }
