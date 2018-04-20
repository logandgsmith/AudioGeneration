#pragma once

#include "note_generator.h"
//#include <string>

using namespace std;
 
class Chord 
{
public:
	//Constructor
	Chord(NoteGenerator &ng);
	Chord(NoteGenerator &ng, unsigned char scale_degree); // Constructs a triad

	//Accessors
	unsigned char getNumNotes();
	Note getNote(unsigned char index);
	/*
	std::string getName();
	*/
	
	//Mutators
	void push_back_note(Note n);
	void push_back_note(unsigned char note_index); // Must be greater than or equal to 1
	void create_triad(unsigned char scale_degree);

private:
	std::vector<Note> chord;
	NoteGenerator ng;
//	string name;
};
