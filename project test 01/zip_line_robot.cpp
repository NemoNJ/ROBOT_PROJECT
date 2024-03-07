#define motorPinA 14
#define motorPinB 12
bool runner = true;
 void runTheMotor1() {
  analogWrite(motorPinA,123);
   }
 void stopTheMotor1() {
  analogWrite(motorPinA,0);
 }
 void runTheMotor2() {
   analogWrite(motorPinB,200);
 }
 void stopTheMotor2() {
   analogWrite(motorPinB,0);
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
       delay(10);
       runTheMotor2();
       delay(2000);
       stopTheMotor2();
       runner = false;
  }
  else{
    stopTheMotor1();
    stopTheMotor2();
    }
  }
