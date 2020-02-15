#include <Servo.h>

int inPin1 = 2;
int inPin2 = 3;

int outPin1 = 9;
int outPin2 = 10;

int degree = 90;

Servo servo;

void setup() {
  pinMode(inPin1, INPUT); 
  pinMode(inPin2, INPUT); 

  pinMode(outPin1,  OUTPUT); 
  pinMode(outPin2, OUTPUT);

  servo.attach(outPin1);
  
  Serial.begin(9600); 
}
void loop() {
  
  int rButton = digitalRead(inPin1); //increase degree
  int lButton= digitalRead(inPin2); //decrease degree
  
  
  if (rButton == LOW) {
    if (degree <= 170)
      degree = degree + 10;
    while (digitalRead(inPin1) == LOW);
  }
  else if (lButton == LOW) {
    if (degree >= 10)
      degree = degree - 10;
    while (digitalRead(inPin2) == LOW);
  }
  servo.write(map(degree, 0, 180, 1000, 2000));
  Serial.println(degree);
}
