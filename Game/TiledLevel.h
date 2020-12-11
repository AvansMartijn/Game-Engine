#pragma once
#include "json.h"
#include "TiledLayer.h"
#include "TiledTileSet.h"
#include <vector>

class TiledLevel {
private:
public:
	int height;
	bool infinite;
	std::vector<TiledLayer> layers;
	int nextLayerId;
	int nextObjectId;
	std::string orientation;
	std::string renderOrder;
	int tileHeight;
	std::vector<TiledTileSet> tileSets;
	int tileWidth;
	std::string type;
	int width;
};

inline void from_json(const nlohmann::json& j, TiledLevel& l) {
	j.at("height").get_to(l.height);
	j.at("infinite").get_to(l.infinite);
	j.at("layers").get_to(l.layers);
	j.at("nextlayerid").get_to(l.nextLayerId);
	j.at("nextobjectid").get_to(l.nextObjectId);
	j.at("orientation").get_to(l.orientation);
	j.at("renderorder").get_to(l.renderOrder);
	j.at("tileheight").get_to(l.tileHeight);
	j.at("tilesets").get_to(l.tileSets);
	j.at("tilewidth").get_to(l.tileWidth);
	j.at("type").get_to(l.type);
	j.at("width").get_to(l.width);

}