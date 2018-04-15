#include "../headers/chord.h"

//Constructor
Chord :: Chord(std::string name, Note* note_one, Note* note_two, Note* note_three) {
	this->note_generator = new NoteGenerator();

	this->name       = name;
	this->note_one   = note_one;
	this->note_two   = note_two;
	this->note_three = note_three;
}

//Accessors
Note* Chord::getNoteOne() {
	return this->note_one;
}

Note* Chord::getNoteTwo() {
	return this->note_two;
}

Note* Chord::getNoteThree() {
	return this->note_three;
}

