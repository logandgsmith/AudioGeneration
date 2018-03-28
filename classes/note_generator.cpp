#include "note_generator.h"

NoteGenerator :: NoteGenerator() {

}

//Accessors
double NoteGenerator::getNoteFreq(int index, Note* keyboard) {
	//return the frequency of the note at the specified index
}

std::string NoteGenerator::getNoteName(int index, Note* keyboard) {
	//return the name of the note at the specified index
}

Note* NoteGnerator::getArray() {
	return this->keyboard;
}

//Mutators
void NoteGenerator::setNote(int index, Note new_note) {
	//Add a note at the specified index
}
