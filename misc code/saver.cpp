#include <iostream>
#include <string>

int main(){
	
string texttoSave;
cout << "enter string" << endl;
getline(cin, texttoSave);

ofstream saveFile ("Save.txt");

saveFile << texttoSave;

saveFile.close();


}