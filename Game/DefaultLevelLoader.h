#pragma once
#include "AbstractLevelLoader.h"
#include <CollisionResolutionPortalExtension.h>
#include "DefaultLevel.h"

class DefaultLevelLoader : public AbstractLevelLoader
{
private:
	std::map<std::string, shared_ptr<AbstractLevel>> _levels;
public:
	DefaultLevelLoader();

	void createLevel(GameEngine gameEngine, std::string& name);
};

