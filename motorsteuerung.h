#ifndef __MOTORSTEUERUNG_H__
#define __MOTORSTEUERUNG_H__
int leftF = 3;
int leftB = 4;
int rightF = 5;
int rightB = 6;
int v1=140;
int v2=110;
void leichtGerade()
{
  analogWrite(rightF, v1);
  analogWrite(rightB, 0);
  analogWrite(leftF, v1);
  analogWrite(leftB, 0);
  Serial.println("Gerade");
  delay(2);
}
void RaumRechts()
{
  analogWrite(rightF, 0);
  analogWrite(rightB, v1);
  analogWrite(leftF, v2);
  analogWrite(leftB, 0);
  delay(2);
}

void RaumGerade()
{
  analogWrite(rightF, 0);
  analogWrite(rightB, v1+5);
  analogWrite(leftF, 0);
  analogWrite(leftB, v1);
  delay(2);
}
void leichtRechts()
{
  analogWrite(rightF, 0);
  analogWrite(rightB, v1);
  analogWrite(leftF, 0);
  analogWrite(leftB, 0);
  delay(2);
}
void leichtLinks()
{
  analogWrite(rightF, 0);
  analogWrite(rightB, 0);
  analogWrite(leftF, 0);
  analogWrite(leftB, v1);
  delay(2);
}
void dreheRechts()                    //leichtes Korrigieren rechts
{
  analogWrite(rightF, 0);
  analogWrite(rightB, v2+22);
  analogWrite(leftF, v1);
  analogWrite(leftB, 0);
  Serial.println("Rechts");
  delay(2);
}
void RampedreheRechts()                    //leichtes Korrigieren rechts
{
  analogWrite(rightF, 0);
  analogWrite(rightB, 100);
  analogWrite(leftF, 255);
  analogWrite(leftB, 0);
  Serial.println("Rechts");
  delay(2);
}

void dreheLinks()                    //leichtes Korrigieren links
{
  analogWrite(rightF, v1+22);
  analogWrite(rightB, 0);
  analogWrite(leftF, 0);
  analogWrite(leftB, v2);
  Serial.println("Links");
  delay(2);
}
void RampedreheLinks()                    //leichtes Korrigieren links
{
  analogWrite(rightF, 255);
  analogWrite(rightB, 0);
  analogWrite(leftF, 0);
  analogWrite(leftB, 100);
  Serial.println("Links");
  delay(2);
}


void dreheStarkLinks()               //starkes Korrigieren links
{
  analogWrite(rightF, v1+32);
  analogWrite(rightB, 0);
  analogWrite(leftF, 0);
  analogWrite(leftB, v1+18);
  Serial.println("Stark Links");
  delay(2);
}

void dreheStarkRechts()             //starkes Korrigieren rechts
{
  analogWrite(rightF, 0);
  analogWrite(rightB, v1+22);
  analogWrite(leftF, v1);
  analogWrite(leftB, 0);
  Serial.println("Stark Rechts");
  delay(2);
}


void drehe90Rechts()             //90 Grad Kurve rechts
{
  analogWrite(rightF, 0);
  analogWrite(rightB, v1+22);
  analogWrite(leftF, v2);
  analogWrite(leftB, 0);
  delay(10);
}
void drehe90Rechts2()             //90 Grad Kurve rechts
{
  analogWrite(rightF, 0);
  analogWrite(rightB, v2+22);
  analogWrite(leftF, 200);
  analogWrite(leftB, 0);
  delay(10);
}

void drehe90Links()             //90 Grad Kurve rechts
{
  analogWrite(rightF, v2+22);
  analogWrite(rightB, 0);
  analogWrite(leftF, 0);
  analogWrite(leftB, v1);
  delay(10);
}
void drehe90Links2()             //90 Grad Kurve rechts
{
  analogWrite(rightF, 222);
  analogWrite(rightB, 0);
  analogWrite(leftF, 0);
  analogWrite(leftB, v2);
  delay(10);
}
void drehe90Links3()             //90 Grad Kurve rechts
{
  analogWrite(rightF, 20);
  analogWrite(rightB, 0);
  analogWrite(leftF, 0);
  analogWrite(leftB, 200);
  delay(10);
}
void turn()             //90 Grad Kurve rechts
{
  analogWrite(rightF, 0);
  analogWrite(rightB, v1);
  analogWrite(leftF, v2);
  analogWrite(leftB, 0);
  delay(10);
}
void gerade()                       //geradeaus
{
  analogWrite(rightF, v1+28);    //v1+15
  analogWrite(rightB, 0);
  analogWrite(leftF, v1);
  analogWrite(leftB, 0);
  Serial.println("Gerade");
  delay(1);
}
void Rampe()                       //geradeaus
{
  analogWrite(rightF, 255);
  analogWrite(rightB, 0);
  analogWrite(leftF, 255);
  analogWrite(leftB, 0);
  Serial.println("Gerade");
  delay(1);
}

void back()                        //zurück
{

  analogWrite(rightF, 0);
  analogWrite(rightB, v1+22);
  analogWrite(leftF, 0);
  analogWrite(leftB, v1);
  Serial.println("Zurück");
  delay(1);
}
void dreheUm(){
  analogWrite(rightF, v1);
  analogWrite(rightB, 0);
  analogWrite(leftF, 0);
  analogWrite(leftB, v1);
  Serial.println("drehe Um");
  delay(1);
  }

void Stop()                        //Stop
{
  analogWrite(rightF, 0);
  analogWrite(rightB, 0);
  analogWrite(leftF, 0);
  analogWrite(leftB, 0);
  Serial.println("Stop");
  delay(20);
}
#endif
