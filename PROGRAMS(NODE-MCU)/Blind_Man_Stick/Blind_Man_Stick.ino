#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "-tj7EROGHHBNTEzyIGL97wiEDhb4p0YR";
char ssid[] = "WiFi home";
char pass[] = "harshita101*#";

BlynkTimer timer;

int trig = D2;
int echo = D3;
int buzzer = D4;
float duration;
int dist;
int red = D5;


void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(red, OUTPUT);
  timer.setInterval(1000, Distance);
}

void Distance(){
  digitalWrite(trig,LOW);
  delayMicroseconds(5);

  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  duration = pulseIn(echo, HIGH);

  dist = duration*0.017;

  Blynk.virtualWrite(V1,dist);

  if(dist>20 && dist<=100){
    Serial.println("Close");
    Blynk.notify("You are close to the obstacle!");
    delay(200);
    digitalWrite(buzzer, LOW);
    delay(500);
    digitalWrite(buzzer,HIGH);
    delay(500);
  }

  else if(dist<=20){
    Serial.println("Very Close");
    Blynk.notify("You are extremely Close to the Obstacle! Move Away Now!");
    delay(200);
    red_color();
    delay(200);
    digitalWrite(buzzer, LOW);
    delay(200);
  }
    
  else{
    Serial.println("Distance "+String(dist) + "cm");
    digitalWrite(buzzer, HIGH);
  }  
  delay(500);
}

void red_color(){
    digitalWrite(red,HIGH);
    delay(200);
    digitalWrite(red,LOW);
    delay(200);
}


void loop() {
  Blynk.run();
  timer.run();
}
