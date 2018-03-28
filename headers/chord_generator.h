#pragma once

#include <string>
#include <vector>
#include "chord.h"

class Chord_Generator {
public:
	//Constructor
	 Chord_Generator();
	~Chord_Generator();

	//Accessors
	Chord getMajorChord(std::string root_note);
	Chord getMinorChord(std::string root_note);
	int checkExistingChord(std::string root_name);
	int searchNote(std::string name);

private:
	Note * note_array;
	vector<Chord>* created_chords;
};

