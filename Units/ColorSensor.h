#include "Pin.h"
#pragma once
#define RGB_MAX (255)
struct ColorFilter {
	int lower, upper;	// used for map() arguments
	ColorFilter(int l, int r) { lower = l, upper = r; }
};
const ColorFilter R = ColorFilter(25, 72);
const ColorFilter G = ColorFilter(30, 90);
const ColorFilter B = ColorFilter(25, 70);
struct RGB {
	int R, G, B;
};
// Using TCS3200
#ifndef COLOR_SENSOR_H
#define COLOR_SENSOR_H
class ColorSensor {
private:
	Pin S0, S1, S2, S3, OUT;
	void shiftMode(int mode);	// 0: clear, 1: red, 2: green, 3: blue
public:
	ColorSensor();
	ColorSensor(uint8_t id0,uint8_t id1,uint8_t id2,uint8_t id3,uint8_t idO);
	~ColorSensor();
	void init();	
	RGB readRGB();
};
#endif // !COLOR_SENSOR_H
