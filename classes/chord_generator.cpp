#include "../headers/chord_generator.h"
#include <stdexcept>

//Constructors
ChordGenerator::ChordGenerator() {
	ng = new NoteGenerator();
	chords = new vector<Chord*>;
}

ChordGenerator::ChordGenerator(NoteGenerator &note_gen) {
	ng = &note_gen;
	chords = new vector<Chord*>;
}

//Accessors

//get the major triad with of the root note
Chord* ChordGenerator::getMajorTriadChord(int root_index) {
	string root_name = ng->getNote(root_index).note_name;
	int chord_index = checkExistingChord(root_name + "_Major_Triad");
	if (chord_index == -1) {
		int root_index = this->searchNote(root_name);
		int third_index = root_index + 4;
		int fifth_index = root_index + 7;
		std::string chord_name = root_name + "_Major_Triad";
		Chord* output;
		try {
			output = new Chord(chord_name, (ng->getKeyboard().at(root_index)),
				(ng->getKeyboard().at(third_index)), (ng->getKeyboard().at(fifth_index)));
			chords->push_back(output);
		}
		catch (const std::out_of_range &e) {
			output = nullptr;
		}
		return output;
	}
	else {
		return chords->at(chord_index);
	}
}

//get the minor triad with of the root note
Chord* ChordGenerator::getMinorTriadChord(int root_index) {
	string root_name = ng->getNote(root_index).note_name;
	int chord_index = checkExistingChord(root_name + "_Minor_Triad");
	if (chord_index == -1) {
		int root_index = this->searchNote(root_name);
		int third_index = root_index + 3;
		int fifth_index = root_index + 7;
		std::string chord_name = root_name + "_Minor_Triad";
		Chord* output;
		try {
			output = new Chord(chord_name, (ng->getKeyboard().at(root_index)),
				(ng->getKeyboard().at(third_index)), (ng->getKeyboard().at(fifth_index)));
			chords->push_back(output);
		}
		catch (const std::out_of_range &e) {
			output = nullptr;
		}
		return output;
	}
	else {
		return chords->at(chord_index);
	}
}

//check if we already have the chord. if so, return the old chord directly
int ChordGenerator::checkExistingChord(std::string chord_name) {
	for (unsigned int i = 0; i < chords->size(); i++) {
		if (chords->at(i)->getName().compare(chord_name) == 0)
			return i;
	}
	return -1;
}

//search the index of the note in keyboard (return the position of the note in the keyboard (including sharps), NOT the major index
int ChordGenerator::searchNote(std::string name) {
	for (int i = 0; i < 12; i++) {
		if (ng->getKeyboard().at(i).note_name.compare(name) == 0) {
			return i;
		}
	}
	return -1;
}