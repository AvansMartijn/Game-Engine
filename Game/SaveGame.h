#pragma once
#include "SaveLevel.h"
#include "SaveSettings.h"
#include <string>
#include <vector>

class SaveGame {
public:
	std::vector<SaveLevel> levels;
	SaveSettings settings;
	int currentSlot;

	int slot1 = -1;
	int slot2 = -1;
	int slot3 = -1;
	int customSlot = -1;
};

inline void to_json(nlohmann::json& j, const SaveGame& sg) {
	j = nlohmann::json{
		{ "levels", sg.levels },
		{ "settings", sg.settings },
		{ "currentSlot", sg.currentSlot },
		{ "slot1", sg.slot1},
		{ "slot2", sg.slot2},
		{ "slot3", sg.slot3}
	};
}

inline void from_json(const nlohmann::json& j, SaveGame& sg) {
	j.at("levels").get_to(sg.levels);
	j.at("settings").get_to(sg.settings);
	j.at("currentSlot").get_to(sg.currentSlot);
	j.at("slot1").get_to(sg.slot1);
	j.at("slot2").get_to(sg.slot2);
	j.at("slot3").get_to(sg.slot3);
}