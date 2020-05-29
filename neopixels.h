#ifndef __NEOPIXEL_H__
#define __NEOPIXEL_H__
#include <Adafruit_NeoPixel.h>
#define PIN        2
Adafruit_NeoPixel pixels(13, PIN, NEO_GRB + NEO_KHZ800);


void setPixelGreen()
{
  pixels.clear();
  pixels.setBrightness(255);
  pixels.setPixelColor(0, pixels.Color(0, 250, 0));
  pixels.setPixelColor(1, pixels.Color(0, 250, 0));
  pixels.setPixelColor(2, pixels.Color(0, 250, 0));
  pixels.setPixelColor(3, pixels.Color(0, 250, 0));
  pixels.setPixelColor(4, pixels.Color(0, 250, 0));
  pixels.setPixelColor(5, pixels.Color(0, 250, 0));
  pixels.setPixelColor(6, pixels.Color(0, 250,0));
  pixels.setPixelColor(7, pixels.Color(0, 250, 0));
  pixels.setPixelColor(8, pixels.Color(0, 250, 0));
  pixels.setPixelColor(9, pixels.Color(0, 250, 0));
  pixels.setPixelColor(10, pixels.Color(0, 250, 0));
  pixels.setPixelColor(11, pixels.Color(0, 250, 0));
  pixels.setPixelColor(12, pixels.Color(0, 250, 0));
    pixels.show();

}
void setPixelBlue()
{
  pixels.clear();
  pixels.setBrightness(255);
  pixels.setPixelColor(0, pixels.Color(0, 0, 250));
  pixels.setPixelColor(1, pixels.Color(0, 0, 250));
  pixels.setPixelColor(2, pixels.Color(0, 0, 250));
  pixels.setPixelColor(3, pixels.Color(0, 0, 250));
  pixels.setPixelColor(4, pixels.Color(0, 0, 250));
  pixels.setPixelColor(5, pixels.Color(0, 0, 250));
  pixels.setPixelColor(6, pixels.Color(0, 0,250));
  pixels.setPixelColor(7, pixels.Color(0, 0, 250));
  pixels.setPixelColor(8, pixels.Color(0, 0, 250));
  pixels.setPixelColor(9, pixels.Color(0, 0, 250));
  pixels.setPixelColor(10, pixels.Color(0, 0, 250));
  pixels.setPixelColor(11, pixels.Color(0, 0, 250));
  pixels.setPixelColor(12, pixels.Color(0, 0, 250));
    pixels.show();

}
void setRightGreen()
{
  pixels.clear();
  pixels.setBrightness(255);
  pixels.setPixelColor(0, pixels.Color(0, 250, 0));
  pixels.setPixelColor(1, pixels.Color(0, 250, 0));
  pixels.setPixelColor(2, pixels.Color(0, 250, 0));
  pixels.setPixelColor(3, pixels.Color(0, 0, 250));
  pixels.setPixelColor(4, pixels.Color(0, 0, 250));
  pixels.setPixelColor(5, pixels.Color(0, 0, 250));
  pixels.setPixelColor(6, pixels.Color(0, 0,250));
  pixels.setPixelColor(7, pixels.Color(0, 0, 250));
  pixels.setPixelColor(8, pixels.Color(0, 0, 250));
    pixels.show();
}
void setLeftGreen()
{
  pixels.clear();
  pixels.setBrightness(255);
  pixels.setPixelColor(0, pixels.Color(0, 0, 250));
  pixels.setPixelColor(1, pixels.Color(0, 0, 250));
  pixels.setPixelColor(2, pixels.Color(0, 0, 250));
  pixels.setPixelColor(3, pixels.Color(0, 0, 250));
  pixels.setPixelColor(4, pixels.Color(0, 0, 250));
  pixels.setPixelColor(5, pixels.Color(0, 0, 250));
  pixels.setPixelColor(6, pixels.Color(0, 250,0));
  pixels.setPixelColor(7, pixels.Color(0, 250, 0));
  pixels.setPixelColor(8, pixels.Color(0, 250, 0));
    pixels.show();
}

#endif
