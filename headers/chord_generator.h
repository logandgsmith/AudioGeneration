#pragma once
#include <string>
#include <vector>
#include "chord.h"
#include "note_generator.h"

using namespace std;
class ChordGenerator
{

public:
	//Constructor
	ChordGenerator();

	//Accessors
	Chord* getMajorChord(string root_note);		//return the major chord with the root note
	Chord* getMinorChord(string root_note);		//return the minor chord with the root note

												//other methods
	int checkExistingChord(string root_name);	//return the index of the chord in the existing chord* vector. If not found, return -1.
	int searchNote(string name);				//return the index of the note in the note array (length 12), if no such note, return -1

private:
	vector<Note>* note_array;
	vector<Chord*>* chords_we_have;
};
