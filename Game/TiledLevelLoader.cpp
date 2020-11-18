#include "TiledLevelLoader.h"

void TiledLevelLoader::createLevel(GameEngine gameEngine, std::string& name) {
	// Don't reload data from the file if we already have the correct game objects.
	if (name != _currentName) {
		TiledLevel tiledLevel = getTiledLevel(name);
		std::vector<TiledGameObject> gameObjects = getTiledGameObjects(tiledLevel);
		_defaultTiledLevel.gameObjects = gameObjects;
		_defaultTiledLevel.tileWidth = tiledLevel.tileWidth;
		_defaultTiledLevel.tileHeight = tiledLevel.tileHeight;
		_currentName = name;
	}

	_defaultTiledLevel.createLevel(gameEngine);
}

TiledLevel TiledLevelLoader::getTiledLevel(std::string& name) {
	// TODO: Custom Properties
	std::string fileDir = AssetRegistry::getInstance().getBasePath() + "res\\levels\\" + name + ".json";

	TiledLevel level = TiledMapBuilder().build(fileDir);

	return level;
}

std::vector<TiledGameObject> TiledLevelLoader::getTiledGameObjects(TiledLevel& level) {
	std::vector<TiledGameObject> gameObjects;

	for (size_t layerIndex = 0; layerIndex < level.layers.size(); layerIndex++) {
		TiledLayer layer = level.layers[layerIndex];
		int x = 1;
		int y = 1;

		int i = 0;
		for (size_t gidIndex = 0; gidIndex < layer.tileGIDs.size(); gidIndex++) {
			// Calculates the x and y coordinates.
			if (i > 0 && i == layer.width) {
				i = 0;
				x = 1;
				y++;
			}

			uint32_t gid = layer.tileGIDs[gidIndex];

			if (gid != 0) {
				TiledTileSet tileSet = findTileSetForGid(level, gid);

				TiledTile tile = findTileForGid(tileSet, gid);

				std::map<std::string, TiledProperty> properties;

				for (size_t propertyIndex = 0; propertyIndex < tile.properties.size(); propertyIndex++) {
					TiledProperty prop = tile.properties[propertyIndex];
					properties.insert(std::make_pair(prop.name, prop));
				}
				TiledGameObject tiledGameObject = { x, y, tile.imageWidth, tile.imageHeight, tile.image, properties };
		
				gameObjects.push_back(tiledGameObject);
			}

			x++;
			i++;
		}
	}

	return gameObjects;
}

TiledTileSet TiledLevelLoader::findTileSetForGid(TiledLevel& level, int gid) const {

	int correctTileSetIndex = -1;
	for (size_t tileSetIndex = 0; tileSetIndex < level.tileSets.size(); tileSetIndex++) {
		TiledTileSet tileSet = level.tileSets[tileSetIndex];

		if (correctTileSetIndex > -1) {
			TiledTileSet correctTileSet = level.tileSets[correctTileSetIndex];

			if (tileSet.firstGid > correctTileSet.firstGid && tileSet.firstGid <= gid)
				correctTileSetIndex = tileSetIndex;
		}
		else if (tileSet.firstGid <= gid)
			correctTileSetIndex = tileSetIndex;
	}

	if (correctTileSetIndex == -1)
		throw invalid_argument("This file is corrupt");
	
	return level.tileSets[correctTileSetIndex];
}

TiledTile TiledLevelLoader::findTileForGid(TiledTileSet& tileSet, int gid) const {
	int correctTileIndex = -1;
	for (size_t tileIndex = 0; tileIndex < tileSet.tiles.size(); tileIndex++) {
		TiledTile tile = tileSet.tiles[tileIndex];

		if (tile.id == gid - tileSet.firstGid) {
			correctTileIndex = tileIndex;

			break;
		}
	}

	if (correctTileIndex == -1)
		throw invalid_argument("This file is corrupt");

	return tileSet.tiles[correctTileIndex];
}