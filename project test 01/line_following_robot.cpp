// Define sensor pins
const int leftSensor = 14;    // Connect left sensor 
const int rightSensor = 27;   // Connect right sensor 

// Define motor control pins
const int leftMotor = 13;     // Connect left motor input 1 
const int rightMotor = 12;    // Connect right motor input 1 
int turn = 1; //นับรอบ 
bool timer = true;
int leftSensorValue;
int rightSensorValue;

void setup() {
  // Initialize sensor and motor pins
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);
  pinMode(leftMotor, OUTPUT);
  pinMode(rightMotor, OUTPUT);
}
// Function to move the robot forward
void moveForward() {
  analogWrite(leftMotor, 100);
  delay(10);
  analogWrite(rightMotor, 100);
  delay(10);
}

// Function to turn the robot left
void turnLeft() {
  analogWrite(leftMotor, 0);
  delay(10);
  analogWrite(rightMotor, 35);
  delay(10);
  analogWrite(leftMotor, 0);
  delay(10);
  analogWrite(rightMotor, 30);
  delay(100);
  analogWrite(leftMotor, 0);
  delay(10);
  analogWrite(rightMotor, 40);
  delay(10);
}

// Function to turn the robot right
void turnRight() {
  analogWrite(leftMotor, 35);
  delay(10);
  analogWrite(rightMotor, 0);
  delay(10);
  analogWrite(leftMotor, 30);
  delay(10);
  analogWrite(rightMotor, 0);
  delay(100);
  analogWrite(leftMotor, 40);
  delay(10);
  analogWrite(rightMotor, 0);
  delay(10);
}

// Function to stop the robot
void stopper() {
   analogWrite(rightMotor,20);
  delay(10);
  analogWrite(leftMotor,20);
  delay(10);
  analogWrite(leftMotor, 0);
  delay(10);
  analogWrite(rightMotor, 0);
  delay(10);
}

// Your count logic goes here
void performturnLogic() {
  // Implement your desired behavior based on the count variable
  if (turn == 1) {
    turnLeft();
    turn += 1;
  }else if (turn == 2) {
    turnLeft();
    turn += 1;
  }else {
    stopper();
    }
}
void loop() {
  leftSensorValue = digitalRead(leftSensor);
  rightSensorValue = digitalRead(rightSensor);
  
    if (leftSensorValue == 0 && rightSensorValue == 0) {
      // Both sensors on the line - move forward
      moveForward();
    } else if (leftSensorValue == 0 && rightSensorValue == 1) {
      // Left sensor off the line - turn right
      turnRight();
    } else if (leftSensorValue == 1 && rightSensorValue == 0) {
      // Right sensor off the line - turn left
      turnLeft();
    } else if (leftSensorValue == 1 && rightSensorValue == 1) {
      // Both sensors off the line - implement your desired behavior here
      performturnLogic();
    }
}
