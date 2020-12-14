#pragma once
#include "AbstractGameObjectExtension.h"
#include <map>

class IsPortalableExtension : public AbstractGameObjectExtension {
public:
	IsPortalableExtension();

	/// <summary>
	/// Fills the extensions with the given properties.
	/// </summary>
	/// <param name="properties">The properties we want to use</param>
	void fillProperties(std::map<std::string, ExtensionProperty> properties);

	static AbstractGameObjectExtension* __stdcall create() { return new IsPortalableExtension(); }

	static std::string __stdcall getType() { return "IsPortalableExtension"; }

};

