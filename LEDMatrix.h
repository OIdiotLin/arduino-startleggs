#include "Pin.h"
#pragma once
//	used for 1588AB-24 LED matrix
#ifndef LED_MATRIX_H
#define LED_MATRIX_H
class LEDMatrix {
#define SIZE (8)
private:
	//	for rowOn[i], if it's HIGH, row[i] will be ON
	//	for colOff[i], if it's HIGH, col[i] will be OFF
	Pin rowOn[8], colOff[8];
public:
	LEDMatrix();
	LEDMatrix(int *r_id, int *c_id);
	~LEDMatrix();
	void clear();
	void test();
	void allOn();
	void singleOn(int r, int c);
};

#endif // !LED_MATRIX_H
