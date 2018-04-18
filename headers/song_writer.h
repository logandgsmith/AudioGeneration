#pragma once

#include "chord.h"
#include "chord_generator.h"
#include "note_generator.h"
#include <cstdlib>

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
	SongWriter(int tempo, int num_measures, std::string mood);

	//Accessors
	int					getTempo();
	std::string			getMood();
	Chord				getChord(int index);
	int					findChord(string chord_name);
	std::vector<Chord*[4]>	getSong();

	//Mutators
	void               setTempo(int tempo);
	void               setNumMeasures(int num_measures);
	void               setMood(std::string mood);
	void               addChord(Chord new_chord);
	void               removeChord(int index);
	void			   generateSong();
	void               printSong();
	void               clearSong();

private:
	NoteGenerator*     note_gen;
	int                tempo;
	int                num_measures;
	std::string        mood;
	std::vector<Chord*[4]> song;
	ChordGenerator*     myChords; //NEW* 4/2/18 - Jared L.
};
