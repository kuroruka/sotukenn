#include <FastLED.h>

#include <HTTPClient.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//const int DIR  = 26;
//const int STEP = 25;

//学校用
char ssid[] = "jikei-open-air";
char password[] = "open-wifi";
//家用
//char ssid[] = "HUMAX-FC4EF-A";
//char password[] = "LWN3LEk4MjNaM";

//char data_lat[] = "36.3919";
//char data_lng[] = "137.2911";
//char http_ip[255] = "http://3.112.225.241/entry.php?comment=";
//char str2[] = "&comment2=";

//char http_ip[255] = "http://54.248.37.203/file_write/light/csv/directing_live_data.csv";
char http_ip[255] = "http://54.248.37.203/file_write/csv/directing_user_data.csv";

#define Neopixel_PIN    18
#define NUM_LEDS    28
CRGB leds[NUM_LEDS]; //LEDの変数宣言


void connectWifi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  //Serial.print(WiFi.status());

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(100);
  }

  Serial.println("connected!");
}

void disconnectWifi() {
  WiFi.disconnect();
  Serial.println("disconnected!");
}

String Request(char host[]) {
  HTTPClient http;
  http.begin(host);
  int httpCode = http.GET();

  String result = "";

  if (httpCode < 0) {
    result = http.errorToString(httpCode);
  } else if (http.getSize() < 0) {
    result =  "size is invalid";
  } else {
    result = http.getString();
  }
  http.end();

  return result;
}

int  int_cov(char str) {
  int value1 = str - 48;

  return value1;
}

void led_part1(int value1, int r, int g, int b) {
  //パート1
  for (int j = 0; j < value1; j++) {
    for (int i = 0; i < 28; i++) {
      leds[i] = CRGB(g, r, b);
      FastLED.show();

    }
    delay(1000);

  }

  for (int i = 0; i < 28; i++) {
    leds[i] = CRGB(0, 0, 0);
    FastLED.show();
  }
}

void led_part2(int value1, double value2, int r, int g, int b, int r2, int g2, int b2) {
  int c = value1 / (value2 * 14);

  for (int j = 0; j <  c; j++) {
    for (int i = 0; i < 14; i++) {
      leds[i] = CRGB(g, r, b);
      leds[27 - i] = CRGB(g2, r2, b2);
      FastLED.show();
      delay(value2 * 1000);
      //Serial.println("%d %d\n", i, j);
    }
        for (int i = 0; i < 28; i++) {
          leds[i] = CRGB(0, 0, 0);
    
          FastLED.show();
        }
  }
}

void led_part3(int value1, double value2, int r, int g, int b ) {
  int c = value1 / value2;
  //  Serial.print(value);
  //  Serial.print(",");
  //  Serial.print(value2);
  //  Serial.print(",");
  //  Serial.println(c);

  for (int j = 0; j < c; j++) {
    for (int i = 0; i < 28; i++) {
      leds[i] = CRGB(g, r, b);
      FastLED.show();

    }
    delay(value2 * 1000);

    for (int k = 0; k < 28; k++) {
      leds[k] = CRGB(0, 0, 0);
      FastLED.show();

    }


  }
}
void led_part4(int value1, double value2, int r, int g, int b) {
  int c = value1 / (value2 * 28);

  for (int j = 0; j < c; j++) {
    for (int i = 0; i < 28; i++) {
      leds[i] = CRGB(g, r, b);
      delay(value2 * 1000);

      FastLED.show();

    }
    for (int i = 0; i < 28; i++) {
      leds[i] = CRGB(0, 0, 0);
      FastLED.show();
    }

  }
}

void led_part5(int value1 , double value2, int r, int g, int b) {
  int c = value1 / (value2 * 9);

  for (int j = 0; j < c; j++) {
    int rand_c = random(0, 3);
    //Serial.print(c);

    switch (rand_c) {
      case 0:
        for (int i = 0; i < 9; i++) {
          leds[i] = CRGB(g, r, b);

          FastLED.show();

        }
        delay(value2 * 1000);
        break;
      case 1:
        for (int i = 9; i < 18; i++) {
          leds[i] = CRGB(g, r , b);

          FastLED.show();

        }
        delay(value2 * 1000);
        break;
      case 2:
        for (int i = 18; i < 28; i++) {
          leds[i] = CRGB(g, r, b);

          FastLED.show();

        }
        delay(value2 * 1000);
        break;

    }


    for (int i = 0; i < 28; i++) {
      leds[i] = CRGB(0, 0, 0);

      FastLED.show();
    }

  }
}



void setup() {
  Serial.begin(115200);
  //  pinMode(DIR, OUTPUT);
  //  pinMode(STEP, OUTPUT);
  //  digitalWrite(DIR, LOW);
  //  digitalWrite(STEP, LOW);


  connectWifi();

  FastLED.addLeds<WS2811, Neopixel_PIN>(leds, NUM_LEDS);

}


void loop() {
  String result = Request(http_ip);
  Serial.println(result);


  int string_size = result.length();
  int velue[string_size];
  int count2 = 0;
  int directing_data_live_element = 0;

  for (int i = 0; i < string_size; i++) {

    velue[i] = int_cov(result[i]);
    if (velue[i] == -4)
      directing_data_live_element = directing_data_live_element + 1;
    //Serial.println(velue[i]);
  }


  directing_data_live_element = directing_data_live_element;
  double directing_data_live[directing_data_live_element ] = {0};
  int count = directing_data_live_element - 1  ;




  for (int i = string_size - 2 ; i >=  0; i--) {
    if (velue[i] != -4) {
      //      Serial.print("count:");
      //      Serial.println(count);
      //      Serial.print("i:");
      //      Serial.println(i);
      //      Serial.print("velue:");
      //      Serial.println(velue[i]);
      //      Serial.print("pow:");
      //      Serial.println(pow(10, count2));
      //      Serial.print("directing_data_live[count]:");
      //      Serial.println(directing_data_live[count]);

      directing_data_live[count] = directing_data_live[count] + velue[i] * pow(10, count2);

      if (directing_data_live[count] >= 1000) {
        directing_data_live[count] = directing_data_live[count] / 100000;
      }
      count2 = count2 + 1;

    }
    else {
      //Serial.println(count);
      //Serial.println(directing_data_live[count]);
      count = count - 1;
      count2 = 0;
    }
    //    Serial.print("count:");
    //    Serial.println(count);
    //Serial.print("directing_data_live:");
    //Serial.println(directing_data_live[count]);
  }

//  for(int i;i<directing_data_live_element;i++){
//    Serial.println(directing_data_live[i]);
//  }


  if ( Serial.available() ) {       // 受信データがあるか？
    int str=Serial.read();

  if(str==49){
  
  for (int i = 0; i < directing_data_live_element - 1; i++) {
    switch (int (directing_data_live[i])) {

       
      case 1:
        Serial.println("1番だよ");
        led_part1(directing_data_live[i + 1], directing_data_live[i + 3], directing_data_live[i + 4], directing_data_live[i + 5]);
        i = i + 4;
        break;
      case 2:
        Serial.println("2番だよ");
        led_part2(directing_data_live[i + 1], directing_data_live[i + 2], directing_data_live[i + 3], directing_data_live[i + 4], directing_data_live[i + 5], directing_data_live[i + 6], directing_data_live[i + 7], directing_data_live[i + 8]);
        i = i + 8;
        break;
      case 3:
        Serial.println("3番だよ");
        led_part3(directing_data_live[i + 1], directing_data_live[i + 2], directing_data_live[i + 3], directing_data_live[i + 4], directing_data_live[i + 5]);
        i = i + 5;
        break;
      case 4:
        Serial.println("4番だよ");
        led_part4(directing_data_live[i + 1], directing_data_live[i + 2], directing_data_live[i + 3], directing_data_live[i + 4], directing_data_live[i + 5]);
        i = i + 5;
        break;
      case 5:
        Serial.println("5番だよ");
        led_part5(directing_data_live[i + 1], directing_data_live[i + 2], directing_data_live[i + 3], directing_data_live[i + 4], directing_data_live[i + 5]);
        i = i + 5;
        break;
      case 6:
        Serial.println(directing_data_live[2]);

        break;
    }
  
  }
  }
  }
}
