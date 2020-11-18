#pragma once
#include <vector>
#include "TiledProperty.h"

struct TiledGameObject {
	int x;
	int y;
	int width;
	int height;
	std::string image;
	std::map<std::string, TiledProperty> properties;
};