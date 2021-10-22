

#include <HTTPClient.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

const int DIR  = 26;
const int STEP = 25;

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

char http_ip[255] = "http://54.248.37.203/file_write/csv/directing_user_penlight_data.csv";




void connectWifi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

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
  int value = str - 48;

  return value;
}

void PEN_1(int number_time, int Time_down, int Time_up, int angle_down, int angle_up, int microsecond_down, int microsecond_up ) {
  digitalWrite(DIR, HIGH);


  for (int i = 0; i < number_time; i++) {
    digitalWrite(DIR, HIGH);
    for (int j = 0; j < angle_down; j++) {
      digitalWrite(STEP, HIGH);
      delayMicroseconds(microsecond_down);
      digitalWrite(STEP, LOW);
      delayMicroseconds(microsecond_down);
    }
    delay(Time_down);

    digitalWrite(DIR, LOW);

    for (int j = 0; j < angle_up; j++) {
      digitalWrite(STEP, HIGH);
      delayMicroseconds(microsecond_up);
      digitalWrite(STEP, LOW);
      delayMicroseconds(microsecond_up);
    }
    delay(Time_up);
  }
}




void setup() {
  Serial.begin(115200);
  pinMode(DIR, OUTPUT);
  pinMode(STEP, OUTPUT);
  digitalWrite(DIR, LOW);
  digitalWrite(STEP, LOW);


  connectWifi();

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
//  Serial.println(string_size);


  directing_data_live_element = directing_data_live_element;
  double directing_data_live[directing_data_live_element ] = {0};
  int count = directing_data_live_element - 1  ;



  //for (int i = string_size - 2 ; i >=  0; i--) {
  for (int i = string_size - 2 ; i >=  0; i--) {
    if (velue[i] != -4) {
      //            Serial.print("count:");
      //            Serial.println(count);
      //           Serial.print("i:");
      //            Serial.println(i);
      //            Serial.print("velue:");
      //            Serial.println(velue[0]);
      //            Serial.print("pow:");
      //            Serial.println(pow(10, count2));
      //            Serial.print("directing_data_live[count]:");
      //            Serial.println(directing_data_live[count]);

      directing_data_live[count] = directing_data_live[count] + velue[i] * pow(10, count2);
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

  if ( Serial.available() ) {       // 受信データがあるか？
    int str=Serial.read();

  if(str==49){

  for (int i = 0; i < directing_data_live_element - 1; i++) {
    switch (int (directing_data_live[i])) {
      case 7:
        Serial.println(directing_data_live[i + 2]);
        PEN_1(directing_data_live[i + 1], directing_data_live[i + 2], directing_data_live[i + 3], directing_data_live[i + 4], directing_data_live[i + 5], directing_data_live[i + 6], directing_data_live[i + 7]);
        i = i + 7;
        break;
      case 8:
        Serial.println(directing_data_live[i + 2]);
        PEN_1(directing_data_live[i + 1], directing_data_live[i + 2], directing_data_live[i + 3], directing_data_live[i + 4], directing_data_live[i + 5], directing_data_live[i + 6], directing_data_live[i + 7]);
        i = i + 7;
        break;
      case 9:
        Serial.println(directing_data_live[i + 2]);
        PEN_1(directing_data_live[i + 1], directing_data_live[i + 2], directing_data_live[i + 3], directing_data_live[i + 4], directing_data_live[i + 5], directing_data_live[i + 6], directing_data_live[i + 7]);
        i = i + 7;
        break;
      case 10:
        Serial.println(directing_data_live[i + 2]);
        PEN_1(directing_data_live[i + 1], directing_data_live[i + 2], directing_data_live[i + 3], directing_data_live[i + 4], directing_data_live[i + 5], directing_data_live[i + 6], directing_data_live[i + 7]);
        i = i + 7;
        break;
      case 11:
        Serial.println(directing_data_live[i + 2]);
        PEN_1(directing_data_live[i + 1], directing_data_live[i + 2], directing_data_live[i + 3], directing_data_live[i + 4], directing_data_live[i + 5], directing_data_live[i + 6], directing_data_live[i + 7]);
        i = i + 7;
        break;
      case 12:
        Serial.println(directing_data_live[i + 2]);
        PEN_1(directing_data_live[i + 1], directing_data_live[i + 2], directing_data_live[i + 3], directing_data_live[i + 4], directing_data_live[i + 5], directing_data_live[i + 6], directing_data_live[i + 7]);
        i = i + 7;
        break;
    }
  }
  }
}
}
