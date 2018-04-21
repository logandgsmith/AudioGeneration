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

		switch(user_input)
		{
			case '1':
			{
				song.writeSong();
				AudioGeneration::play(song);
				break;
			}
			case '2':
			{
				std::cout << "Song notes:" << std::endl; 
				song.printSong();
				break;
			}
			case '3':
			{
				std::string song_name;
				std::cout << "Please name the song:" << std::endl;
				std::cin  >> song_name;
				UserInput::save(song_name);
				break;
			}
			case '4':
			{
				std::string song_name; 
				std::cout << "Please enter the name of the song you wish to play: ";
				std::cin  >> song_name;
				song_name.append(".txt");
				UserInput::load(song_name);
				break;
			}
			case '5':
			{
				std::cout << "Goodbye!" << std::endl;
				run_program = false;
				break;
			}
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

void UserInput::save(std::string song_name, unsigned char* harmony, unsigned char* melody){

ofstream saveFile(song_name);


// getline(cin, printsong()); this is ideally what is supposed to happen. 
// We still need to work on this on the "song writer class".
// my logic may be wrong tho, but it will be easy to fix ;).


//saveFile << getline(cin, printsong());
//this is the the function that actually saves the strings.

saveFile.close();


}


void UserInput::load(std::string song_name){

	ifstream loadFile(song_name);

	if(loadFile.is_open())
	{
		std::string sheet_music;
		std::string har; // Harmony data as a std::string
		std::string mel; // Melody data as a std::string

		getline(loadFile,sheet_music);

		cout << sheet_music << endl;
		
		// The songs are in common time (4/4) w/ all melody notes as quarter notes and all chords as whole notes
		// Hence, for every 4 chords there are 16 melody notes, so only the first fifth are harmony notes
		har = sheet_music.substr(0, (sheet_music.length()/5)); 

		mel = sheet_music.substr((sheet_music.length()/5), sheet_music.length());

		unsigned char harmony [har.length()]; // Harmony data as integers

		unsigned char melody [mel.length()]; // Melody data as integers

		for(unsigned char i = 0; i < har.length(); i++)
			harmony[i] = (unsigned char)(har.at(i) - 48);

		for(unsigned char i = 0; i < mel.length(); i++)
			melody[i] = (unsigned char)(mel.at(i) - 48);

	//Call up songwriter to load unsigned char arrays (I.E. Harmony and Melody)
	}
	else
	{
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
	}

	//TODO: CALL AUDIOGENERATION CLASS TO PLAY THE SONG
}

*/
