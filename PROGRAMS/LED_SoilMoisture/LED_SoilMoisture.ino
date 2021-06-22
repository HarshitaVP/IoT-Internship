int soil = A0;
int soilvalue;
int red = 12;
int yellow = 11;
int green = 10;
int buzzer = 7;
void setup() {
  Serial.begin(9600);
  pinMode(soil, INPUT);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(buzzer,OUTPUT);
}

void loop() {
  soilvalue = analogRead(soil);
  Serial.print("Soil is: ");
  if(soilvalue >= 600){
    Serial.println("dry");
    digitalWrite(buzzer,LOW);
    Red_light();
    delay(3000);
  }
  else if(soilvalue >= 300 && soilvalue < 600){
    Serial.println("Mildly wet");
    digitalWrite(buzzer,HIGH);
    Yellow_light();
    delay(3000);
  }
  else{
    Serial.println("Completely wet");
    digitalWrite(buzzer,HIGH);
    Green_light();
    delay(3000);
  }
  delay(1000);
}

void Green_light(){
  digitalWrite(green,HIGH);
  digitalWrite(red,LOW);
  digitalWrite(yellow,LOW);
}

void Yellow_light(){
  digitalWrite(green,LOW);
  digitalWrite(red,LOW);
  digitalWrite(yellow,HIGH);
}

void Red_light(){
  digitalWrite(green,LOW);
  digitalWrite(red,HIGH);
  digitalWrite(yellow,LOW);
}
