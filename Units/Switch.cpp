#include "Switch.h"

Switch::Switch()
{
}

Switch::Switch(uint8_t id) {
	pin.setId(id);
	pin.setMode(INPUT);
}

bool Switch::getStatus() {
	return pin.getDigital();
}

Switch::~Switch()
{
}
