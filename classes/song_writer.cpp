#include "../headers/song_writer.h"
#include "../headers/note_generator.h"

#define Num_of_Progressions 4

/*Preset major chord progressions
*https://www.libertyparkmusic.com/common-chord-progressions/
*https://en.wikipedia.org/wiki/Chord_progression
*/

int progressions[Num_of_Progressions][4] =
{
	{1,6,4,5},
	{1,5,6,4},
	{1,4,1,5},
	{1,4,5,1}
};


//Constructor
SongWriter::SongWriter(int tempo, int num_measures)
{
	SongWriter::setTempo(tempo);
	SongWriter::setNumMeasures(num_measures);
	myChords = new ChordGenerator;
	note_gen = new NoteGenerator;
	vector<Chord*> song();
}

//Accessors
int SongWriter::getTempo()
{
	return this->tempo;
}

int* SongWriter::getHarmony()
{
	int* output = &harmony[0];
	return output;
}

float* SongWriter::getMelody()
{
	float* output = &melody[0];
	return output;
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

void SongWriter::printSong()
{
	//Should display the notes of the song on the console and
	//get the user to name the song
}

void SongWriter::clearSong()
{
	//this->song.clear();
	melody.clear();
	harmony.clear();

}

void SongWriter::writeSong()
{
	//srand(time(0));

	for(int i = 0; i < (SONG_LENGTH/4); i++)
	{
		int r = rand() % progressions.size(); //change the modulo returned
		for(int j = 0; j < 4; j++)
		{
			harmony.push_back(progressions[r][j]);
		}
	}
	for(int k = 0; k < NUM_MELODY_NOTES; k++ )
	{
		Note new_note = this->note_gen->getRandomNote(true);
		melody.push_back(new_note);
	}

}

void SongWriter::setMelody(int[] melodyArr)
{
	melody.clear();

	for (int i = 0; i < melodyArr.size(); i++)
	{
		float temp_note_freq = getNoteFreq(melodyArr[i]);
		melody.push_back(temp_note_freq);
	}
}

void SongWriter::setHarmony(int[] harmonyArr)
{
	harmony.clear();

	//use getNoteFreq to convert int representation of notes back to freq
	for (int i = 0; i < harmonyArr.size(); i++)
	{
		harmony.push_back(harmonyArr[i]);
	}
}
