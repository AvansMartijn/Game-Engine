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

	TiledLevel build(std::string& fileLocation);
};

