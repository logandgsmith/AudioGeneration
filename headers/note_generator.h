#pragma once
#include <string>
#include <vector>

const size_t default_keyboard_size = 24;

struct Note{
	double			note_frequency;
	std::string		note_name;
//	unsigned int	note_duration;
};

class NoteGenerator {
private:
	std::vector<Note> keyboard;

public:
	//Constructor
	 NoteGenerator();

	//Accessors
	double				getNoteFreq(unsigned char index);
	std::string			getNoteName(unsigned char index);
	std::vector<Note>	getKeyboard();
	unsigned char		getKeyboardSize();
	Note				getRandomNote(bool is_major_key);
	Note				getNote(unsigned char index);

	//Mutators
	//starting from the base note with base freq, count numOfNotes notes
	void setNote(double base_freq, std::string base_note, unsigned char num_of_notes);
};
