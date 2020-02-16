#include <Stepper.h>

int inPin1 = 2;
int inPin2 = 3;
int inPin3 = 4;

int outPin1 = 6;
int outPin2 = 9;
int outPin3 = 10;
int outPin4 = 11;

int stepperSpeed = 3;
int currentDirection = -1;

Stepper stepper= Stepper(36, outPin1, outPin2, outPin3, outPin4);

void setup() {
  pinMode(inPin1, INPUT); 
  pinMode(inPin2, INPUT);
  pinMode(inPin3, INPUT);  

  pinMode(outPin1,  OUTPUT); 
  pinMode(outPin2, OUTPUT);
  pinMode(outPin3,  OUTPUT); 
  pinMode(outPin4, OUTPUT);

  stepper.setSpeed(stepperSpeed);
  
  Serial.begin(9600); 
}
void loop() {
  int lButton = digitalRead(inPin1);
  int rButton = digitalRead(inPin2);
  int stopButton = digitalRead(inPin3);
  if (lButton == LOW) {
    currentDirection = 1;
    while(digitalRead(inPin1) == LOW);
  }
  else if (rButton == LOW) {
    currentDirection = -1;
    while(digitalRead(inPin2) == LOW);
  }
  else if (stopButton == LOW) {
    currentDirection = 0;
    while(digitalRead(inPin3) == LOW);
  }
  stepper.step(currentDirection);
}
