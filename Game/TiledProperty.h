#pragma once
#include "json.h"
#include "ExtensionProperty.h"

class TiledProperty {
private:
public:
	std::string name;
	std::string type;
	bool valueBool;
	float valueFloat;
	int valueInt;
	std::string valueString;

	ExtensionProperty toExtensionProperty() {
		ExtensionProperty extensionProperty = ExtensionProperty(name, type, valueBool, valueFloat, valueInt, valueString);

		return extensionProperty;
	}
};

inline void from_json(const nlohmann::json& j, TiledProperty& p) {
	j.at("name").get_to(p.name);
	j.at("type").get_to(p.type);

	if (p.type == "bool")
		p.valueBool = j.at("value").get_to(p.valueBool);
	else if (p.type == "float")
		p.valueFloat = j.at("value").get_to(p.valueFloat);
	else if (p.type == "int")
		p.valueInt = j.at("value").get_to(p.valueInt);
	else if (p.type == "string")
		p.valueString = j.at("value").get_to(p.valueString);
}

