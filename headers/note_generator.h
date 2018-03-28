#pragma once

struct Note{
	double note_frequency;
	string note_name;
};

class NoteGenerator {
public:
	//Constructor
	 NoteGenerator();
	//~NoteGenerator(); May or may not use

	//Accessors
	double      getNoteFreq(int index, Note* keyboard);
	std::string getNoteName(int index, Note* keyboard);
	Note*       getArray();

	//Mutators
	void        setNote(int index, Note new_note);

private:
	int const   note_array_size = 13;
	Note        keyboard[note_array_size];
};