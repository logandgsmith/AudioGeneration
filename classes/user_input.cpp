#include "user_input.h"

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

//what the user can do after the song is placed 
void UserInput::feedback() {

	std::cout << "1. Print the Song\n2. Exit the program\n3. Save the Song" << endl;
	int user_decision = 0;
	std::cin >> user_decision;

	if (user_decision == 1)
		//call songwriter and print the song 
	else if (user_decision == 2)
		return -1;
	else if (user_decision == 3) {
		std::cout << "Please name the song" << endl;
		userInput.save();
	}
}

void UserInput::setLike() {
	this

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

//testing 
int main() {
	userInput->displayMood(); //prints out list of moods for user selection 
	std::cout << "Please pick a mood." << endl;
	userInput->setMood("Cheerful");

	//call SongWriter class and play the song generated 
	//after song finish playing, ask for feedback (like/dislike, save--> name the song)
	userInput->userFeedback();
}