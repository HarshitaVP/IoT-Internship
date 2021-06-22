int ain = A0;
int aval;

void setup() {
  Serial.begin(9600);
  pinMode(ain,INPUT);
}
void loop() {
  aval = analogRead(ain);
  Serial.print("Analog Value is: ");
  Serial.println(aval);
  delay(500);
}
