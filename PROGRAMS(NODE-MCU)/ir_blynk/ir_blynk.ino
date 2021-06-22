#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

BlynkTimer timer;

char auth[] = "PYPy17kbD8Pd0KOq4SUspRwwOxuwKjtL";
char ssid[] = "WiFi home";
char pass[] = "harshita101*#";

int ir = D1;
int irval;

void setup()
{
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(ir,INPUT);
  timer.setInterval(1000, sendirval);
}

void sendirval(){
  irval = digitalRead(ir);
  Blynk.virtualWrite(V1,irval);
  Serial.println(irval);
  if(irval == 0){
    Blynk.virtualWrite(V3,"Obstacle detected");
  }
  else{
    Blynk.virtualWrite(V3,"no obstacle");
  }
}
void loop()
{
  Blynk.run();
  timer.run();
}
