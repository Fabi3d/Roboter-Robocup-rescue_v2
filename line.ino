void Line()
{
   auslesen();
  
  if(La>grenzLa && Li>grenzLi  && Mi>grenzMi && Ri>grenzRi && Ra>grenzRa)
{  
unsigned long  Nowtime = millis();

  auslesen();
  while((La>grenzLa && Li>grenzLi  && Mi>grenzMi && Ri>grenzRi && Ra>grenzRa))      
  {
    Serial.println(Nowtime);
    auslesen();
    gerade();
    tcs();
  /*  if( f1+f2+f3 < 4500)
{
//  Raum();
}*/
    if(millis() - Nowtime >= 1000)
    {
    
      while(La>grenzLa && Li>grenzLi  && Mi>grenzMi && Ri>grenzRi && Ra>grenzRa)
      {
        auslesen();
      back();
      Serial.println("back");
      delay(100);
      }
      
    }
  }
}
  auslesen();
   if((La>grenzLa && Li>grenzLi && Mi<grenzMi && Ri>grenzRi && Ra>grenzRa)  || (La>grenzLa && Li<grenzLi && Mi<grenzMi && Ri<grenzRi && Ra>grenzRa) ) //alle bedingungen für gerade gerade aus
  {
      gerade();
   }
   auslesen();
if((La>grenzLa && Li<grenzLi && Mi>grenzMi && Ri>grenzRi && Ra>grenzRa) || (La>grenzLa && Li<grenzLi && Mi<grenzMi && Ri>grenzRi && Ra>grenzRa))          //wenn der seonsor li/li+mi auf schwarz ist
  {

   
      auslesen();
      dreheLinks();
    
  }
auslesen();
  if((La>grenzLa && Li>grenzLi && Mi>grenzMi && Ri<grenzRi && Ra>grenzRa) || (La>grenzLa && Li>grenzLi && Mi<grenzMi && Ri<grenzRi && Ra>grenzRa))        //wenn der sensor ri/ri+mi schwarz ist
  {
   
 
      auslesen();
      dreheRechts();
    
  }

auslesen();
 if((La<grenzLa && Li>grenzLi && Mi>grenzMi && Ri>grenzRi && Ra>grenzRa) || (La<grenzLa && Li<grenzLi && Mi>grenzMi && Ri>grenzRi && Ra>grenzRa))          //wenn der seonsor la/la+li auf schwarz ist
 {

      auslesen();
      dreheStarkLinks();
    
  }
auslesen();
  if((La>grenzLa && Li>grenzLi && Mi>grenzMi && Ri>grenzRi && Ra<grenzRa) || (La>grenzLa && Li>grenzLi && Mi>grenzMi && Ri<grenzRi && Ra<grenzRa))        //wenn der sensor ra/ra+ri schwarz ist
  {
    

      auslesen();
      dreheStarkRechts();
    
  }
  auslesen();

  if(La<grenzLa && Li<grenzLi && Mi<grenzMi && Ri>grenzRi && Ra>grenzRa) 
  {
    gerade();
    delay(200);
    dreheStarkLinks();
    delay(150);
    auslesen();
    while(Mi>grenzMi)
    {
      auslesen();
      dreheStarkLinks();
    }
   back();
   delay(30);
  }
  auslesen();
    if(La>grenzLa && Li>grenzLi && Mi<grenzMi && Ri<grenzRi && Ra<grenzRa) 
  {
    gerade();
    delay(200);
    dreheStarkRechts();
    delay(150);
    auslesen();
    while(Mi>grenzMi)
    {
      auslesen();
      dreheStarkRechts();
    }
    back();
    delay(30);
  }
  auslesen();

}



void auslesen()
{
    
    Ra = analogRead(A4);
   Ri = analogRead(A3);
   Mi = analogRead(A2);
   Li = analogRead(A1);
   La= analogRead(A0);
//   irVal=  analogRead(A5);
    Serial.print(La);
    Serial.print("---");
    Serial.print(Li);
    Serial.print("---");
    Serial.print(Mi);
    Serial.print("---");
    Serial.print(Ri);
    Serial.print("---");
    Serial.println(Ra);
    Serial.print("           ");
//    Serial.println(irVal);
 
    }
