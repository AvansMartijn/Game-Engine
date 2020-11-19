#pragma once
#include "SaveGame.h"
#include "json.h"
#include "AssetRegistry.h"
#include <fstream>
#include <iomanip>
#include "LevelData.h"
class GameSettings

{
private:
	GameSettings();

	static GameSettings instance;
	std::map<int, LevelData> _storyLevels;
public:
	static GameSettings& getInstance() { return instance; }

	GameSettings(const GameSettings&) = delete;
	GameSettings(GameSettings&&) = delete;
	GameSettings& operator=(const GameSettings&) = delete;
	GameSettings& operator=(GameSettings&&) = delete;

	SaveGame saveGame;

	void save();
	void load();

	void addLevel(int number, LevelData levelData);
	LevelData getCurrentLevel();
};

