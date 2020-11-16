#pragma once
#include "json.h"

class TiledGrid
{
public:
	int height;
	std::string orientation;
	int width;
};


inline void from_json(const nlohmann::json& j, TiledGrid& g) {
	j.at("height").get_to(g.height);
	j.at("orientation").get_to(g.orientation);
	j.at("width").get_to(g.width);
}

