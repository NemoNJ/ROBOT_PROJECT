//Recent
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
void powerstepup() {
  analogWrite(leftMotor, 107);
  delay(1);
  analogWrite(rightMotor, 110);
  delay(1);
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
  analogWrite(leftMotor, 5);
  delay(1);
  analogWrite(rightMotor, 132);
  delay(150);
}

// Function to turn the robot right
void turnRight() {
  analogWrite(leftMotor, 85);
  delay(1);
  analogWrite(rightMotor, 1);
  delay(150);
}
/*void turnRightSpeed() {
  analogWrite(leftMotor, 220);
  delay(1);
  analogWrite(rightMotor, 4);
  delay(1);
}*/
void turnLeftSlow() {
  analogWrite(leftMotor, 20);
  delay(1);
  analogWrite(rightMotor, 95);
  delay(1);
}

// Function to turn the robot right
void turnRightSlow() {
  analogWrite(leftMotor, 57);
  delay(1);
  analogWrite(rightMotor, 15);
  delay(1);
}
void turnLeftSlowAfter() {
  
  analogWrite(leftMotor, 8);
  delay(1);
  analogWrite(rightMotor, 125);
  delay(1);
}

// Function to turn the robot right
void turnRightSlowAfter() {
  analogWrite(leftMotor, 125);
  delay(1);
  analogWrite(rightMotor, 8);
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
  analogWrite(leftMotor, 180);
  delay(1);
  analogWrite(rightMotor, 3);
  delay(250);
}
void stage() {
  analogWrite(leftMotor, 110);
  delay(1);
  analogWrite(rightMotor, 3);
  delay(10);
}
void turnCircle2() {
  analogWrite(leftMotor, 140);
  delay(1);
  analogWrite(rightMotor, 10);
  delay(300);
}
void turnRightcircle() {
  analogWrite(leftMotor, 140);
  delay(1);
  analogWrite(rightMotor, 10);
  delay(1);
}
void turnLeftSlowAfter2() {
  
  analogWrite(leftMotor, 10);
  delay(1);
  analogWrite(rightMotor, 85);
  delay(1);
}
void loop() {
  leftSensorVal = analogRead(leftSensor);
  rightSensorVal = analogRead(rightSensor);
  midSensorVal = analogRead(midSensor);
  if(leftSensorVal > 3000){
    leftSensorValue = 1;
  }else{
    leftSensorValue = 0;
  }
  if(rightSensorVal > 3000){
    rightSensorValue = 1;
  }else{
    rightSensorValue = 0;
  }
   if(midSensorVal > 3000){
      midSensorValue = 1;
  }else{
      midSensorValue = 0;
  }
  Serial.println(timer);
  timercircle = millis();
  if(timer){
    delay(14000);
    timer = false;
  }
  if(timercircle > 47000){
    if (leftSensorValue == 0 && rightSensorValue == 0) {
    // Both sensors on the line - move forward
    //cut safety system
            moveForward();
        if(timercircle >= 47000 && midSensorValue == 0){
           stopper();
         }
      }else if (leftSensorValue == 1 && midSensorValue == 1 && rightSensorValue == 1) {
          stopper();
         }
       else if (leftSensorValue == 1 && rightSensorValue == 0){
          turnLeft();
        }
       else if (leftSensorValue == 1 && midSensorValue == 1 && rightSensorValue == 0){
          turnLeftSlow();
        } 
        else if (leftSensorValue == 0 && rightSensorValue == 1) {
           stage();
        }
        else if (leftSensorValue == 0 && midSensorValue == 1 && rightSensorValue == 1){
          turnRightSlow();
          }
      
    }else if (leftSensorValue == 0 && rightSensorValue == 0) {
    // Both sensors on the line - move forward
    //cut safety system
            moveForward();
        if(timercircle >= 47000 && midSensorValue == 0){
           stopper();
         }
  } /*else if (leftSensorValue == 1 && midSensorValue == 1 && rightSensorValue == 1 && timercircle > 50000) {
          stopper();
  } */else if (leftSensorValue == 1 && midSensorValue == 1 && rightSensorValue == 1 && timercircle > 42000 && timercircle < 50000) {
          stopper();
          delay(500);
          turnCircle2();
  }else if (leftSensorValue == 1 && midSensorValue == 1 && rightSensorValue == 1 && timercircle > 38400) {
          stopper();
          delay(500);
          turnCircle();
  } else if (leftSensorValue == 1 && midSensorValue == 1 && rightSensorValue == 1 && timercircle > 35000) {
          moveForward();
  } else if (leftSensorValue == 1 && midSensorValue == 1 && rightSensorValue == 0) {
    // Left sensor off the line - turn right
    if(timercircle < 22000 && timercircle > 18000){
           turnLeft();
          }else{
            turnLeftSlow();
            if(timercircle > 33000 && timercircle < 45000) turnLeftSlowAfter();
            if(timercircle >= 45000 && timercircle < 50000)turnLeftSlowAfter2();
          }
  } else if (leftSensorValue == 0 && midSensorValue == 1 && rightSensorValue == 1 && timercircle > 42000 ) {
    // Right sensor off the line - turn right
    turnCircle2();
  } else if (leftSensorValue == 0 && midSensorValue == 1 && rightSensorValue == 1) {
    // Left sensor off the line - turn right
     if(timercircle > 33000 && timercircle < 42000) turnRightSlowAfter();
      if(timercircle > 42000 && timercircle < 52000 ){
        stopper();
        delay(500);
        turnRightcircle();
        }
      else turnRightSlow();
  } else if (leftSensorValue == 0 && rightSensorValue == 1) {
    // Left sensor off the line - turn right
       turnRight();
  } else if (leftSensorValue == 1 && rightSensorValue == 0) {
    // Right sensor off the line - turn left
    turnLeft();
  }
}
