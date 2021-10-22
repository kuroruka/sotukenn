#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
//#define BLYNK_TEMPLATE_ID   "YourTemplateID"


#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "ut7sjm4LyZFuWuewTxsq1DwjQ_twFrPf"; //Blynkから送られてきたメール内にある Auth コード
char ssid[] = "jikei-open-air"; //ご自分のルーターの SSID
char pass[] = "open-wifi"; //ご自分のルーターのパスワード

int Flag = 0;


void setup()
{
  Serial.begin(115200);


  Blynk.begin(auth, ssid, pass);
  // ピン定義
  const int R = 25;
  const int G = 33;
  const int B = 32;

  // チャンネル定義
  const int R_CHANNEL = 1;
  const int G_CHANNEL = 2;
  const int B_CHANNEL = 3;
    
}

void loop()
{
  
  Blynk.run();

}

BLYNK_WRITE(V0)
{
  ledR = param[0].asInt();
  ledG = param[1].asInt();
  ledB = param[2].asInt();
  Serial.print( "ledR: ");
  Serial.print(ledR);
  Serial.print( " ledG: ");
  Serial.print(ledG);
  Serial.print( " ledB: ");
  Serial.println(ledB);
}
