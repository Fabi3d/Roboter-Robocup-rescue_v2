#ifndef __MOTORSTEUERUNG_H__
#define __MOTORSTEUERUNG_H__
int linksV = 3;
int linksR = 4;
int rechtsV = 5;
int rechtsR = 6;
int v1=140;
int v2=110;
void leichtGerade()
{
  analogWrite(rechtsV, v1);
  analogWrite(rechtsR, 0);
  analogWrite(linksV, v1);
  analogWrite(linksR, 0);
  Serial.println("Gerade");
  delay(2);
}
void RaumRechts()
{
  analogWrite(rechtsV, 0);
  analogWrite(rechtsR, v1);
  analogWrite(linksV, v2);
  analogWrite(linksR, 0);
  delay(2);
}

void RaumGerade()
{
  analogWrite(rechtsV, 0);
  analogWrite(rechtsR, v1+5);
  analogWrite(linksV, 0);
  analogWrite(linksR, v1);
  delay(2);
}
void leichtRechts()
{
  analogWrite(rechtsV, 0);
  analogWrite(rechtsR, v1);
  analogWrite(linksV, 0);
  analogWrite(linksR, 0);
  delay(2);
}
void leichtLinks()
{
  analogWrite(rechtsV, 0);
  analogWrite(rechtsR, 0);
  analogWrite(linksV, 0);
  analogWrite(linksR, v1);
  delay(2);
}
void dreheRechts()                    //leichtes Korrigieren rechts
{
  analogWrite(rechtsV, 0);
  analogWrite(rechtsR, v2+22);
  analogWrite(linksV, v1);
  analogWrite(linksR, 0);
  Serial.println("Rechts");
  delay(2);
}
void RampedreheRechts()                    //leichtes Korrigieren rechts
{
  analogWrite(rechtsV, 0);
  analogWrite(rechtsR, 100);
  analogWrite(linksV, 255);
  analogWrite(linksR, 0);
  Serial.println("Rechts");
  delay(2);
}

void dreheLinks()                    //leichtes Korrigieren links
{
  analogWrite(rechtsV, v1+22);
  analogWrite(rechtsR, 0);
  analogWrite(linksV, 0);
  analogWrite(linksR, v2);
  Serial.println("Links");
  delay(2);
}
void RampedreheLinks()                    //leichtes Korrigieren links
{
  analogWrite(rechtsV, 255);
  analogWrite(rechtsR, 0);
  analogWrite(linksV, 0);
  analogWrite(linksR, 100);
  Serial.println("Links");
  delay(2);
}


void dreheStarkLinks()               //starkes Korrigieren links
{
  analogWrite(rechtsV, v1+32);
  analogWrite(rechtsR, 0);
  analogWrite(linksV, 0);
  analogWrite(linksR, v1+18);
  Serial.println("Stark Links");
  delay(2);
}

void dreheStarkRechts()             //starkes Korrigieren rechts
{
  analogWrite(rechtsV, 0);
  analogWrite(rechtsR, v1+22);
  analogWrite(linksV, v1);
  analogWrite(linksR, 0);
  Serial.println("Stark Rechts");
  delay(2);
}


void drehe90Rechts()             //90 Grad Kurve rechts
{
  analogWrite(rechtsV, 0);
  analogWrite(rechtsR, v1+22);
  analogWrite(linksV, v2);
  analogWrite(linksR, 0);
  delay(10);
}
void drehe90Rechts2()             //90 Grad Kurve rechts
{
  analogWrite(rechtsV, 0);
  analogWrite(rechtsR, v2+22);
  analogWrite(linksV, 200);
  analogWrite(linksR, 0);
  delay(10);
}

void drehe90Links()             //90 Grad Kurve rechts
{
  analogWrite(rechtsV, v2+22);
  analogWrite(rechtsR, 0);
  analogWrite(linksV, 0);
  analogWrite(linksR, v1);
  delay(10);
}
void drehe90Links2()             //90 Grad Kurve rechts
{
  analogWrite(rechtsV, 222);
  analogWrite(rechtsR, 0);
  analogWrite(linksV, 0);
  analogWrite(linksR, v2);
  delay(10);
}
void drehe90Links3()             //90 Grad Kurve rechts
{
  analogWrite(rechtsV, 20);
  analogWrite(rechtsR, 0);
  analogWrite(linksV, 0);
  analogWrite(linksR, 200);
  delay(10);
}
void turn()             //90 Grad Kurve rechts
{
  analogWrite(rechtsV, 0);
  analogWrite(rechtsR, v1);
  analogWrite(linksV, v2);
  analogWrite(linksR, 0);
  delay(10);
}
void gerade()                       //geradeaus
{
  analogWrite(rechtsV, v1+28);    //v1+15
  analogWrite(rechtsR, 0);
  analogWrite(linksV, v1);
  analogWrite(linksR, 0);
  Serial.println("Gerade");
  delay(1);
}
void Rampe()                       //geradeaus
{
  analogWrite(rechtsV, 255);
  analogWrite(rechtsR, 0);
  analogWrite(linksV, 255);
  analogWrite(linksR, 0);
  Serial.println("Gerade");
  delay(1);
}

void back()                        //zurück
{

  analogWrite(rechtsV, 0);
  analogWrite(rechtsR, v1+22);
  analogWrite(linksV, 0);
  analogWrite(linksR, v1);
  Serial.println("Zurück");
  delay(1);
}
void dreheUm(){
  analogWrite(rechtsV, v1);
  analogWrite(rechtsR, 0);
  analogWrite(linksV, 0);
  analogWrite(linksR, v1);
  Serial.println("drehe Um");
  delay(1);
  }

void Stop()                        //Stop
{
  analogWrite(rechtsV, 0);
  analogWrite(rechtsR, 0);
  analogWrite(linksV, 0);
  analogWrite(linksR, 0);
  Serial.println("Stop");
  delay(20);
}
#endif
