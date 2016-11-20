#include "Startleggs.h"

#define DEBUG

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
	while (true) {
		detectColor();
#ifdef DEBUG
		int x = this->getCurrentColor();
		switch (x)
		{
		case 0:
			sendMsg("RED\n");
			break;
		case 1:
			sendMsg("GREEN\n");
			break;
		case 2:
			sendMsg("BLUE\n");
			break;
		default:
			sendMsg("UNKNOWN\n");
			break;
		}
#endif
	}
	turnplate.sweep(RED_GROOVE, BLUE_GROOVE);
	head.sweep(MIN_SHAKE, MAX_SHAKE);
	delay(500);
	crow.playMelody(testNotes, testDuration, 38);
	currentColor = UNKNOWN;
	for (int i = 0;i < 70;i++) {
		turnplate.setAngle(MID_GROOVE);
		head.setAngle(MID_SHAKE);
	}
	for (int i = 0;i < 3;i++) {
		eyesBlue.blink(200);
		delay(100);
		eyesRed.blink(200);
		delay(100);
	}
}

int Startleggs::detectColor() {
	color x;
	bool isBlue=1, isRed=1, isGreen=1;
	for (int i = 0;i < 3;i++) {
		RGB colorInfo = this->sensor.readRGB();
		if (colorInfo.B < colorInfo.G)
			isBlue = false;
		if (colorInfo.R < -200)
			return this->currentColor = GREEN;
		if (colorInfo.R > 200)
			return this->currentColor = RED;

	}
	if (isRed && isGreen && !isBlue)
		return this->currentColor = UNKNOWN;
	return this->currentColor = BLUE;
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

#ifdef DEBUG
void Startleggs::changeEye(color x) {
	switch (x) {
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
#endif

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
#ifdef DEBUG
		this->turnplate.sweep(RED_GROOVE, BLUE_GROOVE);
		delay(200);
		this->turnplate.sweep(BLUE_GROOVE, RED_GROOVE);
		delay(300);
#endif
		break;
	}
}

void Startleggs::shakeHead() {
	this->head.sweep(MID_ANG, MIN_SHAKE);
	this->head.sweep(MIN_SHAKE, MAX_SHAKE);
	this->head.sweep(MAX_SHAKE, MID_ANG);
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
