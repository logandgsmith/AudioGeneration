#include "../headers/chord.h"
#include <iostream>

/**************************************************
This class defines the Chord object. Each chord
usually has three notes that are generated with 
a formula. These notes in the same chord has 
frequencies that are in small ratios to make the 
chord sound good.
***************************************************/

//Constructor for triads
Chord::Chord() {

}

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

//return the name of the chord
std::string Chord::getName() {
	return name;
}

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
	name = ng.getNoteName(scale_degree) + "_Chord";
	this->push_back_note(scale_degree);
	this->push_back_note(scale_degree + 2);
	this->push_back_note(scale_degree + 4);
}

//format the chord to a string, if withNotes is true, the string includes both the chord name and the note names;
//if withNote is false, the string contains only chord name (same as getName)
string Chord::printChord(bool withNotes) {
	string a = "";
	if (withNotes)
		a = a + getName() + ": " + getNote(0).note_name + " " + getNote(1).note_name + " " + getNote(2).note_name;
	else
		a = a + getName();
	return a;
}
