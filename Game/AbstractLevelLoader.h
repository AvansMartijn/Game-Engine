#pragma once
#include <memory>
#include "GameEngine.h"

class AbstractLevelLoader
{
protected:
public:
	virtual void createLevel(GameEngine gameEngine, std::string& name) = 0;
};

