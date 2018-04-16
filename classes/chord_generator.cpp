#include "../headers/chord_generator.h"
#include <stdexcept>

//Constructors
ChordGenerator::ChordGenerator() {
	ng = new NoteGenerator();
//	keyboard = &(ng->getKeyboard());
	chords = new vector<Chord*>;
}

ChordGenerator::ChordGenerator(NoteGenerator &note_gen) {
	ng = &note_gen;
//	keyboard = &(ng->getKeyboard());
	chords = new vector<Chord*>;
}

//Accessors
Chord* ChordGenerator::getMajorTriadChord(std::string root_name) {
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

Chord* ChordGenerator::getMinorTriadChord(std::string root_name) {
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

int ChordGenerator::checkExistingChord(std::string chord_name) {
	for (unsigned int i = 0; i < chords->size(); i++) {
		if (chords->at(i)->getName().compare(chord_name) == 0)
			return i;
	}
	return -1;
}

int ChordGenerator::searchNote(std::string name) {
	for (int i = 0; i < 12; i++) {
		if (ng->getKeyboard().at(i).note_name.compare(name) == 0) {
			return i;
		}
	}
	return -1;
}
