int ain = A0;
int aval;
int led = 10;

void setup() {
  Serial.begin(9600);
  pinMode(ain,INPUT);
  pinMode(led,OUTPUT);
}
void loop() {
  aval = analogRead(ain);
  if(aval>700 && aval<710){
    digitalWrite(led,HIGH);
    }
  else{
    digitalWrite(led,LOW);
  }
  delay(500);
}
