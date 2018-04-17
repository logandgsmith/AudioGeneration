#pragma once

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

int main();

namespace UserInput {
//public:
	void feedback();
	void save();
	void playBack();

	//Accessors
	void displayMood();
	std::string getMood();
	
	//Mutators
	void setMood(std::string mood);
	void setLike();

//private:
	std::string song_mood;
	std::string song_name;
}
