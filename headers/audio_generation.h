#pragma once

#include <iostream>
#include <math.h>
#include "../headers/portaudio.h"

#define PI (3.14159265)
#define NUM_SECONDS (1)
#define SAMPLE_RATE (44100)
#define FRAMES_PER_BUFFER (64)

#define TABLE_SIZE (44100)

namespace AudioGeneration {
	float  sineMaker(int, double);
	double getFrequency(int);
};
