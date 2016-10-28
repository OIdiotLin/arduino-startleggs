#include "Pin.h"
#pragma once
#define RGB_MAX (255.0)
struct RGBscale {
	float red, green, blue;
};
struct RGB {
	int red, green, blue;
	RGB operator*(const RGBscale& scale) {
		RGB res;
		res.red = this->red*scale.red;
		res.green = this->green*scale.green;
		res.blue = this->blue*scale.blue;
		return res;
	}
	char* getString() {
		char *s;
		sprintf(s, "[%d,%d,%d]\0", red, green, blue);
		return s;
	}
};
// Using TCS3200
#ifndef COLOR_SENSOR_H
#define COLOR_SENSOR_H
class ColorSensor {
private:
	Pin S0, S1, S2, S3, OUT;
	int freqCount;	// count the frequency
	int currentFilter;	// store current filter, choosing which color is being read
	RGB colorData;	// store final result
	RGBscale scale;	// save the RGB Scale factor
	void filterChange(bool level0, bool level1);	// change the filter mode
public:
	ColorSensor();
	ColorSensor(uint8_t id0,uint8_t id1,uint8_t id2,uint8_t id3,uint8_t idO);
	~ColorSensor();
	void recall();	// return RGB
	void count();	// used for attachInterrupt
	void init();		// initialize the sensor and calc the scale factor
	void reset();	// reset the freqCount
	RGB getRGB();	// calculate the RGB value and delay 2s
};
#endif // !COLOR_SENSOR_H
