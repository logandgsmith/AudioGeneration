#include "note_generator.h"

// constructor defaults to middle C (C4)
NoteGenerator :: NoteGenerator() {
	
}

//frequncy getter
double NoteGenerator::getNoteFreq(int index){
	return keyboard[index].note_frequency;
}
//name getter
std::string NoteGenerator::getNoteName(int index) {
	return keyboard[index].note_name;
}
//array getter
Note* NoteGenerator::getArray() {
	return this->keyboard;
}

//Mutators  //ERROR MIGHT OCCUR DUE TO ME NOT USING POINTER NOTATION '->'
void NoteGenerator::setNote(double base_freq, string base_note, int num_of_notes) {
	char letter=base_note[0];
	bool has_sharp=false;
	if (base_note[1] == '#') {
		has_sharp = true;
	}
	int number=has_sharp?base_note[2]:base_note[1]-'0';
	string note_name=base_note;
	double freq = base_freq;
	Note* keyboard = new Note[num_of_notes];
	keyboard[0].note_frequency = freq;
	keyboard[0].note_name = note_name;
	int octave_count = 0;
	for(int i = 1; i < num_of_notes; i++){
		note_name = "";
		//determine number
		if (octave_count == 11) {
			number++;
			octave_count = 0;
		}
		else {
			octave_count++;
		}
		//determine sharp and letter
		if (has_sharp) {
			letter++;
			if (letter == 'H') {
				letter = 'A';
			}
			has_sharp = false;
		}
		else {
			if (letter == 'B' || letter == 'E') {
				has_sharp = false;
				letter++;
				if (letter == 'H') {
					letter = 'A';
				}
			}
			else {
				has_sharp = true;
			}
		}
		//assemble note name
		if (has_sharp) {
			note_name = note_name + letter + '#' + char(48 + number);
		}
		else {
			note_name = note_name + letter + char(48 + number);
		}
		//calculate frequency
		freq *= 1.059463;
		keyboard[i].note_frequency = freq;
		keyboard[i].note_name = note_name;
	}
}
