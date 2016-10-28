#include <Arduino.h>
#include "Pin.h"
#pragma once
#ifndef STEERING_GEAR_H
#define STEERING_GEAR_H
class SteeringGear{
private:
	Pin pin;
	void servoPulse(int angle);
public:
	SteeringGear();
	SteeringGear(uint8_t _id);
	~SteeringGear();
	void setAngle(int angle);
	void sweep(int startAngle, int endAngle);
};

#endif // !STEERING_GEAR_H