#include "../headers/user_input.h"

UserInput::userInput(std::string mood) {
	this->mood = mood;
}

//display the 5 moods the user can choose from
void UserInput::displayMood() {
	std::cout << "Moods " << endl;
	std::cout << "Boisterous\nCheerful\nWistful\nWhimsical\nAggressive" << endl;
}

//user picks and sets the mood of the song 
void UserInput::setMood(std::string mood) {
	this->mood = mood;
}

//user feedback: what the user can do after the song is played
void UserInput::feedback() {

	int user_decision = 0;
	std::cout << "1. Print the Song\n2. Save the Song\n3. Exit the program" << endl;
	std::cin >> user_decision;

	if (user_decision == 1)
		//call songwriter class and the print() method 
	else if (user_decision == 2) {
		std::string song_name;
		std::cout << "Please name the song: " << endl;
		std::cin >> song_name;

		userInput.save(); //method to save the song(i.e., the chord array/vector?
	}
	else if (user_decision == 3) //exit the program/ application?
		return -1; 
}

void UserInput::setLike() {


}

//GETTERS
std::string UserInput::getMood() {
	return mood;
}

void UserInput::save() {
	// how do we save the song that was generated?
}

bool getLike() {

	return like;
}

void UserInput::playBack() {

}

//TESTING/DEBUGGING 
int main() {

	std::string mood_of_song;
	userInput->displayMood(); //prints out list of moods for user selection 
	std::cout << "Please pick a mood: " << endl;
	std::cin >> mood_of_song;

	userInput->setMood(mood_of_song); 

	//call SongWriter class and play the song generated 
	//after song finish playing, ask for feedback (like/dislike, save--> name the song)
	userInput->userFeedback();
}
