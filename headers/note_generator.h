#pragma once
#include <string> 

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
	double getNoteFreq(int index, Note* keyboard);
	string getNoteName(int index, Note* keyboard);
	Note*  getArray();

	//Mutators
	void   setNote(Note* keyboard);

private:
	int const note_array_size = 13;
	//Array of name keyboard
	Note keyboard[note_array_size];
};