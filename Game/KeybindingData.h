#pragma once
#include <string>
#include <SDL.h>
#include "json.h"

class KeybindingData
{
public:
	std::string defaultKey;
	std::string userKey;
	SDL_Scancode defaultSDLKey;
	SDL_Scancode userSDLKey;
	bool isDefault = true;

	KeybindingData();

	KeybindingData(std::string defaultKey, SDL_Scancode defaultSDLKey) {
		defaultKey = defaultKey;
		defaultSDLKey = defaultSDLKey;
	}

	KeybindingData(std::string defaultKey, std::string userKey, SDL_Scancode defaultSDLKey, SDL_Scancode userSDLKey) {
		defaultKey = defaultKey;
		userKey = userKey;
		defaultSDLKey = defaultSDLKey;
		userSDLKey = userSDLKey;
	}
};

inline void to_json(nlohmann::json& j, const KeybindingData& l) {
	j = nlohmann::json{
		{ "defaultKey", l.defaultKey },
		{ "userKey", l.userKey },
		{ "defaultSDLKey", l.defaultSDLKey },
		{ "userSDLKey", l.userSDLKey }
	};
}

inline void from_json(const nlohmann::json& j, KeybindingData& l) {
	j.at("defaultKey").get_to(l.defaultKey);
	j.at("userKey").get_to(l.userKey);
	j.at("defaultSDLKey").get_to(l.defaultSDLKey);
	j.at("userSDLKey").get_to(l.userSDLKey);
}

