#pragma once
#include <string>
#include <vector>

const size_t default_keyboard_size = 24;

struct Note{
	double      note_frequency;
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
	double            getNoteFreq(int index);
	std::string       getNoteName(int index);
	std::vector<Note> getKeyboard();
	size_t            getKeyboardSize();
	Note              getRandomNote(bool is_major_key);

	//Mutators
	void setNote(double base_freq, std::string base_note, int num_of_notes);	//starting from the base note with base freq, count numOfNotes notes
};
