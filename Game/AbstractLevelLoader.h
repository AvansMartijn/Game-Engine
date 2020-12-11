#pragma once
#include <memory>
#include "GameEngine.h"

class AbstractLevelLoader {
protected:
public:
	/// <summary>
	/// Create a level.
	/// </summary>
	/// <param name="gameEngine">The game engine.</param>
	/// <param name="name">The name of the level.</param>
	virtual void createLevel(GameEngine gameEngine, std::string& name) = 0;
};

