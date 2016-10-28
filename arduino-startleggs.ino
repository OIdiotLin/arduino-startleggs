// This is a test program for ColorSensor TCS3200

#include <Arduino.h>
#include "ColorSensor.h"
#include "Serial.h"
#include "TimerOne.h"

ColorSensor TCS3200 = ColorSensor(3, 4, 5, 6, 2);

void callback() {
	// used for TCS3200.recall()
	TCS3200.recall();
}
void count() {
	// used for TCS3200.count();
	TCS3200.count();
}

void setup() {
	Serial.begin(9600);
	Timer1.initialize();
	Timer1.attachInterrupt(callback);
	attachInterrupt(0, count, RISING);
	TCS3200.init();
}

void loop() {
	TCS3200.reset();
	sendMsg((TCS3200.getRGB()).getString());
}