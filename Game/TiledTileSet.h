#pragma once
#include "json.h"
#include "TiledGrid.h"
#include "TiledTile.h"

class TiledTileSet
{
private:
public:
	int columns;
	int firstGid;
	TiledGrid grid;
	int margin;
	std::string name;
	int spacing;
	int tileCount;
	int tileHeight;
	std::vector<TiledTile> tiles;
	int tileWidth;
};

inline void from_json(const nlohmann::json& j, TiledTileSet& ts) {
	j.at("columns").get_to(ts.columns);
	j.at("firstgid").get_to(ts.firstGid);
	j.at("grid").get_to(ts.grid);
	j.at("margin").get_to(ts.margin);
	j.at("name").get_to(ts.name);
	j.at("spacing").get_to(ts.spacing);
	j.at("tilecount").get_to(ts.tileCount);
	j.at("tileheight").get_to(ts.tileHeight);
	j.at("tiles").get_to(ts.tiles);
	j.at("tilewidth").get_to(ts.tileWidth);
}