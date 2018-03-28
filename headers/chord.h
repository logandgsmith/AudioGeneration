#pragma once
#include "note_generator.h"

//this is a test
 
class Chord {
public:
	//Constructor
	Chord(std::string note_one, std::string note_two, std::string note_three);

	//Accessors
	Chord getNoteOne();
	Chord getNoteTwo();
	Chord getNoteThree();

	//Mutators
	void setNoteOne(std::string note_name);
	void setNoteTwo(std::string note_name);
	void setNoteThree(std::string note_name);

private:
	Note note_one;
	Note note_two;
	Note note_three;
};