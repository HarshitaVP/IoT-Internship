#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

BlynkTimer timer;

char auth[] = "7F4QT9OzwvjYLX9jMrn7YmJ_ObmChg8w";
char ssid[] = "WiFi home";
char pass[] = "harshita101*#";

int led = D0;

void setup()
{
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(led,OUTPUT);
}

BLYNK_WRITE(V1){
  int butval = param.asInt();
  if(butval == 1){
    digitalWrite(led,HIGH);
  }
  else{
    digitalWrite(led,LOW);
  }
  Serial.println(butval);
}

void loop()
{
  Blynk.run();
}
