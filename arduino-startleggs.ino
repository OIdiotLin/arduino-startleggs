#include <Arduino.h>
#include "Buzzer.h"

Buzzer buz = Buzzer(8);

void setup() {
	Serial.begin(115200);
}

void loop() {
	buz.sweep(200,1200);
	delay(3000);
}