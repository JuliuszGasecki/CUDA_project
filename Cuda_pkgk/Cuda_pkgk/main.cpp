#include <iostream>
#include <cstdlib>
#include "loadPNG.h"
//#include <cuda.h>
//#include <cuda_runtime.h>
//#include <functional>
#include <string>
#include <fstream>
#include "FileReader.h"

using namespace std;

int main() {


	vector<unsigned char> decodedImage;
	vector<unsigned char> in;
	unsigned long width, height;

	if (FileReader::readFileToBuffer("D:/Repos/Cpp/CUDA/CUDA_project/Cuda_pkgk/a.png", in) == false) {
		cout << "Fatal ERROR. Cant load image to buffer" << endl;
	}
	else {
		cout << "BUFFER IS FULL OF IMAGE :3" << endl;
	}

	unsigned error = decodePNG(decodedImage, width, height, &(in[0]), in.size());

	if (error != 0) {
		cout << "Fatal ERROR. Cant decode PNG image" << endl;
	}
	else {
		cout << "IMAGE IS DECODED YAY!" << endl;
	}

	int a;
	cin >> a;

	return 0;

}

