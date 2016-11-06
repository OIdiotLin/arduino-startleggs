// Using TCS3200
#include "ColorSensor.h"

#define DEBUG

#ifdef DEBUG
#include "Serial.h"
#endif

void ColorSensor::shiftMode(int mode) {
	switch (mode) {
	case 0:
		S2.setDigital(HIGH);
		S3.setDigital(LOW);
		break;
	case 1:		// red
		S2.setDigital(LOW);
		S3.setDigital(LOW);
		break;
	case 2:		// green
		S2.setDigital(HIGH);
		S3.setDigital(HIGH);
		break;
	case 3:		// blue
		S2.setDigital(LOW);
		S3.setDigital(HIGH);
		break;
	default:
		break;
	}
}

ColorSensor::ColorSensor() {
	
}

ColorSensor::ColorSensor(uint8_t id0, uint8_t id1, uint8_t id2, uint8_t id3, uint8_t idO) {
	S0.setId(id0), S0.setMode(OUTPUT);
	S1.setId(id1), S1.setMode(OUTPUT);
	S2.setId(id2), S2.setMode(OUTPUT);
	S3.setId(id3), S3.setMode(OUTPUT);
	OUT.setId(idO), OUT.setMode(INPUT);
}

ColorSensor::~ColorSensor()
{
}

void ColorSensor::init() {
	// Setting frequency-scaling to 20%
	S0.setDigital(HIGH);
	S1.setDigital(LOW);
}

RGB ColorSensor::readRGB() {
	RGB color;

	shiftMode(1);
	color.R = map(pulseIn(OUT.getId(), LOW), R.lower, R.upper, RGB_MAX, 0);
	delay(100);
	shiftMode(2);
	color.G = map(pulseIn(OUT.getId(), LOW), G.lower, G.upper, RGB_MAX, 0);
	delay(100);
	shiftMode(3);
	color.B = map(pulseIn(OUT.getId(), LOW), B.lower, B.upper, RGB_MAX, 0);
	delay(100);

#ifdef DEBUG
	sendMsg(color.R);
	sendMsg(color.G);
	sendMsg(color.B);
	sendMsg("\n");
#endif // DEBUG
	return color;
}
