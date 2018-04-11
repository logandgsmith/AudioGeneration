#pragma once

#include "note_generator.h"
#include <string>

using namespace std;
//this is a test
 
class Chord {
public:
	//Constructor
	Chord(std::string name, std::string note_one, std::string note_two, std::string note_three);

	//Accessors
	Note* getNoteOne();
	Note* getNoteTwo();
	Note* getNoteThree();

	//Mutators
	void setNote(std::string note_name);

private:
	Note* note_one;
	Note* note_two;
	Note* note_three;
	string name;
	NoteGenerator note_generator;
};