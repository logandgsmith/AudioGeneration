#pragma once

#include <iostream>
#include <math.h>
#include "../headers/portaudio.h"
#include "../headers/song_writer.h"

//Declaration of Constants
const float PI                = 3.14159265f;
const int   NOTE_TIME         = 1;
const int 	SAMPLE_RATE       = 44100;
const int 	FRAMES_PER_BUFFER = 64;
const int 	TABLE_SIZE        = 75;
const int   MEASURES          = 16;

namespace AudioGeneration {
	bool   	play(SongWriter song);
	float* 	generateSineWave(float frequency);
	float*	generateChordWave(Chord chord);
};
