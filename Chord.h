#ifndef CHORD_H
#define CHORD_H
#include "Note_Generator.h"

//this is a test
 
class Chord {
public:
	Chord(std::string note_name1, std::string note_name2, std::string note_name3) {
		n1 = note_name1;
		n2 = note_name2;
		n3 = note_name3;
	}

	Chord(bool major, std::string base_note) {

	}

	void Chord::set_note_one(std::string note_name);
	void Chord::set_note_two(std::string note_name);
	void Chord::set_note_three(std::string note_name);

	Chord::get_note_one();
	Chord::get_note_two();
	Chord::get_note_three();

private:
	Note n1;
	Note n2;
	Note n3;
};
#endif

