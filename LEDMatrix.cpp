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


