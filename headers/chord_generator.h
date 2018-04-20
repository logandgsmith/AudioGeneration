#pragma once
#include <string>
#include <vector>
#include "chord.h"
#include "note_generator.h"

class ChordGenerator
{

public:
	//Constructor
	ChordGenerator();
	ChordGenerator(NoteGenerator &note_gen);

	//Accessors
	Chord* getMajorTriadChord(int root_index);		//returns a major triad chord with the given root note
	Chord* getMinorTriadChord(int root_index);		//returns a minor triad chord with the given root note

													//other methods
	int checkExistingChord(std::string root_name);	//return the index of the chord in the existing chord* vector. If not found, return -1.
	int searchNote(string name);				//return the index of the note in the note array (length 12), if no such note, return -1

private:
	NoteGenerator * ng;
	//	vector<Note>* keyboard;
	vector<Chord*>* chords;
};
