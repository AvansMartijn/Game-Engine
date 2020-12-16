#include "DefaultLevelLoader.h"

DefaultLevelLoader::DefaultLevelLoader() {
	_levels.insert(std::make_pair("Default", std::make_unique<DefaultLevel>(DefaultLevel())));
}

void DefaultLevelLoader::createLevel(GameEngine gameEngine, const std::string& name) {
	if (_levels.find(name) != _levels.end())
		_levels[name]->createLevel(gameEngine);
}