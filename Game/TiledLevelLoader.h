#pragma once
#include "AbstractLevelLoader.h"
#include "TiledMapBuilder.h"

class TiledLevelLoader : public AbstractLevelLoader
{
private:

public:
	void createLevel(GameEngine gameEngine);
};

