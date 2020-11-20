#pragma once
#include "AbstractLevel.h"
#include "PlayerMoves.h"
#include <ButtonUiElement.h>
#include <CollisionResolutionPortalExtension.h>
#include <GlueManageableItem.h>
#include <ThrusterManagableItem.h>
#include <PortalManagableItem.h>

class DefaultLevel : public AbstractLevel
{
private:
public:
	/// <summary>
	/// Create the level.
	/// </summary>
	/// <param name="gameEngine">The game engine</param>
	void createLevel(GameEngine gameEngine);
};

