int ir = 5;
int irvalue;
int buzzer = 7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  pinMode(ir, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  irvalue = digitalRead(ir);
  if(irvalue == 0){
    digitalWrite(buzzer,LOW);
  }
  else{
    digitalWrite(buzzer,HIGH);
  }
}
