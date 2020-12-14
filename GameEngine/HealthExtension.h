#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_HealthExtension __declspec(dllexport)
#else
#define GAMEENGINE_HealthExtension __declspec(dllimport)
#endif
#include "AbstractGameObjectExtension.h"

class GAMEENGINE_HealthExtension HealthExtension : public AbstractGameObjectExtension {
private:
	int _health;
public:
	HealthExtension();

	/// <summary>
	/// Get the current health.
	/// </summary>
	/// <returns>The current health.</returns>
	int getHealth();

	/// <summary>
	/// Set the current health.
	/// </summary>
	/// <param name="value">The new health.</param>
	void setHealth(int value);

	/// <summary>
	/// Reduce the current health with the given value.
	/// </summary>
	/// <param name="value">The amount of health we want to reduce.</param>
	void reduceHealth(int value);

	/// <summary>
	/// Fills the extensions with the given properties.
	/// </summary>
	/// <param name="properties">The properties we want to use</param>
	void fillProperties(std::map<std::string, ExtensionProperty> properties);

	static AbstractGameObjectExtension* __stdcall create() { return new HealthExtension(); }
};

