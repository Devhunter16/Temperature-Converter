#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>

using namespace std;

/**
* This program reads information from a file, processes the information and prints the information to a different file.
* 
* Author: Devin Hunter
* 9/24/21
*/

class ReadAndWrite {                                         // This is my class which contains functions to read a files and write to files.
public:
	void readFile();
	void getCelcius();
	void writeFile();
	vector<string> cityNames; 
	vector<double> cityTempsF;
	vector<double> cityTempsC;
private:
	string city;
	int temp;	
	int i;
	double celciusTemp;
	double farenheightTemp;
};

	void ReadAndWrite::readFile() {
		ifstream inFS;                                        // This is my input file stream.
		inFS.open("FahrenheitTemperature.txt");               // Here I  open the file and print an error message is the file does not open properly.
		if (!inFS.is_open()) {
			cout << "Could not open file." << endl;
		}
		while (!inFS.eof()) {                                 // This while loop goes through and gets each city and temperature from the file.
			inFS >> city;
			cityNames.push_back(city);
			inFS >> temp;
			cityTempsF.push_back(temp);
		}
		inFS.close();
	}

	void ReadAndWrite::getCelcius() {                          // This function calculates celcius fron farenheight and then stores the new temps in a vector.
		for (i = 0; i < cityTempsF.size(); i++) {
			farenheightTemp = cityTempsF.at(i);
			celciusTemp = (farenheightTemp - 32) * 0.56;
			cityTempsC.push_back(celciusTemp);
		}
	}

	void ReadAndWrite::writeFile() {                           // This function opens a new file and writes the city name and new temp in celcius to the file.
		ofstream newFile("CelciusTemperature.txt");
		for (i = 0; i < cityTempsC.size(); i++) {
			newFile << cityNames.at(i) << " " << cityTempsC.at(i) << endl;
		}
		newFile.close();
	}



int main() {                                                    // Here I call all my functions to read the old file, do calculations with what was read, then write to the new file.
	
	ReadAndWrite file1;

	file1.readFile();
	file1.getCelcius();
	file1.writeFile();

	return(0);
}