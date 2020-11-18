#include "DefaultLevelLoader.h"

DefaultLevelLoader::DefaultLevelLoader() {
	_levels.insert(std::make_pair("Default", std::make_shared<DefaultLevel>(DefaultLevel())));
}

void DefaultLevelLoader::createLevel(GameEngine gameEngine, std::string& name) {
	if (_levels.find(name) != _levels.end())
		_levels[name]->createLevel(gameEngine);
}