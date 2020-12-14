#include "pch.h"
#include "IsPortalableExtension.h"

IsPortalableExtension::IsPortalableExtension() {
	type = getType();
}

void IsPortalableExtension::fillProperties(std::map<std::string, ExtensionProperty> properties) {}