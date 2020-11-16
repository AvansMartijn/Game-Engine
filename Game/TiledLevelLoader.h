#pragma once
#include "AbstractLevelLoader.h"
#include "TiledMapBuilder.h"
#include "TiledGameObject.h"

class TiledLevelLoader : public AbstractLevelLoader
{
private:

public:
	void createLevel(GameEngine gameEngine);
	std::vector<TiledGameObject> getTiledGameObjects();
	TiledTileSet findTileSetForGid(TiledLevel& level, uint32_t gid);
	TiledTile findTileForGid(TiledTileSet& tileSet, uint32_t gid);
};