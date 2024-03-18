const int leftMotor = 13;   
const int rightMotor = 12;   
const int leftSensor = 14;
const int rightSensor = 27;
const int midSensor = 26;
bool turn = true; 
bool timer = true;
int begintime = millis();
int leftSensorValue;
int rightSensorValue;
int midSensorValue;

void setup() {
  // Initialize sensor and motor pins
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);
  pinMode(midSensor, INPUT);
  pinMode(leftMotor, OUTPUT);
  pinMode(rightMotor, OUTPUT);
}
// Function to move the robot forward
void moveFast() {
  analogWrite(leftMotor,80);
  delay(1);
  analogWrite(rightMotor,80);
  delay(1);
}
void moveForward() {
  analogWrite(leftMotor,50);
  delay(1);
  analogWrite(rightMotor,50);
  delay(1);
}

// Function to turn the robot left
void turnLeft() {
  analogWrite(leftMotor, 20);
  delay(1);
  analogWrite(rightMotor,90);
  delay(1);
}

// Function to turn the robot right
void turnRight() {
  analogWrite(leftMotor,90);
  delay(1);
  analogWrite(rightMotor,20);
  delay(1);
}

// Function to stop the robot
void stopper() {
  analogWrite(leftMotor, 0);
  delay(1);
  analogWrite(rightMotor, 0);
  delay(1);
}

void loop() {
  if(timer){
     delay(15500); 
     timer = false;
     //starter move 
     moveFast();
     delay(4000);
  } 
  leftSensorValue = digitalRead(leftSensor);
  rightSensorValue = digitalRead(rightSensor);
  midSensorValue = digitalRead(midSensor);
  
    if (leftSensorValue == 0 && rightSensorValue == 0) {
      // Both sensors on the line - move forward
      moveForward();
    } else if (leftSensorValue == 1 && rightSensorValue == 1 && midSensorValue == 1 ) {
        if (turn) {
             turnLeft();
             turn = false;
         }else {
             analogWrite(rightMotor,20);
             delay(10);
             analogWrite(leftMotor,20);
             delay(10);
             stopper();
         }
    }else if (leftSensorValue == 1 && rightSensorValue == 0 && midSensorValue == 1 ) {
      // Left sensor off the line - turn right
      turnLeft();
    }else if (leftSensorValue == 0 && rightSensorValue == 1) {
      // Left sensor off the line - turn right
      turnRight();
    } else if (leftSensorValue == 1 && rightSensorValue == 0) {
      // Right sensor off the line - turn left
      turnLeft();
    }
}
