#pragma once
#include "Pin.h"
#ifndef SWITCH_H
#define SWITCH_H
class Switch {
private:
	Pin pin;	// pin used.
public:
	Switch();
	Switch(uint8_t id);	// set pin_id when create a switch.
	bool getStatus();	// get the switch status
	~Switch();
};
#endif // !SWITCH_H
