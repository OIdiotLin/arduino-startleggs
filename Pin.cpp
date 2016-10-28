#include "Pin.h"

Pin::Pin() {}

Pin::Pin(uint8_t _id) {
	id = _id;
}
Pin::~Pin() {}

void Pin::setId(uint8_t _id) {
	id = _id;
}

uint8_t Pin::getId() {
	return id;
}

void Pin::setMode(int mode) {
	pinMode(this->getId(), mode);
}

void Pin::setDigital(bool v) {
	digitalWrite(this->getId(), v);
}

bool Pin::getDigital() {
	return digitalRead(this->getId());
}
