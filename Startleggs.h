/*
	This head file includes the main high-level operations.
	All other underlying codes are included in the head files below.
*/

#define DEBUG

#include "Units\Buzzer.h"	// Simulating the crow
#include "Units\ColorSensor.h"	// Scanning the kind of the food given
#include "Units\LED.h"	// Changing colors after swallow particular kinds of food 
#include "Units\Serial.h"		// Communicating with PC
#include "Units\SteeringGear.h"	// 1.Turning its head. 2.Turing the turnplate to transport eggs.
#include "Units\Switch.h"	// Detecting if touched.
#pragma once
/****************************PINS_ID**********************************/
#define EYES_BLUE_PIN_ID 4	// pin id of blue eyes LED
#define EYES_RED_PIN_ID 7	// pin id of red eyes LED
#define HEAD_PIN_ID 6	// pulse pin id of head SteeringGear
#define TURNPLATE_PIN_ID 5	// pulse pin id of turnplate SteeringGear
#define CROW_PIN_ID 3	// pulse pin id of crow Buzzer
#define SENSOR_PINS_ID 8,9,10,11,2	// s0 to s3 pins id and out pin id of ColorSensor TCS3200
#define TOUCH_PIN_ID 13	// pin id of touch Switch
/***************************COLOR_ID**********************************/
#define RED 0
#define GREEN 1
#define BLUE 2
#define UNKNOWN 233
typedef int color;
/***************************CONSTANT_ANGLE***********************/
#define MIN_SHAKE 45		// head rotated to left
#define MAX_SHAKE 135	// head rotated to right
#define MID_SHAKE 90		// head reset to mid position
#define RED_GROOVE 0	// left groove restoring red eggs
#define BLUE_GROOVE 55	// right groove restoring blue eggs
#define MID_GROOVE 30	// turnplate reset to the middle position

/***************************CONSTANT_MELODY***********************/
const int crowNotes[3] = { NOTE_A5,NOTE_C6,NOTE_AS5};
const double crowDurations[3] = { DUR_HALF_PNT,DUR_DOUBLE,DUR_DOUBLE };

#ifndef STARTLEGGS_H
#define STARTLEGGS_H
class Startleggs {
private:
	LED eyesBlue, eyesRed;
	SteeringGear head, turnplate;
	Buzzer crow;
	ColorSensor sensor;
	Switch touch;
	color currentColor;
public:
	Startleggs();
	~Startleggs();
	void init();		// Initialize all units (pins' id & mode)
	color detectColor();	// return RED 0; GREEN 1; BLUE 2;
	color getCurrentColor();	// return member cuurentColor
	void changeEye();	// change eyes' color according to cuurentColor
#ifdef DEBUG
	void changeEye(color x);
#endif
	void layEgg();
	void shakeHead();	// shake head when getColor red
	void crowing();
	bool isFed();	// return if particular colors detected
	bool isTouched();
};


#endif // !STARTLEGGS_H

