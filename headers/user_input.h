#pragma once

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

int main();

namespace UserInput {

//public:
	void save(string name);
	void load(string name);
	void playnewSong();


//private:
	std::string song_name;
	SongWriter mySongWriter;
}
