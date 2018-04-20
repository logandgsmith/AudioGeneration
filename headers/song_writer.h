#pragma once

#include "chord.h"
#include "note_generator.h"
#include <cstdlib>
#include <ctime>
#include <array>
#include <iostream>


class SongWriter
{
public:
	//Constructor
	SongWriter();

	//Accessors
	unsigned char       getHarmony();
	float           getMelody(); //gets compatible melody notes with chords in a progression

	//Mutators
	void             clearSong();
	void             writeSong();
	void 			setMelody(unsigned char* melodyArr);
	void 			setHarmony(unsigned char* harmonyArr);
	void             printSong();

private:
	const int        SONG_LENGTH = 16; //# of chords / num_measures
	const int        NUM_MELODY_NOTES = 4 * SONG_LENGTH;
	NoteGenerator*   note_gen;
	std::vector<unsigned char> harmony;
  std::vector<float> melody;
};
