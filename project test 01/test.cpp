const int leftSensor = 14;
const int rightSensor = 27;
const int midSensor = 26;
int leftSensorValue;
int rightSensorValue;
int midSensorValue;

void setup() {
  // Initialize sensor and motor pins
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);
  pinMode(midSensor, INPUT);
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  leftSensorValue = analogRead(leftSensor);
  rightSensorValue = analogRead(rightSensor);
  midSensorValue = analogRead(midSensor);
  //Serial.println(leftSensorValue);
  //Serial.println("Right :");
  //Serial.println(rightSensorValue);
  //Serial.println("Mid :");
  Serial.println(midSensorValue);
}
