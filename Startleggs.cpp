#include "Startleggs.h"

Startleggs::Startleggs()
{
}


Startleggs::~Startleggs()
{
}

void Startleggs::init() {
	// units pin setting
	eyesBlue = LED(EYES_BLUE_PIN_ID);
	eyesRed = LED(EYES_RED_PIN_ID);
	head = SteeringGear(HEAD_PIN_ID);
	turnplate = SteeringGear(TURNPLATE_PIN_ID);
	crow = Buzzer(CROW_PIN_ID);
	sensor = ColorSensor(SENSOR_PINS_ID);
	touch = Switch(TOUCH_PIN_ID);

	// units testing
	turnplate.sweep(RED_GROOVE, BLUE_GROOVE);
	head.sweep(MIN_SHAKE, MAX_SHAKE);
	delay(500);
//	crow.playMelody(testNotes, testDuration, 38);
	currentColor = UNKNOWN;
	for (int i = 0;i < 70;i++) {
		turnplate.setAngle(MID_GROOVE);
		head.setAngle(MID_SHAKE);
	}
	for (int i = 0;i < 3;i++) {
		eyesBlue.blink(200);
		eyesRed.blink(200);
	}
}

int Startleggs::detectColor() {
	color x;
//	bool isBlue=1, isRed=1, isGreen=1;
	for (int i = 0;i < 3;i++) {
		RGB colorInfo = this->sensor.readRGB();
#ifdef DEBUG
		sendMsg(colorInfo.R);
		sendMsg(colorInfo.G);
		sendMsg(colorInfo.B);
		sendMsg("\n");
#endif
		if (colorInfo.G - colorInfo.R > 45)
			return this->currentColor = GREEN;
		if (colorInfo.B - colorInfo.R > 55)
			return this->currentColor = BLUE;
		if (colorInfo.R - colorInfo.G > 60)
			return this->currentColor = RED;
		//if (colorInfo.B < colorInfo.G)
		//	isBlue = false;
		//if (colorInfo.R < -200)
		//	return this->currentColor = GREEN;
		//if (colorInfo.R > 200)
		//	return this->currentColor = RED;
	}
	return this->currentColor = UNKNOWN;
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
		crowing();
		this->turnplate.sweep(MID_GROOVE, RED_GROOVE);
		delay(20);
		this->turnplate.sweep(RED_GROOVE, MID_GROOVE);
		delay(20);
		break;
	case BLUE:
		crowing();
		this->turnplate.sweep(MID_GROOVE, BLUE_GROOVE);
		delay(20);
		this->turnplate.sweep(BLUE_GROOVE, MID_GROOVE);
		delay(20);
		break;
	default:
		break;
	}
}

void Startleggs::shakeHead() {
	this->head.sweep(MID_SHAKE, MIN_SHAKE);
	this->head.sweep(MIN_SHAKE, MAX_SHAKE);
	this->head.sweep(MAX_SHAKE, MID_SHAKE);
}

void Startleggs::crowing() {
	crow.playMelody(crowNotes, crowDurations, 3);
	
}

bool Startleggs::isFed() {
	return this->currentColor != UNKNOWN;
}

bool Startleggs::isTouched() {
	return touch.getStatus();
}
