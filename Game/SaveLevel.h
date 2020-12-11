#pragma once
#include "json.h"
#include <string>
#include "SaveHighscore.h"
#include <vector>

class SaveLevel {
public:
	std::string name;
	std::vector<SaveHighscore> highscores;
};

inline void to_json(nlohmann::json& j, const SaveLevel& l) {
	j = nlohmann::json{
		{ "name", l.name },
		{ "highscores", l.highscores }
	};
}

inline void from_json(const nlohmann::json& j, SaveLevel& l) {
	j.at("name").get_to(l.name);
	j.at("highscores").get_to(l.highscores);
}