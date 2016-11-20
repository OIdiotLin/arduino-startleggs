#include "Switch.h"

Switch::Switch()
{
}


Switch::Switch(uint8_t id1, uint8_t id3) {
	pin1.setId(id1);
	pin1.setMode(OUTPUT);
	pin1.setDigital(HIGH);
	pin3.setDigital(id3);
	pin3.setMode(INPUT);
}

bool Switch::getStatus() {
	return pin3.getDigital();
}

Switch::~Switch()
{
}
