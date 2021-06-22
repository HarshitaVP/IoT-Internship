int soil = 5;
int soilvalue;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(soil, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  soilvalue = digitalRead(soil);
  Serial.print("Soil moisture value is: ");
  Serial.println(soilvalue);
  delay(1000);
}
