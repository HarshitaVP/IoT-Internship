int GREEN = 10;
int DELAY_GREEN = 1000;

void setup() {
  Serial.begin(9600);
  pinMode(GREEN, OUTPUT);
  Serial.println("Traffic Light");
}

void loop() {  
  digitalWrite(GREEN,HIGH);
  delay(DELAY_GREEN);  
  digitalWrite(GREEN,LOW); 
  delay(DELAY_GREEN);   
}
