#pragma once

#include "chord.h"
#include "chord_generator.h"
#include "note_generator.h"

/******************************************************************
*							Regarding Songs					      *
*			Are we going to be able to store the songs in         *
*           maps? Can maps have muliple values for keys?          *
*		    Currently we have a vector to store chords, 		  *
*           but we don't have anything for duration.              *
*******************************************************************/

class SongWriter {
public:
	//Constructor
	SongWriter(int tempo, std::string mood);

	//Accessors
	int					getTempo();
	std::string			getMood();
	Chord				getChord(int index);
	int					findChord(string chord_name);
	std::vector<Chord>	getSong();

	//Mutators
	note melodyGenerator (note melody_line[], int melody_array_size);
	void setTempo(int tempo);
	void setMood(std::string);
	void addChord(Chord new_chord);
	void removeChord(int index);
	void printSong();
	void clearSong();

private:
	int tempo;
	//int duration;
	std::string mood;
	std::vector<Chord> current_song;
	ChordGenerator myChords; //NEW* 4/2/18 - Jared L.
};
