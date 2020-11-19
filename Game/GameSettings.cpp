#include "GameSettings.h"

GameSettings GameSettings::instance;

GameSettings::GameSettings() {
}

void GameSettings::save() {
	std::string prefPath = AssetRegistry::getInstance().getPrefPath("Mike", "Laptrop 2");
	nlohmann::json j = saveGame;

	std::ofstream outputStream(prefPath + "save.json");
	outputStream << std::setw(4) << j << std::endl;
}

void GameSettings::load() {
	std::string prefPath = AssetRegistry::getInstance().getPrefPath("Mike", "Laptrop 2");
	std::ifstream inputStream(prefPath + "save.json");

	if (!inputStream.fail()) {
		nlohmann::json j;
		inputStream >> j;

		saveGame = j.get<SaveGame>();
	}
}