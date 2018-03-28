#include "chord.h"

//Constructor
Chord :: Chord(std::string name, std::string note_one, std::string note_two, std::string note_three) {
	this->name       = name;
	this->note_one   = note_one;
	this->note_two   = note_two;
	this->note_three = note_three;
}

//Destructor
Chord :: ~Chord() {
	//FILL IN
}

std::string Chord::get_note_one() {
	return this->note_one;
}

std::string Chord::get_note_two() {
	return this->note_two;
}

std::string Chord::get_note_three() {
	return this->note_three;
}
