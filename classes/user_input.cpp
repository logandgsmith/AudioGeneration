#include "../headers/user_input.h"

/*********************************************************
							MAIN 
	The following code controls the program. It will
	handle any input the user gives it and will display
	the menu along with the outputs of functions. We 
	also give the user the ability to save/load songs
	in this namespace.
**********************************************************/


int main() 
{
	//creates the object song of type SongWriter 
	SongWriter song; 

	char user_input;
	bool run_program = true; 

	std::cout << "Welcome to group 9's project!" << std::endl;

	while(run_program){


		std::cout 	<< "****************************************" << std::endl
				 	<< " < Please input your desired command >"   << std::endl
				 	<< " 1. Play a new song"                      << std::endl
					<< " 2. Print the song"                       << std::endl
					<< " 3. Save Song"                            << std::endl
					<< " 4. Load and play a saved song"           << std::endl
					<< " 5. Exit program"                         << std::endl
					<< "****************************************" << std::endl; 

		//Try and catch statment to prevent bad user input
		try 
		{
			std::cin >> user_input;
		}
		catch (const std::exception &e)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		//A switch statement that utilizes char's. This is evidenced by the single quotes. 
		switch(user_input)
		{

			//generates and plays a unique song on command.
			case '1':
			{

				song.writeSong();
				AudioGeneration::play(song);
				break;

			}

			//Prints the song
			case '2':
			{

				if(song.isEmpty()) {
					std::cout << "There is no song to print yet. Try writing one!" << std::endl;
					break;
				}

				bool isValid = false;
				std::string response;

				while(!isValid) {
					std::cout << "Would you like note names included (y/n)?" << std::endl;
					std::cin  >> response;
					if(response.compare("y") == 0 || response.compare("Y") == 0) {
						std::cout << "Song notes:" << std::endl;
						song.printSong(true);
						isValid = true;
					}
					else if(response.compare("n") == 0 || response.compare("N") == 0) {
						std::cout << "Song notes:" << std::endl;
						song.printSong(false);
						isValid = true;
					}
					else
						std::cout << "That was not a valid response. Please try again." << std::endl;
				}

				break;
			}

			//Saves the song under a desired name
			case '3':
			{

				std::string song_name;
				std::cout << "Please name the song:" << std::endl;
				std::cin  >> song_name;
				UserInput::save(song_name, song.getHarmony(), song.getMelodyIndexes());
				break;

			}

			//Loads a song if it exists
			case '4':
			{

				std::string song_name; 
				std::cout << "Please enter the name of the song you wish to play: ";
				std::cin  >> song_name;
				song_name.append(".txt");
				UserInput::load(song, song_name);
				break;

			}

			//exits program
			case '5':
			{
				std::cout << "Goodbye!" << std::endl;
				run_program = false;
				break;
			}

			//error statement 
			default:
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input. Please try again" << std::endl;
				break;
			}
		}
	}	
}


//user save function
void UserInput::save(std::string song_name, unsigned char* harmony, unsigned char* melody){
	SongWriter sw=SongWriter();
	int length = sw.getSongLength();
	ofstream saveFile(song_name + ".txt");

	for(int i = 0; i < length; i++){
		
		saveFile << (char)(harmony[i] + 48);

	}


	for(int i = 0; i < length*4; i++){

		saveFile << (char)(melody[i] + 48);

	}

	saveFile.close();

<<<<<<< HEAD
}

//load function
void UserInput::load(SongWriter song, std::string song_name){
=======


	// getline(cin, printsong()); this is ideally what is supposed to happen. 
	// We still need to work on this on the "song writer class".
	// my logic may be wrong tho, but it will be easy to fix ;).


	//saveFile << getline(cin, printsong());
	//this is the the function that actually saves the strings.

	saveFile.close();

}


void UserInput::load(SongWriter &song, std::string song_name){
>>>>>>> 6e245dbdec9cc0d58f70bbbaa1a134ca2edb483b

	ifstream loadFile(song_name);

	if(loadFile.is_open())
	{

		std::string sheet_music;
		std::string har; // Harmony data as a std::string
		std::string mel; // Melody data as a std::string

		getline(loadFile,sheet_music);
		
		// The songs are in common time (4/4) w/ all melody notes as quarter notes and all chords as whole notes
		// Hence, for every 4 chords there are 16 melody notes, so only the first fifth are harmony notes
		har = sheet_music.substr(0, (sheet_music.length()/5)); 

		mel = sheet_music.substr((sheet_music.length()/5), sheet_music.length());

		unsigned char* harmony=new unsigned char[har.length()]; // Harmony data as integers

		unsigned char* melody = new unsigned char[mel.length()]; // Melody data as integers

		for(unsigned char i = 0; i < har.length(); i++)
			harmony[i] = (unsigned char)(har.at(i) - 48);

		for(unsigned char i = 0; i < mel.length(); i++)
			melody[i] = (unsigned char)(mel.at(i) - 48);

		song.setHarmony(harmony);
		song.setMelody(melody);

<<<<<<< HEAD
=======
		AudioGeneration::play(song);
>>>>>>> 6e245dbdec9cc0d58f70bbbaa1a134ca2edb483b
	}

	else
	{
<<<<<<< HEAD
		cout << "The file for this song does not exist. Please provide another file name.";
	}
	
}

/*
void UserInput::playBack() {
	//TODO: WRITE A FUNCTION TO FIND SONG .TXT FILES 

	//Checks for valid file names
	bool          isValidFileName = false;
	std::ifstream inFile;
	std::string   token;

	while (!isValidFileName) {
		std::cout << "Please enter the name of the input file:" << std::endl;
		std::getline(std::cin, fileName);
		try {
			inFile.open(fileName);
			if (!inFile)
				throw std::runtime_error("File could not be opened");
		}
		catch (std::runtime_error e) {
			std::cout << e.what() << std::endl;
			continue;
		}

		isValidFileName = true;
	}

	while (inFile >> token) {
		//TODO TURN TOKENS INTO CHORDS THEN ADD TO SONG VECTOR
=======
		std::cout << "The file for this song does not exist. Please provide another file name. \n" << std::endl;
>>>>>>> 6e245dbdec9cc0d58f70bbbaa1a134ca2edb483b
	}
}
