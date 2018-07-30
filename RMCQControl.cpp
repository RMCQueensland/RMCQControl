/*

*/

#include "Arduino.h"
#include "RMCQControl.h"
#include "Servo.h"

RMCQControl::RMCQControl(){
}

void RMCQControl::setUp(int servoCenter, int throwNormal, int throwReverse, int delayValue, int servoRate){
	_throwNormal = throwNormal;
	_throwReverse = throwReverse;
	_delayValue = delayValue;
	_servoRate = servoRate;
	_servoCenter = servoCenter;
}

void RMCQControl::changeNormal(boolean currentState, Servo servoName, int outputPin) {
	Serial.println("Library changeNormal");
  int x = 1;
  servoName.attach(outputPin);
  if (currentState == HIGH) {
    // do nothing as OP is already Normal
  }
  else {
    for (x = _servoCenter-_throwReverse; x <= (_servoCenter+_throwNormal); x ++) {
      servoName.write(x);
      delay(_servoRate);
    }
  }
  servoName.detach();
  delay(_delayValue);
}
void RMCQControl::changeReverse(boolean currentState, Servo servoName, int outputPin) {
	Serial.println("Library changeReverse");
  int x = 1;
  servoName.attach(outputPin);
  if (currentState == HIGH) {
    for (x = _servoCenter+_throwNormal; x >= (_servoCenter-_throwReverse); x --) {
      servoName.write(x);
      delay(_servoRate);
    }
  }
  else {
    // do nothing as OP already Reverse
  }
  servoName.detach();
  delay(_delayValue);
}
void RMCQControl::center(Servo servoName, int endPos, int outputPin){
	servoName.attach(outputPin);
	servoName.write(endPos);
	servoName.detach();
}