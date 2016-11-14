#include "Pin.h"
#pragma once
#ifndef LED_H
#define LED_H
class LED {
private:
	Pin pin;	// this LED uses only 1 pin
public:
	LED();
	LED(uint8_t _id);	//	set pin number when create an LED
	~LED();
	void lightOn();	// Turn on the LED
	void lightOff();		// Turn off the LED
	void blink(int interval);	// Turn on the LED, wait for a while and turn off the LED
};

#endif // !LED_H