#pragma once
#include "SaveLevel.h"
#include "SaveSettings.h"
#include <string>
#include <vector>

class SaveGame
{
private:
public:
	std::vector<SaveLevel> levels;
	SaveSettings settings;
	int currentLevel;
};

inline void to_json(nlohmann::json& j, const SaveGame& sg) {
	j = nlohmann::json{
		{ "levels", sg.levels },
		{ "settings", sg.settings },
		{ "currentLevel", sg.currentLevel }
	};
}

inline void from_json(const nlohmann::json& j, SaveGame& sg) {
	j.at("levels").get_to(sg.levels);
	j.at("settings").get_to(sg.settings);
	j.at("currentLevel").get_to(sg.currentLevel);
}