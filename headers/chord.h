#pragma once

#include "note_generator.h"
#include <string>

using namespace std;
//this is a test
 
class Chord {
public:
	//Constructor
	Chord(std::string name, Note note_one, Note note_two, Note note_three);

	//Accessors
	std::string getName();
	Note* getNoteOne();
	Note* getNoteTwo();
	Note* getNoteThree();

private:
	std::vector<Note> chord;
	string name;
//	NoteGenerator* note_generator;
};
