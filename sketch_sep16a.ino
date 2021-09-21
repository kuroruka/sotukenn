#include <Adafruit_NeoPixel.h>
#define PIN        10// 信号用のピンを指定
#define NUMPIXELS 28 // LEDの数を指定

#include "ledLib.h"
//
//Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 50

//int step_num = 0;
//uint32_t color = pixels.Color(127, 127, 127);

void setup() {
  pixels.begin();
}

void loop() {
//runWhite();
//  delay(1000);
  //runRed();
  allWhite();
  //allRed();
  
}
