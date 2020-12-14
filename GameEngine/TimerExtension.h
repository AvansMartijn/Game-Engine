#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_TimerExtension __declspec(dllexport)
#else
#define GAMEENGINE_TimerExtension __declspec(dllimport)
#endif
#include "AbstractGameObjectExtension.h"
#include "AbstractManageableItem.h"
#include "GameObject.h"
#include "Scene.h"
#include "Physics.h"

class GAMEENGINE_TimerExtension TimerExtension : public AbstractGameObjectExtension {
private:
	std::chrono::steady_clock::time_point _creationTime;
	long _expiresAfter;
public:
	TimerExtension();

	/// <summary>
	/// Get's the creation time.
	/// </summary>
	/// <returns>The creation time.</returns>
	std::chrono::steady_clock::time_point getCreationTime();

	/// <summary>
	/// Get's the time it takes to expire.
	/// </summary>
	/// <returns>The time it takes to expire.</returns>
	long getExpiresAfter();

	/// <summary>
	/// Checks if the object has expired.
	/// </summary>
	/// <returns>If the object has expired.</returns>
	bool isExpired();

	/// <summary>
	/// Set's the expiration time.
	/// </summary>
	/// <param name="miliseconds">The expiration time in ms.</param>
	void setExpiresAfter(int miliseconds);

	/// <summary>
	/// Fills the extensions with the given properties.
	/// </summary>
	/// <param name="properties">The properties we want to use</param>
	void fillProperties(std::map<std::string, ExtensionProperty> properties);

	static AbstractGameObjectExtension* __stdcall create() { return new TimerExtension(); }
};

