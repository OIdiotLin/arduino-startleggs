#include "LEDMatrix.h"



LEDMatrix::LEDMatrix() {}

LEDMatrix::LEDMatrix(int * r_id, int * c_id) {
	for (int i = 0;i < SIZE;i++) {
		rowOn[i].setId(r_id[i]);
		rowOn[i].setMode(OUTPUT);
	}
	for (int i = 0;i < SIZE;i++) {
		colOff[i].setId(c_id[i]);
		colOff[i].setMode(OUTPUT);
	}
	this->clear();
}


LEDMatrix::~LEDMatrix() {}

void LEDMatrix::clear() {
	for (int i = 0;i < SIZE;i++)
		rowOn[i].setDigital(LOW);
	for (int i = 0;i < SIZE;i++)
		colOff[i].setDigital(LOW);
}

void LEDMatrix::test() {
	for (int i = 0;i < SIZE;i++) {
		for (int j = 0;j < SIZE;j++) {
			this->singleOn(i, j);
			delay(100);
			this->clear();
		}
	}
}

void LEDMatrix::allOn() {
	for (int i = 0;i < SIZE;i++)
		rowOn[i].setDigital(HIGH);
}

void LEDMatrix::singleOn(int r, int c) {
	rowOn[r].setDigital(HIGH);
	for (int i = 0;i < SIZE;i++)
		if (i != c)
			colOff[i].setDigital(HIGH);
}

void LEDMatrix::yi() {
	rowOn[3].setDigital(HIGH);
	colOff[7].setDigital(HIGH);
	delay(2500);
	rowOn[3].setDigital(LOW);
	colOff[7].setDigital(LOW);
}

void LEDMatrix::zhong() {
	int k = 80;
	while (k--) {
		for (int i = 0;i < 3;i++)
			colOff[i].setDigital(HIGH);
		for (int i = 4;i < SIZE;i++)
			colOff[i].setDigital(HIGH);
		for (int i = 0;i < 2;i++)
			rowOn[i].setDigital(HIGH);
		for (int i = 5;i < SIZE;i++)
			rowOn[i].setDigital(HIGH);
		delay(5);

		for (int i = 0;i < 2;i++)
			rowOn[i].setDigital(LOW);
		for (int i = 5;i < SIZE;i++)
			rowOn[i].setDigital(LOW);
		for (int i = 0;i < 3;i++)
			colOff[i].setDigital(LOW);
		for (int i = 4;i < SIZE;i++)
			colOff[i].setDigital(LOW);

		colOff[7].setDigital(HIGH);
		rowOn[2].setDigital(HIGH);
		rowOn[4].setDigital(HIGH);
		delay(5);

		colOff[7].setDigital(LOW);
		rowOn[2].setDigital(LOW);
		rowOn[4].setDigital(LOW);

		colOff[1].setDigital(HIGH);
		colOff[2].setDigital(HIGH);
		colOff[4].setDigital(HIGH);
		colOff[5].setDigital(HIGH);
		colOff[7].setDigital(HIGH);
		rowOn[3].setDigital(HIGH);
		delay(5);

		colOff[1].setDigital(LOW);
		colOff[2].setDigital(LOW);
		colOff[4].setDigital(LOW);
		colOff[5].setDigital(LOW);
		colOff[7].setDigital(LOW);
		rowOn[3].setDigital(LOW);
	}
}


