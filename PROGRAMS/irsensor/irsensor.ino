int irsensor = 5;
int irsensorval;

void setup() {
  Serial.begin(9600);
  pinMode(irsensor,INPUT);
}
void loop() {
  irsensorval = analogRead(irsensor);
  if(irsensorval == 0){
    Serial.println("Obstacle Detected");
  }
  else{
    Serial.println("Obstacle not detected");
  }
  delay(1000);
}
