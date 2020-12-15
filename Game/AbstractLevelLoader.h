#pragma once
#include <memory>
#include "GameEngine.h"

class AbstractLevelLoader {
public:
	std::string directory;

	/// <summary>
	/// Create a level.
	/// </summary>
	/// <param name="gameEngine">The game engine.</param>
	/// <param name="name">The name of the level.</param>
	virtual void createLevel(GameEngine gameEngine, const std::string& name) = 0;
};

