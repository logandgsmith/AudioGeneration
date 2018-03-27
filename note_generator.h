#ifndef NOTE_GENERATOR_H
#define NOTE_GENERATOR_H
#include <string> 

using namespace std;

struct Note{
	double note_frequency;
	string note_name;
};

class NoteGenerator {
public:
	 NoteGenerator();
	//~NoteGenerator(); May or may not use according to Logan.
	//Sets the note in question. Assigns a name and a frequency value. 
	void setNote(Note* keyboard);
	double getNoteFreq(Note* keyboard);
	string getNoteName(Note* keyboard);
	Note* getArray();


private:
	int const note_array = 13;
	//Array of name keyboard
	Note keyboard[note_array];




};

#endif /*NOTE_GENERATOR_H*/
