#include <Adafruit_NeoPixel.h>
#define PIN        10// 信号用のピンを指定
#define NUMPIXELS 28 // LEDの数を指定
#define DELAYVAL 50
int step_num = 0;
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
/*
   runred()
   点滅赤
*/
void runRed() {
  uint32_t color = pixels.Color(127, 0,0 );
  pixels.clear();
  for (int c = step_num; c < pixels.numPixels(); c += 3) {
    pixels.setPixelColor(c, color);
  }
  pixels.show();
  if (++step_num == 3) {
    step_num = 0;
  }
  delay(DELAYVAL);
}
/*
   runWhite()
   点滅白
*/
void runWhite() {
  uint32_t color = pixels.Color(127, 127, 127);
  pixels.clear();
  for (int c = step_num; c < pixels.numPixels(); c += 3) {
    pixels.setPixelColor(c, color);
  }
  pixels.show();
  if (++step_num == 3) {
    step_num = 0;
  }
  delay(DELAYVAL);
}
/*
   allWhite()
   白
*/
void allWhite() {
// pixels.clear(); // すべてのLEDの色を0にセット
  for(int i=0; i<NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(127, 127, 127));
    pixels.show();
  }
}
/*
   allRed()
   赤
*/
void allRed() {
// pixels.clear(); // すべてのLEDの色を0にセット
  for(int i=0; i<NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(127, 0, 0));
    pixels.show();
  }
}







CADNEET にメッセージを送信する
