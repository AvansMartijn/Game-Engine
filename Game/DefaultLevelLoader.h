#pragma once
#include "AbstractLevelLoader.h"
#include <CollisionResolutionPortalExtension.h>
#include "AbstractLevel.h"

class DefaultLevelLoader : public AbstractLevelLoader {
private:
	std::map<std::string, unique_ptr<AbstractLevel>> _levels;
public:
	DefaultLevelLoader();

	/// <summary>
	/// Create a level.
	/// </summary>
	/// <param name="gameEngine">The game engine.</param>
	/// <param name="name">The name of the level.</param>
	void createLevel(GameEngine& gameEngine, const std::string& name);
};

