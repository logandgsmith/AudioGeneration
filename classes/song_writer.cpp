#include "song_writer.h"

//Constructor
SongWriter :: SongWriter(int tempo, std::string mood) {
	this->tempo = tempo;
	this->mood  = mood;
	this->song  = //vector initialization;
}

//Accessors
int SongWriter::getTempo() {
	return this->tempo;
}

std::string SongWriter::getMood() {
	return this->mood;
}

Chord SongWriter::getChord(int index) {
	return myChords[index];
}

int SongWriter::findChord(chord_name){
	return myChords.checkExistingChord(chord_name);
}

std::vector<Chord> SongWriter::getSong() {
	return this->song;
}


//Mutators
void SongWriter::setTempo(int tempo) {
	this->tempo = tempo;
}

void SongWriter::setMood(std::string) {
	this->mood  = mood;
}

void SongWriter::addChord(Chord new_chord) {
	if (findChord(new_chord.name) != -1)
	{
			myChords.push_back(new_chord);
	}
}

void SongWriter::removeChord(int index) {
	//Deletes the indexed Chord
}

void SongWriter::printSong() {
	//Should display the notes of the song on the console and
	//get the user to name the song
}

void SongWriter::clearSong() {
	delete this->song;
	this->song -> //initialize new song
}
