#pragma once
#include "AbstractLevelLoader.h"
#include "TiledMapBuilder.h"
#include "TiledGameObject.h"
#include "DefaultTiledLevel.h"
#include "TiledProperty.h"

class TiledLevelLoader : public AbstractLevelLoader {
private:
	DefaultTiledLevel _defaultTiledLevel;
	std::string _currentName;
public:
	/// <summary>
	/// Create a level.
	/// </summary>
	/// <param name="gameEngine">The game engine.</param>
	/// <param name="name">The name of the level.</param>
	void createLevel(GameEngine gameEngine, std::string& name);

	/// <summary>
	/// Get's the tiled level from the given name.
	/// </summary>
	/// <param name="name">The name of the tiled level.</param>
	/// <returns>The tiled level.</returns>
	TiledLevel getTiledLevel(std::string& name);

	/// <summary>
	/// Get's all the tiled game objects from the tiled level.
	/// </summary>
	/// <param name="tiledLevel">The tiled level.</param>
	/// <returns>All the tiled game objects from the tiled level.</returns>
	std::vector<TiledGameObject> getTiledGameObjects(TiledLevel& tiledLevel);

	/// <summary>
	/// Find the correct tile set for the given GID.
	/// </summary>
	/// <param name="level">The tiled level we want to search in.</param>
	/// <param name="gid">The tile GID.</param>
	/// <returns>The correct tile set.</returns>
	TiledTileSet findTileSetForGid(TiledLevel& level, int gid) const;

	/// <summary>
	/// Find the correct tile from the GID.
	/// </summary>
	/// <param name="tileSet">The tile set we want to search in.</param>
	/// <param name="gid">The tile GID.</param>
	/// <returns>The correct tile.</returns>
	TiledTile findTileForGid(TiledTileSet& tileSet, int gid) const;
};