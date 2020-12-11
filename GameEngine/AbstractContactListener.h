#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_AbstractContactListener __declspec(dllexport)
#else
#define GAMEENGINE_AbstractContactListener __declspec(dllimport)
#endif
#include <Box2D.h>

class Physics;
class GAMEENGINE_AbstractContactListener AbstractContactListener : public b2ContactListener {
public:
	/// <summary>
	/// When the contact begins.
	/// </summary>
	/// <param name="contact">The contact.</param>
	virtual void BeginContact(b2Contact* contact) = 0;

	/// <summary>
	/// When the contact ends.
	/// </summary>
	/// <param name="contact">The contact</param>
	virtual void EndContact(b2Contact* contact) = 0;
};
