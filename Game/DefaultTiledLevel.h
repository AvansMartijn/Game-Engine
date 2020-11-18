#pragma once
#include "AbstractLevel.h"
#include "TiledGameObject.h"

class DefaultTiledLevel : public AbstractLevel
{
private:
public:
	std::vector<TiledGameObject> gameObjects;
	int tileWidth;
	int tileHeight;

	/// <summary>
	/// Create the level.
	/// </summary>
	/// <param name="gameEngine">The game engine</param>
	void createLevel(GameEngine gameEngine);

	/// <summary>
	/// Get's the texture key from the path.
	/// </summary>
	/// <param name="prefix">The prefix we want to use.</param>
	/// <param name="path">The texture path.</param>
	/// <returns>The texture key.</returns>
	std::string getTextureKeyFromPath(std::string prefix, std::string& path);
};

