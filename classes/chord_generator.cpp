#include "chord_generator.h"

//Constructor
chord_generator::chord_generator()
{
	note_generator* ng = new note_generator();
	note_array = ng.get_array();
	chords_we_have = new vector<chord*>();
}

//Accessors
chord* chord_generator::get_major_chord(string root_name) {
	int chord_index = check_existing_chord(root_name);
	if (chord_index==-1) {
		int root_index = this->search_note(root_name);
		int third_index = root_index + 4;
		int fifth_index = root_index + 7;
		string chord_name = root_name + " Major";
		chord* output = new chord(chord_name, note_array[root_index], note_array[third_index], note_array[fifth_index]);
		chords_we_have->insert(output);
		return output;
	}
	else {
		return chords_we_have->at(chord_index);
	}
}

chord* chord_generator::get_minor_chord(string root_name) {
	int chord_index = check_existing_chord(root_name);
	if (chord_index == -1) {
		int root_index = this->search_note(root_name);
		int third_index = root_index + 3;
		int fifth_index = root_index + 7;
		string chord_name = root_name + " Minor";
		chord* output = new chord(chord_name, note_array[root_index], note_array[third_index], note_array[fifth_index]);
		chords_we_have->insert(output);
		return output;
	}
	else {
		return chords_we_have->at(chord_index);
	}
}

int chord_generator::check_existing_chord(string root_Note) {
	for (int i = 0; i < chords_we_have->size(); i++) {
		if (chords_we_have->at(i)->get_note_one().note_name.compare(root_Note) == 0){
			return i;
		}
	}
	return -1;
}

int chord_generator::search_note(string name) {
	for (int i = 0; i < 12; i++) {
		if (note_array[i].compare(name) == 0) {
			return i;
		}
	}
	return -1;
}