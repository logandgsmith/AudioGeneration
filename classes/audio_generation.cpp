#include "../headers/audio_generation.h"

int main() {
	//PortAudio Setup
	PaStreamParameters outputParameters;
	PaStream* stream;
	PaError err;
	float buffer[FRAMES_PER_BUFFER][2];
	int phase = 0;
	int bufferCount;

	//Initialize the Stream
	err = Pa_Initialize();
	if(err != paNoError)
		goto error;

	outputParameters.device = Pa_GetDefaultOutputDevice();
	if(outputParameters.device == paNoDevice) {
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
	if(err != paNoError)
		goto error;

	//Audio Generation
	err = Pa_StartStream(stream);
	if(err != paNoError)
		goto error;

	//Composite Wave Form for Chord
	int* waveform_one = AudioGeneration::generateWaveForm();
	int* waveform_two = AudioGeneration::generateWaveForm();
	int* waveform_thr = AudioGeneration::generateWaveForm();
	int* waveform_end = new int[SAMPLE_RATE];

	for(int i = 0; i < SAMPLE_RATE; i++)
		waveform_end[i] = waveform_one[i] + waveform_two[i] + waveform_thr[i];

	bufferCount = ((duration * SAMPLE_RATE) / FRAMES_PER_BUFFER);

	//Add Waveform to buffer then output
	for(int i = 0; i < bufferCount; i++) {
		for(int j = 0; j < FRAMES_PER_BUFFER; j++) {
			buffer[j][0] = waveform_end[phase];
			buffer[j][1] = waveform_end[phase];
			phase++;
			if (phase >= TABLE_SIZE)
				phase -= TABLE_SIZE;
		}

		err = Pa_WriteStream(stream, buffer, FRAMES_PER_BUFFER);
		if(err != paNoError)
			goto error;

	}

	err = Pa_StopStream(stream);
	if(err != paNoError)
		goto error;

	err = Pa_CloseStream(stream);
	if(err != paNoError)
		goto error;

	Pa_Terminate();
	std::cout << "No Error" << std::endl;

	return err;

error:
	std::cout << stderr << "An error has occured in the portaudio stream \n" << std::endl;
	std::cout << stderr << "Error Number: "  << err << std::endl;
	std::cout << stderr << "Error Message: " << Pa_GetErrorText(err);

	Pa_Terminate();
	return err;
}

int* AudioGeneration::generateWaveForm(float frequency, float duration) {
	int* waveform = new int[SAMPLE_RATE];

	for(int i = 0; i < SAMPLE_RATE; i++)
		waveform[i] = (float)sin(((double)i / (double)SAMPLE_RATE) * PI * 2 * frequency);
	
	return waveform;
}

float* AudioGeneration::findMelody(Song song) {
	//This is where frequencies of notes will be stored
	float* melody = new float[SONG_LENGTH];

	//Turns all of the Notes in melody into frequencies
	for(int i = 0; i < SONG_LENGTH; i++)
		melody[i] = song->melody.at(i).getFrequency();
	
	return melody;
}

float* AudioGeneration::findHarmony(Song song) {
	float* harmony = new float[SONG_LENGTH * 3];
	int index = 0;

	for(int i = 0; i < SONG_LENGTH * 3; i++) {
		for(int j = 0; j < 3; j++) {

		}
	}
}