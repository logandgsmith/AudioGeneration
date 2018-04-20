#include "../headers/audio_generation.h"

/**************************************************
	This class makes use of the Portaudio library.
	Portaudio is across platform library that allows 
	us to use our code on different platforms. 
	That being said, we are specifically targetting
	Windows OS running minGW.
***************************************************/

bool AudioGeneration::play(Song& song) {
	//PortAudio Setup
	PaStreamParameters outputParameters;
	PaStream* stream;
	PaError err;
	float buffer[FRAMES_PER_BUFFER][2];
	int phase = 0;
	int bufferCount;
	chord* harmony;
	float* melody;
	float* harmony_current;
	float* melody_current;

	harmony = song->getHarmony();
	melody  = song->getMelody();

	//Initialize the Stream
	err = Pa_Initialize();
	if (err != paNoError)
		goto error;

	outputParameters.device = Pa_GetDefaultOutputDevice();
	if (outputParameters.device == paNoDevice) {
		std::cout << stderr << "Error: No Output Devices Found" << std::endl;
		goto error;
	}
	outputParameters.channelCount = 2;
	outputParameters.sampleFormat = paFloat32;
	outputParameters.suggestedLatency = Pa_GetDeviceInfo(outputParameters.device)->defaultLowOutputLatency;
	outputParameters.hostApiSpecificStreamInfo = nullptr;

	err = Pa_OpenStream(
		&stream,
		nullptr,
		&outputParameters,
		SAMPLE_RATE,
		FRAMES_PER_BUFFER,
		paClipOff,
		nullptr,
		nullptr);
	if (err != paNoError)
		goto error;

	//Audio Generation
	err = Pa_StartStream(stream);
	if (err != paNoError)
		goto error;

	bufferCount = ((NUM_SECONDS * SAMPLE_RATE) / FRAMES_PER_BUFFER);

	//Write Waveforms and plays them for each part of a song
	for(int h = 0; h < song.size(); h++) {
		harmony_current = AudioGeneration::generateChordWave(harmony[h]);
		melody_current  = AudioGeneration::generateWaveform(melody[h]);
		//Add Waveform to buffer then output
		for (int i = 0; i < bufferCount; i++) {
			for (int j = 0; j < FRAMES_PER_BUFFER; j++) {
				buffer[j][0] = harmony_current[phase];
				buffer[j][1] = melody_current[phase];
				phase++;
				if (phase >= TABLE_SIZE)
					phase -= TABLE_SIZE;
			}

			err = Pa_WriteStream(stream, buffer, FRAMES_PER_BUFFER);
			if (err != paNoError)
				goto error;
		}
	}

	err = Pa_StopStream(stream);
	if (err != paNoError)
		goto error;

	err = Pa_CloseStream(stream);
	if (err != paNoError)
		goto error;

	Pa_Terminate();
	std::cout << "No Error" << std::endl;

	return err;

//Handles errors that occur in the PortAudio Stream only
error:
	std::cout << stderr << "An error has occured in the portaudio stream \n" << std::endl;
	std::cout << stderr << "Error Number: " << err << std::endl;
	std::cout << stderr << "Error Message: " << Pa_GetErrorText(err);

	Pa_Terminate();
	return err;
}

//Generates a single sine wave of a given frequency
float* AudioGeneration::generateWaveform(float frequency) {
	float* waveform = new float[SAMPLE_RATE];

	for (int i = 0; i < SAMPLE_RATE; i++) {
		waveform[i] = (float)sin(((double)i / (double)SAMPLE_RATE) * PI * 2 * frequency);
	}

	return waveform;
}

//First finds the frequencies of a chord, then creates the composite waveform
float* AudioGeneration::generateChordWave(Chord chord) {
	float* waveform_one;
	float* waveform_two;
	float* waveform_thr;
	float* waveform_end;

	waveform_one = AudioGeneration::generateWaveform(chord->getNote(0));
	waveform_two = AudioGeneration::generateWaveform(chord->getNote(1));
	waveform_thr = AudioGeneration::generateWaveform(chord->getNote(2));
	waveform_end = new float[SAMPLE_RATE];

	//Attempting to make the tone sound a little "rounder"
	for (int i = 0; i < SAMPLE_RATE; i++) {
		waveform_end[i] = waveform_one[i] + waveform_two[i] + waveform_thr[i];
		//The following if/else block will be changed
		if(i < SAMPLE_RATE / 2)
			waveform_end[i] *= 0.001 * i;
		else if(i > SAMPLE_RATE / 2)
			waveform_end[i] *= 0.001 * (SAMPLE_RATE - i);
	}

	return waveform_end;
}
