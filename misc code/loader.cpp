#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){

string name;

cin >> name;


ifstream loadFile(name);

if (loadFile.is_open()){
	char buffer[16384];
	loadFile.get(buffer, 16384);
	for (int i = 0; buffer[i] != '\0'; ++i ) {
		buffer[i] = buffer[i] - 48;
	}

for (int i = 0; buffer[i] != '\0'; ++i) {
	printf("%d ", buffer[i]);

}
}
cout << endl;
	
}