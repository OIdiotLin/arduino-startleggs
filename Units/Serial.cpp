#include "Serial.h"

void sendMsg(char *msg) {
	Serial.print(msg);
}

void sendMsg(int n) {
	Serial.println(n);
}

int readInt() {
	String inString = "";
	while (Serial.available() > 0) {
		int inChar = Serial.read();
		inString += (char)inChar;
		delay(2);
	}
	return inString.toInt();
}
