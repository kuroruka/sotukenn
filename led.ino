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
  pinMode(27,OUTPUT);  
}

void loop()
{
  
  Blynk.run();
  Serial.print(Flag);
  Serial.print("\n");

  if(Flag==1){
    digitalWrite(27,HIGH);
    Serial.print("こんにちわ");
    Serial.print("\n");
  }
  else{
    digitalWrite(27,LOW);
  }
}

BLYNK_WRITE(V0)
{
  Flag = param.asInt();
  
}
