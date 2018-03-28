#include "Chord_Generator.h"



Chord_Generator::Chord_Generator()
{
	Note_Generator* ng = new Note_Generator();
	note_array = ng.get_array();
	created_chords = new vector<Chord>();
}

Chord Chord_Generator::get_major_chord(string root_name) {
	int chord_index = check_existing_chord(root_name);
	if (chord_index==-1) {
		int root_index = this->search_note(root_name);
		int third_index = root_index + 4;
		int fifth_index = root_index + 7;
		string chord_name = root_name + " Major";
		Chord* output = new Chord(chord_name, note_array[root_index], note_array[third_index], note_array[fifth_index]);
		created_chords->insert(output);
		return output;
	}
	else {
		return created_chords->at(chord_index);
	}
}

Chord Chord_Generator::get_minor_chord(string root_name) {
	int chord_index = check_existing_chord(root_name);
	if (chord_index == -1) {
		int root_index = this->search_note(root_name);
		int third_index = root_index + 3;
		int fifth_index = root_index + 7;
		string chord_name = root_name + " Minor";
		Chord* output = new Chord(chord_name, note_array[root_index], note_array[third_index], note_array[fifth_index]);
		created_chords->insert(output);
		return output;
	}
	else {
		return created_chords->at(chord_index);
	}
}

Chord_Generator::~Chord_Generator()
{
}
