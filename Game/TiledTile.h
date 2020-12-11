#pragma once
#include "json.h"
#include "TiledProperty.h"

class TiledTile {
public:
	int id;
	std::string image;
	int imageHeight;
	int imageWidth;
	std::vector<TiledProperty> properties;
};


inline void from_json(const nlohmann::json& j, TiledTile& t) {
	j.at("id").get_to(t.id);
	j.at("image").get_to(t.image);
	j.at("imageheight").get_to(t.imageHeight);
	j.at("imagewidth").get_to(t.imageWidth);
	j.at("properties").get_to(t.properties);
}

