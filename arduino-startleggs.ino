/*
	this project is a homework of the Digital System Creative Design.
	Developers: Muming Lian, Huidong Lin, Wenyu Huang, Queji Li
	Tutor: Jinhui Zhu
*/

#include <Arduino.h>
#include "Startleggs.h"	// including all classes used in this project
 
Startleggs ancientGiantCock;

//#define DEBUG

void setup() {
	ancientGiantCock.init();
	delay(2000);
}

void loop() {
	ancientGiantCock.detectColor();
	ancientGiantCock.changeEye();
	if (ancientGiantCock.getCurrentColor() == GREEN) {
		ancientGiantCock.shakeHead();
	}
	ancientGiantCock.layEgg();
}
