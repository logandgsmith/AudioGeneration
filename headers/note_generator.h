#pragma once
#include <string>
using namespace std;

struct Note{
	double note_frequency;
	string note_name;
};

class NoteGenerator {
public:
	//Constructor
	 NoteGenerator();
	//~NoteGenerator(); May or may not use

	//Accessors
	double      getNoteFreq(int index);
	string		getNoteName(int index);
	Note*       getArray();

	//Mutators
	void        setNote(double base_freq, string base_note, int num_of_notes);	//starting from the base note with base freq, count numOfNotes notes

private:
	Note*       keyboard;
};