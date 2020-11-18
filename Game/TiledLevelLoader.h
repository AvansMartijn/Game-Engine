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
	TiledLevel getTiledLevel(std::string& name);
	std::vector<TiledGameObject> getTiledGameObjects(TiledLevel& tiledLevel);
	TiledTileSet findTileSetForGid(TiledLevel& level, int gid) const;
	TiledTile findTileForGid(TiledTileSet& tileSet, int gid) const;
};