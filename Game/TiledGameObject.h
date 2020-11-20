#pragma once
#include <vector>
#include "TiledProperty.h"

struct TiledGameObject {
	std::string layerType;
	std::string layer;
	std::string name;
	std::string type;
	int x;
	int y;
	int width;
	int height;
	std::string image;
	std::map<std::string, TiledProperty> properties;
};