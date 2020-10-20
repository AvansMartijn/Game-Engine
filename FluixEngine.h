#pragma once
#include "GameObjectFacade.h"
#include "PhysicsFacade.h"

// TODO: Gebruiken we deze nog wel / Kan deze niet gewoon weg? In principe wordt de engine gebruikt d.m.v. AbstractScreen & AbstractGame
class FluixEngine
{
private:
	GameObjectFacade _gameObjectFacade;
	PhysicsFacade _physicsFacade;
public:
};

