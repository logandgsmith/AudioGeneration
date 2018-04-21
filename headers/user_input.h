#pragma once

#include <cstdlib>
#include <fstream>
#include <string>
#include "song_writer.h"

int main();

namespace UserInput {

//public:
	void save(std::string name , unsigned char* harmony, unsigned char* melody);
	void load(std::string name);
	void playnewSong();

//private:
	std::string song_name;
}
