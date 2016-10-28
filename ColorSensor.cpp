// Using TCS3200
#include "ColorSensor.h"
#include "TimerOne.h"
#include <Arduino.h>

void ColorSensor::filterChange(bool level0, bool level1) {
	freqCount = 0;
	currentFilter++;
	S2.setDigital(level0);
	S3.setDigital(level1);
	Timer1.setPeriod(1000000);		// set 1s period
}

ColorSensor::ColorSensor() {}

ColorSensor::ColorSensor(uint8_t id0, uint8_t id1, uint8_t id2, uint8_t id3, uint8_t idO) {
	S0.setId(id0), S0.setMode(OUTPUT);
	S1.setId(id1), S1.setMode(OUTPUT);
	S2.setId(id2), S2.setMode(OUTPUT);
	S3.setId(id3), S3.setMode(OUTPUT);
	OUT.setId(idO), OUT.setMode(INPUT);
	S0.setDigital(LOW);
	S1.setDigital(HIGH);
	currentFilter = freqCount = 0;
}


ColorSensor::~ColorSensor() {}

void ColorSensor::recall() {
	switch (currentFilter) {
	case 0:
		filterChange(LOW, LOW);	// filter without red
		break;
	case 1:
		colorData.red = freqCount;
		filterChange(HIGH, HIGH);	// filter without green
		break;
	case 2:
		colorData.green = freqCount;
		filterChange(LOW, HIGH);	// filter without blue
		break;
	case 3:
		colorData.blue = freqCount;
		filterChange(HIGH, LOW);	// filter clear
		break;
	default:
		freqCount = 0;
		break;
	}
}

void ColorSensor::count() {
	freqCount++;
}

void ColorSensor::init() {
	delay(4000);
	scale.red = RGB_MAX / colorData.red;
	scale.green = RGB_MAX / colorData.green;
	scale.blue = RGB_MAX / colorData.blue;
}

void ColorSensor::reset() {
	freqCount = 0;
}

RGB ColorSensor::getRGB() {
	delay(4000);
	return this->colorData*this->scale;
}
