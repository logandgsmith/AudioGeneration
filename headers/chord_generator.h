#pragma once
#include <string>
#include <vector>
#include "chord.h"
#include "note_generator.h"

using namespace std;
class chord_generator
{

public:
	//Constructor
	chord_generator();

	//Accessors
	chord* get_major_chord(string root_note);
	chord* get_minor_chord(string root_note);

	//other methods
	int check_existing_chord(string root_name);	//return the index of the chord in the existing chord* vector. If not found, return -1.
	int search_note(string name);				//return the index of the note in the note array (length 12), if no such note, return -1

private:
	note * note_array;
	vector<chord*>* chords_we_have;
};

