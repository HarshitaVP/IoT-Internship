int irsensor = 5;
int irsensorval;
int GREEN = 10;
int YELLOW = 11;
int RED = 12;
int DELAY_GREEN = 1000;
int DELAY_YELLOW = 1000;
int DELAY_RED = 1000;

void setup() {
  Serial.begin(9600);
  pinMode(irsensor,INPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
}

void loop() {
  irsensorval = digitalRead(irsensor);
  if(irsensorval == 0){
    green_light();
    delay(DELAY_GREEN);
  }
  else{
    red_light();
    delay(DELAY_RED);
    yellow_light();
    delay(DELAY_YELLOW);
    green_light();
    delay(DELAY_GREEN);
    yellow_light();
    delay(DELAY_YELLOW);
  }
  delay(1000);
}

void green_light()
{
  digitalWrite(GREEN, HIGH);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, LOW);
}

void yellow_light()
{
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(RED, LOW);
}

void red_light()
{
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, HIGH);
}
