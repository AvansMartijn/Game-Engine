#include "pch.h"
#include "IOFiles.h"


void IOFiles::writeToFile(std::string FileName, std::string Line, bool Append)
{
	std::ofstream file;

	//check if overwrite is needed or append
	if (Append)
		file.open("Highscores.txt", std::ios_base::app); // append instead of overwrite
	else
		file.open("Highscores.txt"); // overwrite instead of append

	//write the line
	if (file.is_open())
	{
		file << Line << "\n";
		file.close();
	}
	else
	{
		throw std::runtime_error("Unable to open file");
	}
}

void IOFiles::writeToFile(std::string FileName, std::vector<std::string> Lines, bool Append)
{
	std::ofstream file;

	//check if overwrite is needed or append
	if (Append)
		file.open("Highscores.txt", std::ios_base::app); // append instead of overwrite
	else
		file.open("Highscores.txt"); // overwrite instead of append


	if (file.is_open())
	{
		for (std::string Line : Lines)
		{
			file << Line << "\n";
		}
		
		file.close();
	}
	else
	{
		throw std::runtime_error("Unable to open file");
	}
}

std::vector<std::string> IOFiles::readFromFile(std::string FileName)
{

	std::ifstream file(FileName + ".txt");
	std::vector<std::string> Lines;

	if (file.is_open())
	{
		std::string line;
		// Read the next line from File untill it reaches the end.
		while (std::getline(file, line))
		{
			// Line contains string of length > 0 then save it in vector
			if (line.size() > 0)
				Lines.push_back(line);
		}
		file.close();
	}
	else
	{
		throw std::runtime_error("Unable to open file");
	}
	return Lines;
}
