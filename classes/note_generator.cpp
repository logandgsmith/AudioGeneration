#include "note_generator.h"

// constructor defaults to middle C (C4)
NoteGenerator :: NoteGenerator() {
	note_frequency = 261.63;
	note_name = "C4";
	keyboard[note_array_size]

}

//frequncy getter
double NoteGenerator::getNoteFreq(int index, ){
	return keyboard[index].note_frequency;
}
//name getter
std::string NoteGenerator::getNoteName(int index) {
	return keyboard[index].note_name;
}
//array getter
Note* NoteGnerator::getArray() {
	return this->keyboard;
}

//Mutators  //ERROR MIGHT OCCUR DUE TO ME NOT USING POINTER NOTATION '->'
void NoteGenerator::setNote() {
	for(int i = 0; i < 12; i++){
		
		if(i == 0){
			keyboard[i].note_name = "C4";
			keyboard[i].note_frequency = 261.63;
		}

		if(i == 1){
			keyboard[i].note_name = "C#4";
			keyboard[i].note_frequency = 277.19;
		}

		if(i == 2){
			keyboard[i].note_name = "D4";
			keyboard[i].note_frequency = 293.67 ;
		}

		if(i == 3){
			keyboard[i].note_name = "D#4";
			keyboard[i].note_frequency = 311.13;
		}

		if(i == 4){
			keyboard[i].note_name = "E4";
			keyboard[i].note_frequency = 329.63;
		}

		if(i == 5){
			keyboard[i].note_name = "F4";
			keyboard[i].note_frequency = 349.23 ;
		}

		if(i == 6){
			keyboard[i].note_name = "F#4";
			keyboard[i].note_frequency = 370.00;
		}

		if(i == 7){
			keyboard[i].note_name = "G4";
			keyboard[i].note_frequency = 392.00;
		}

		if(i == 8){
			keyboard[i].note_name = "G#4";
			keyboard[i].note_frequency = 415.31;
		}

		if(i == 9){
			keyboard[i].note_name = "A4";
			keyboard[i].note_frequency = 440.01;
		}

		if(i == 10){
			keyboard[i].note_name = "A#4";
			keyboard[i].note_frequency = 466.17;
		}

		if(i == 11){
			keyboard[i].note_name = ;
			keyboard[i].note_frequency = 493.89;	
		}
	}
}
