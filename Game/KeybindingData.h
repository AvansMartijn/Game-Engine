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

	KeybindingData(std::string _defaultKey, SDL_Scancode _defaultSDLKey) {
		defaultKey = _defaultKey;
		defaultSDLKey = _defaultSDLKey;
	}

	KeybindingData(std::string _defaultKey, std::string _userKey, SDL_Scancode _defaultSDLKey, SDL_Scancode _userSDLKey, bool _isDefault) {
		defaultKey = _defaultKey;
		userKey = _userKey;
		defaultSDLKey = _defaultSDLKey;
		userSDLKey = _userSDLKey;
		isDefault = _isDefault;
	}
};

inline void to_json(nlohmann::json& j, const KeybindingData& l) {
	j = nlohmann::json{
		{ "defaultKey", l.defaultKey },
		{ "userKey", l.userKey },
		{ "defaultSDLKey", l.defaultSDLKey },
		{ "userSDLKey", l.userSDLKey },
		{ "isDefault", l.isDefault }
	};
}

inline void from_json(const nlohmann::json& j, KeybindingData& l) {
	j.at("defaultKey").get_to(l.defaultKey);
	j.at("userKey").get_to(l.userKey);
	j.at("defaultSDLKey").get_to(l.defaultSDLKey);
	j.at("userSDLKey").get_to(l.userSDLKey);
	j.at("isDefault").get_to(l.isDefault);
}

