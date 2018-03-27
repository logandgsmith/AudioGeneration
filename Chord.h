#ifndef CHORD_H
#define CHORD_H
#include "Note_Generator.h"

//this is a test
 
class Chord {
public:
	Chord(std::string note_one, std::string note_two, std::string note_three) {
		this-> note_one = note_one;
	    this-> note_two = note_two;
		this-> note_three = note_three;
	}

	void Chord::set_note_one(std::string note_name);
	void Chord::set_note_two(std::string note_name);
	void Chord::set_note_three(std::string note_name);

	Chord::get_note_one();
	Chord::get_note_two();
	Chord::get_note_three();

private:
	Note note_one;
	Note note_two;
	Note note_three;
};
#endif