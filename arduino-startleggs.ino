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
#ifdef DEBUG
	Serial.begin(115200);
	sendMsg("Initialization finished!");
#endif // DEBUG

}

void loop() {
	ancientGiantCock.detectColor();
	if (ancientGiantCock.getCurrentColor() == GREEN)
		ancientGiantCock.shakeHead();
	if (ancientGiantCock.isTouched())
		ancientGiantCock.layEgg();
}
