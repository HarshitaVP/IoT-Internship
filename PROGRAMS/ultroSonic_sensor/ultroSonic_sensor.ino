int trig = 5;
int echo = 6;

int buzzer = 7;
float duration;
int dist;


void setup() {
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(buzzer,OUTPUT);
}

void loop() {
  digitalWrite(trig,LOW);
  delayMicroseconds(5);

  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  duration = pulseIn(echo, HIGH);

  dist = duration*0.017;

  if( dist<=2 || dist>=400){
    Serial.println("Error");
    digitalWrite(buzzer, LOW);
  }

  else{
    Serial.println("Distance "+String(dist) + "cm");
    digitalWrite(buzzer, HIGH);
  }
  delay(500);
}
