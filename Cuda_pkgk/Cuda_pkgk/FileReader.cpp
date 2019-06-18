#include "FileReader.h"
#include <fstream>
#include <iostream>

bool FileReader::readFileToBuffer(std::string filePath, std::vector<unsigned char>& buffer)
{
	std::ifstream file(filePath, std::ios::binary);
	if (file.fail()) {
		std::cout << "NIE UDALO SIE WCZYTAC PLIKU" << std::endl;
		return false;
	}

	file.seekg(0, std::ios::end);
	int size = file.tellg();
	file.seekg(0, std::ios::beg);
	size -= file.tellg();

	buffer.resize(size);
	file.read((char *)&(buffer[0]), size);
	file.close();

	return true;
}
