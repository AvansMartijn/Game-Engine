#pragma once
#include <string>
enum class LevelType {
	DEFAULT,
	TILED
};

struct LevelData {
	std::string levelName;
	LevelType levelType;
};

