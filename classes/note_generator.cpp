#include "../headers/note_generator.h"
#include <vector>
#include <ctime> // To be used for note generator
#include <stdexcept>

using namespace std;

/**************************************************
This class defines a struct called Note, which
contains the note name and note frequency. The
note generator automatically generates and stores
a certain number of notes in the keyboard vector.
These notes can be used to form chords and melody
in our song.
***************************************************/

// constructor defaults to the note range starting one octave below middle C (C3) and being 3 octaves
NoteGenerator::NoteGenerator() {
	keyboard = vector<Note>();
	NoteGenerator::setNote(default_base_freq, default_base_note_name, default_keyboard_size);
}

//frequncy getter
float NoteGenerator::getNoteFreq(unsigned char index) {
	return getNote(index).note_frequency;
}

//name getter
string NoteGenerator::getNoteName(unsigned char index) {
	return getNote(index).note_name;
}

//Finds a note's index given a note name (ex. C4)
//It will return 255 if the note does not exist on the keyboard.
unsigned char NoteGenerator::getNoteIndex(string note_name) {
	for (int i = 0; i < getKeyboardSize(); i++) {
		string curr_name = keyboard.at(i).note_name;
		if (curr_name.compare(note_name) == 0) {
			return i;
		}
	}
	return 255;
}

//keyboard vector getter
//It will return the entire keyboard vector.
vector<Note> NoteGenerator::getKeyboard() {
	return this->keyboard;
}
//keyboard size getter
//It will return the keyboard's size, which can be up to size 254
// (It cannot ve size 255, as the getNoteIndex function returns 255 if it cannot find a number.
unsigned char NoteGenerator::getKeyboardSize() {
	return this->keyboard.size();
}
//keyboard size without notes outside of the actual key (ex. in C major it is the number of white keys)
//Currently, it only works correctly if the keyboard does not have a range that includes something outside of just octaves
//	(ex. a keyboard 3.5 octaves (42 notes) in size will only return saying it has 21 notes instead of more, as it should.)
unsigned char NoteGenerator::getMajorKeyboardSize() {
	unsigned char actual_keyboard_size = getKeyboardSize();
	unsigned char major_keyboard_size = actual_keyboard_size / 12 * 7;
	return major_keyboard_size;
}

//Mutators
//Generates the keyboard. It will give each note in the specified num_of_notes range a name, frequency, and duration 0.
//It erases the previous keyboard vector contents. (Of course, if there weren't any this won't actually do anything.)
void NoteGenerator::setNote(float base_freq, string base_note, unsigned char num_of_notes) {
	keyboard.clear();

	char letter = base_note[0];
	bool has_sharp = false;
	if (base_note[1] == '#') {
		has_sharp = true;
	}
	int number = has_sharp ? base_note[2] : base_note[1] - '0';
	string note_name = base_note;
	float freq = base_freq;
	keyboard.push_back(Note());
	keyboard[0].note_frequency = freq;
	keyboard[0].note_name = note_name;
	///	keyboard[0].note_duration = 0; // the keyboard doesn't have note durations
	int octave_count = 0;
	for (int i = 1; i < num_of_notes; i++) {
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
		keyboard.push_back(Note());
		keyboard[i].note_frequency = freq;
		keyboard[i].note_name = note_name;
		///		keyboard[i].note_duration = 0; // the keyboard doesn't have note durations
	}
}

int state = 0;

//generate a random note in the higher octave only (without sharp)
unsigned char NoteGenerator::getRandomNote() {
	//higher octaves
	//unsigned char rand_num = rand() % 14+8;
	unsigned char rand_num = state % 14 + 8;
	state++;
	return rand_num;
}

//get note based on the index on the major scale (after removing all the sharps)
/*
Since by default our bottom note is C3,
1=C3
2=D3
3=E3
4=F3
5=G3
6=A3
7=B3
8=C4
.
.
.
as high as the keyboard gets
*/
Note NoteGenerator::getNote(unsigned char index) 
{
	unsigned char multiple = (index - 1) / 7;
	index %= 7;
	switch (index) {
	case 1:
		return keyboard.at(0 + multiple * 12);
	case 2:
		return keyboard.at(2 + multiple * 12);
	case 3:
		return keyboard.at(4 + multiple * 12);
	case 4:
		return keyboard.at(5 + multiple * 12);
	case 5:
		return keyboard.at(7 + multiple * 12);
	case 6:
		return keyboard.at(9 + multiple * 12);

		// Actually note 7 of the given key
	case 0:
		return keyboard.at(11 + multiple * 12);
	default:
		throw domain_error("Invalid note index");
	}
}

//gets the notes that are not within the key of the keyboard (by default it is C major)
/*
Since by default our bottom note is C3,
1=C#3
2=D#3
3=F#3
4=G#3
5=A#3
6=C#4
7=D#4
.
.
.
as high as the keyboard gets
*/
Note NoteGenerator::getSharpNote(unsigned char index) 
{
	unsigned char multiple = (index - 1) / 5;
	index %= 5;
	switch (index) {
	case 1:
		return keyboard.at(1 + multiple * 12);
	case 2:
		return keyboard.at(3 + multiple * 12);
	case 3:
		return keyboard.at(6 + multiple * 12);
	case 4:
		return keyboard.at(8 + multiple * 12);
	case 0:
		return keyboard.at(10 + multiple * 12);
	default:
		throw domain_error("Invalid note index");
	}
}
