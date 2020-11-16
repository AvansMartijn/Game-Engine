#pragma once
#include "AbstractLevelLoader.h"
class TiledLevelLoader : public AbstractLevelLoader
{
public:
	void createLevel(GameEngine gameEngine);
};

