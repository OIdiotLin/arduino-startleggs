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

void Startleggs::layEgg() {
	switch (currentColor) {
	case RED:
		
	}
}

bool Startleggs::isTouched() {
	return touch.getStatus();
}
