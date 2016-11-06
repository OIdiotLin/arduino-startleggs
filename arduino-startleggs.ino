#include <Arduino.h>
#include "Serial.h"
#include "ColorSensor.h"

ColorSensor tcs3200 = ColorSensor(2, 3, 4, 5, 6);

void setup() {
	Serial.begin(115200);
	tcs3200.init();
}

void loop() {
	sendMsg(tcs3200.readRGB().info());
	delay(800);
}