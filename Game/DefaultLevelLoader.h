#pragma once
#include "AbstractLevelLoader.h"
#include <CollisionResolutionPortalExtension.h>
#include "DefaultLevel.h"

class DefaultLevelLoader : public AbstractLevelLoader {
private:
	std::map<std::string, shared_ptr<AbstractLevel>> _levels;
public:
	DefaultLevelLoader();

	/// <summary>
	/// Create a level.
	/// </summary>
	/// <param name="gameEngine">The game engine.</param>
	/// <param name="name">The name of the level.</param>
	void createLevel(GameEngine gameEngine, std::string& name);
};

