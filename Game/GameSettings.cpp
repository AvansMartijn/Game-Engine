#include "GameSettings.h"
#include <SoundPlayer.h>
#include <windows.h>
#include <string>

GameSettings GameSettings::instance;

GameSettings::GameSettings() {}

void GameSettings::save() {
	std::string prefPath = AssetRegistry::getInstance().getPrefPath("Mike", "Latrop 2");
	nlohmann::json j = saveGame;

	std::ofstream outputStream(prefPath + "save.json");
	outputStream << std::setw(4) << j << std::endl;
}

void GameSettings::load() {
	std::string prefPath = AssetRegistry::getInstance().getPrefPath("Mike", "Latrop 2");
	std::ifstream inputStream(prefPath + "save.json");

	if (!inputStream.fail()) {
		nlohmann::json j;
		inputStream >> j;

		saveGame = j.get<SaveGame>();
	}

	SoundPlayer::getInstance().changeMusicVolume(saveGame.settings.sound);
	SoundPlayer::getInstance().changeSFXVolume(saveGame.settings.soundFx);

	std::string levelDirectory = prefPath + "Levels\\";

	CreateDirectoryA(levelDirectory.c_str(), NULL);
}

void GameSettings::addLevel(int number, const LevelData& levelData) {
	bool found = false;
	for (size_t levelIndex = 0; levelIndex < saveGame.levels.size(); levelIndex++) {
		SaveLevel data = saveGame.levels[levelIndex];
		if (data.name == levelData.levelName) {
			found = true;
			break;
		}
	}
	
	if (!found) {
		SaveLevel saveLevel;
		saveLevel.name = levelData.levelName;
		saveGame.levels.push_back(saveLevel);
		save();
	}

	_storyLevels.insert(std::make_pair(number, levelData));
}

bool GameSettings::isStoryLevel(const LevelData& levelData) {
	bool found = false;
	for (size_t levelIndex = 0; levelIndex < saveGame.levels.size(); levelIndex++) {
		SaveLevel data = saveGame.levels[levelIndex];
		if (data.name == levelData.levelName) {
			found = true;
			break;
		}
	}

	return found;
}

LevelData GameSettings::getCurrentLevel() {
	switch (saveGame.currentSlot)
	{
	case 0 :
		return _storyLevels[saveGame.customSlot];
		break;
	case 1:
		return _storyLevels[saveGame.slot1];
		break;

	case 2:
		return _storyLevels[saveGame.slot2];
		break;
	case 3:
		return _storyLevels[saveGame.slot3];
		break;
	default:
		return {};
		break;
	}
}

LevelData GameSettings::getLevelByIndex(int i) {
	return _storyLevels[i];
}

LevelData GameSettings::getNextLevel() {
	if (saveGame.currentSlot == 1) {
		if (saveGame.slot1 >= (int)_storyLevels.size())
			return {};

		return _storyLevels[saveGame.slot1 + 1];
	}

	if (saveGame.currentSlot == 2) {
		if (saveGame.slot2 >= (int)_storyLevels.size())
			return {};

		return _storyLevels[saveGame.slot2 + 1];
	}

	if (saveGame.currentSlot == 3) {
		if (saveGame.slot3 >= (int)_storyLevels.size())
			return {};

		return _storyLevels[saveGame.slot3 + 1];
	}

	return {};
}

int GameSettings::getIndexByLevelName(const std::string& name) const {
	auto levelPair = std::find_if(_storyLevels.begin(), _storyLevels.end(), [name](std::pair<int, LevelData> level ) { return level.second.levelName == name; });

	if (levelPair != _storyLevels.end())
		return (*levelPair).first;

	return -1;
}
