#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_AbstractGameObjectExtension __declspec(dllexport)
#else
#define GAMEENGINE_AbstractGameObjectExtension __declspec(dllimport)
#endif

#include <memory>
#include <iostream>
#include "ExtensionProperty.h"
#include <vector>
#include <map>

using namespace std;

class GameObject;
class GAMEENGINE_AbstractGameObjectExtension AbstractGameObjectExtension {
protected:
	shared_ptr<GameObject> _subject;
public:
	string type;

	/// <summary>
	/// Registers the subject of the extension.
	/// </summary>
	/// <param name="subject">The subject of the extension.</param>
	virtual void registerSubject(shared_ptr<GameObject> subject);

	/// <summary>
	/// Fills the extensions with the given properties.
	/// </summary>
	/// <param name="properties">The properties we want to use</param>
	virtual void fillProperties(std::map<std::string, ExtensionProperty> properties);
};

typedef AbstractGameObjectExtension* (__stdcall* CreateExtensionFn)(void);

