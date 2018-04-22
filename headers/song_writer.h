#pragma once

#include "chord.h"
#include "note_generator.h"
#include <cstdlib>
#include <ctime>
#include <array>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class SongWriter
{
public:
	//Constructor
	SongWriter();

	//Accessors
	int            getSongLength();
	unsigned char* getHarmony();
	float*         getMelody(); //gets compatible melody notes with chords in a progression
	unsigned char* getMelodyIndexes();
	Chord*         getChords();
	bool		   isEmpty();

	//Mutators
	void           clearSong();
	void           writeSong();
	void           setMelody(unsigned char* melodyArr);
	void           setHarmony(unsigned char* harmonyArr);
	void           printSong(bool displayNoteName);

private:
	const int      SONG_LENGTH = 16; //# of chords / num_measures
	const int      NUM_MELODY_NOTES = 4 * SONG_LENGTH;
	NoteGenerator* note_gen;
	std::vector<unsigned char> harmony;
	std::vector<float> melody;
	std::vector<unsigned char> melody_indexes;
};
