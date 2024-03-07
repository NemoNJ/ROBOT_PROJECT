// Define motor control pins
const int leftMotor = 13;     // Connect left motor input 1 
const int rightMotor = 12;    // Connect right motor input 1 
bool turn = true; //นับรอบ 
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
void moveForward() {
  analogWrite(leftMotor,70);
  delay(3);
  analogWrite(rightMotor,70);
  delay(3);
}

// Function to turn the robot left
void turnLeft() {
  analogWrite(leftMotor, 15);
  delay(3);
  analogWrite(rightMotor,50);
  delay(3);
  analogWrite(leftMotor,10);
  delay(3);
  analogWrite(rightMotor,40);
  delay(3);
  analogWrite(leftMotor,15);
  delay(3);
  analogWrite(rightMotor,50);
  delay(3);
}

// Function to turn the robot right
void turnRight() {
  analogWrite(leftMotor,50);
  delay(3);
  analogWrite(rightMotor,15);
  delay(3);
  analogWrite(leftMotor,40);
  delay(3);
  analogWrite(rightMotor,10);
  delay(3);
  analogWrite(leftMotor,50);
  delay(3);
  analogWrite(rightMotor,15);
  delay(3);
}

// Function to stop the robot
void stopper() {
  analogWrite(leftMotor, 0);
  delay(5);
  analogWrite(rightMotor, 0);
  delay(5);
}

void loop() {
  if(timer){
     delay(2000); 
     timer = false;
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
