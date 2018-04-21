#include "../headers/user_input.h"
#include <limits>
#include <stdexcept>



int main() 
{
	SongWriter s_w();

	char user_input;
	bool run_program = true; 

	cout << "Welcome to group 9's project!" << endl;

	while(run_program){

		cout 	<< "< Please input your desired command >" << endl;
		cout 	<< "1. Play a new song" << endl
				<< "2. Print the song" << endl
				<< "3. Save Song" << endl
				<< "4. Load and play a saved song" << endl
				<< "5. Exit program" << endl;

		try 
		{
			cin >> user_input;
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
				// do stuff
				break;
			}
			case '2':
			{
				cout << "Song notes:" << endl; 
				// call songwriter class and the print() method
				break;
			}
			case '3':
			{
				std::string song_name;
				cout << "Please name the song:" << endl;
				cin >> song_name;
				UserInput::save(song_name);
				break;
			}
			case '4':
			{
				std::string song_name; 
				cout << "Please enter the name of the song you wish to play: ";
				cin >> song_name;
				song_name.append(".txt");
				UserInput::load(song_name);
				break;
			}
			case '5':
			{
				cout << "Goodbye!" << endl;
				run_program = false;
				break;
			}
			default:
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Invalid input. Please try again" << endl;
				break;
			}
		}
	}	
}

void UserInput::save(std::string song_name){

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
