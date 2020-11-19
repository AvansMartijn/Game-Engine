#pragma once
#include "SaveGame.h"
#include "json.h"
#include "AssetRegistry.h"
#include <fstream>
#include <iomanip>
class GameSettings
{
private:
	GameSettings();

	static GameSettings instance;
public:
	static GameSettings& getInstance() { return instance; }

	GameSettings(const GameSettings&) = delete;
	GameSettings(GameSettings&&) = delete;
	GameSettings& operator=(const GameSettings&) = delete;
	GameSettings& operator=(GameSettings&&) = delete;

	std::string currentLevel;
	SaveGame saveGame;

	void save();
	void load();
};

