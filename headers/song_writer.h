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

class SongWriter 
{
public:
	//Constructor
	SongWriter(int tempo, int num_measures, std::string mood);

	//Accessors
	int					getTempo();
	std::string			getMood();
	Chord				getChord(int index);
	int					findChord(string chord_name);
	std::vector<Chord>	getSong();

	//Mutators
	void setTempo(int tempo);
	void setNumMeasures(int num_measures);
	void setMood(std::string mood);
	void addChord(Chord new_chord);
	void removeChord(int index);
	std::vector<Chord> generateSong();
	void printSong();
	void clearSong();

private:
	NoteGenerator * note_gen;
	int tempo;
	int num_measures;
	std::string mood;
	std::vector<Chord> song;
	ChordGenerator myChords; //NEW* 4/2/18 - Jared L.
};
