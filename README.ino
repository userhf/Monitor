# Monitor
Runs an Arduino-powered, autonomous car, with large wheels, a gyroscope, LEDs, and a laser.

#include <Servo.h>
int laserpin = 13;
int LEDpin = 12;
int gyropin = 11;
int trigpin = 9;
int echopin = 8;
int lpin = 6;
int rpin = 7;
Servo left;
Servo right;

int howFar(){
  int cm = 0;
  int duration = 0;
  
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigpin, LOW);
  duration = pulseIn(echopin, HIGH);
  
  cm = duration / 58.2;
  
  return cm;
}

void forward(){
  boolean up;
  //read from gyroscope if up or not, and adjust up accordingly
  if(up){
    left.write(0);
    right.write(0);
  }
  else{
    left.write(180);
    right.write(180);
  }
  delay(1000);
  left.write(90);
  right.write(90);
}

void setup(){
  
  pinMode(laserpin, OUTPUT);
  pinMode(LEDpin, OUTPUT);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(lpin, OUTPUT);
  pinMode(rpin, OUTPUT);
  left.attach(lpin);
  right.attach(rpin);
  
  digitalWrite(laserpin, HIGH);
  digitalWrite(LEDpin, HIGH);
  digitalWrite(trigpin, LOW);
  left.write(90);
  right.write(90);
  
  delay(5000);
}

void loop(){
  int far = howFar();
  if (far <= 5){
    //stop, turn
  }
  if (far > 5){
    forward();
  }
}
