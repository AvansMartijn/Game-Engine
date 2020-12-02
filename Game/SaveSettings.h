#pragma once
#include "json.h"

class SaveSettings
{
private:
public:
	int sound = 60;
	int soundFx = 60;
};

inline void to_json(nlohmann::json& j, const SaveSettings& s) {
	j = nlohmann::json{ 
		{ "sound", s.sound },
		{ "soundFx", s.soundFx }
	};
}

inline void from_json(const nlohmann::json& j, SaveSettings& s) {
	j.at("sound").get_to(s.sound);
	j.at("soundFx").get_to(s.soundFx);
}


