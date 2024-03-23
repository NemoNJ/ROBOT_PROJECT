const int leftMotor = 13;   
const int rightMotor = 12;   
const int leftSensor = 14;
const int rightSensor = 27;
const int midSensor = 26;
bool timer = true;
int timercircle;
int leftSensorValue;
int rightSensorValue;
int midSensorValue;
int roboclock;
int leftSensorVal;
int rightSensorVal;
int  midSensorVal;

void setup() {
  // Initialize sensor and motor pins
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);
  pinMode(midSensor, INPUT);
  pinMode(leftMotor, OUTPUT);
  pinMode(rightMotor, OUTPUT);
  Serial.begin(9600);
}
// Function to move the robot forward
void moveForward() {
  analogWrite(leftMotor, 39);
  delay(1);
  analogWrite(rightMotor, 42);
  delay(1);
}
void moveFast() {
  analogWrite(leftMotor, 80);
  delay(1);
  analogWrite(rightMotor, 2);
  delay(1);
}
// Function to turn the robot left
void turnLeft() {
  analogWrite(leftMotor, 2);
  delay(1);
  analogWrite(rightMotor, 73);
  delay(1);
}

// Function to turn the robot right
void turnRight() {
  analogWrite(leftMotor, 81);
  delay(1);
  analogWrite(rightMotor, 2);
  delay(1);
}
/*void turnRightSpeed() {
  analogWrite(leftMotor, 220);
  delay(1);
  analogWrite(rightMotor, 4);
  delay(1);
}*/
void turnLeftSlow() {
  analogWrite(leftMotor, 35);
  delay(1);
  analogWrite(rightMotor, 60);
  delay(1);
}

// Function to turn the robot right
void turnRightcircle() {
  analogWrite(leftMotor, 50);
  delay(1);
  analogWrite(rightMotor, 15);
  delay(1);
}
void turnLeftcircle() {
  analogWrite(leftMotor, 35);
  delay(1);
  analogWrite(rightMotor, 60);
  delay(1);
}

// Function to turn the robot right
void turnRightSlow() {
  analogWrite(leftMotor, 57);
  delay(1);
  analogWrite(rightMotor, 15);
  delay(1);
}
// Function to stop the robot
void stopper() {
  analogWrite(leftMotor, 0);
  delay(1);
  analogWrite(rightMotor, 0);
  delay(1);
}
void turnCircle() {
  analogWrite(leftMotor, 90);
  delay(1);
  analogWrite(rightMotor, 2);
  delay(1);
}

void loop() {
  leftSensorVal = analogRead(leftSensor);
  rightSensorVal = analogRead(rightSensor);
  midSensorVal = analogRead(midSensor);
  if(leftSensorVal >= 50 && leftSensorVal <= 500){
    leftSensorValue = 0;
  }else{
    leftSensorValue = 1;
  }
  if(rightSensorVal >= 5 && rightSensorVal <= 300){
    rightSensorValue = 0;
  }else{
    rightSensorValue = 1;
  }
   if(midSensorVal >= 180 && midSensorVal <= 500){
      midSensorValue = 0;
  }else{
      midSensorValue = 1;
  }
  Serial.println(timer);
  timercircle = millis();
  if(timer){
    delay(14000);
    timer = false;
  }
  if (leftSensorValue == 0 && rightSensorValue == 0) {
    // Both sensors on the line - move forward
    moveForward();
    //cut safety system
        if(timercircle >= 56000 && midSensorValue == 0){
           stopper();
         }
  } else if (leftSensorValue == 1 && midSensorValue == 1 && rightSensorValue == 1 && timercircle > 56000) {
          stopper();
  } else if (leftSensorValue == 1 && midSensorValue == 1 && rightSensorValue == 1 && timercircle > 43000) {
          turnCircle();
  } else if (leftSensorValue == 1 && midSensorValue == 1 && rightSensorValue == 1 && timercircle > 38000) {
          moveForward();
  } else if (leftSensorValue == 1 && midSensorValue == 1 && rightSensorValue == 0) {
    // Left sensor off the line - turn right
    turnLeft();
  } else if (leftSensorValue == 0 && midSensorValue == 1 && rightSensorValue == 1 && timercircle > 42000 ) {
    // Right sensor off the line - turn right
    turnCircle();
  } else if (leftSensorValue == 0 && midSensorValue == 1 && rightSensorValue == 1) {
    // Left sensor off the line - turn right
      if(timercircle > 43000 && timercircle < 54000 )turnRightcircle();
      else turnRightSlow();
  } else if (leftSensorValue == 0 && rightSensorValue == 1) {
    // Left sensor off the line - turn right
       turnRight();
  } else if (leftSensorValue == 1 && rightSensorValue == 0) {
    // Right sensor off the line - turn left
    turnLeft();
  }
}
