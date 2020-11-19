#pragma once
#include "json.h"

class SaveSettings
{
private:
public:
	int sound;
};

inline void to_json(nlohmann::json& j, const SaveSettings& s) {
	j = nlohmann::json{ 
		{ "sound", s.sound } 
	};
}

inline void from_json(const nlohmann::json& j, SaveSettings& s) {
	j.at("sound").get_to(s.sound);
}


