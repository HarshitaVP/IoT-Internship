#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#include "ThingSpeak.h"

#include "DHT.h"

#define DHTPIN D3     

#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);


char auth[] = "-tj7EROGHHBNTEzyIGL97wiEDhb4p0YR";
char ssid[] = "WiFi home";
char pass[] = "harshita101*#";

BlynkTimer timer;
WiFiClient  client;

unsigned long myChannelNumber = 1117898;
const char * myWriteAPIKey = "MR095NR8T20Y9K41";


String myStatus = "";

int autoMode;
int relay_control;
int soil = A0;
int soilvalue;
int relay = D2;
int trig = D5;
int echo = D6;
int buzzer = D7;

float duration;
int dist;


BLYNK_WRITE(V5) {
  autoMode = param.asInt();
}

BLYNK_WRITE(V6) {
  relay_control = param.asInt();
}


void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(soil, INPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(relay,OUTPUT);
  pinMode(buzzer,OUTPUT);
  WiFi.mode(WIFI_STA); 
  ThingSpeak.begin(client); 
  timer.setInterval(100,blk);
  timer.setInterval(1000,ultra);
  dht.begin();
  timer.setInterval(500,sendupdata);
}

void blk(){
  soilvalue = analogRead(soil);
  Serial.print("Soil moisture value is: ");
  Serial.println(soilvalue);
  delay(1000);
  Blynk.virtualWrite(V4,soilvalue);
  ThingSpeak.setField(1,soilvalue);
  ThingSpeak.setStatus(myStatus);
}

void ultra(){
  digitalWrite(trig,LOW);
  delayMicroseconds(5);

  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  duration = pulseIn(echo, HIGH);

  dist = duration*0.017;

  Blynk.virtualWrite(V3,dist);
  ThingSpeak.setField(2,dist);  
  ThingSpeak.setStatus(myStatus);
  
  if( dist<=2 ){
    Serial.println("Water is full, Soil is wet");
    digitalWrite(buzzer, HIGH);
    digitalWrite(relay,LOW);
  }

  if(dist >=10){
    Serial.println("No Water, Soil is dry");
    Blynk.notify("Soil is Dry");
    digitalWrite(buzzer, LOW);
    digitalWrite(relay,HIGH);
  }
  if(autoMode == 0) {
    if(relay_control == 1) {
       digitalWrite(relay, LOW);
    } else {
      digitalWrite(relay, HIGH);
    }
  }
}


void sendupdata(){
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Blynk.virtualWrite(V10,h);
  Blynk.virtualWrite(V11,t);

  ThingSpeak.setField(3, t);
  ThingSpeak.setField(4, h);

  ThingSpeak.setStatus(myStatus);

}


void loop()
{
  if(WiFi.status() != WL_CONNECTED){
  Serial.print("Attempting to connect to SSID: ");  
  while(WiFi.status() != WL_CONNECTED){
    WiFi.begin(ssid, pass);  // Connect to WPA/WPA2 network. Change this line if using open or WEP network
    Serial.print(".");
    delay(5000);     
    } 
    Serial.println("\nConnected.");
  }
  
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
  Blynk.run();
  timer.run();

  delay(20000);
}
