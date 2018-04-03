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
	double      getNoteFreq(int index);
	std::string getNoteName(int index);
	Note*       getArray();

	//Mutators
	void        setNote();

private:
	int const   note_array_size = 12;
	Note*       keyboard;
};