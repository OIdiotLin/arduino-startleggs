/*
	This head file includes the main high-level operations.
	All other underlying codes are included in the head files below.
*/
#include "Units\Buzzer.h"	// Simulating the crow
#include "Units\ColorSensor.h"	// Scanning the kind of the food given
#include "Units\LED.h"	// Changing colors after swallow particular kinds of food 
#include "Units\Serial.h"		// Communicating with PC
#include "Units\SteeringGear.h"	// 1.Turning its head. 2.Turing the turnplate to transport eggs.
#include "Units\Switch.h"	// Detecting if touched.
#pragma once
#ifndef STARTLEGGS_H
#define STARTLEGGS_H
class Startleggs {
private:
	LED eyesBlue, eyesRed;
	SteeringGear head, turnplate;
	Buzzer crow;
	ColorSensor sensor;
	Switch touch;
	int currentColor;
public:
	Startleggs();
	~Startleggs();
	void init();		// Initialize all units (pins' id & mode)
	int getColor();	// return RED 0; GREEN 1; BLUE 2;
	void changeEye();	// change eyes' color according to cuurentColor
	void layEgg();
	void crowing();
	bool isTouched();
};


#endif // !STARTLEGGS_H

