#pragma once

#include <cstdlib>
#include <fstream>
#include <limits>
#include <stdexcept>
#include <string>

#include "../headers/audio_generation.h"
#include "../headers/song_writer.h"

namespace UserInput {
	void save(std::string name , unsigned char* harmony, unsigned char* melody);
	void load(SongWriter song, std::string name);
	void playnewSong();
}
