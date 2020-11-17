#pragma once
#include "AbstractLevelLoader.h"
#include "TiledMapBuilder.h"
#include "TiledGameObject.h"
#include "DefaultTiledLevel.h"

class TiledLevelLoader : public AbstractLevelLoader
{
private:
	DefaultTiledLevel _defaultTiledLevel;
	std::string _currentName;
public:
	void createLevel(GameEngine gameEngine, std::string& name);
	std::vector<TiledGameObject> getTiledGameObjects(std::string& name);
	TiledTileSet findTileSetForGid(TiledLevel& level, uint32_t gid) const;
	TiledTile findTileForGid(TiledTileSet& tileSet, uint32_t gid) const;
};