#pragma once

#include <cstdlib>
#include <fstream>
#include <limits>
#include <stdexcept>
#include <string>
#include "song_writer.h"

namespace UserInput {
	void save(std::string name , unsigned char* harmony, unsigned char* melody);
	void load(std::string name);
	void playnewSong();
}
