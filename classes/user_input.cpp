#include "../headers/user_input.h"

//using namespace std;

//TESTING/DEBUGGING 
int main() {

	string song_mood;
	UserInput::displayMood(); //prints out list of moods for user selection 
	std::cout << "Please pick a mood: " << std::endl;
	std::cin  >> song_mood;

	UserInput::setMood(song_mood); 

	//call SongWriter class and play the song generated 
	//after song finish playing, ask for feedback (like/dislike, save--> name the song)
	UserInput::feedback();
}

//user feedback: what the user can do after the song is played
void UserInput::feedback() {

	int user_decision = 0;
	std::cout << "1. Print the Song\n2. Save the Song\n3. Exit the program" << std::endl;
	std::cin  >> user_decision;

	if (user_decision == 1) {
		cout << "Placeholder" << std::endl;
		//call songwriter class and the print() method
	}
	else if (user_decision == 2) {
		string song_name;
		std::cout << "Please name the song: " << std::endl;
		std::cin  >> song_name;

		UserInput::save(); //method to save the song(i.e., the chord array/vector?
	}
	else if (user_decision == 3) //exit the program
		exit(0);
}

void UserInput::save() {

}

void UserInput::playBack() {

	//Checks for valid file names
	bool          isValidFileName = false;
	std::ifstream inFile;
	std::string   token

	while (!isValidFileName) {
		std::cout << "Please enter the name of the input file:" << std::endl;
		std::getline(std::cin, fileName);
		try {
			inFile.open(fileName);
			if (!inFile)
				throw std::runtime_error("File could not be opened");
		}
		catch (std::runtime_error e) {
			std::cout << e.what() << std::endl;
			continue;
		}

		isValidFileName = true;
	}

	while (inFile >> token) {
		//TODO TURN TOKENS INTO CHORDS THEN ADD TO SONG VECTOR
	}
}

//display the 5 moods the user can choose from
void UserInput::displayMood() {
	std::cout << "Moods " << std::endl;
	std::cout << "Boisterous\nCheerful\nWistful\nWhimsical\nAggressive" << std::endl;
}

std::string UserInput::getMood() {
	return this->song_mood;
}


//user picks and sets the mood of the song 
void UserInput::setMood(string mood) {
	this->song_mood = mood;
}

//Should set a like on the current SongWriter Song
void UserInput::setLike() {


}

