#pragma once

#include "chord.h"
#include "chord_generator.h"
#include "note_generator.h"
#include <cstdlib>
#include <ctime>
#include <array>


struct selectedChord {
	int index;
	bool major;
	selectedChord(int a, bool b){
		index=a;
		major=b;
	}
};

class SongWriter
{
public:
	//Constructor
	SongWriter(int tempo, int num_measures);

	//Accessors
	int		         getTempo();
	Chord	         getChord(int index);
	int			     findChord(string chord_name);
	std::vector<Chord*[4]> getSong();
	int*             getHarmony();
	float*           getMelody(); //gets compatible melody notes with chords in a progression

	//Mutators
	void             setTempo(int tempo);
	void             setNumMeasures(int num_measures);
	void             addChord(Chord new_chord);
	void             removeChord(int index);
	void    	     generateSong();
	void             printSong();
	void             clearSong();
	void             writeSong();

private:
	const int        SONG_LENGTH = 16; //# of chords / num_measures
	const int        NUM_MELODY_NOTES = 4 * SONG_LENGTH;
	NoteGenerator*   note_gen;
	int              tempo;
	int              num_measures;
	std::vector<Chord*[4]> song; //create song_harmony & song_melody vectors?
	//std::vector<Note> song_melody; //store all notes in a melody vector
	//Note[8]             melody; //stores 8 notes compatible with at least 2 chords; 8 melody half-notes per progression
	ChordGenerator*  myChords; //NEW* 4/2/18 - Jared L.
	std::vector<int> harmony;
  std::vector<float> melody;
};
