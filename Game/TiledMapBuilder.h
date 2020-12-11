#pragma once
#include "TiledLevel.h"
#include <fstream>
#include "json.h"

class TiledMapBuilder {
private:
	std::ifstream _inputStream;
public:
	TiledMapBuilder() {}
	~TiledMapBuilder();

	TiledMapBuilder(const TiledMapBuilder&) = delete;
	TiledMapBuilder& operator=(const TiledMapBuilder&) = delete;
	TiledMapBuilder(TiledMapBuilder&&) = delete;
	TiledMapBuilder& operator=(TiledMapBuilder&&) = delete;

	/// <summary>
	/// Build the level.
	/// </summary>
	/// <param name="fileLocation">The location of the file we want to load.</param>
	/// <returns>The level which we build.</returns>
	TiledLevel build(std::string& fileLocation);
};

