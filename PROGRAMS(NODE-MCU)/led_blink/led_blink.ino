int led1 = D0;
int led2 = D4;

void setup() {
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
}

void loop() {
  Serial.println("LED turned off");
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  delay(1000);
  Serial.println("LED turned on");
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  delay(1000);
}
