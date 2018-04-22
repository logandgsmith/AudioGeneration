#pragma once
#include <string>
#include <vector>

// Default values for the NoteGenerator Constructor
const size_t default_keyboard_size = 36; // 3 octaves of range
const float default_base_freq = 130.81;
const std::string default_base_note_name = "C3";

struct Note {
	float		note_frequency;
	std::string	note_name;
	int		note_duration;
};

class NoteGenerator {
private:
	std::vector<Note> keyboard;

public:
	//Constructor
	NoteGenerator();

	//Accessors
	float			getNoteFreq(unsigned char index);
	std::string		getNoteName(unsigned char index);
	unsigned char		getNoteIndex(std::string note_name);
	std::vector<Note>	getKeyboard();
	unsigned char		getKeyboardSize();
	unsigned char		getMajorKeyboardSize();
	unsigned char		getRandomNote();
	Note			getNote(unsigned char index);
	Note			getSharpNote(unsigned char index);


	//Mutators
	//starting from the base note with base freq, count numOfNotes notes
	void setNote(float base_freq, std::string base_note, unsigned char num_of_notes);
};
