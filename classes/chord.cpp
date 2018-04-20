#include "../headers/chord.h"
#include <stdexcept>

//Constructor for triads
Chord::Chord(std::string name, Note note_one, Note note_two, Note note_three) {

	this->name = name;
	this->chord.push_back(note_one);
	this->chord.push_back(note_two);
	this->chord.push_back(note_three);
}

//Accessors
//return the name of the chord
std::string Chord::getName() {
	return name;
}

//return the first note of the chord
Note* Chord::getNoteOne() {
	Note* note;
	try {
		note = &(this->chord.at(0));
	}
	catch (const std::out_of_range &e) {
		note = nullptr;
	}
	return note;
}

//return the second note of the chord
Note* Chord::getNoteTwo() {
	Note* note;
	try {
		note = &(this->chord.at(1));
	}
	catch (const std::out_of_range &e) {
		note = nullptr;
	}
	return note;
}

//return the third note of the chord
Note* Chord::getNoteThree() {
	Note* note;
	try {
		note = &(this->chord.at(2));
	}
	catch (const std::out_of_range &e) {
		note = nullptr;
	}
	return note;
}

//format the chord to a string, if withNotes is true, the string includes both the chord name and the note names;
//if withNote is false, the string contains only chord name (same as getName)
string Chord::printChord(bool withNotes) {
	string a = "";
	if (withNotes)
		a = a + getName() + ": " + getNoteOne()->note_name + " " + getNoteTwo()->note_name + " " + getNoteThree()->note_name;
	else
		a = a + getName();
	return a;
}
