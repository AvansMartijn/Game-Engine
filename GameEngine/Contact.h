#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_Contact __declspec(dllexport)
#else
#define GAMEENGINE_Contact __declspec(dllimport)
#endif
#include <box2d.h>
#include <memory>
#include "Fixture.h"

class GAMEENGINE_Contact Contact{
private:
	b2Contact* _contact;
public:
	Contact(b2Contact* contact);

	/// <summary>
	/// Get's the second fixture.
	/// </summary>
	/// <returns>The first fixture.</returns>
	std::unique_ptr<Fixture> getFixtureA();

	/// <summary>
	/// Get's the first fixture.
	/// </summary>
	/// <returns>The second fixture.</returns>
	std::unique_ptr<Fixture> getFixtureB();
};

