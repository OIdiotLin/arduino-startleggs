/*
	this project is a homework of the Digital System Creative Design.
	Developers: Muming Lian, Huidong Lin, Wenyu Huang, Queji Li
	Tutor: Jinhui Zhu
*/

#include <Arduino.h>
#include "Startleggs.h"	// including all classes used in this project
 
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

Startleggs ancientGiantCock;

void setup() {
	ancientGiantCock.init();
}

void loop() {
}