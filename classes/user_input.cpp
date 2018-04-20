iostream>
#include <string> 
#include <fstream>
#include "../headers/user_input.h"


int main(){

SongWriter Song_Writer = new SongWriter();

string user_input;
bool run_program = true; 



cout << "Welcome to group 9's project!" << endl;

while(run_program){

	cout << "< Please input your desired command >" << endl;
	cout << "1.Play a new song\n2. Print the song\n3. Save Song\n4.load and play a saved song\n5. Exit prorgram" << endl;

	cin >> user_input;


		if(user_input == "1"){

			// do stuff

		}


		else if (user_input == "2"){

			cout << "Song notes:" << endl; 
			// call songwriter class and the print() method
		}

		else if (user_input == "3"){

			string song_name;
			cout << "Please name the song:" << endl;
			cin >> song_name;
			save(song_name);

		}

		else if (user_input == "4"){

			string song_name; 
			cout << "Please enter the name of the song you wish to play: "
			cin >> song_name + ".txt";
			load(song_name);

		}

		else if (user_input == "5"){

			cout << "Logging out...";
			run_program = false;

		}

		else{

			cout << "Invalid input. Please try again" << endl; 

		}

	}
}


void UserInput::save(string song_name){

ofstream saveFile(song_name);


// getline(cin, printsong()); this is ideally what is supposed to happen. 
// We still need to work on this on the "song writer class".
// my logic may be wrong tho, but it will be easy to fix ;).


//saveFile << getline(cin, printsong());
//this is the the function that actually saves the strings.

saveFile.close();


}


void UserInput::load(string song_name){

ifstream loadFile(song_name);

if(loadFile.is_open()){


	string sheet_music;
	string har;
	string mel;

	//const unsigned char chord_prog_length = 5;

	getline(loadFile,sheet_music);

	cout << sheet_music << endl;

	har = sheet_music.substr(0, (sheet_music.length()/2));

	mel = sheet_music.substr((sheet_music.length()/2), sheet_music.length());

	unsigned char harmony [har.length()];

	unsigned char melody [mel.length()];

	for(unsigned char i = 0; i < chord_prog_length; i++){

		unsigned char temp = ((unsigned char)har[i] - 48);
	
		harmony[i] = temp;

		}

	for(unsigned char i = 0; i < mel.length; i++){

		unsigned char temp = ((unsigned char)mel[i] - 48);

		melody[i] = temp;

		}


	//Call up songwriter to load unsigned char arrays (I.E. Harmony and Melody)

}

else{

	cout << "The file does not exist. Input another name."
	return;

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