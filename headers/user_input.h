#pragma once

#include <cstdlib>
#include <fstream>
#include <string>
#include "song_writer.h"

const unsigned char chord_prog_length = 5;

int main();

namespace UserInput {

//public:
	void save(std::string name);
	void load(std::string name);
	void playnewSong();

//private:
	std::string song_name;
}
