#include <iostream>
#include "ppm.hpp"

void lighten(std::string filename) {
	PPM myPPM(filename);
	myPPM.lighten();
	myPPM.savePPM("./lighten.ppm");
}

void darken(std::string filename) {
	PPM myPPM(filename);
	myPPM.darken();
	myPPM.savePPM("./darken.ppm");
}

void blueHue(std::string filename) {
	PPM myPPM(filename);
	myPPM.blueHue();
	myPPM.savePPM("./blueHue.ppm");
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cout << "Cannot run program: Usage ./prog file.ppm\n";
		return EXIT_FAILURE;
	}

	lighten(argv[1]);
	darken(argv[1]);
	blueHue(argv[1]);

	return 0;
}
