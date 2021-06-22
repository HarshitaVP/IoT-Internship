
//Motor Pins
#define IN1 6      //IN1
#define IN2 5      //IN2
#define IN3 8      //IN3
#define IN4 7      //IN4

//Sensor PINS
#define trigger 10     //Trigger
#define echo 9        //Echo

//Declares Variables
int duration;
float distance;

//Robot Movements
void forward()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void backward()
{
  digitalWrite(IN2, HIGH);
  digitalWrite(IN1, LOW);
  digitalWrite(IN4, HIGH);
  digitalWrite(IN3, LOW);
}
void right()
{
  digitalWrite(IN2, LOW);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN4, HIGH);
  digitalWrite(IN3, LOW);
  delay(50);
}

void stopm(void)
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void setup(void)
{
  Serial.begin (9600);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(IN1 , OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}
void loop(void) {
  inputs();
  if ((distance < 10) && (distance > 5)) {
    stopm();
  }
  else if (distance < 5) {
    backward();
  }
  else if ((distance > 10) && (distance < 60))
  {
    forward();
  }
  else {
    right();
    stopm();
    delay(500);
  }
}

//Function to get value of Distance
void inputs()
{
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration / 2) / 29.1;
  digitalWrite(trigger, LOW);
  Serial.print("Distance: ");
  Serial.println(distance);
}
