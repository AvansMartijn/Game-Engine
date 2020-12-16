#include "TiledLevelLoader.h"

void TiledLevelLoader::createLevel(GameEngine& gameEngine, const std::string& name) {
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

TiledLevel TiledLevelLoader::getTiledLevel(const std::string& name) {
	std::string fileDir = directory + name + ".json";

	TiledLevel level = TiledMapBuilder().build(fileDir);

	return level;
}

std::vector<TiledGameObject> TiledLevelLoader::getTiledGameObjects(const TiledLevel& level) {
	std::vector<TiledGameObject> gameObjects;

	for (size_t layerIndex = 0; layerIndex < level.layers.size(); layerIndex++) {
		TiledLayer layer = level.layers[layerIndex];

		if (layer.type == "tilelayer") {
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
					TiledGameObject tiledGameObject = { layer.name, layer.type, to_string(tile.id), "", x, y, tile.imageWidth, tile.imageHeight, tile.image, properties };

					gameObjects.push_back(tiledGameObject);
				}

				x++;
				i++;
			}
		}
		else if (layer.type == "objectgroup") {
			for (size_t objectIndex = 0; objectIndex < layer.objects.size(); objectIndex++) {
				TiledObject tiledObject = layer.objects[objectIndex];
				
				float maxWidth = (float)level.width * (float)level.tileWidth;
				float maxHeight = (float)level.height * (float)level.tileHeight;
				int x = (int)ceil((float)tiledObject.x / (float)level.tileWidth);
				int y = (int)ceil((float)tiledObject.y / (float)level.tileHeight);

				std::map<std::string, TiledProperty> properties;

				for (size_t propertyIndex = 0; propertyIndex < tiledObject.properties.size(); propertyIndex++) {
					TiledProperty prop = tiledObject.properties[propertyIndex];
					properties.insert(std::make_pair(prop.name, prop));
				}

				TiledGameObject tiledGameObject = { layer.name, layer.type, tiledObject.name, tiledObject.type, x, y, 256, 256, "", properties };

				gameObjects.push_back(tiledGameObject);
			}
		}
	}

	return gameObjects;
}

TiledTileSet TiledLevelLoader::findTileSetForGid(const TiledLevel& level, int gid) const {

	int correctTileSetIndex = -1;
	for (size_t tileSetIndex = 0; tileSetIndex < level.tileSets.size(); tileSetIndex++) {
		TiledTileSet tileSet = level.tileSets[tileSetIndex];

		if (correctTileSetIndex > -1) {
			TiledTileSet correctTileSet = level.tileSets[correctTileSetIndex];

			if (tileSet.firstGid > correctTileSet.firstGid && tileSet.firstGid <= gid)
				correctTileSetIndex = (int)tileSetIndex;
		}
		else if (tileSet.firstGid <= gid)
			correctTileSetIndex = (int)tileSetIndex;
	}

	if (correctTileSetIndex == -1)
		throw invalid_argument("This file is corrupt");
	
	return level.tileSets[correctTileSetIndex];
}

TiledTile TiledLevelLoader::findTileForGid(const TiledTileSet& tileSet, int gid) const {
	int correctTileIndex = -1;
	for (size_t tileIndex = 0; tileIndex < tileSet.tiles.size(); tileIndex++) {
		TiledTile tile = tileSet.tiles[tileIndex];

		if (tile.id == gid - tileSet.firstGid) {
			correctTileIndex = (int)tileIndex;

			break;
		}
	}

	if (correctTileIndex == -1)
		throw invalid_argument("This file is corrupt");

	return tileSet.tiles[correctTileIndex];
}