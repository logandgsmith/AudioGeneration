#pragma once

#include <iostream>
#include <math.h>
#include "../headers/portaudio.h"
//#include "../headers/song.h"

const float PI = 3.14159265f;
const int NUM_SECONDS = 5;
const int SAMPLE_RATE = 44100;
const int FRAMES_PER_BUFFER = 64;

const int TABLE_SIZE = 44100;

namespace AudioGeneration {
	float*   generateWaveform(float frequency);
	//float* findMelody(Song song);
};
