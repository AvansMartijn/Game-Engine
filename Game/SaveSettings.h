#pragma once
#include "json.h"
#include "SaveKeybindings.h"

class SaveSettings {
public:
	SaveKeybindings cm;
	int sound = 60;
	int soundFx = 60;
};

inline void to_json(nlohmann::json& j, const SaveSettings& s) {
	j = nlohmann::json{ 
		{ "sound", s.sound },
		{ "soundFx", s.soundFx },
		{ "cm", s.cm }
	};
}

inline void from_json(const nlohmann::json& j, SaveSettings& s) {
	j.at("sound").get_to(s.sound);
	j.at("soundFx").get_to(s.soundFx);
	j.at("cm").get_to(s.cm);
}


