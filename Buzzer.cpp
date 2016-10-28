#include "Buzzer.h"

Buzzer::Buzzer() {}

Buzzer::Buzzer(uint8_t _id) {
	this->pin.setId(_id);
	this->pin.setMode(OUTPUT);
}


Buzzer::~Buzzer() {}

void Buzzer::beep(int interval) {
	this->pin.setDigital(HIGH);
	delayMicroseconds(interval);
	this->pin.setDigital(LOW);
	delayMicroseconds(interval);
}

void Buzzer::sweep(int from, int end) {
	if (from < end)
		for (int i = from;i <= end;i++)
			this->beep(i);
	else
		for (int i = from;i >= end;i--)
			this->beep(i);
}
