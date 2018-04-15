#pragma once
#include <string>
#include <vector>

using namespace std;

const size_t default_keyboard_size = 24;

struct Note{
	double note_frequency;
	string note_name;
	int note_duration;
};

class NoteGenerator {
private:
	std::vector<Note>	keyboard;

public:
	//Constructor
	 NoteGenerator();
	//~NoteGenerator(); May or may not use

	//Accessors
	double				getNoteFreq(int index);
	string				getNoteName(int index);
	std::vector<Note>	getKeyboard();
	size_t				getKeyboardSize();
	Note 				getRandomNote();

	//Mutators
	void        setNote(double base_freq, string base_note, int num_of_notes);	//starting from the base note with base freq, count numOfNotes notes
};
