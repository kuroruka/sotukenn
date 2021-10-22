#include <FastLED.h>


//色情報
//右に流れるか？　左に流れるか？
//点滅する間隔
//白色のライトの向きが動かずにずっと当たっている時のパターン



int i;
int j;
#define Neopixel_PIN    18
#define NUM_LEDS    28
CRGB leds[NUM_LEDS]; //LEDの変数宣言

void led_1() {
  //1パート
  for (i = 0; i < 28; i++) {
    leds[i] = CRGB(255, 255, 255);
    FastLED.show();

  }
  delay(10000);

  for (i = 0; i < 28; i++) {
    leds[i] = CRGB(0, 0, 0);
    FastLED.show();

  }
  //2パート
  //  for (j = 0; j < 10; j++) {
  //    for (i = 0; i < 28; i++) {
  //      leds[i] = CRGB(255, 255, 255);
  //      delay(10);
  //
  //      FastLED.show();
  //
  //    }
  //    for (i = 0; i < 28; i++) {
  //      leds[i] = CRGB(0, 0, 0);
  //      FastLED.show();
  //    }
  //  }
  //  for (i = 0; i < 28; i++) {
  //    leds[i] = CRGB(0, 0, 0);
  //    FastLED.show();
  //  }


  //  for (j = 0; j < 10; j++) {
  //    for (i = 27; i >= 0; i--) {
  //      leds[i] = CRGB(255, 255, 255);
  //      FastLED.show();
  //      delay(10);
  //
  //    }
  //    for (i = 0; i < 28; i++) {
  //      leds[i] = CRGB(0, 0, 0);
  //      FastLED.show();
  //    }
  //  }
  //
  //  for (i = 0; i < 28; i++) {
  //    leds[i] = CRGB(0, 0, 0);
  //    FastLED.show();
  //  }

  //3パート
  //  for (j = 0; j < 9; j++) {
  //    for (i = 0; i < 28; i++) {
  //      leds[i] = CRGB(255, 0, 0);
  //      delay(10);
  //
  //      FastLED.show();
  //
  //    }
  //    for (i = 0; i < 28; i++) {
  //      leds[i] = CRGB(0, 0, 0);
  //      FastLED.show();
  //    }
  //  }
  //  for (i = 0; i < 28; i++) {
  //    leds[i] = CRGB(0, 0, 0);
  //    FastLED.show();
  //  }


  //  for (j = 0; j < 9; j++) {
  //    for (i = 27; i >= 0; i--) {
  //      leds[i] = CRGB(255, 0, 0);
  //      FastLED.show();
  //      delay(10);
  //
  //    }
  //    for (i = 0; i < 28; i++) {
  //      leds[i] = CRGB(0, 0, 0);
  //      FastLED.show();
  //    }
  //  }
  //パート4



  //  for (j = 0; j < 50; j++) {
  //    int c = random(0, 3);
  //    Serial.print(c);
  //
  //    switch (c) {
  //      case 0:
  //        for (i = 0; i < 9; i++) {
  //          leds[i] = CRGB(j * 1.2, j * 1.2, 255);
  //
  //          FastLED.show();
  //
  //        }
  //        delay(100);
  //        break;
  //      case 1:
  //        for (i = 9; i < 18; i++) {
  //          leds[i] = CRGB(j * 1.2, j * 1.2, 255);
  //
  //          FastLED.show();
  //
  //        }
  //        delay(100);
  //        break;
  //      case 2:
  //        for (i = 18; i < 28; i++) {
  //          leds[i] = CRGB(j * 1.2, j * 1.2, 255);
  //
  //          FastLED.show();
  //
  //        }
  //        delay(100);
  //        break;
  //
  //    }
  //
  //
  //    for (i = 0; i < 28; i++) {
  //      leds[i] = CRGB(0, 0, 0);
  //
  //      FastLED.show();
  //    }
  //
  //  }

  //パート5
  for (j = 0; j < 25; j++) {
    for (i = 0; i < 14; i++) {
      leds[i] = CRGB(0, 255, 255);
      leds[28 - i] = CRGB(0, 255, 255);
      FastLED.show();
      delay(10);

    }
    for (i = 0; i < 28; i++) {
      leds[i] = CRGB(0, 0, 0);

      FastLED.show();
    }
  }
}




void setup() {
  FastLED.addLeds<WS2811, Neopixel_PIN>(leds, NUM_LEDS);
  Serial.begin(115200);

}

void loop() {

  led_1();

}
