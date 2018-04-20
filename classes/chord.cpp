#include "../headers/chord.h"

//Constructor for triads
Chord::Chord(NoteGenerator &ng) { }

Chord::Chord(NoteGenerator &ng, unsigned char scale_degree)
{
	Chord::create_triad(scale_degree);
}

//Accessors
Note Chord::getNote(unsigned char index)
{
	return this->chord.at(index);
}
unsigned char Chord::getNumNotes()
{
	return this->chord.size();
}
/*
std::string Chord::getName() {
	return name;
}
*/

//Mutators
void Chord::push_back_note(Note n)
{
	this->chord.push_back(n);
}
void Chord::push_back_note(unsigned char note_index) // Must be greater than or equal to 1
{
	this->push_back_note(ng.getNote(note_index));
}
void Chord::create_triad(unsigned char scale_degree)
{
	this->chord.clear();
	this->push_back_note(scale_degree);
	this->push_back_note(scale_degree + 2);
	this->push_back_note(scale_degree + 4);
}

