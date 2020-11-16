#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_IOFILES __declspec(dllexport)
#else
#define GAMEENGINE_IOFILES __declspec(dllimport)
#endif

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

class GAMEENGINE_IOFILES IOFiles
{
public: 
	/// <summary>
	/// Write a line to a file
	/// </summary>
	/// <param name="FileName"> the filename</param>
	/// <param name="Line">the line that is going to be written</param>
	/// <param name="Append"> true: append , false: overwrite</param>
	void writeToFile(std::string fileName, std::string line, bool append);

	/// <summary>
	/// Write multiple lines to a file
	/// </summary>
	/// <param name="FileName"> the filename</param>
	/// <param name="Lines">the lines that is going to be written</param>
	/// <param name="Append"> true: append , false: overwrite</param>
	void writeToFile(std::string fileName, std::vector<std::string> lines, bool append);

	/// <summary>
	/// read all the lines in the dile
	/// </summary>
	/// <param name="FileName">the filename</param>
	/// <returns>all the lines</returns>
	std::vector<std::string>  readFromFile(std::string fileName);
};

