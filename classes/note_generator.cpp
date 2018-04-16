#include "../headers/note_generator.h"
#include <algorithm>
#include <vector>
#include <ctime> // To be used for note generator

// constructor defaults to the note range starting one octave below middle C (C3) and being 2 octaves
NoteGenerator::NoteGenerator() {
	NoteGenerator::setNote(130.81, std::string("C3"), default_keyboard_size);
}

//frequncy getter
double NoteGenerator::getNoteFreq(int index){
	return keyboard.at(index).note_frequency;
}
//name getter
std::string NoteGenerator::getNoteName(int index) {
	return keyboard.at(index).note_name;
}
//keyboard vector getter
std::vector<Note> NoteGenerator::getKeyboard() {
	return keyboard;
}
//keyboard size getter
size_t NoteGenerator::getKeyboardSize() {
	return this->keyboard.size();
}

//Mutators  //ERROR MIGHT OCCUR DUE TO ME NOT USING POINTER NOTATION '->'
void NoteGenerator::setNote(double base_freq, std::string base_note, int num_of_notes) {
	char letter=base_note[0];
	bool has_sharp=false;
	if (base_note[1] == '#') {
		has_sharp = true;
	}
	int number=has_sharp?base_note[2]:base_note[1]-'0';
	string note_name=base_note;
	double freq = base_freq;

	keyboard[0].note_frequency = freq;
	keyboard[0].note_name = note_name;
	keyboard[0].note_duration = 0; // the keyboard doesn't have note durations
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
		keyboard[i].note_duration = 0; // the keyboard doesn't have note durations
	}
}

Note NoteGenerator::getRandomNote(bool is_major_key) {
	Note rand_note;

//	srand(time(NULL));
	bool valid_key = false;
	int rn_i; // rn_i is the random note's index
	if (is_major_key) {
		do {
			rn_i = rand() % (this->keyboard.size());
			if ((rn_i % 12 == 0) || (rn_i % 12 == 2) || (rn_i % 12 == 4) || (rn_i % 12 == 5) || 
				(rn_i % 12 == 7) || (rn_i % 12 == 8) || (rn_i % 12 == 10)) 
				valid_key = true;
		}
		while (valid_key == false);
	}
	else {
		do {
			rn_i = rand() % (this->keyboard.size());
			if ((rn_i % 12 == 0) || (rn_i % 12 == 2) || (rn_i % 12 == 3) || (rn_i % 12 == 5) || 
				(rn_i % 12 == 7) || (rn_i % 12 == 8) || (rn_i % 12 == 10))
				valid_key = true;
		}
		while (valid_key == false);	
	}
	
	rand_note.note_frequency = getNoteFreq(rn_i);
	rand_note.note_name = getNoteName(rn_i);
	
	int rand_note_duration = (rand() % 2) + 1; // notes can be quarter (1 beat) or half (2 beats)
	rand_note.note_duration = rand_note_duration;
	
	return rand_note;
}
