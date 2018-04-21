CXX = g++
CXXFLAGS = -Wall -g -I../headers/
LDLIBS = -Llibs/ -lportaudio-2

test.out: user_input.o note_generator.o chord.o audio_generation.o song_writer.o
	$(CXX) $(CXXFLAGS) $(LDLIBS) -o test.out user_input.o note_generator.o chord.o audio_generation.o song_writer.o

user_input.o: user_input.h note_generator.h chord.h audio_generation.h song_writer.h
	$(CXX) $(CXXFLAGS) -c user_input.cpp

note_generator.o: note_generator.h
	$(CXX) $(CXXFLAGS) -c note_generator.cpp

chord.o: chord.h
	$(CXX) $(CXXFLAGS) -c chord.cpp

audio_generation.o: audio_generation.h portaudio.h song_writer.h
	$(CXX) $(CXXFLAGS) -c audio_generation.cpp

song_writer.o: song_writer.h note_generator.h chord.h
	$(CXX) $(CXXFLAGS) -c song_writer.cpp