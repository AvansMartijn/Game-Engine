#pragma once
#include <string>

class ExtensionProperty {
public:
	std::string name;
	std::string type;
	bool valueBool;
	float valueFloat;
	int valueInt;
	std::string valueString;

	ExtensionProperty() {}

	ExtensionProperty(std::string propertyName, std::string propertyType, bool propertyValueBool, float propertyValueFloat, int propertyValueInt, std::string propertyValueString) {
		name = propertyName;
		type = propertyType;
		valueBool = propertyValueBool;
		valueFloat = propertyValueFloat;
		valueInt = propertyValueInt;
		valueString = propertyValueString;
	}
};

