#include "../headers/song_writer.h"
#include "../headers/note_generator.h"

//Constructor
SongWriter::SongWriter(int tempo, int num_measures, std::string mood) 
{
	SongWriter::setTempo(tempo);
	SongWriter::setNumMeasures(num_measures);
	SongWriter::setMood(mood);
	
	this->note_gen = new NoteGenerator;
}

//Accessors
int SongWriter::getTempo() 
{
	return this->tempo;
}

std::string SongWriter::getMood() 
{
	return this->mood;
}

Chord SongWriter::getChord(int index) 
{
	//return specified Chord
}

std::vector<Chord> SongWriter::getSong() 
{
	return this->song;
}


//Mutators
void SongWriter::setTempo(int tempo) 
{
	this->tempo = tempo;
}

void SongWriter::setNumMeasures(int num_measures) 
{
	this->num_measures = num_measures;
}

void SongWriter::setMood(std::string mood) 
{
	this->mood  = mood;
}

void SongWriter::addChord(Chord new_chord) 
{
  
	//Adds a new Chord to the end of the song vector
}

void SongWriter::removeChord(int index) 
{
	//Deletes the indexed Chord
}

std::vector<Chord> SongWriter::generateSong()
{
	// Measures are assumed to be in common time (4/4)
	int max_num_quarter_notes = 4 * num_measures;
	std::vector<Note> melody;
	for(int i = 0; i < max_num_quarter_notes; )
	{
		Note new_note = this->note_gen->getRandomNote(true); // Will be in the major key
		melody.push_back(new_note);
		i += new_note.note_duration;
	}
	
	std::vector<Chord> new_song;
	
	return new_song;
}

void SongWriter::printSong() 
{
	//Should display the notes of the song on the console and
	//get the user to name the song
}

void SongWriter::clearSong() 
{
	this->song.clear();
	this->song = SongWriter::generateSong(); //initialize new song
}
