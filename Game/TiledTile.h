#pragma once
#include "json.h"
class TiledTile
{
private:
public:
	int id;
	std::string image;
	int imageHeight;
	int imageWidth;
};


inline void from_json(const nlohmann::json& j, TiledTile& t) {
	j.at("id").get_to(t.id);
	j.at("image").get_to(t.image);
	j.at("imageheight").get_to(t.imageHeight);
	j.at("imagewidth").get_to(t.imageWidth);
}

