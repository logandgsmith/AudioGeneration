#ifndef NOTE_GENERATOR_H
#define NOTE_GENERATOR_H
#include <string> 

using namespace std;

class Note_Generator {
public:
	 Note_Generator();
	//~Note_Generator(); May or may not use according to Logan.
	//Sets the note in question. Assigns a name and a frequency value. 
	void setNote(Note* keyBoard);
	double getNoteFreq(Note* keyBoard);
	string getNoteName(Note* keyBoard);
	Note* keyBoard getarray();


private:
	int const noteArray = 13;

	struct Note{
		double noteFrequency;
		string noteName;
	}

	//Array of name keyBoard
	Note* keyBoard = new Note* [noteArray];




};

#endif /*NOTE_GENERATOR_H*/