#include "LED.h"

LED::LED()
{
}

LED::LED(uint8_t _id) {
	this->pin.setId(_id);		// set the pin ID
	this->pin.setMode(OUTPUT);	// set the pinMode to OUTPUT
}

LED::~LED() {}

void LED::lightOn() {		// turn on the LED by set a HIGH level
	this->pin.setDigital(HIGH);
}

void LED::lightOff() {	// turn off the LED by set a LOW level
	this->pin.setDigital(LOW);
}

void LED::blink(int interval) {		// the TOTAL waiting time is interval
	this->lightOn();
	delay(interval >> 1);
	this->lightOff();
	delay(interval >> 1);
}
