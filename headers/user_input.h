#pragma once

#include <string>

using namespace std;

int main();

namespace UserInput {
//public:
	void feedback();
	void save();
	void playBack();

	//Accessors
	void displayMood();
	std::string getMood();
	bool getLike();
	
	//Mutators
	void setMood(std::string mood);
	void setLike();

//private:
	std::string mood;

}
