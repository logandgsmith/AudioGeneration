#pragma once

#include <iostream>
#include <math.h>
#include "../headers/portaudio.h"
#include "../headers/song_writer.h"

//Declaration of Constants
const float PI                = 3.14159265f;
const int 	HARMONY_TIME      = 4;
const int   MELODY_TIME       = 1;
const int 	SAMPLE_RATE       = 44100;
const int 	FRAMES_PER_BUFFER = 64;
const int 	TABLE_SIZE        = 75;
const int   MEASURES          = 16;
const int   AUDIO_LENGTH      = 64;

namespace AudioGeneration {
	bool   	play(SongWriter song);
	float* 	generateWaveform(float frequency);
	float*	generateChordWave(Chord chord);
};
