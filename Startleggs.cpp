#include "Startleggs.h"



Startleggs::Startleggs()
{
}


Startleggs::~Startleggs()
{
}

void Startleggs::init() {
	eyesBlue = LED(EYES_BLUE_PIN_ID);
	eyesRed = LED(EYES_RED_PIN_ID);
	head = SteeringGear(HEAD_PIN_ID);
	turnplate = SteeringGear(TURNPLATE_PIN_ID);
	crow = Buzzer(CROW_PIN_ID);
	sensor = ColorSensor(SENSOR_PINS_ID);
	touch = Switch(TOUCH_PIN_ID);
}

int Startleggs::detectColor() {
	// something left to do.
	// unfinished.
	return 0;
}

color Startleggs::getCurrentColor() {
	return this->currentColor;
}

void Startleggs::changeEye() {
	switch (currentColor) {
	case RED:
		eyesBlue.lightOff();
		eyesRed.lightOn();
		break;
	case BLUE:
		eyesRed.lightOff();
		eyesBlue.lightOn();
		break;
	case UNKNOWN:
	default:
		eyesBlue.lightOff();
		eyesRed.lightOff();
		break;
	}
}

void Startleggs::layEgg() {
	switch (currentColor) {
	case RED:
		this->turnplate.setAngle(RED_GROOVE);
		this->turnplate.setAngle(MID_ANG);
		break;
	case BLUE:
		this->turnplate.setAngle(BLUE_GROOVE);
		this->turnplate.setAngle(MID_ANG);
		break;
	default:
		break;
	}
}

void Startleggs::shakeHead() {
	this->head.sweep(MID_ANG, MIN_SHAKE);
	this->head.sweep(MIN_SHAKE, MAX_SHAKE);
	this->head.sweep(MAX_SHAKE, MID_ANG);
}

bool Startleggs::isFed() {
	return this->currentColor != UNKNOWN;
}

bool Startleggs::isTouched() {
	return touch.getStatus();
}
