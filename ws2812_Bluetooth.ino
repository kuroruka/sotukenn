#define BLYNK_PRINT Serial
#define BLYNK_USE_DIRECT_CONNECT
#include <BlynkSimpleEsp32_BLE.h>
#include <BLEDevice.h>
#include <BLEServer.h>
char auth[]= "onpsYByj8WWynNpkliDKpLVPRqxqa3Ij";


//NeoPixelColorのライブラリの読み込み
#include <Adafruit_NeoPixel.h>
#define MAX_VAL 64 // 0 to 255 for brightness
#define DELAY_TIME 50
#define LED_NUM 28
#define PIN_NUM 27
int ledR = 0;
int ledG = 0;
int ledB = 0;
//NeoPixel strip の初期化
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_NUM, PIN_NUM, NEO_GRB + NEO_KHZ800);

//--------------------------------------------

void setup()
{
// Debug console
Serial.begin(9600);
Serial.println("Waiting for connections...");
Blynk.begin(auth);
//Strip initialise
strip.begin();
strip.show(); // Initialize all pixels to 'off'
}

//ヴァーチャルピンV0
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

//LED点灯
for(int i=0;i<LED_NUM;i++){
//strip.Color(ledR, ledG, ledB), DELAY_TIME;
strip.setPixelColor(i,ledR, ledG, ledB);
}
strip.show();
delay(DELAY_TIME);
}

void loop()
{
Blynk.run();
}
