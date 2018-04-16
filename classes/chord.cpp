#include "../headers/chord.h"
#include <stdexcept>

//Constructor for triads
Chord :: Chord(std::string name, Note note_one, Note note_two, Note note_three) {
//	this->note_generator = new NoteGenerator();

	this->name = name;
	this->chord.push_back(note_one);
	this->chord.push_back(note_two);
	this->chord.push_back(note_three);
}

//Accessors
std::string Chord::getName() {
	return name;
}

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
