int buzzer = 7;

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
}

void loop() {
tone(buzzer,450);
delay(5000);
noTone(buzzer);
 
}
