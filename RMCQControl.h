/*
My frist attempt to create a library for my Arduino control system that we are using at my local HO model club.
We are using Arduino controlled servo systems to control points.

David Lowe 20160914
*/
#ifndef RMCQControl_h
#define RMCQControl_h

#include "Arduino.h"
#include "Servo.h"


class RMCQControl {
	public:
		RMCQControl();
		void setUp(int servoCenter, int throwNormal, int throwReverse, int delayValue, int servoRate);
		void center(Servo servoName, int endPos, int outputPin);
		void changeNormal(boolean currentState, Servo servoName, int outputPin);
		void changeReverse(boolean currentState, Servo servoName, int outputPin);
private:
		int _throwNormal;
		int _throwReverse;
		int _delayValue;
		int _servoRate;
		int _servoCenter;
};
#endif