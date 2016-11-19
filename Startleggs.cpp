#include "Startleggs.h"

#define DEBUG

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
	currentColor = UNKNOWN;
}

int Startleggs::detectColor() {
	// something left to do.
	// unfinished.
	RGB colorInfo = this->sensor.readRGB();
	return this->currentColor;
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
#ifdef DEBUG
	sendMsg("current Color is ");
	sendMsg(currentColor);
#endif
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
	/*this->head.sweep(MID_ANG, MIN_SHAKE);
	this->head.sweep(MIN_SHAKE, MAX_SHAKE);
	this->head.sweep(MAX_SHAKE, MID_ANG);*/
	this->head.setAngle(MIN_SHAKE);
	delay(20);
	this->head.setAngle(MAX_SHAKE);
	delay(20);
	this->head.setAngle(MID_SHAKE);
}

void Startleggs::crowing() {
	this->crow.sweep(1000, 2000);
	delay(200);
	this->crow.sweep(2000,1000);
}

bool Startleggs::isFed() {
	return this->currentColor != UNKNOWN;
}

bool Startleggs::isTouched() {
	return touch.getStatus();
}
