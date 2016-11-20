#include "SteeringGear.h"


SteeringGear::SteeringGear() {}

SteeringGear::SteeringGear(uint8_t _id) {
	this->pin.setId(_id);
	this->pin.setMode(OUTPUT);
}

SteeringGear::~SteeringGear() {}

void SteeringGear::setAngle(int angle) {
	this->servoPulse(angle);
	delay(15);
}

void SteeringGear::sweep(int startAngle, int endAngle) {
	if (startAngle < endAngle)
		for (int angle = startAngle;angle <= endAngle;angle++)
			this->setAngle(angle);
	if (startAngle > endAngle)
		for (int angle = startAngle;angle >= endAngle;angle--)
			this->setAngle(angle);
}

void SteeringGear::servoPulse(int angle) {
	int pulseWidth = (angle * 11) + 500;	// turn the angle to a pulse width
	this->pin.setDigital(HIGH);
	delayMicroseconds(pulseWidth);
	this->pin.setDigital(LOW);
	delay(20 - pulseWidth / 1000);
}
