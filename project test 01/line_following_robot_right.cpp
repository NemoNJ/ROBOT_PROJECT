const int leftMotor = 13;   
const int rightMotor = 12;   
const int leftSensor = 14;
const int rightSensor = 27;
const int midSensor = 26;
bool timer = true;
int timer2;
int timercircle;
int timerside;
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
  Serial.begin(9600);
}
// Function to move the robot forward
void moveForward() {
  analogWrite(leftMotor, 39);
  delay(1);
  analogWrite(rightMotor, 42);
  delay(1);
}

// Function to turn the robot left
void turnLeft() {
  analogWrite(leftMotor, 2);
  delay(1);
  analogWrite(rightMotor, 75);
  delay(1);
}

// Function to turn the robot right
void turnRight() {
  analogWrite(leftMotor, 83);
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
  analogWrite(rightMotor, 50);
  delay(1);
}

// Function to turn the robot right
void turnRightSlow() {
  analogWrite(leftMotor, 44);
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
  analogWrite(leftMotor, 39);
  delay(1);
  analogWrite(rightMotor, 180);
  delay(1);
}
void turnCircle2() {
  analogWrite(leftMotor, 39);
  delay(1);
  analogWrite(rightMotor, 180);
  delay(1);
}

void loop() {
  leftSensorValue = digitalRead(leftSensor);
  rightSensorValue = digitalRead(rightSensor);
  midSensorValue = digitalRead(midSensor);
  Serial.println(timer);
  if(timer){
    delay(14000);
    timer = false;
  }
  if (leftSensorValue == 0 && rightSensorValue == 0) {
    // Both sensors on the line - move forward
    moveForward();
  } else if (leftSensorValue == 1 && midSensorValue == 1 && rightSensorValue == 1) {
    timer2 = millis();
    if (timer2 < 42500) {
      moveForward();
    } else if (timer2 <= 42500 && timer2 > 46500) {
      turnCircle();
    } else {
      stopper();
    }
  } else if (leftSensorValue == 1 && midSensorValue == 1 && rightSensorValue == 0) {
    // Left sensor off the line - turn right
    turnLeft();
  } else if (leftSensorValue == 0 && midSensorValue == 1 && rightSensorValue == 1) {
    // Left sensor off the line - turn right
    turnRightSlow();
  } else if (leftSensorValue == 1 && midSensorValue == 1 && rightSensorValue == 0) {
    // Right sensor off the line - turn left
    timercircle = millis();
    turnLeftSlow();
    if(timercircle >= 44500) turnCircle2();// turn left circle
  } else if (leftSensorValue == 0 && rightSensorValue == 1) {
    // Left sensor off the line - turn right
       turnRight();
        /*timerside = millis();
        if(timerside >= 26500 && timerside <= 31600) turnRightSpeed();
        else turnRight();*/
  } else if (leftSensorValue == 1 && rightSensorValue == 0) {
    // Right sensor off the line - turn left
    turnLeft();
  }
}