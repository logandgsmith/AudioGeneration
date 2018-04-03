#include "chord.h"

//Constructor
Chord :: Chord(std::string name, std::string note_one, std::string note_two, std::string note_three) {
	this->note_gernerator = new NoteGenerator();

	this->name       = name;
	this->note_one   = setNote(note_one);
	this->note_two   = setNote(note_two);
	this->note_three = setNote(note_three);
}

//Accessors
std::string Chord::get_note_one() {
	return this->note_one;
}

std::string Chord::get_note_two() {
	return this->note_two;
}

std::string Chord::get_note_three() {
	return this->note_three;
}

Note Chord::setNote(std::string note_name) {
	return note_generator->getNote(note_name);
}
