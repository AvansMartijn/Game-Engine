#pragma once
#include "AbstractLevel.h"
#include "TiledGameObject.h"

class DefaultTiledLevel : public AbstractLevel
{
private:
public:
	std::vector<TiledGameObject> gameObjects;
	/// <summary>
	/// Create the level.
	/// </summary>
	/// <param name="gameEngine">The game engine</param>
	void createLevel(GameEngine gameEngine);
};

