#include <Pixy2.h> 

 void green()
{
   static int i = 0;
  int j;
  char buf[64]; 
  int32_t panOffset, tiltOffset;
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
      auslesen();
      if(Ra<grenzRa&&Ri<grenzRi)
      {
        gerade();
        delay(700);
        auslesen();
        return;
      }
      gerade();
      delay(550);
      dreheStarkRechts();
      delay(800);
      auslesen();
     while(Mi>grenzMi && Li>grenzLi && La>grenzLa)
        {
                auslesen();
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
      
      
      auslesen();
      if(La<grenzLa&&Li<grenzLi)
      {
        gerade();
        delay(700);
        auslesen();
       return;
      }
      gerade();
      delay(550);
      dreheStarkLinks();
      delay(800);
      auslesen();
      while(Mi>grenzMi&& Ri>grenzRi && Ra>grenzRa)
        {
                auslesen();
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
      auslesen();
      while(Mi>grenzMi)
      {
        dreheStarkRechts();
        auslesen();
      } 
}
else
{
  return;
}
}
}
}
