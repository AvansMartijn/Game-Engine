#include "pch.h"
#include "DoesDamageExtension.h"

DoesDamageExtension::DoesDamageExtension() {
	type = "DoesDamageExtension";
}

void DoesDamageExtension::fillProperties(std::map<std::string, ExtensionProperty> extensionProperties) {
	if (extensionProperties.find("damage") != extensionProperties.end())
		damage = extensionProperties["damage"].valueInt;
}
