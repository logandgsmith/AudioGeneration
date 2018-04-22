#include "../headers/song_writer.h"
#include "../headers/note_generator.h"

#define Num_of_Progressions 4

/**************************************************
This class definds a SongWriter object. The song
writer can generate songs in two ways:
1. Generate song using available chords,
pre-defined popular chord progressions, and
available notes.
2. Generate song when given two unsigned char
arrays, one for harmony (series of chords) and
the other for melody (series of notes). The
two arrays will be passed in by the userInput
class when it load song from a text file.
***************************************************/

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
	{ 1,6,4,5 },
{ 1,5,6,4 },
{ 1,4,1,5 },
{ 1,4,5,1 }
};


//Constructor
/*
Initialize the song writer with the necessary components.
harmony: series of chords
melody: series of note frequencies
melody_indexes: series of notes
*/
SongWriter::SongWriter()
{
	note_gen = new NoteGenerator();
	harmony = vector<unsigned char>();
	melody = vector<float>();
	melody_indexes = vector<unsigned char>();
}

//Accessors
/*
Return the length of the song.

The length is a pre-defined const that equals
the number of measures in the song. Since
our song has one chord for each measure, the
song length is also the number of chords in our song.
*/
int SongWriter::getSongLength()
{
	return SONG_LENGTH;
}

/*
Convert harmony vector to an unsigned char array
and return the array.

The harmony vector contains the indexes of the root
notes of the chord. These indexes, combined with the
note generator and the chord constructor, help the
program generate the corresponding chords.
*/
unsigned char* SongWriter::getHarmony()
{
	unsigned char* output = &harmony[0];
	return output;
}

/*
Convert melody vector to an float array
and return the array.

The melody vector contains the frequencies
of the corresponding notes. The audio
generation class will need these frequencies
to generate sounds.
*/
float* SongWriter::getMelody()
{
	float* output = &melody[0];
	return output;
}

/*
Convert melody_indexes vector to an unsigned
char array and return the array.

The melody_indexes vector contains the indexes of the
corresponding notes. These indexes, combined with the
note generator, help the program generate
the corresponding notes.
*/
unsigned char* SongWriter::getMelodyIndexes()
{
	unsigned char* output = &melody_indexes[0];
	return output;
}

//Mutators
/*
Print the song in the form of a music sheet.
If the parameter "displayNoteName" is true, this
method will print the notes on the music sheet with
their names. If the parameter is false, the note
names will be replaced by "0"s.

The printed music sheet will have 4 measures in each line.
The number of lines depends on the length of the song.
Each measure can hold four notes with a frequency range
of two octaves. The note names on each music line depends
on the base note defined in the note generator class.

On top of each measure, the corresponding chord names are
also displayed. Each line will be separated by a line of
"XXXX...", so the user will not mix two measures that
are vertically adjacent to each other.

Example:
C3_Chord         G3_Chord         A3_Chord         F3_Chord
B   B            B
-A-      -A-
G
|----------------|----------------|----------------|----------------|
|                |                |                |                |
|----------------|----------------|----------------|----------------|
|                |        C       |        C       |                |
|----------------|----B-----------|----------------|----------------|
|                |            A   |                |                |
|----------------|----------------|----------------|------------G---|
|F               |                |                |                |
|----E-----------|----------------|----------------|----------------|
D
-C-                                        -C-
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
NEXT line...
*/
void SongWriter::printSong(bool displayNoteName)
{
	//Initialize a 2D array that represents the music sheet
	string** music_sheet = new string*[16 * SONG_LENGTH / 4];
	for (int i = 0; i < 16 * SONG_LENGTH / 4; i++)
	{
		music_sheet[i] = new string[69];
	}

	/*
	Set up the outline of the music sheet.

	Each line has four measures, each measure is consist of
	the chord name, the music staff, two extra lines below the
	main music staff (for low C and low B) and 3 extra lines above
	the main music staff (for high G, high A, and high B).
	Different measures are separated by verticle arrangement of "|"s.
	Different lines are separated ny horicontal arrangement of "X"s.
	*/
	int chord_count = 0;
	for (int i = 0; i < 16 * SONG_LENGTH / 4; i++)
	{
		for (int j = 0; j < 69; j++) {
			if (i % 16 >= 4 && i % 16 <= 12)
			{
				if (i % 16 % 2 == 1)
				{
					if (j % 17 == 0)
					{
						music_sheet[i][j] = "|";
					}
					else
					{
						music_sheet[i][j] = " ";
					}
				}
				else
				{
					if (j % 17 == 0)
					{
						music_sheet[i][j] = "|";
					}
					else
					{
						music_sheet[i][j] = "-";
					}
				}
			}
			else
			{
				if (i % 16 == 0 && j % 17 == 1)
				{
					string chord_name = Chord(*note_gen, harmony.at(chord_count)).getName();
					music_sheet[i][j + 0] = chord_name.substr(0, 1);
					music_sheet[i][j + 1] = chord_name.substr(1, 1);
					music_sheet[i][j + 2] = chord_name.substr(2, 1);
					music_sheet[i][j + 3] = chord_name.substr(3, 1);
					music_sheet[i][j + 4] = chord_name.substr(4, 1);
					music_sheet[i][j + 5] = chord_name.substr(5, 1);
					music_sheet[i][j + 6] = chord_name.substr(6, 1);
					music_sheet[i][j + 7] = chord_name.substr(7, 1);
					chord_count++;
				}
				else if (i % 16 == 15)
				{
					music_sheet[i][j] = "X";
				}
				else if (i % 16 == 0 && j % 17 >= 2 && j % 17 <= 8)
				{
					continue;
				}
				else
				{
					music_sheet[i][j] = " ";
				}
			}
		}
	}

	/*
	Add melody notes to the correct position in the music sheet.

	Each measure has 16 spaces for melody notes. Since we have 4
	notes in each measure, they will be positioned in the space 1,
	5, 9, and 13.
	If the note is not in the main staff but need a line across it,
	it will be represented by "-0-" or "-note name-" depending on
	the mode (parameter).
	*/
	int line_count = 0;
	unsigned char note_count = 0;
	while (line_count < SONG_LENGTH / 4)
	{
		for (int x = 0; x < 69; x++)
		{
			string display = "";
			if (x % 17 == 0)
			{
				continue;
			}
			int note_position = 22 - melody_indexes.at(note_count);
			if (displayNoteName)
			{
				display = note_gen->getNoteName(melody_indexes.at(note_count)).substr(0, 1);
			}
			else
			{
				display = "0";
			}
			if (note_position == 2 || note_position == 14)
			{
				music_sheet[note_position + line_count * 16][x - 1] = "-";
				music_sheet[note_position + line_count * 16][x] = display;
				music_sheet[note_position + line_count * 16][x + 1] = "-";
			}
			else
			{
				music_sheet[note_position + line_count * 16][x] = display;
			}
			note_count++;
			x += 3;
		}
		line_count++;
	}
	for (int i = 0; i < 16 * SONG_LENGTH / 4; i++)
	{
		for (int j = 0; j < 69; j++)
		{
			cout << music_sheet[i][j];
		}
		cout << endl;
	}
}

/*
Display a piano keyboard with playing keys black out.
Input playing keys:
1. one unsigned char for the root note of a 3-note major scale chord
2. one unsigned char for the extra melody note that plays with the keyboard
*/
void SongWriter::printKeyboard(unsigned char chord_index,
	unsigned char note_index)
{
	/*
	Keyboard height, white key width, black key width, and
	black key height can be adjusted based on the shape of
	keyboard you want.

	The width and height DO NOT contain the edge of each key
	and the edge of the keyboard.
	*/
	int keyboard_height = 10;
	int white_key_width = 5;
	int black_key_width = 3;
	int black_key_height = 5;

	//the full keyboard including the sharps
	vector<Note> full_keyboard = note_gen->getKeyboard();

	/*
	Initialize the keyboard_image 2D string array based on the
	keyboard_height, white_key_width, black_key_width, and
	black_key_height specified above.
	*/
	string** keyboard_image = new string*[keyboard_height + 3];
	int num_major_notes = note_gen->getMajorKeyboardSize();
	int keyboard_width = num_major_notes * (white_key_width + 1) + 1;
	for (int i = 0; i < keyboard_height + 2; i++)
	{
		keyboard_image[i] = new string[keyboard_width];
	}

	/*
	Draw the boarders and all the basic elements, like the
	black and white keys, key names.
	*/
	unsigned char sharp_count = 1;
	unsigned char note_count = 1;
	for (int i = 0; i < keyboard_height + 2; i++)
	{
		for (int j = 0; j < keyboard_width; j++)
		{
			int normal_j = j % ((white_key_width + 1) * 7);
			//top boarder of the keyboard
			if (i == 0)
			{
				keyboard_image[i][j] = "-";

			}
			/*
			The verticle range of the keyboard that has black keys.
			This range has C-C#-D-D#-E-F-F#-G-G#-A-A#-B. A boarder
			will be placed on all the sharp notes.
			*/
			else if (i >= 1 && i <= black_key_height + 1)
			{
				//fill boarder with "|"
				if ((//the boarders of the white keys
					 //between B and C, between E and F
					normal_j == 0 ||
					normal_j == (white_key_width + 1) * 3 ||

					//the boarder of the first 2 black keys
					//C# and D#
					normal_j == (white_key_width + 1) * 1 - (black_key_width / 2 + 1) ||
					normal_j == (white_key_width + 1) * 1 + (black_key_width / 2 + 1) ||
					normal_j == (white_key_width + 1) * 2 - (black_key_width / 2 + 1) ||
					normal_j == (white_key_width + 1) * 2 + (black_key_width / 2 + 1) ||

					//the boarder of the next 3 black keys
					//F#, G#, and A#
					normal_j == (white_key_width + 1) * 4 - (black_key_width / 2 + 1) ||
					normal_j == (white_key_width + 1) * 4 + (black_key_width / 2 + 1) ||
					normal_j == (white_key_width + 1) * 5 - (black_key_width / 2 + 1) ||
					normal_j == (white_key_width + 1) * 5 + (black_key_width / 2 + 1) ||
					normal_j == (white_key_width + 1) * 6 - (black_key_width / 2 + 1) ||
					normal_j == (white_key_width + 1) * 6 + (black_key_width / 2 + 1)) &&

					//excludes the lower boarder of the black key
					i != black_key_height + 1)
				{
					keyboard_image[i][j] = "|";
				}
				else
				{
					/*
					Top portion of the black keys (excluding the last
					line of the black key that will be used to write
					name and the bottom boarder of the black keys)
					*/
					if (i >= 1 && i <= black_key_height - 1)
					{
						keyboard_image[i][j] = " ";
					}
					/*
					The last line of the region inside the black key.
					This line will contain the name of the black key.
					*/
					else if (i == black_key_height)
					{
						/*
						Print the key name of the black keys when j
						is inside the black keys
						*/
						if (normal_j == (white_key_width + 1) * 1 - 1 ||
							normal_j == (white_key_width + 1) * 2 - 1 ||
							normal_j == (white_key_width + 1) * 4 - 1 ||
							normal_j == (white_key_width + 1) * 5 - 1 ||
							normal_j == (white_key_width + 1) * 6 - 1)
						{
							string note_name = note_gen->getSharpNote(sharp_count).note_name;
							keyboard_image[i][j + 0] = note_name.substr(0, 1);
							keyboard_image[i][j + 1] = note_name.substr(1, 1);
							keyboard_image[i][j + 2] = note_name.substr(2, 1);
							sharp_count++;
						}
						//skip the place with printed names
						else if (normal_j == (white_key_width + 1) * 1 ||
							normal_j == (white_key_width + 1) * 2 ||
							normal_j == (white_key_width + 1) * 4 ||
							normal_j == (white_key_width + 1) * 5 ||
							normal_j == (white_key_width + 1) * 6 ||
							normal_j == (white_key_width + 1) * 1 + 1 ||
							normal_j == (white_key_width + 1) * 2 + 1 ||
							normal_j == (white_key_width + 1) * 4 + 1 ||
							normal_j == (white_key_width + 1) * 5 + 1 ||
							normal_j == (white_key_width + 1) * 6 + 1)
						{
							continue;
						}
						//put white space in the remaining parts
						else {
							if (normal_j == 0 || normal_j == (white_key_width + 1) * 3)
							{
								keyboard_image[i][j] = "|";
							}
							else
							{
								keyboard_image[i][j] = " ";
							}
						}
					}
					//the bottom boarder of the black keys
					else
					{
						if (normal_j == (white_key_width + 1) * 1 - 2 ||
							normal_j == (white_key_width + 1) * 2 - 2 ||
							normal_j == (white_key_width + 1) * 4 - 2 ||
							normal_j == (white_key_width + 1) * 5 - 2 ||
							normal_j == (white_key_width + 1) * 6 - 2)
						{
							keyboard_image[i][j + 0] = "-";
							keyboard_image[i][j + 1] = "-";
							keyboard_image[i][j + 2] = "-";
							keyboard_image[i][j + 3] = "-";
							keyboard_image[i][j + 4] = "-";
							j += 4;
						}
						//put white space in the remaining parts
						else {
							if (normal_j == 0 || normal_j == (white_key_width + 1) * 3)
							{
								keyboard_image[i][j] = "|";
							}
							else
							{
								keyboard_image[i][j] = " ";
							}
						}
					}
				}
			}
			/*
			The verticle range of the keyboard that has ONLY white keys.
			This range has C-D-E-F-G-A-B. A boarder will be placed on
			all the white keys.
			*/
			else if (i >= black_key_height + 2 && i <= keyboard_height)
			{
				//draw boarder
				if (normal_j % (white_key_width + 1) == 0)
				{
					keyboard_image[i][j] = "|";
				}
				//put white space when not the last line of the white key
				else if (i >= black_key_height + 2 && i <= keyboard_height - 1)
				{
					keyboard_image[i][j] = " ";
				}
				//the last line of the white key, put name
				else
				{
					if (normal_j % (white_key_width + 1) == (white_key_width + 1) / 2 - 1)
					{
						string note_name = note_gen->getNote(note_count).note_name;
						keyboard_image[i][j] = note_name.substr(0, 1);
						keyboard_image[i][j + 1] = " ";
						keyboard_image[i][j + 2] = note_name.substr(1, 1);
						j += 2;
						note_count++;
					}
					else
					{
						keyboard_image[i][j] = " ";
					}
				}
			}
			/*
			The last line of the keyboard image, all "-"s
			*/
			else {
				keyboard_image[i][j] = "-";
			}
		}
	}

	//convert notes inside the chord to the index on the keyboard
	Chord chord = Chord(*note_gen, chord_index);
	int chord_note_1_index = note_gen->getNoteIndex(chord.getNote(0).note_name);
	int chord_note_2_index = note_gen->getNoteIndex(chord.getNote(1).note_name);
	int chord_note_3_index = note_gen->getNoteIndex(chord.getNote(2).note_name);

	//convert the input note index to the index on the keyboard
	int keyboard_note_index = note_gen->getNoteIndex(note_gen->getNote(note_index).note_name);

	//mark which keys are being plyed
	int* playing_indicator = new int[4]();
	playing_indicator[0] = chord_note_1_index;
	playing_indicator[1] = chord_note_2_index;
	playing_indicator[2] = chord_note_3_index;
	playing_indicator[3] = keyboard_note_index;

	for (int k = 0; k < 4; k++)
	{
		int curr_index = playing_indicator[k];
		int shape_choice = 0;
		int start_j = 0;
		int multiple = (curr_index) / 12;
		int normal_index = curr_index % 12;

		/*
		Determine the shape of the key being played. There are 4
		different kinds of shaped on the piano keyboard:

		Shape 1:
		-----
		|   |
		|   |
		|   |
		|   |
		|   |
		|   ---
		|     |
		|     |
		|     |
		| C 3 |
		-------

		Shape 2:
		---
		| |
		| |
		| |
		| |
		| |
		--- ---
		|     |
		|     |
		|     |
		| D 3 |
		-------

		Shape 3:
		-----
		|   |
		|   |
		|   |
		|   |
		|   |
		---   |
		|     |
		|     |
		|     |
		| E 3 |
		-------

		Shape 4:
		-----
		|   |
		|   |
		|   |
		|   |
		|C#3|
		-----
		*/
		switch (normal_index)
		{
		case 0:
			shape_choice = 1;
			start_j = 1 + (white_key_width + 1) * 7 * multiple;
			break;
		case 1:
			shape_choice = 4;
			start_j = white_key_width + 1 - black_key_width / 2 + (white_key_width + 1) * 7 * multiple;
			break;
		case 2:
			shape_choice = 2;
			start_j = white_key_width + 2 + (white_key_width + 1) * 7 * multiple;
			break;
		case 3:
			shape_choice = 4;
			start_j = (white_key_width + 1) * 2 - black_key_width / 2 + (white_key_width + 1) * 7 * multiple;
			break;
		case 4:
			shape_choice = 3;
			start_j = (white_key_width + 1) * 2 + 1 + (white_key_width + 1) * 7 * multiple;
			break;
		case 5:
			shape_choice = 1;
			start_j = (white_key_width + 1) * 3 + 1 + (white_key_width + 1) * 7 * multiple;
			break;
		case 6:
			shape_choice = 4;
			start_j = (white_key_width + 1) * 4 - black_key_width / 2 + (white_key_width + 1) * 7 * multiple;
			break;
		case 7:
			shape_choice = 2;
			start_j = (white_key_width + 1) * 4 + 1 + (white_key_width + 1) * 7 * multiple;
			break;
		case 8:
			shape_choice = 4;
			start_j = (white_key_width + 1) * 5 - black_key_width / 2 + (white_key_width + 1) * 7 * multiple;
			break;
		case 9:
			shape_choice = 2;
			start_j = (white_key_width + 1) * 5 + 1 + (white_key_width + 1) * 7 * multiple;
			break;
		case 10:
			shape_choice = 4;
			start_j = (white_key_width + 1) * 6 - black_key_width / 2 + (white_key_width + 1) * 7 * multiple;
			break;
		case 11:
			shape_choice = 3;
			start_j = (white_key_width + 1) * 6 + 1 + (white_key_width + 1) * 7 * multiple;
			break;
		}

		/*
		Black out the playing keys with "X"s based on their shape and starting point.
		The key names and the key boarders will not be blacked out.
		*/
		switch (shape_choice)
		{
		case 1:
			for (int i = 1; i < keyboard_height; i++)
			{
				for (int j = start_j; j <= start_j + white_key_width - 1; j++)
				{
					if (i <= black_key_height + 1)
					{
						if (j <= start_j + (white_key_width - black_key_width / 2 - 2))
						{
							keyboard_image[i][j] = "X";
						}
						else
						{
							continue;
						}
					}
					else {
						keyboard_image[i][j] = "X";
					}
				}
			}
			break;
		case 2:
			for (int i = 1; i < keyboard_height; i++)
			{
				for (int j = start_j; j <= start_j + white_key_width - 1; j++)
				{
					if (i <= black_key_height + 1)
					{
						if (j <= start_j + (white_key_width - black_key_width / 2 - 2) &&
							j >= start_j + (black_key_width / 2 + 1))
						{
							keyboard_image[i][j] = "X";
						}
						else
						{
							continue;
						}
					}
					else {
						keyboard_image[i][j] = "X";
					}
				}
			}
			break;
		case 3:
			for (int i = 1; i < keyboard_height; i++)
			{
				for (int j = start_j; j <= start_j + white_key_width - 1; j++)
				{
					if (i <= black_key_height + 1)
					{
						if (j >= start_j + (black_key_width / 2 + 1))
						{
							keyboard_image[i][j] = "X";
						}
						else
						{
							continue;
						}
					}
					else {
						keyboard_image[i][j] = "X";
					}
				}
			}
			break;
		case 4:
			for (int i = 1; i < black_key_height; i++)
			{
				for (int j = start_j; j <= start_j + black_key_width - 1; j++)
				{
					keyboard_image[i][j] = "X";
				}
			}
			break;
		}
	}

	//print the keyboard
	for (int i = 0; i < keyboard_height + 2; i++)
	{
		for (int j = 0; j < keyboard_width; j++)
		{
			cout << keyboard_image[i][j];
		}
		cout << endl;
	}
}

/*
Display a piano keyboard with playing keys black out.
Input playing keys:
1. an unsigned char array that has all the indexes for the notes
being played.
********************************************************************
ATTENTION: THESE INDEXES INCLUDES THE SHARP NOTES, SO IN EACH OCTAVE,
THE INDEXES RANGE FROM 0 TO 11.
********************************************************************
2. the length of the unsigned char array
*/
void SongWriter::printKeyboard(unsigned char* note_index, int length)
{
	/*
	Keyboard height, white key width, black key width, and
	black key height can be adjusted based on the shape of
	keyboard you want.

	The width and height DO NOT contain the edge of each key
	and the edge of the keyboard.
	*/
	int keyboard_height = 10;
	int white_key_width = 5;
	int black_key_width = 3;
	int black_key_height = 5;

	//the full keyboard including the sharps
	vector<Note> full_keyboard = note_gen->getKeyboard();

	/*
	Initialize the keyboard_image 2D string array based on the
	keyboard_height, white_key_width, black_key_width, and
	black_key_height specified above.
	*/
	string** keyboard_image = new string*[keyboard_height + 3];
	int num_major_notes = note_gen->getMajorKeyboardSize();
	int keyboard_width = num_major_notes * (white_key_width + 1) + 1;
	for (int i = 0; i < keyboard_height + 2; i++)
	{
		keyboard_image[i] = new string[keyboard_width];
	}

	/*
	Draw the boarders and all the basic elements, like the
	black and white keys, key names.
	*/
	unsigned char sharp_count = 1;
	unsigned char note_count = 1;
	for (int i = 0; i < keyboard_height + 2; i++)
	{
		for (int j = 0; j < keyboard_width; j++)
		{
			int normal_j = j % ((white_key_width + 1) * 7);
			//top boarder of the keyboard
			if (i == 0)
			{
				keyboard_image[i][j] = "-";

			}
			/*
			The verticle range of the keyboard that has black keys.
			This range has C-C#-D-D#-E-F-F#-G-G#-A-A#-B. A boarder
			will be placed on all the sharp notes.
			*/
			else if (i >= 1 && i <= black_key_height + 1)
			{
				//fill boarder with "|"
				if ((//the boarders of the white keys
					 //between B and C, between E and F
					normal_j == 0 ||
					normal_j == (white_key_width + 1) * 3 ||

					//the boarder of the first 2 black keys
					//C# and D#
					normal_j == (white_key_width + 1) * 1 - (black_key_width / 2 + 1) ||
					normal_j == (white_key_width + 1) * 1 + (black_key_width / 2 + 1) ||
					normal_j == (white_key_width + 1) * 2 - (black_key_width / 2 + 1) ||
					normal_j == (white_key_width + 1) * 2 + (black_key_width / 2 + 1) ||

					//the boarder of the next 3 black keys
					//F#, G#, and A#
					normal_j == (white_key_width + 1) * 4 - (black_key_width / 2 + 1) ||
					normal_j == (white_key_width + 1) * 4 + (black_key_width / 2 + 1) ||
					normal_j == (white_key_width + 1) * 5 - (black_key_width / 2 + 1) ||
					normal_j == (white_key_width + 1) * 5 + (black_key_width / 2 + 1) ||
					normal_j == (white_key_width + 1) * 6 - (black_key_width / 2 + 1) ||
					normal_j == (white_key_width + 1) * 6 + (black_key_width / 2 + 1)) &&

					//excludes the lower boarder of the black key
					i != black_key_height + 1)
				{
					keyboard_image[i][j] = "|";
				}
				else
				{
					/*
					Top portion of the black keys (excluding the last
					line of the black key that will be used to write
					name and the bottom boarder of the black keys)
					*/
					if (i >= 1 && i <= black_key_height - 1)
					{
						keyboard_image[i][j] = " ";
					}
					/*
					The last line of the region inside the black key.
					This line will contain the name of the black key.
					*/
					else if (i == black_key_height)
					{
						/*
						Print the key name of the black keys when j
						is inside the black keys
						*/
						if (normal_j == (white_key_width + 1) * 1 - 1 ||
							normal_j == (white_key_width + 1) * 2 - 1 ||
							normal_j == (white_key_width + 1) * 4 - 1 ||
							normal_j == (white_key_width + 1) * 5 - 1 ||
							normal_j == (white_key_width + 1) * 6 - 1)
						{
							string note_name = note_gen->getSharpNote(sharp_count).note_name;
							keyboard_image[i][j + 0] = note_name.substr(0, 1);
							keyboard_image[i][j + 1] = note_name.substr(1, 1);
							keyboard_image[i][j + 2] = note_name.substr(2, 1);
							sharp_count++;
						}
						//skip the place with printed names
						else if (normal_j == (white_key_width + 1) * 1 ||
							normal_j == (white_key_width + 1) * 2 ||
							normal_j == (white_key_width + 1) * 4 ||
							normal_j == (white_key_width + 1) * 5 ||
							normal_j == (white_key_width + 1) * 6 ||
							normal_j == (white_key_width + 1) * 1 + 1 ||
							normal_j == (white_key_width + 1) * 2 + 1 ||
							normal_j == (white_key_width + 1) * 4 + 1 ||
							normal_j == (white_key_width + 1) * 5 + 1 ||
							normal_j == (white_key_width + 1) * 6 + 1)
						{
							continue;
						}
						//put white space in the remaining parts
						else {
							if (normal_j == 0 || normal_j == (white_key_width + 1) * 3)
							{
								keyboard_image[i][j] = "|";
							}
							else
							{
								keyboard_image[i][j] = " ";
							}
						}
					}
					//the bottom boarder of the black keys
					else
					{
						if (normal_j == (white_key_width + 1) * 1 - 2 ||
							normal_j == (white_key_width + 1) * 2 - 2 ||
							normal_j == (white_key_width + 1) * 4 - 2 ||
							normal_j == (white_key_width + 1) * 5 - 2 ||
							normal_j == (white_key_width + 1) * 6 - 2)
						{
							keyboard_image[i][j + 0] = "-";
							keyboard_image[i][j + 1] = "-";
							keyboard_image[i][j + 2] = "-";
							keyboard_image[i][j + 3] = "-";
							keyboard_image[i][j + 4] = "-";
							j += 4;
						}
						//put white space in the remaining parts
						else {
							if (normal_j == 0 || normal_j == (white_key_width + 1) * 3)
							{
								keyboard_image[i][j] = "|";
							}
							else
							{
								keyboard_image[i][j] = " ";
							}
						}
					}
				}
			}
			/*
			The verticle range of the keyboard that has ONLY white keys.
			This range has C-D-E-F-G-A-B. A boarder will be placed on
			all the white keys.
			*/
			else if (i >= black_key_height + 2 && i <= keyboard_height)
			{
				//draw boarder
				if (normal_j % (white_key_width + 1) == 0)
				{
					keyboard_image[i][j] = "|";
				}
				//put white space when not the last line of the white key
				else if (i >= black_key_height + 2 && i <= keyboard_height - 1)
				{
					keyboard_image[i][j] = " ";
				}
				//the last line of the white key, put name
				else
				{
					if (normal_j % (white_key_width + 1) == (white_key_width + 1) / 2 - 1)
					{
						string note_name = note_gen->getNote(note_count).note_name;
						keyboard_image[i][j] = note_name.substr(0, 1);
						keyboard_image[i][j + 1] = " ";
						keyboard_image[i][j + 2] = note_name.substr(1, 1);
						j += 2;
						note_count++;
					}
					else
					{
						keyboard_image[i][j] = " ";
					}
				}
			}
			/*
			The last line of the keyboard image, all "-"s
			*/
			else {
				keyboard_image[i][j] = "-";
			}
		}
	}

	/*
	Copy the passed in array into playing_indicator.
	Playing_indicator is then used to determine which keys
	to black out.
	*/
	unsigned char* playing_indicator = &note_index[0];

	/*
	Determine the shape of the key being played. There are 4
	different kinds of shaped on the piano keyboard:

	Shape 1:
	-----
	|   |
	|   |
	|   |
	|   |
	|   |
	|   ---
	|     |
	|     |
	|     |
	| C 3 |
	-------

	Shape 2:
	---
	| |
	| |
	| |
	| |
	| |
	--- ---
	|     |
	|     |
	|     |
	| D 3 |
	-------

	Shape 3:
	-----
	|   |
	|   |
	|   |
	|   |
	|   |
	---   |
	|     |
	|     |
	|     |
	| E 3 |
	-------

	Shape 4:
	-----
	|   |
	|   |
	|   |
	|   |
	|C#3|
	-----
	*/
	for (int k = 0; k < length; k++)
	{
		int curr_index = playing_indicator[k];
		int shape_choice = 0;
		int start_j = 0;
		int multiple = (curr_index) / 12;
		int normal_index = curr_index % 12;
		switch (normal_index)
		{
		case 0:
			shape_choice = 1;
			start_j = 1 + (white_key_width + 1) * 7 * multiple;
			break;
		case 1:
			shape_choice = 4;
			start_j = white_key_width + 1 - black_key_width / 2 + (white_key_width + 1) * 7 * multiple;
			break;
		case 2:
			shape_choice = 2;
			start_j = white_key_width + 2 + (white_key_width + 1) * 7 * multiple;
			break;
		case 3:
			shape_choice = 4;
			start_j = (white_key_width + 1) * 2 - black_key_width / 2 + (white_key_width + 1) * 7 * multiple;
			break;
		case 4:
			shape_choice = 3;
			start_j = (white_key_width + 1) * 2 + 1 + (white_key_width + 1) * 7 * multiple;
			break;
		case 5:
			shape_choice = 1;
			start_j = (white_key_width + 1) * 3 + 1 + (white_key_width + 1) * 7 * multiple;
			break;
		case 6:
			shape_choice = 4;
			start_j = (white_key_width + 1) * 4 - black_key_width / 2 + (white_key_width + 1) * 7 * multiple;
			break;
		case 7:
			shape_choice = 2;
			start_j = (white_key_width + 1) * 4 + 1 + (white_key_width + 1) * 7 * multiple;
			break;
		case 8:
			shape_choice = 4;
			start_j = (white_key_width + 1) * 5 - black_key_width / 2 + (white_key_width + 1) * 7 * multiple;
			break;
		case 9:
			shape_choice = 2;
			start_j = (white_key_width + 1) * 5 + 1 + (white_key_width + 1) * 7 * multiple;
			break;
		case 10:
			shape_choice = 4;
			start_j = (white_key_width + 1) * 6 - black_key_width / 2 + (white_key_width + 1) * 7 * multiple;
			break;
		case 11:
			shape_choice = 3;
			start_j = (white_key_width + 1) * 6 + 1 + (white_key_width + 1) * 7 * multiple;
			break;
		}

		/*
		Black out the playing keys with "X"s based on their shape and starting point.
		The key names and the key boarders will not be blacked out.
		*/
		switch (shape_choice)
		{
		case 1:
			for (int i = 1; i < keyboard_height; i++)
			{
				for (int j = start_j; j <= start_j + white_key_width - 1; j++)
				{
					if (i <= black_key_height + 1)
					{
						if (j <= start_j + (white_key_width - black_key_width / 2 - 2))
						{
							keyboard_image[i][j] = "X";
						}
						else
						{
							continue;
						}
					}
					else {
						keyboard_image[i][j] = "X";
					}
				}
			}
			break;
		case 2:
			for (int i = 1; i < keyboard_height; i++)
			{
				for (int j = start_j; j <= start_j + white_key_width - 1; j++)
				{
					if (i <= black_key_height + 1)
					{
						if (j <= start_j + (white_key_width - black_key_width / 2 - 2) &&
							j >= start_j + (black_key_width / 2 + 1))
						{
							keyboard_image[i][j] = "X";
						}
						else
						{
							continue;
						}
					}
					else {
						keyboard_image[i][j] = "X";
					}
				}
			}
			break;
		case 3:
			for (int i = 1; i < keyboard_height; i++)
			{
				for (int j = start_j; j <= start_j + white_key_width - 1; j++)
				{
					if (i <= black_key_height + 1)
					{
						if (j >= start_j + (black_key_width / 2 + 1))
						{
							keyboard_image[i][j] = "X";
						}
						else
						{
							continue;
						}
					}
					else {
						keyboard_image[i][j] = "X";
					}
				}
			}
			break;
		case 4:
			for (int i = 1; i < black_key_height; i++)
			{
				for (int j = start_j; j <= start_j + black_key_width - 1; j++)
				{
					keyboard_image[i][j] = "X";
				}
			}
			break;
		}
	}

	//print the keyboard
	for (int i = 0; i < keyboard_height + 2; i++)
	{
		for (int j = 0; j < keyboard_width; j++)
		{
			cout << keyboard_image[i][j];
		}
		cout << endl;
	}
}

/*
Clear the data in current song sheet, including the
harmony, melody, and melody_indexes.
*/
void SongWriter::clearSong()
{
	this->harmony = vector<unsigned char>();
	this->melody = vector<float>();
	this->melody_indexes = vector<unsigned char>();
}

/*
Generate song based on the available chords, available
notes, and pre-defined chord progressions.
*/
void SongWriter::writeSong()
{
	//srand(time(0));
	/*
	Clear everything to make sure the new song is written
	on a fresh song sheet.
	*/
	this->harmony = vector<unsigned char>();
	this->melody = vector<float>();
	this->melody_indexes = vector<unsigned char>();
	for (int i = 0; i < (SONG_LENGTH / 4); i++)
	{
		/*
		Choose which progression to use randomly.
		rand()%4 produces a random number between 0 and 3.
		*/
		int r = rand() % Num_of_Progressions; //change the modulo returned
		for (int j = 0; j < 4; j++)
		{
			/*
			Push the indexes in the corresponding progression into
			the harmony vector. These indexes can be used to generate
			chords later.
			*/
			harmony.push_back(progressions[r][j]);
		}
	}
	/*
	Use getRandomNote() method in note generator to get
	random notes that are available on our keyboard. The
	indexes of these notes are stored in the melody_indexes
	vector; the frequencies of these notes are stored in the
	melody vector.
	*/
	for (int k = 0; k < NUM_MELODY_NOTES; k++)
	{
		unsigned char new_index = this->note_gen->getRandomNote();
		melody.push_back(note_gen->getNote(new_index).note_frequency);
		melody_indexes.push_back(new_index);
	}

}

/*
Take an unsigned char array of indexes of the melody
notes, store these indexes into the melody_indexes vector;
convert these indexes to the frequencies of corresponding
notes and store the frequencies in the melody vector.
*/
void SongWriter::setMelody(unsigned char* melodyArr)
{
	this->melody_indexes = vector<unsigned char>();
	this->melody = vector<float>();
	for (int i = 0; i<SONG_LENGTH * 4; i++)
	{
		melody_indexes.push_back(melodyArr[i]);
		//use getNoteFreq to convert int representation of notes back to freq
		float temp_note_freq = note_gen->getNoteFreq(melodyArr[i]);
		melody.push_back(temp_note_freq);
	}
	return;
}

/*
Take an unsigned char array of indexes of the chords. Store the
indexes into the harmony vector. These indexes can be used to
generate chords later.
*/
void SongWriter::setHarmony(unsigned char* harmonyArr)
{
	this->harmony = vector<unsigned char>();
	for (int i = 0; i < SONG_LENGTH; i++)
	{
		harmony.push_back(harmonyArr[i]);
	}
	return;
}

/*
Convert the indexes in the harmony vector to the
corresponding chords, store them in a chord array,
return the chord array.
*/
Chord* SongWriter::getChords()
{
	Chord* harmony_chords = new Chord[SONG_LENGTH];

	for (int i = 0; i < SONG_LENGTH; i++)
	{
		harmony_chords[i] = Chord(*note_gen, harmony.at(i));
	}

	return harmony_chords;
}

/*
Return true if the song is empty (no chord or melody note);
otherwise, if the any of the vectors (harmony, melody, and
melody_indexes) is not empty, return false.
*/
bool SongWriter::isEmpty()
{
	return harmony.size() == 0 && melody.size() == 0 && melody_indexes.size() == 0;
}