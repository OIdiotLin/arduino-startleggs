/*
	this project is a homework of the Digital System Creative Design.
	Developers: Muming Lian, Huidong Lin, Wenyu Huang, Queji Li
	Tutor: Jinhui Zhu
*/

#include <Arduino.h>
#include "Startleggs.h"	// including all classes used in this project
 
Startleggs ancientGiantCock;

#define DEBUG

void setup() {
	ancientGiantCock.init();
//#ifdef DEBUG
//	Serial.begin(115200);
//	sendMsg("Initialization finished!\n");
//#endif // DEBUG
	delay(5000);
}

void loop() {
	ancientGiantCock.layEgg();
	delay(2000);
//	if (ancientGiantCock.getCurrentColor() == GREEN) {
//#ifdef DEBUG
//		sendMsg("\tGREEN!\n");
//#endif
//		ancientGiantCock.shakeHead();
//	}
//	if (ancientGiantCock.isTouched()) {
//#ifdef DEBUG
//		sendMsg("TOUCHED!\n");
//#endif
//		ancientGiantCock.layEgg();
//	}
}
