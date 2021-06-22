int trig = 5;
int echo = 6;
int buzzer = 7;
float duration;
int dist;
int red = 11;


void setup() {
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(red, OUTPUT);
}

void loop() {
  digitalWrite(trig,LOW);
  delayMicroseconds(5);

  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  duration = pulseIn(echo, HIGH);

  dist = duration*0.017;

  if(dist>20 && dist<=100){
    Serial.println("Close");
    delay(200);
    digitalWrite(buzzer, LOW);
    delay(500);
    digitalWrite(buzzer,HIGH);
    delay(500);
  }

  else if(dist<=20){
    Serial.println("Very Close");
    delay(200);
    red_color();
    delay(200);
    digitalWrite(buzzer, LOW);
    delay(200);
  }
    
  else{
    Serial.println("Distance "+String(dist) + "cm");
    digitalWrite(buzzer, HIGH);
  }  
  delay(500);
}

void red_color(){
    digitalWrite(red,HIGH);
    delay(200);
    digitalWrite(red,LOW);
    delay(200);
}
