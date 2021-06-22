int sw = 5;
int swval;
int led = 10;
void setup() {
  Serial.begin(9600);
  pinMode(sw, INPUT_PULLUP);
  pinMode(led,OUTPUT);
  Serial.println("Switch button");
}

void loop() {
  swval = digitalRead(sw);
  if(swval == 0){
    digitalWrite(led,HIGH);
    }
  else{
    digitalWrite(led,LOW);
    }
  delay(1000);
}
