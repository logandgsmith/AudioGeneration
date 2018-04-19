#include "../headers/song_writer.h"
#include "../headers/note_generator.h"

const selectedChord progression1[4] = { selectedChord(0,true), selectedChord(9,false), selectedChord(5,true), selectedChord(7,true) };
const selectedChord progression2[4] = { selectedChord(0,true), selectedChord(7,true), selectedChord(9,false), selectedChord(5,true) };

//Constructor
SongWriter::SongWriter(int tempo, int num_measures, std::string mood) 
{
	SongWriter::setTempo(tempo);
	SongWriter::setNumMeasures(num_measures);
	SongWriter::setMood(mood);
	myChords = new ChordGenerator;
	note_gen = new NoteGenerator;
	vector<Chord*> song();
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

std::vector<Chord*[4]> SongWriter::getSong() 
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
	this->mood = mood;
}

void SongWriter::addChord(Chord new_chord) 
{
  
	//Adds a new Chord to the end of the song vector
}

void SongWriter::removeChord(int index) 
{
	//Deletes the indexed Chord
}

void SongWriter::generateSong()
{
	/*
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
	*/
	Chord* progA[4];
	Chord* progB[4];
	int randNum = 0;
	//generate progressions
	for (int i = 0; i < 4; i++) {
		Chord* in = NULL;
		if (progression1[i].major) {
			in = myChords->getMajorTriadChord(note_gen->getNoteName(progression1[i].index));
		}
		else {
			in = myChords->getMinorTriadChord(note_gen->getNoteName(progression1[i].index));
		}
		progA[i] = in;
	}
	for (int i = 0; i < 4; i++) {
		Chord* in = NULL;
		if (progression2[i].major) {
			in = myChords->getMajorTriadChord(note_gen->getNoteName(progression2[i].index));
		}
		else {
			in = myChords->getMinorTriadChord(note_gen->getNoteName(progression2[i].index));
		}
		progB[i] = in;
	}
	//one chord per measure (4 measures per progression)
	for (int i = 0; i < num_measures; i+=4) {
		randNum = rand() % 2;
		randNum == 0 ? song.push_back(progA) : song.push_back(progB);
	}
}

void SongWriter::printSong() 
{	
	song current_song = getSong();

	for(int i = 0; i < current_song.size(); i++){
		for (int j = 0; j < current_song.at(i).size(); j++){

			//cout << current_song.
			// we need to complete getChord



			//not sure if this will work as intendend...
		}
	}

	//if (current_song!= NULL){


	//Should display the notes of the song on the console and
}

void SongWriter::clearSong() 
{
	this->song.clear();
	//generateSong(); //initialize new song
}
