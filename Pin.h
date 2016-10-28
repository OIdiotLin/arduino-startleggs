#include <Arduino.h>
#pragma once
#ifndef PIN_H
#define PIN_H
class Pin {
private:
	uint8_t id;
public:
	Pin(uint8_t _id);
	Pin();
	~Pin();
	void setId(uint8_t _id);
	void setMode(int mode);
	void setDigital(bool v);
	uint8_t getId();
	bool getDigital();
};
#endif