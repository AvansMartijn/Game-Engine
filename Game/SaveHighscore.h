#pragma once
#include "json.h"
#include <string>

class SaveHighscore
{
private:
public:
	std::string name;
	int score;
};

inline void to_json(nlohmann::json& j, const SaveHighscore& hs) {
	j = nlohmann::json{ 
		{ "name", hs.name },
		{ "score", hs.score } 
	};
}

inline void from_json(const nlohmann::json& j, SaveHighscore& hs) {
	j.at("name").get_to(hs.name);
	j.at("score").get_to(hs.score);
}

