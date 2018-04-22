CXX = g++
CXXFLAGS = -Wall -g 
LDLIBS = -Llibs -lportaudio-2 
INC = ../headers/

audio.out: user_input.o note_generator.o chord.o audio_generation.o song_writer.o
	$(CXX) $(CXXFLAGS) $(LDLIBS) -o audio.out user_input.o note_generator.o chord.o audio_generation.o song_writer.o

user_input.o: $(INC)user_input.h $(INC)note_generator.h $(INC)chord.h $(INC)audio_generation.h $(INC)song_writer.h user_input.cpp
	$(CXX) $(CXXFLAGS) -c user_input.cpp

note_generator.o: $(INC)note_generator.h note_generator.cpp
	$(CXX) $(CXXFLAGS) -c note_generator.cpp

chord.o: $(INC)chord.h chord.cpp
	$(CXX) $(CXXFLAGS) -c chord.cpp

audio_generation.o: $(INC)audio_generation.h $(INC)portaudio.h $(INC)song_writer.h audio_generation.cpp
	$(CXX) $(CXXFLAGS) -c audio_generation.cpp

song_writer.o: $(INC)song_writer.h $(INC)note_generator.h $(INC)chord.h song_writer.cpp
	$(CXX) $(CXXFLAGS) -c song_writer.cpp