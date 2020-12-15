#pragma once
#include "AbstractGameObjectExtension.h"
#include "GameObject.h"

class DoesDamageExtension : public AbstractGameObjectExtension {
public:
	int damage;
	DoesDamageExtension();

	/// <summary>
	/// Fills the extensions with the given properties.
	/// </summary>
	/// <param name="properties">The properties we want to use</param>
	void fillProperties(std::map<std::string, ExtensionProperty> properties);

	static AbstractGameObjectExtension* __stdcall create() { return new DoesDamageExtension(); }

	static std::string __stdcall getType() { return "DoesDamageExtension"; }

};

