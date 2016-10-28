#include "Pin.h"
#pragma once
#ifndef BUZZER_H
#define BUZZER_H
class Buzzer {
private:
	Pin pin;
public:
	Buzzer();
	Buzzer(uint8_t _id);
	~Buzzer();
	void beep(int interval);
	void sweep(int from, int end);
};


#endif // !BUZZER_H
