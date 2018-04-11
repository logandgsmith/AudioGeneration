#include "chord_generator.h"

//Constructor
ChordGenerator::ChordGenerator()
{
	NoteGenerator* ng = new NoteGenerator();
	note_array = ng->getArray();
	chords_we_have = new vector<Chord*>();
}

//Accessors
Chord* ChordGenerator::getMajorChord(string root_name) {
	int chord_index = checkExistingChord(root_name);
	if (chord_index == -1) {
		int root_index = this->searchNote(root_name);
		int third_index = root_index + 4;
		int fifth_index = root_index + 7;
		string chord_name = root_name + "_Major";
		Chord* output = new Chord(chord_name, note_array[root_index].note_name, note_array[third_index].note_name, note_array[fifth_index].note_name);
		chords_we_have->push_back(output);
		return output;
	}
	else {
		return chords_we_have->at(chord_index);
	}
}

Chord* ChordGenerator::getMinorChord(string root_name) {
	int chord_index = checkExistingChord(root_name);
	if (chord_index == -1) {
		int root_index = this->searchNote(root_name);
		int third_index = root_index + 3;
		int fifth_index = root_index + 7;
		string chord_name = root_name + "_Minor";
		Chord* output = new Chord(chord_name, note_array[root_index], note_array[third_index], note_array[fifth_index]);
		chords_we_have->push_back(output);
		return output;
	}
	else {
		return chords_we_have->at(chord_index);
	}
}

int ChordGenerator::checkExistingChord(string root_Note) {
	for (int i = 0; i < chords_we_have->size(); i++) {
		if (chords_we_have->at(i)->getNoteOne()->note_name.compare(root_Note) == 0) {
			return i;
		}
	}
	return -1;
}

int ChordGenerator::searchNote(string name) {
	for (int i = 0; i < 12; i++) {
		if (note_array[i].note_name.compare(name) == 0) {
			return i;
		}
	}
	return -1;
}