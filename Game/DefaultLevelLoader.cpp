#include "DefaultLevelLoader.h"

DefaultLevelLoader::DefaultLevelLoader() {
}

void DefaultLevelLoader::createLevel(GameEngine& gameEngine, const std::string& name) {
	if (_levels.find(name) != _levels.end())
		_levels[name]->createLevel(gameEngine);
}