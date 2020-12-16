#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_Fixture __declspec(dllexport)
#else
#define GAMEENGINE_Fixture __declspec(dllimport)
#endif
#include <box2d.h>
#include <memory>
#include "Body.h"
#include "CustomUserData.h"
#include "FixtureFilter.h"

class GAMEENGINE_Fixture Fixture {
private:
	b2Fixture* _fixture;
public:
	Fixture(b2Fixture* fixture);

	/// <summary>
	/// Get's the body bound to this fixture.
	/// </summary>
	/// <returns>The body.</returns>
	std::unique_ptr<Body> getBody();
	
	/// <summary>
	/// Get's the user data bound to this fixture.
	/// </summary>
	/// <returns>The user data.</returns>
	CustomUserData* getUserData();

	/// <summary>
	/// Get's the filter data bound to this fixture.
	/// </summary>
	/// <returns>The filter data.</returns>
	std::unique_ptr<FixtureFilter> getFilterData();

	/// <summary>
	/// Set's the filter data.
	/// </summary>
	/// <param name="filterData">The filter data.</param>
	void setFilterData(std::unique_ptr<FixtureFilter> filterData);
};

