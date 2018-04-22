#include "../headers/audio_generation.h"
#include <math.h>


/**************************************************
	This class makes use of the Portaudio library.
	Portaudio is across platform library that allows 
	us to use our code on different platforms. 
	That being said, we are specifically targetting
	Windows OS running minGW.
***************************************************/

//Debug Function, uncomment to use
/*
int main() {
	SongWriter sw = SongWriter();
	sw.writeSong();
	sw.printSong(true);
	AudioGeneration::play(sw);
}
*/

int p = 0;

/*
	Plays the song it's passed
	
	We utilize the portaudio stream in this function extensively.
	The stream, once properly set up, takes multiple buffers of 
	frequencies then outputs them on the default audio device for
	the system which is found during the discovery process
*/
bool AudioGeneration::play(SongWriter song) 
{
	//PortAudio Setup
	PaStreamParameters outputParameters;
	PaStream* stream;
	PaError err;
	float buffer[FRAMES_PER_BUFFER][2];
	int phase = 0;
	int bufferCount;

	//Song Info
	Chord* harmony;
	float* melody;
	float* harmony_current;
	float* melody_current;

	harmony = song.getChords();
	melody  = song.getMelody();
	
	//Initialize the Stream
	err = Pa_Initialize();
	if (err != paNoError)
		goto error;

	//Checks if should output from speakers or headphones
	outputParameters.device = Pa_GetDefaultOutputDevice();
	if (outputParameters.device == paNoDevice) 
	{
		std::cout << stderr << "Error: No Output Devices Found" << std::endl;
		goto error;
	}

	//Uses what we know about the system to output correctly
	outputParameters.channelCount = 2; //Stereo Output
	outputParameters.sampleFormat = paFloat32;
	outputParameters.suggestedLatency = Pa_GetDeviceInfo(outputParameters.device)->defaultLowOutputLatency;
	outputParameters.hostApiSpecificStreamInfo = nullptr;

	err = Pa_OpenStream(
		&stream,
		nullptr,
		&outputParameters,
		SAMPLE_RATE,
		FRAMES_PER_BUFFER,
		paNoFlag,
		nullptr,
		nullptr);
	if (err != paNoError)
		goto error;

	//Audio Generation Begins
	err = Pa_StartStream(stream);
		if (err != paNoError)
			goto error;
	
	//How many buffers should be created for the wave
	bufferCount = ((NOTE_TIME * SAMPLE_RATE) / FRAMES_PER_BUFFER);

	//Write Waveforms and plays them for each part of a song
	for(int h = 0; h < song.getSongLength() * 4; h++) {

		melody_current = AudioGeneration::generateSineWave(melody[h]);

		if(1==1)//h % 4 == 0)
		{
			int last_chord = floor(h/4);
			harmony_current = AudioGeneration::generateChordWave(harmony[last_chord]);
		}
		for (int i = 0; i < bufferCount; i++) 
		{
		harmony_current[i] = harmony_current[i] + melody_current[i];
		}

		//Add Waveform to buffer then output
		for (int i = 0; i < bufferCount; i++) 		
		{
			for (int j = 0; j < FRAMES_PER_BUFFER; j++) 
			{
				buffer[j][0] = harmony_current[phase];
				buffer[j][1] = harmony_current[phase];
				p++;
				
				phase++;
				
				p = phase;

				if (phase >= TABLE_SIZE)
					phase -= TABLE_SIZE;
			}

			//Writes buffer to stream -> speakers
			err = Pa_WriteStream(stream, buffer, FRAMES_PER_BUFFER);
			if (err != paNoError)
				goto error;
		}

	}

	//Ending the stream
	err = Pa_StopStream(stream);
		if (err != paNoError)
		goto error;

	err = Pa_CloseStream(stream);
	if (err != paNoError)
		goto error;

	//Cleans up anything leftover from the streams
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

/*
	Generates a single sine wave of a given frequency

	The sine waves sound the most pleasing to the ear out
	of the waves we tested (sawtooth, triagle, square, etc.)
	We generate the waves using the formula in the way
	shown below in order to chop up the sine wave into
	samples that the buffer could hold
*/
float* AudioGeneration::generateSineWave(float frequency) 
{
	float* waveform = new float[SAMPLE_RATE];

	for (int i = 0; i < SAMPLE_RATE; i++) 
	{
		waveform[i] = (float)sin(((((double)i + p % SAMPLE_RATE) / (double)SAMPLE_RATE) * PI * 2 * frequency);
	}

	return waveform;
}

/*
	First finds the frequencies of a chord, then creates
	the composite waveform

	This method creates the sum of all of the waves
	that create a chord. Since waves naturally have both
	constructive and destructive properties, we're able to 
	produce a waves that mimics the three notes being played
	simultaneously for our harmonies. 
*/
float* AudioGeneration::generateChordWave(Chord chord) 
{
	float* waveform_one;
	float* waveform_two;
	float* waveform_thr;
	float* waveform_end;

	waveform_one = AudioGeneration::generateSineWave(chord.getNote(0).note_frequency);
	waveform_two = AudioGeneration::generateSineWave(chord.getNote(1).note_frequency);
	waveform_thr = AudioGeneration::generateSineWave(chord.getNote(2).note_frequency);
	waveform_end = new float[SAMPLE_RATE];

	//Attempting to make the tone sound a little "rounder"
	for (int i = 0; i < SAMPLE_RATE; i++) 
	{
		waveform_end[i] = (waveform_one[i] + waveform_two[i] + waveform_thr[i]);
		//if(i < SAMPLE_RATE / 2)
			//waveform_end[i] *= 0.001 * i;
		//else
			//if(i > SAMPLE_RATE / 2)
			//waveform_end[i] *= (SAMPLE_RATE - i)/SAMPLE_RATE;
	}

	return waveform_end;
}