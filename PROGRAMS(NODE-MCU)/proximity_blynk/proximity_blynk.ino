#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"

#define DHTPIN D2     

#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);

BlynkTimer timer;

char auth[] = "59VbddWh4XmcgaEEql_ZsDfMaGEo4DGa";
char ssid[] = "WiFi home";
char pass[] = "harshita101*#";

int ir = D1;
int irval;

WidgetLCD lcd(V2);

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  lcd.print(0,0,"Blynk");
  delay(1000);
  lcd.clear();
  pinMode(ir,INPUT);
  Serial.println(F("DHTxx test!"));
  dht.begin();
  timer.setInterval(1000,sendupdata);
}

void sendupdata(){
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Blynk.virtualWrite(V10,h);
  Blynk.virtualWrite(V11,t);
  lcd.print(0,0,"Temp");
  lcd.print(5,0,t);
  lcd.print(7,0,"C");
  lcd.print(0,1,"Humidity");
  lcd.print(10,1,h);
}


void loop()
{
  Blynk.run();
  timer.run();
}
