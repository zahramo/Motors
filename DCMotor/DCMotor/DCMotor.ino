int inPin1 = 2;
int inPin2 = 3;
int inPin3 = 4;
int inPin4 = 5;

int outPin1 = 9;
int outPin2 = 10;

int pwmRange = 255;
int currentSpeed = 255;

bool onStatus = false;
int currentDirection = 1;

void setup() {
  pinMode(inPin1, INPUT); 
  pinMode(inPin2, INPUT); 
  pinMode(inPin3, INPUT); 
  pinMode(inPin4, INPUT); 

  pinMode(outPin1,  OUTPUT); 
  pinMode(outPin2, OUTPUT);
  
  Serial.begin(9600); 
}
void loop() {
  
  int onOffButton = digitalRead(inPin1);
  int decreaseButton = digitalRead(inPin2);
  int increaseButton = digitalRead(inPin3);
  int revertButton = digitalRead(inPin4);
  
  if (onOffButton == LOW) {
    onStatus = !onStatus;
    while (digitalRead(inPin1) == LOW);
   
  }
  else if (decreaseButton == LOW && onStatus) {
    if (currentSpeed >= 10){
      currentSpeed = currentSpeed - 10;
    }
    while (digitalRead(inPin2) == LOW);
  }

  else if (increaseButton == LOW && onStatus) {
    if (currentSpeed <= 245){
      currentSpeed = currentSpeed + 10;
    }
    while (digitalRead(inPin3) == LOW);
  }

  else if (revertButton == LOW && onStatus) {
    if (currentDirection == 1)
      currentDirection = 2;
    else if (currentDirection == 2)
      currentDirection = 1;
    while (digitalRead(inPin4) == LOW);
  }
  
  if (onStatus) {
    Serial.println(currentSpeed);
    if (currentDirection == 1){
      analogWrite(outPin2, 0);
      analogWrite(outPin1, currentSpeed);
    }
    if (currentDirection == 2){
      analogWrite(outPin1, 0);
      analogWrite(outPin2, currentSpeed);
    }
  }
  else {
    Serial.println(0);
    if (currentDirection == 1)
      analogWrite(outPin1, 0);
    if (currentDirection == 2)
      analogWrite(outPin2, 0);
  }
}
