#include "Pin.h"

#include "pitches.h"
#pragma once
#ifndef BUZZER_H
#define BUZZER_H

#define WHOLE_NOTE_DURATION 300		// whole note lasts 1 sec.
#define INTERVAL_BETWEEN_NOTES 1.3	// to distinguish the notes, set a minimum time between them.

class Buzzer {
private:
	Pin pin;
public:
	Buzzer();
	Buzzer(uint8_t _id);
	~Buzzer();
	void beep(const int note, const double noteDuration);	// duration = meter. real duration = (1000/duration)
	void sweep(int from, int end);
	void playMelody(const int* melody, const double* duration, const int size);
	void test();	// playing melody of S.C.U.T
};


#endif // !BUZZER_H

// melody of S.C.U.T
const int testNotes[38] = {
	NOTE_C4,NOTE_C4,NOTE_A3,NOTE_G3,NOTE_G4,NOTE_G4,NOTE_A4,NOTE_G4,
	NOTE_G4,
	NOTE_A4,NOTE_G4,NOTE_G4,NOTE_E4,NOTE_C4,NOTE_A3,NOTE_F4,NOTE_G4,
	NOTE_D4,
	NOTE_E4,NOTE_D4,NOTE_E4,NOTE_G4,NOTE_G4,
	NOTE_E4,NOTE_E4,NOTE_D4,NOTE_E4,NOTE_B3,NOTE_A3,
	NOTE_D4,NOTE_D4,NOTE_D4,NOTE_E4,NOTE_D4,NOTE_D4,NOTE_A3,NOTE_C4,
	NOTE_C4
};

const double testDuration[38] = {
	DUR_HALF,DUR_HALF,DUR_HALF,DUR_HALF,DUR_HALF,DUR_WHOLE,DUR_QUARTER,DUR_QUARTER,
	DUR_QUADRA,
	DUR_HALF_PNT,DUR_QUARTER,DUR_HALF,DUR_HALF,DUR_HALF,DUR_HALF,DUR_HALF_PNT,DUR_QUARTER,
	DUR_QUADRA,
	DUR_WHOLE,DUR_HALF_PNT,DUR_QUARTER_PNT,DUR_HALF,DUR_WHOLE_PNT,
	DUR_HALF,DUR_HALF,DUR_QUARTER,DUR_QUARTER,DUR_HALF,DUR_DOUBLE,
	DUR_HALF_PNT,DUR_QUARTER,DUR_HALF,DUR_HALF,DUR_HALF,DUR_HALF,DUR_HALF,DUR_HALF,
	DUR_QUADRA
};