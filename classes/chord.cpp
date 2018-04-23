#include "../headers/chord.h"
#include <iostream>

/**************************************************
This class defines the Chord object. Each chord
usually has three notes that are generated with
a formula. Each chord created by this class is a major
chord, which contains the 1st, 3rd and 5th notes of a
major scale.

"The interval is the difference in pitch between the notes,
mathematically represented by a ratio between the frequency
of the two notes. Observation and testing shows simple ratios
sound pleasing and concordant." - Bill Carroll

https://www.quora.com/Why-do-the-minor-chords-sound-sad-and-major-
chords-happy-Ive-read-everything-there-is-to-read-on-this-subject-
and-theres-still-no-answer
***************************************************/

//Constructor for triads

/*

Initialize a Chord object based on the following parameters:
1. Default Constructor
	--> Necessary to create dynamic chord array
2. address of a Note Generator object
	--> degree of chord has not been specified
3. address of Note Generator object, ng, and scale_degree
	--> creates chord based on scale_degree (i.e. root note)

	*Note: scale_degree refers to the base note of the triad (chord)
		All root notes for the harmony chords are created using the lowest available octave.
		scale_degree starts indexing at 1:

		1. C_Major chord
		2. D_Major chord
		3. E_Major chord
		4. F_Major chord
		5. G_Major chord
		6. A_Major chord
		7. B_Major chord

*/

Chord::Chord() { }

Chord::Chord(NoteGenerator &ng) { }

Chord::Chord(NoteGenerator &ng, unsigned char scale_degree)
{
	Chord::create_triad(scale_degree);
}

//Accessors

/*
Returns a note in the chord triad based on the
given parameter, index. Each chord triad contains 3 notes.

*/
Note Chord::getNote(unsigned char index)
{
	return this->chord.at(index);
}

/*
Returns the number of notes in a Chord object
If created correctly, the size of each filled Chord
object should be 3, accounting for 3 notes in a triad.
*/
unsigned char Chord::getNumNotes()
{
	return this->chord.size();
}

//returns the name of the chord
std::string Chord::getName()
{
	return name;
}

//Mutators

/*
Overloaded method used in conjucntion

Logic Flow:
1. Using method with parameter (unsigned char note_index):
	--> method create_triad calls push_back_note method, passing in indices of major third and perfect fifth note
		relative to a given root note
	-->calls getNote method to return corresponding Note object for each note in chord
	-->calls other push_back_note declaration...
 2. Using method with parameter (Note n)
 	--> stores each Note object in order into chord vector
	--> creates major triad

*/
void Chord::push_back_note(Note n)
{
	this->chord.push_back(n);
}

void Chord::push_back_note(unsigned char note_index) // Must be greater than or equal to 1
{
	this->push_back_note(ng.getNote(note_index));
}

/*
Creates a triad, a chord with 3 notes, based on the passed in parameter, scale_degree.
The scale_degree is the base or root note of the chord. All chords generated in this
method are major chords.

The method does the following:
a. clears the contents of object's chord vector
b. Defines name of chord based on root note
	--> (i.e. if C is root note, chord name = "C_Major")
c. stores the three notes that will create the new chord in instance's vector

Based on basic music theory, a major chord (or a major triad) is composed of the following:
1. Root note (i.e. note defined by scale_degree)
2. Major third --> 4 half steps from the root note
3. Perfect Fifth --> 7 half steps from the root note

*However*, since our program omits black keys for simplicity, a chord is generated using a simplified algorithm:
1. Root note --> scale_degree
2. Major third --> 2 whole steps (i.e. two white keys)
3. Perfect fifth --> 3.5 whole steps (i.e four white keys)

*/

void Chord::create_triad(unsigned char scale_degree)
{
	this->chord.clear();
	name = ng.getNoteName(scale_degree) + "_Chord";
	this->push_back_note(scale_degree);
	this->push_back_note(scale_degree + 2);
	this->push_back_note(scale_degree + 4);
}

/*
Returns the given chord and its constituent notes formatted as a string.
if withNotes is true --> If the chord has a complete triad (i.e. has notes), string includes both the chord name and the note names
if withNote is false --> If chord has empty vector --> returned string only contains chord name (same as getName)
*/

string Chord::printChord(bool withNotes)
{
	string a = "";
	if (withNotes)
		a = a + getName() + ": " + getNote(0).note_name + " " + getNote(1).note_name + " " + getNote(2).note_name;
	else
		a = a + getName();
	return a;
}
