#include <Arduino.h>
#include "Pin.h"
#pragma once
#ifndef STEERING_GEAR_H
#define STEERING_GEAR_H
class SteeringGear{
private:
	Pin pin;
	void servoPulse(int angle);
/****************************Particular_Angle****************************/
#define MID_ANG 90
#define MIN_ANG 0
#define MAX_ANG 180
public:
	SteeringGear();
	SteeringGear(uint8_t _id);
	~SteeringGear();
	void setAngle(int angle);
	void sweep(int startAngle, int endAngle);
};

#endif // !STEERING_GEAR_H