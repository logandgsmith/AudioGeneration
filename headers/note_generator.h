#pragma once
#include <string>
#include <vector>

const size_t default_keyboard_size = 36;
struct Note {
	float      note_frequency;
	std::string note_name;
	int         note_duration;
};

class NoteGenerator {
private:
	std::vector<Note> keyboard;

public:
	//Constructor
	NoteGenerator();

	//Accessors
	float				getNoteFreq(unsigned char index);
	std::string			getNoteName(unsigned char index);
	std::vector<Note>	getKeyboard();
	unsigned char		getKeyboardSize();
	unsigned char		getMajorKeyboardSize();
	unsigned char		getRandomNote();
	Note				getNote(unsigned char index);


	//Mutators
	//starting from the base note with base freq, count numOfNotes notes
	void setNote(float base_freq, std::string base_note, unsigned char num_of_notes);
};
