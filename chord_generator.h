#pragma once
#include <string>
#include <vector>
#include "Chord.h"
using namespace std;
class Chord_Generator
{
private:
	Note * note_array;
	vector<Chord>* chords_we_have;
public:
	Chord_Generator();
	~Chord_Generator();
	Chord get_major_chord(string root_note);
	Chord get_minor_chord(string root_note);
	int check_existing_chord(string root_name);
	int search_note(string name);
};

