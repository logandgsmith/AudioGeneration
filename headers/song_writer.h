#pragma once

#include "chord.h"
#include "chord_generator.h"
#include "note_generator.h"
#include <cstdlib>
#include <ctime>
#include <array>


class SongWriter
{
public:
	//Constructor
	SongWriter(int tempo, int num_measures);

	//Accessors
	int		         	 getTempo();
	int*             getHarmony();
	float*           getMelody(); //gets compatible melody notes with chords in a progression

	//Mutators
	void             setTempo(int tempo);
	void             setNumMeasures(int num_measures);
	void             printSong();
	void             clearSong();
	void             writeSong();
	void 						 setMelody(int[] melodyArr);
	void 						 setHarmony(int[] harmonyArr);

private:
	const int        SONG_LENGTH = 16; //# of chords / num_measures
	const int        NUM_MELODY_NOTES = 4 * SONG_LENGTH;
	NoteGenerator*   note_gen;
	int              tempo;
	int              num_measures;
	std::vector<int> harmony;
  std::vector<float> melody;
};
