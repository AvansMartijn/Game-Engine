#include "pch.h"
#include "IOFiles.h"

void IOFiles::writeToFile(std::string fileName, std::string line, bool append) {
	std::ofstream file;
	//check if overwrite is needed or append
	if (append)
		file.open(fileName + ".txt", std::ios_base::app); // append instead of overwrite
	else
		file.open(fileName + ".txt"); // overwrite instead of append

	//write the line
	if (file.is_open()) {
		file << line << "\n";
		file.close();
	}
	else {
		throw std::runtime_error("Unable to open file");
	}
}

void IOFiles::writeToFile(std::string fileName, std::vector<std::string> lines, bool append) {
	std::ofstream file;

	if (append)
		file.open(fileName + ".txt", std::ios_base::app); 
	else
		file.open(fileName + ".txt");

	if (file.is_open()) {
		for (std::string line : lines) {
			file << line << "\n";
		}
		file.close();
	}
	else {
		throw std::runtime_error("Unable to open file");
	}
}

std::vector<std::string> IOFiles::readFromFile(std::string fileName) {

	std::ifstream file(fileName + ".txt");
	std::vector<std::string> lines;

	if (file.is_open()) {

		std::string line;
		while (std::getline(file, line)) {
			if (line.size() > 0)
				lines.push_back(line);
		}
		file.close();
	}

	return lines;
}