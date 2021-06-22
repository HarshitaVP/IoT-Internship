int relay = D2;
int fire = D1;
int smoke= A0;

int smokeval;
int fireval;

void setup() {
  Serial.begin(9600);
  pinMode(relay,OUTPUT);
  pinMode(fire,INPUT);
  pinMode(smoke,INPUT);
}

void loop() {
  smokeval = analogRead(smoke);
  fireval = digitalRead(fire);
  Serial.println("Smoke value is "+ String(smokeval));
  Serial.println("Fire value is "+String(fireval));
  delay(1000);
}
