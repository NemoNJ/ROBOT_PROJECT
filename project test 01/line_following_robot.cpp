// Define sensor pins
const int leftSensor = 19;    // Connect left sensor to Analog pin 6
const int rightSensor = 18;   // Connect right sensor to Analog pin A8

// Define motor control pins
const int leftMotor = 27;     // Connect left motor input 1 to digital pin 16
const int rightMotor = 12;    // Connect right motor input 1 to digital pin 13
int count = 1; //นับรอบ 
bool use_motor = true;

void setup() {
  // Initialize sensor and motor pins
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);
  pinMode(leftMotor, OUTPUT);
  pinMode(rightMotor, OUTPUT);
}

void loop() {
  delay(10500);
  // Read sensor values
  int leftSensorValue = digitalRead(leftSensor);
  int rightSensorValue = digitalRead(rightSensor);
  moveForward();
  // Line following logic
if(use_motor){
  if (leftSensorValue == 1 && rightSensorValue == 1) {
    // Both sensors on the line - move forward
    moveForward();
  } else if (leftSensorValue == 1 && rightSensorValue == 0) {
    // Left sensor off the line - turn right
    turnRight();
  } else if (leftSensorValue == 0 && rightSensorValue == 1) {
    // Right sensor off the line - turn left
    turnLeft();
  } else if (leftSensorValue == 0 && rightSensorValue == 0) {
    if (count == 1) {
      moveForward();
      count++;
    } else if (count == 2) {
      turnRight();
      count++;
    } else if (count == 3) {
      turnRight();
      count++;
    } else {
      use_motor = false;
    }
  }
 }
else{
   stop();
  }
}

// Function to move the robot forward
void moveForward() {
  digitalWrite(leftMotor, HIGH);
  digitalWrite(rightMotor, HIGH);
}

// Function to turn the robot left
void turnLeft() {
  digitalWrite(leftMotor, LOW);
  digitalWrite(rightMotor, HIGH);
}

// Function to turn the robot right
void turnRight() {
  digitalWrite(leftMotor, HIGH);
  digitalWrite(rightMotor, LOW);
}

// Function to stop the robot
void stop() {
  digitalWrite(leftMotor, LOW);
  digitalWrite(rightMotor, LOW);
}