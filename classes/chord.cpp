#include "chord.h"

//Constructor
Chord :: Chord(std::string name, std::string note_one, std::string note_two, std::string note_three) {
	this->note_generator = new NoteGenerator();

	this->name       = name;
	this->note_one   = setNote(note_one);
	this->note_two   = setNote(note_two);
	this->note_three = setNote(note_three);
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

Note Chord::setNote(std::string note_name) {
	return note_gernerator->getNote(note_name);
}

