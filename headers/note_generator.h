#pragma once
#include <string>
#include <vector>

const size_t default_keyboard_size = 24;

<<<<<<< HEAD
struct Note{
	double			note_frequency;
	std::string		note_name;
//	unsigned int	note_duration;
=======
struct Note {
	double      note_frequency;
	std::string note_name;
	int         note_duration;
>>>>>>> ea459e60a8d2f405acf3e80c67b0e0882541f753
};

class NoteGenerator {
private:
	std::vector<Note> keyboard;

public:
	//Constructor
	NoteGenerator();

	//Accessors
<<<<<<< HEAD
	double				getNoteFreq(unsigned char index);
	std::string			getNoteName(unsigned char index);
	std::vector<Note>	getKeyboard();
	unsigned char		getKeyboardSize();
	Note				getRandomNote(bool is_major_key);
	Note				getNote(unsigned char index);
=======
	double            getNoteFreq(int index);
	std::string       getNoteName(int index);
	std::vector<Note> getKeyboard();
	size_t            getKeyboardSize();
	Note              getRandomNote();
	Note			  getNote(int index);
>>>>>>> ea459e60a8d2f405acf3e80c67b0e0882541f753

	//Mutators
	//starting from the base note with base freq, count numOfNotes notes
	void setNote(double base_freq, std::string base_note, unsigned char num_of_notes);
};
