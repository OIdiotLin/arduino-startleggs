#include "SteppingMotor.h"



void SteppingMotor::stepMotor(int thisStep) {
	switch (thisStep) {
	case 0:	// 1010
		this->pin[0].setDigital(HIGH);
		this->pin[1].setDigital(LOW);
		this->pin[2].setDigital(HIGH);
		this->pin[3].setDigital(LOW);
		break;
	case 1:	// 0110
		this->pin[0].setDigital(LOW);
		this->pin[1].setDigital(HIGH);
		this->pin[2].setDigital(HIGH);
		this->pin[3].setDigital(LOW);
		break;
	case 2:	// 0101
		this->pin[0].setDigital(LOW);
		this->pin[1].setDigital(HIGH);
		this->pin[2].setDigital(LOW);
		this->pin[3].setDigital(HIGH);
		break;
	case 3:	// 1001
		this->pin[0].setDigital(HIGH);
		this->pin[1].setDigital(LOW);
		this->pin[2].setDigital(LOW);
		this->pin[3].setDigital(HIGH);
		break;
	default:
		break;
	}
}

SteppingMotor::SteppingMotor(int stepCount, int pin0, int pin1, int pin2, int pin3) {
	this->stepCount = stepCount;
	this->direction = 0;
	this->lastStepTime = 0;
	this->stepIndex = 0;
	this->pin[0].setId(pin0);
	this->pin[1].setId(pin1);
	this->pin[2].setId(pin2);
	this->pin[3].setId(pin3);
	for (int i = 0;i < pinCount;i++)
		this->pin[i].setMode(OUTPUT);
}
SteppingMotor::~SteppingMotor() {}

void SteppingMotor::setSpeed(int speed) {
	this->stepDelay = 60000000 / this->stepCount / speed;
}

void SteppingMotor::step(int stepCount) {
	int stepsLeft = abs(stepCount);
	this->direction = (stepCount < 0);	// when stepCount negative, moves in the reverse direction
	while (stepsLeft) {
		if (millis() - this->lastStepTime >= this->stepDelay) {
			this->lastStepTime = millis();	// get the timeStamp of when you stepped
			if (this->direction == ClockWise) {
				if (++(this->stepIndex) == this->stepCount)
					this->stepIndex = 0;
			}
			else if(this->direction==AntiClockWise) {
				if (this->stepIndex == 0)
					this->stepIndex = this->stepCount;
				this->stepIndex--;
			}
		}
		stepsLeft--;
		stepMotor(this->stepIndex % 4);
	}
}
