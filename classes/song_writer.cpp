#include "../headers/song_writer.h"
#include "../headers/note_generator.h"

#define Num_of_Progressions 4

/*Preset major chord progressions
*https://www.libertyparkmusic.com/common-chord-progressions/
*https://en.wikipedia.org/wiki/Chord_progression
*/
/*
These are the possible chord progressions we have in this program.
The numbers represent the position of the root note of each chord in out scale.
*/
int progressions[Num_of_Progressions][4] =
{
	{1,6,4,5},
	{1,5,6,4},
	{1,4,1,5},
	{1,4,5,1}
};


//Constructor
SongWriter::SongWriter()
{
	note_gen = new NoteGenerator;
	vector<Chord*> song();
	harmony = vector<unsigned char>();
	melody = vector<float>();
}

//Accessors
int SongWriter::getSongLength() {
	return SONG_LENGTH;
}

unsigned char* SongWriter::getHarmony()
{
	unsigned char* output = &harmony[0];
	return output;
}

float* SongWriter::getMelody()
{
	float* output = &melody[0];
	return output;
}

unsigned char* SongWriter::getMelodyIndexes() {
	unsigned char* output = &melody_indexes[0];
	return output;
}

//Mutators
//Can be modified to print more informations in a user-friendly way
void SongWriter::printSong()
{
	string melodyStr = "";
	string harmonyStr = "";
	for (int i = 0; i < melody.size(); i++) {
		if (i % 16 == 0&&i!=0) {
			cout << endl;
		}
		if (i % 4 == 0) {
			if (i != 0) {
				cout << endl;
			}
			cout << Chord(*note_gen,harmony.at(i/4)).getName() << endl;
			
		}
		cout << melody.at(i)<<" ";
	}
}

void SongWriter::clearSong()
{
	harmony = vector<unsigned char>();
	melody = vector<float>();
	melody_indexes = vector<unsigned char>();
}

void SongWriter::writeSong()
{
	//srand(time(0));
	harmony = vector<unsigned char>();
	melody = vector<float>();
	melody_indexes = vector<unsigned char>();
	for(int i = 0; i < (SONG_LENGTH/4); i++)
	{
		int r = rand() % Num_of_Progressions; //change the modulo returned
		for(int j = 0; j < 4; j++)
		{
			harmony.push_back(progressions[r][j]);
		}
	}
	for(int k = 0; k < NUM_MELODY_NOTES; k++ )
	{
		unsigned char new_index = this->note_gen->getRandomNote();
		melody.push_back(note_gen->getNote(new_index).note_frequency);
		melody_indexes.push_back(new_index);
	}

}

void SongWriter::setMelody(unsigned char* melodyArr)
{
	melody_indexes = vector<unsigned char>();
	melody = vector<float>();
	int length = sizeof(melodyArr) / sizeof(unsigned char);
	//use getNoteFreq to convert int representation of notes back to freq
	for (int i=0;i<length;i++)
	{
		melody_indexes.push_back(melodyArr[i]);
		float temp_note_freq = note_gen->getNoteFreq(melodyArr[i]);
		melody.push_back(temp_note_freq);
	}
}

void SongWriter::setHarmony(unsigned char* harmonyArr)
{
	harmony = vector<unsigned char>();
	int length = sizeof(harmonyArr) / sizeof(unsigned char);
	for (int i = 0; i < length; i++)
	{
		harmony.push_back(harmonyArr[i]);
	}
}
