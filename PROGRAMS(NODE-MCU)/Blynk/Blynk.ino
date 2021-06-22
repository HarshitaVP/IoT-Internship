#define BLYNK_PRINT Serial
#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#include "DHT.h"

#define DHTPIN D3     

#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);


char auth[] = "-tj7EROGHHBNTEzyIGL97wiEDhb4p0YR";
char ssid[] = "WiFi home";
char pass[] = "harshita101*#";

BlynkTimer timer;
WiFiClient  client;

unsigned long myChannelNumber = 1116280;
const char * myWriteAPIKey = "F8PZI0IP00B61HG1";

int number1 = 56;
int number2 = 65;


String myStatus = "";

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  ThingSpeak.begin(client);
  dht.begin();
  timer.setInterval(20000,uploadts);
  timer.setInterval(1000,uploadTemp);
}

void uploadts(){
  ThingSpeak.setField(1, number1);
  ThingSpeak.setField(2, number2);
  
  // set the status
  ThingSpeak.setStatus(myStatus);
  
  // write to the ThingSpeak channel
  int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if(x == 200){
    Serial.println("Channel update successful.");
  }
  else{
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }
  number1 = random(0,100);
  number2 = random(0,100);
}

void uploadTemp(){
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Blynk.virtualWrite(V10,h);
  Blynk.virtualWrite(V11,t);
  
}

void loop()
{
  Blynk.run();
  timer.run();
}
