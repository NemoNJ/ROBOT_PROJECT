#define motorPinA 14
#define motorPinB 12
bool runner = true;
 void runTheMotor1() {
  digitalWrite(motorPinA, HIGH);
   }
 void stopTheMotor1() {
  digitalWrite(motorPinA,LOW);
 }
 void runTheMotor2() {
   digitalWrite(motorPinB, HIGH);
 }
 void stopTheMotor2() {
   digitalWrite(motorPinB,LOW);
 }

void setup() {
  // put your setup code here, to run once:
  pinMode(motorPinA,OUTPUT);
  pinMode(motorPinB,OUTPUT);
  stopTheMotor1();
  stopTheMotor2();
}
void loop(){
  if(runner){
         runTheMotor1();
       delay(10000);
       stopTheMotor1();
       delay(500);
       runTheMotor2();
       delay(100);
       stopTheMotor2();
       runner = false;
  }
  else{
    stopTheMotor1();
    stopTheMotor2();
    }
  }

