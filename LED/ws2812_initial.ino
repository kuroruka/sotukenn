#include <FastLED.h>


#define Neopixel_PIN    10
#define NUM_LEDS    28
CRGB leds[NUM_LEDS]; //LEDの変数宣言

void LED_Start_up() {
  int Time = 100;
  int i = 0;
  //点灯
  for (i = 0; i < 9; i++) {
    leds[i] = CRGB::Red;
    FastLED.show();
    delay(Time);
  }
  for (i = 9; i < 18; i++) {
    leds[i] = CRGB::Blue;
    FastLED.show();
    delay(Time);
  }
  for (i = 18; i < 28; i++) {
    leds[i] = CRGB::Green;
    FastLED.show();
    delay(Time);
  }
  //消灯
  for (i = 28; i > 18; i--) {
    leds[i] = CRGB(0, 0, 0);
    FastLED.show();
    delay(Time);
  }
  for (i = 18; i > 9; i--) {
    leds[i] = CRGB(0, 0, 0);
    FastLED.show();
    delay(Time);
  }
  for (i = 9; i >= 0; i--) {
    leds[i] = CRGB(0, 0, 0);
    FastLED.show();
    delay(Time);
  }

}

void setup() {
  FastLED.addLeds<WS2811, Neopixel_PIN>(leds, NUM_LEDS);

}

void loop() {
  
  LED_Start_up();
}
