int led = 13;

void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  Serial.println("Hello world!");

}

void loop() {
  Serial.println("LED is high");
  digitalWrite(led,HIGH);
  delay(1000);
  Serial.println("LED is low");
  digitalWrite(led,LOW);
  delay(1000);
}
