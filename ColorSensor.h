#include "Pin.h"
#pragma once
#define RGB_MAX (255)
struct Color {
	int lower, upper;	// used for map() arguments
	Color(int l, int r) { lower = l, upper = r; }
};
const Color R = Color(25, 72);
const Color G = Color(30, 90);
const Color B = Color(25, 70);
struct RGB {
	int R, G, B;
	char* info() {
		char *s;
		sprintf(s, "R=%d,G=%d,B=%d\n", R, G, B);
		return s;
	}
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
