#pragma once
#include "SaveGame.h"
#include "json.h"
#include "AssetRegistry.h"
#include <fstream>
#include <iomanip>
#include "LevelData.h"

class GameSettings {
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

	/// <summary>
	/// Save the settings.
	/// </summary>
	void save();

	/// <summary>
	/// Load the settings.
	/// </summary>
	void load();

	/// <summary>
	/// Add a level to the save.
	/// </summary>
	/// <param name="number">The level number.</param>
	/// <param name="levelData">The level data.</param>
	void addLevel(int number, LevelData levelData);

	/// <summary>
	/// Get's the current level.
	/// </summary>
	/// <returns>The current level.</returns>
	LevelData getCurrentLevel();

	/// <summary>
	/// Get's a level by index.
	/// </summary>
	/// <param name="i">The index.</param>
	/// <returns>The level with the given index.</returns>
	LevelData getLevelByIndex(int i);

	/// <summary>
	/// Get's the next level.
	/// </summary>
	/// <returns>The next level.</returns>
	LevelData getNextLevel();
	
	/// <summary>
	/// Get's a level index by name.
	/// </summary>
	/// <param name="name">The level name.</param>
	/// <returns>The level index.</returns>
	int getIndexByLevelName(std::string name);

	/// <summary>
	/// Checks if the given level is a story level.
	/// </summary>
	/// <param name="levelData">The level.</param>
	/// <returns>If the given level is a story level.</returns>
	bool isStoryLevel(LevelData levelData);
};

