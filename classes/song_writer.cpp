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
	note_gen = new NoteGenerator();
	vector<Chord*> song();
	harmony  = vector<unsigned char>();
	melody   = vector<float>();
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
void SongWriter::printSong(bool displayNoteName)
{
	string** music_sheet = new string*[16*SONG_LENGTH/4];
	for (int i = 0; i < 16 * SONG_LENGTH / 4; i++) {
		music_sheet[i] = new string[69];
	}
	int chord_count = 0;
	for (int i = 0; i < 16 * SONG_LENGTH / 4; i++) {
		for (int j = 0; j < 69; j++) {
			if (i % 16 >= 4 && i % 16 <= 12) {
				if (i % 16 % 2 == 1) {
					if (j%17==0) {
						music_sheet[i][j] = "|";
					}
					else {
						music_sheet[i][j] = " ";
					}
				}
				else {
					if (j%17==0) {
						music_sheet[i][j] = "|";
					}
					else {
						music_sheet[i][j] = "-";
					}
				}
			}
			else {
				if (i % 16 == 0 && j%17==1) {
					string chord_name = Chord(*note_gen,harmony.at(chord_count)).getName();
					music_sheet[i][j+0] = chord_name.substr(0, 1);
					music_sheet[i][j+1] = chord_name.substr(1, 1);
					music_sheet[i][j+2] = chord_name.substr(2, 1);
					music_sheet[i][j+3] = chord_name.substr(3, 1);
					music_sheet[i][j+4] = chord_name.substr(4, 1);
					music_sheet[i][j+5] = chord_name.substr(5, 1);
					music_sheet[i][j+6] = chord_name.substr(6, 1);
					music_sheet[i][j+7] = chord_name.substr(7, 1);
					chord_count++;
				}
				else if (i % 16 == 15) {
					music_sheet[i][j] = "X";
				}
				else if (i % 16 == 0 && j % 17 >= 2 && j % 17 <= 8) {
					continue;
				}
				else {
					music_sheet[i][j] = " ";
				}
			}
		}
	}
	int line_count = 0;
	unsigned char note_count = 0;
	while (line_count < SONG_LENGTH / 4) {
		for (int x = 0; x < 69; x++) {
			string display = "";
			if (x % 17 == 0) {
				continue;
			}
			int note_position = 22 - melody_indexes.at(note_count);
			if (displayNoteName) {
				display = note_gen->getNoteName(melody_indexes.at(note_count)).substr(0, 1);
			}
			else {
				display = "0";
			}
			if (note_position == 2 || note_position == 14) {
				music_sheet[note_position + line_count * 16][x-1] = "-";
				music_sheet[note_position + line_count * 16][x] = display;
				music_sheet[note_position + line_count * 16][x+1] = "-";
			}
			else {
				music_sheet[note_position + line_count * 16][x] = display;
			}
			note_count++;
			x+=3;
		}
		line_count++;
	}
	for (int i = 0; i < 16 * SONG_LENGTH / 4; i++) {
		for (int j = 0; j < 69; j++) {
			cout << music_sheet[i][j];
		}
		cout << endl;
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

Chord* SongWriter::getChords() {
	Chord* harmony_chords=new Chord[SONG_LENGTH];

	for(int i = 0; i < SONG_LENGTH; i++) {
		harmony_chords[i] = Chord(*note_gen, harmony.at(i));
	}

	return harmony_chords;
}

bool SongWriter::isEmpty() {
	return harmony.size() == 0;
}