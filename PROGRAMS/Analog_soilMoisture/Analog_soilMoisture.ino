int soil = A0;
int soilvalue;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(soil, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  soilvalue = analogRead(soil);
  Serial.print("Soil is: ");
  if(soilvalue >= 1000){
    Serial.println("dry");
  }
  else if(soilvalue >= 600 && soilvalue < 1000){
    Serial.println("Mildly wet");
  }
  else if(soilvalue >= 500 && soilvalue < 600){
    Serial.println("Partially wet");
  }
  else{
    Serial.println("Completely wet");
  }
  delay(1000);
}
