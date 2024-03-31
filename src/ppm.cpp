// source file
// Serves as the implementation of our interface
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include "ppm.hpp"

PPM::PPM(std::string filename){
	//std::cout << "PPM::PPM\n";
	std::ifstream inputFile;
	inputFile.open(filename);

	bool foundP3 = false;
	bool foundDimensions = false;
	bool foundRange = false;
	bool readingPixels = false;
	
	// If file successfully opened up
	if (inputFile.is_open()) {
		std::cout << filename << " was opened. Processing image." << std::endl;
		std::string line;
		
		// Read one line at a time
		while(std::getline(inputFile, line)) {
			std::stringstream stream(line);
			
			// Reach each space seperated character
			std::string chunkOfData;
			while (stream >> chunkOfData) {
				if (chunkOfData[0] == '#') {
					//std::cout << line  << std::endl;
					break;
				}
				else if (false == foundP3) {
					if (chunkOfData == "P3") {
						//std::cout << "Found P3: " << line << std::endl;
					}
					foundP3 = true;
				}
				else if (false == foundDimensions) {
					int data = std::stoi(chunkOfData);
					mWidth = data;
					stream >> chunkOfData;
					mHeight = std::stoi(chunkOfData);
					foundDimensions = true;
				}
				else if (false == foundRange) {
					mMaxRange = std::stoi(chunkOfData);
					foundRange = true;
				}
				else {
					int data = std::stoi(chunkOfData);
					mPixels.push_back(data);
				}
			
			}
		}
		inputFile.close();
	}
	else
		std::cout << "No file opened\n";
}

PPM::~PPM() {

}

void PPM::savePPM(std::string outFileName) {
	std::ofstream myFile;
	myFile.open(outFileName);
	myFile << "P3\n";
	myFile << "# Created w/ c++ code.\n";
	myFile << mWidth << " " << mHeight << "\n";
	myFile << mMaxRange << "\n";

	for (int i = 0; i < mPixels.size(); i++) {
		myFile << mPixels[i] << std::endl;
	}

	myFile.close();
}

void PPM::lighten() {
	for (int i = 0; i < mPixels.size(); i++) {
		int data = mPixels[i]*2;
		mPixels[i] = std::clamp(data, 0, mMaxRange);
	}
}

void PPM::darken() {
	for (int i = 0; i < mPixels.size(); i++) {
		int data = mPixels[i]/4;
		mPixels[i] = std::clamp(data, 0, mMaxRange);
	}

}

void PPM::blueHue() {
	for (int i = 0; i < mPixels.size(); i+=3) {
		int data = mPixels[i]/4;
		mPixels[i] = std::clamp(data, 0, mMaxRange);
	}
}

