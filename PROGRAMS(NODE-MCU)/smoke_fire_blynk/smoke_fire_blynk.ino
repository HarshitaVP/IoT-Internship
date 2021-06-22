#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

BlynkTimer timer;
char auth[] = "_dWr5TKCPCfjMkM7tvM9eS33HhAMh6xk";

char ssid[] = "WiFi home";
char pass[] = "harshita101*#";

int relay = D2;
int fire = D1;
int smoke= A0;

int smokeval;
int fireval;

int smokecount=0;
int firecount=0;

void setup()
{
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(relay,OUTPUT);
  pinMode(fire,INPUT);
  pinMode(smoke,INPUT);
  timer.setInterval(1000, sendsmokeval);
  timer.setInterval(1000, sendfireval);
}

void sendsmokeval(){
  smokeval = analogRead(smoke);
  smokecount +=1;
  Blynk.virtualWrite(V1,smokeval);
  Serial.println(smokeval);
  Blynk.virtualWrite(V2,"Smoke Value:"+String(smokeval));
  Blynk.virtualWrite(V5,smokeval);
  Blynk.virtualWrite(V6,smokecount);
}

void sendfireval(){
  fireval = digitalRead(fire);
  firecount += 1;
  Blynk.virtualWrite(V3,fireval);
  Serial.println(fireval);
  if(fireval == 1){
    Blynk.virtualWrite(V4,"Fire Not Detected");
  }
  else{
    Blynk.virtualWrite(V4,"Fire Detected");
  }
  Blynk.virtualWrite(V7,firecount);
}


void loop()
{
  Blynk.run();
  timer.run();
}
