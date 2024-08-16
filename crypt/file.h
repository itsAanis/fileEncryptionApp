#pragma once
#include <string>
#include <fstream>
#include <iostream>


class File
{
public:
	std::string readFile(const std::string& filePath) {
		std::ifstream files(filePath, std::ios::binary | std::ios::ate);
		if (!files) {
			std::cerr << "Could not open file for reading: " << filePath << std::endl;
			return "";
		}

		std::streamsize size = files.tellg();
		files.seekg(0, std::ios::beg);

		std::string buffer(size, ' ');
		if (!files.read(&buffer[0], size)) {
			std::cerr << "Failed to read file: " << filePath << std::endl;
			return "";
		}
		return buffer;
	}

	void writeFile(const std::string& filePath, const std::string& data) {
		std::ofstream file(filePath, std::ios::binary);
		if (!file) {
			std::cerr << "Could not open file for writing: " << filePath << std::endl;
			return;
		}

		file.write(data.data(), data.size());
		if (!file) {
			std::cerr << "Failed to write to file: " << filePath << std::endl;
		}
	}


};

