// header file
// Header hiles serve as interfaces
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "pixel.hpp"

class PPM {
public:
	// Constructor
	PPM(std::string filename);
	
	// Destructor
	~PPM();

	void savePPM(std::string outFileName);

	void lighten();
	void darken();
	void blueHue();

private:
	std::vector<int> mPixels;
	int mWidth;
	int mHeight;
	int mMaxRange;
};
