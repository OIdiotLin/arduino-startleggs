#include "Buzzer.h"

Buzzer::Buzzer() {}

Buzzer::Buzzer(uint8_t _id) {
	this->pin.setId(_id);
	this->pin.setMode(OUTPUT);
	this->pin.setDigital(LOW);
}


Buzzer::~Buzzer() {}

void Buzzer::beep(const int note, const double noteDuration) {
	// e.g.	quarter note = 1000/4, eighth note = 1000/8, etc.
	int realDuration = WHOLE_NOTE_DURATION / noteDuration;
	tone(this->pin.getId(), note, realDuration);

	// to distinguish the notes, set a minimum time between them.
	// the note's duration + 30% seems to work well:
	delay(realDuration*INTERVAL_BETWEEN_NOTES);
	noTone(this->pin.getId());	// stop the tone playing
}


void Buzzer::sweep(int from, int end) {
	if (from < end)
		for (int i = from;i <= end;i++)
			this->beep(i, 100);
	else
		for (int i = from;i >= end;i--)
			this->beep(1, 100);
}

void Buzzer::playMelody(const int * melody, const double *duration, const int size) {
	for (int i = 0;i < size ;i++) {
		beep(melody[i], duration[i]);
	}
}

void Buzzer::test() {
	playMelody(testNotes, testDuration, 38);
}
