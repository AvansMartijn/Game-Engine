#pragma once
#include "AbstractLevelLoader.h"
#include "PlayerMoves.h"
#include <CollisionResolutionPortalExtension.h>

class DefaultLevelLoader : public AbstractLevelLoader
{
public:
	void createLevel(GameEngine gameEngine);
};

