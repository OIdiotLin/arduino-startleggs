#include <Arduino.h>
#include "LEDMatrix.h"

int pinMatR[] = { 2,3,4,5,14,15,16,17 };
int pinMatC[] = { 6,7,8,9,10,11,12,13 };
LEDMatrix mat = LEDMatrix(pinMatR,pinMatC);

void setup() {
	mat.test();
}

void loop() {
}