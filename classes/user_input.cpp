#include "../headers/user_input.h"
#include <iostream>
#include <cstdlib>

//using namespace std;

//TESTING/DEBUGGING 
int main() {

	string mood_of_song;
	UserInput::displayMood(); //prints out list of moods for user selection 
	cout << "Please pick a mood: " << endl;
	cin >> mood_of_song;

	UserInput::setMood(mood_of_song); 

	//call SongWriter class and play the song generated 
	//after song finish playing, ask for feedback (like/dislike, save--> name the song)
	UserInput::feedback();
}

//user feedback: what the user can do after the song is played
void UserInput::feedback() {

	int user_decision = 0;
	cout << "1. Print the Song\n2. Save the Song\n3. Exit the program" << endl;
	cin >> user_decision;

	if (user_decision == 1) {
		cout << "Placeholder" << endl;
		//call songwriter class and the print() method
	}
	else if (user_decision == 2) {
		string song_name;
		cout << "Please name the song: " << endl;
		cin >> song_name;

		UserInput::save(); //method to save the song(i.e., the chord array/vector?
	}
	else if (user_decision == 3) //exit the program
		exit(0);
}

void UserInput::save() {
	// how do we save the song that was generated?
}

void UserInput::playBack() {

}

//display the 5 moods the user can choose from
void UserInput::displayMood() {
	cout << "Moods " << endl;
	cout << "Boisterous\nCheerful\nWistful\nWhimsical\nAggressive" << endl;
}

string UserInput::getMood() {
	return mood;
}

bool getLike() {

//	return like;
}

//user picks and sets the mood of the song 
void UserInput::setMood(string new_mood) {
	mood = new_mood;
}

void UserInput::setLike() {


}

