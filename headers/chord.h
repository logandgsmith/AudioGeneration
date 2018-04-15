#pragma once

#include "note_generator.h"
#include <string>

using namespace std;
//this is a test
 
class Chord {
public:
	//Constructor
	Chord(std::string name, Note* note_one, Note* note_two, Note* note_three);

	//Accessors
	Note* getNoteOne();
	Note* getNoteTwo();
	Note* getNoteThree();

private:
	Note* note_one;
	Note* note_two;
	Note* note_three;
	string name;
	NoteGenerator* note_generator;
};