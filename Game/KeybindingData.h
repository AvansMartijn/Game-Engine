#pragma once
#include <string>
#include "json.h"
#include "Scancode.h"
class KeybindingData {
public:
	std::string defaultKey;
	std::string userKey;
	Scancode defaultScanKey;
	Scancode userScanKey;
	bool isDefault;

	KeybindingData();

	KeybindingData(const std::string& defaultKeyIn, const Scancode& defaultScanKeyIn) {
		defaultKey = defaultKeyIn;
		defaultScanKey = defaultScanKeyIn;
		isDefault = true;
	}

	KeybindingData(const std::string& defaultKeyIn, const std::string& userKeyIn, const Scancode& defaultScanKeyIn, const Scancode& userScanKeyIn, bool _isDefault) {
		defaultKey = defaultKeyIn;
		userKey = userKeyIn;
		defaultScanKey = defaultScanKeyIn;
		userScanKey = userScanKeyIn;
		isDefault = _isDefault;
	}
};

inline void to_json(nlohmann::json& j, const KeybindingData& l) {
	j = nlohmann::json{
		{ "defaultKey", l.defaultKey },
		{ "userKey", l.userKey },
		{ "defaultScanKey", l.defaultScanKey },
		{ "userScanKey", l.userScanKey },
		{ "isDefault", l.isDefault }
	};
}

inline void from_json(const nlohmann::json& j, KeybindingData& l) {
	j.at("defaultKey").get_to(l.defaultKey);
	j.at("userKey").get_to(l.userKey);
	j.at("defaultScanKey").get_to(l.defaultScanKey);
	j.at("userScanKey").get_to(l.userScanKey);
	j.at("isDefault").get_to(l.isDefault);
}

