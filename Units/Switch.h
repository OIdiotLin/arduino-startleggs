#pragma once
#include "Pin.h"
#ifndef SWITCH_H
#define SWITCH_H
class Switch {
private:
	Pin pin1, pin3;	// pin used.
public:
	Switch();
	Switch(uint8_t id1,uint8_t id3);	// set pin_id when create a switch.
	bool getStatus();	// get the switch status
	~Switch();
};
#endif // !SWITCH_H
