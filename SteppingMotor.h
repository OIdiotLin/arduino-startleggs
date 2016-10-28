#include "Pin.h"
#pragma once
#ifndef STEPPING_MOTOR_H
#define STEPPING_MOTOR_H
#define pinCount (4)
class SteppingMotor {
private:
	Pin pin[pinCount];	// this motor uses 4 pins
	bool direction;	// 0 for clockwise, 1 for anti-clockwise
#define ClockWise (0)
#define AntiClockWise (1)
	unsigned int stepDelay;	// delay between steps, in ms, based on speed
	int stepCount;	// total number of steps this motor can take
	int stepIndex;	// which step the motor is on
	unsigned int lastStepTime;	// time stamp in us of when the last step was taken
	void stepMotor(int thisStep);
public:
	SteppingMotor(int stepCount, int pin0, int pin1, int pin2, int pin3);
	~SteppingMotor();
	void setSpeed(int speed);
	void step(int stepCount);	// Moves the motor stepCount steps. stepCount Can be negative
};

#endif // !STEPPING_MOTOR_H