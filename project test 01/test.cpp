const int leftSensor = 14;
const int rightSensor = 27;
const int midSensor = 26;
bool timer = true;
int timercircle;
int leftSensorValue;
int rightSensorValue;
int midSensorValue;
int roboclock;

void setup() {
  // Initialize sensor and motor pins
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);
  pinMode(midSensor, INPUT);
  pinMode(leftMotor, OUTPUT);
  pinMode(rightMotor, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  leftSensorValue = analogRead(leftSensor);
  rightSensorValue = analogRead(rightSensor);
  midSensorValue = analogRead(midSensor);
  Serial.println(leftSensorValue)
}