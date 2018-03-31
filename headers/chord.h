#pragma once

#include "note_generator.h"

//this is a test
 
class Chord {
public:
	//Constructor
	Chord(std::string name, std::string note_one, std::string note_two, std::string note_three);

	//Accessors
	Chord getNoteOne();
	Chord getNoteTwo();
	Chord getNoteThree();

	//Mutators
	void setNote(std::string note_name);

private:
	Note note_one;
	Note note_two;
	Note note_three;

	NoteGenerator note_generator;
};