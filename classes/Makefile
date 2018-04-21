CXX = g++
CXXFLAGS = -Wall -g 
LDLIBS = -Llibs/ -lportaudio-2 
INC = ../headers/

test.out: user_input.o note_generator.o chord.o audio_generation.o song_writer.o
	$(CXX) $(CXXFLAGS) $(LDLIBS) -o test.out user_input.o note_generator.o chord.o audio_generation.o song_writer.o

user_input.o: $(INC)user_input.h $(INC)note_generator.h $(INC)chord.h $(INC)audio_generation.h $(INC)song_writer.h
	$(CXX) $(CXXFLAGS) -c user_input.cpp

note_generator.o: $(INC)note_generator.h
	$(CXX) $(CXXFLAGS) -c note_generator.cpp

chord.o: $(INC)chord.h
	$(CXX) $(CXXFLAGS) -c chord.cpp

audio_generation.o: $(INC)audio_generation.h $(INC)portaudio.h $(INC)song_writer.h
	$(CXX) $(CXXFLAGS) -c audio_generation.cpp

song_writer.o: $(INC)song_writer.h $(INC)note_generator.h $(INC)chord.h
	$(CXX) $(CXXFLAGS) -c song_writer.cpp