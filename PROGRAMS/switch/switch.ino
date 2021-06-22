int sw = 5;
int swval;

void setup() {
  Serial.begin(9600);
  pinMode(sw, INPUT_PULLUP);
  Serial.println("Switch button");
}

void loop() {
  swval = digitalRead(sw);
  Serial.print("Switch value is: ");
  Serial.println(swval);
  delay(1000);
}
