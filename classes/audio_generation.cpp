#include "../headers/audio_generation.h"

int main() {

	//SetUp PortAudio
	PaStreamParameters outputParameters;
	PaStream *stream;
	PaError err;
	float buffer[FRAMES_PER_BUFFER][2];
	float sine[TABLE_SIZE];
	int left_phase = 0;
	int right_phase = 0;
	int left_inc = 1;
	int right_inc = 3;
	int bufferCount;

	//Fill Table With Sine Values
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		sine[i] = (float)sin(((double)i / (double)TABLE_SIZE) * PI * 2.);
	}

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

	std::cout << "Stream Opened" << std::endl;

	//Audio Generation
	for (int k = 0; k < 3; ++k) {
		err = Pa_StartStream(stream);
		if (err != paNoError)
			goto error;

		bufferCount = ((NUM_SECONDS * SAMPLE_RATE) / FRAMES_PER_BUFFER);

		for (int i = 0; i < bufferCount; i++) {
			for (int j = 0; j < FRAMES_PER_BUFFER; j++) {
				buffer[j][0] = sine[left_phase];
				buffer[j][1] = sine[right_phase];
				left_phase  += left_inc;
				if (left_phase >= TABLE_SIZE)
					left_phase -= TABLE_SIZE;
				right_phase += right_inc;
				if (right_phase >= TABLE_SIZE)
					right_phase -= TABLE_SIZE;
			}

			err = Pa_WriteStream(stream, buffer, FRAMES_PER_BUFFER);
			if (err != paNoError)
				goto error;
		}

		err = Pa_StopStream(stream);
		if (err != paNoError)
			goto error;

		++left_inc;
		++right_inc;

		Pa_Sleep(1000);
	}

	//Clean Up
	err = Pa_CloseStream(stream);
	if (err != paNoError)
		goto error;

	Pa_Terminate();
	std::cout << "No Error" << std::endl;

	return err;

error:
	 std::cout << stderr << "An error has occured in the portaudio stream\n";
	 std::cout << stderr << "Error Number: " << err << std::endl;
	 std::cout << stderr << "Error Message: " << Pa_GetErrorText(err);

	 Pa_Terminate();
	 return err;
}