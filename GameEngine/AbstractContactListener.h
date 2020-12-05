#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_AbstractContactListener __declspec(dllexport)
#else
#define GAMEENGINE_AbstractContactListener __declspec(dllimport)
#endif
#include <Box2D.h>


class Physics;
class GAMEENGINE_AbstractContactListener AbstractContactListener : public b2ContactListener
{
public:
	virtual void BeginContact(b2Contact* contact) = 0;

	virtual void EndContact(b2Contact* contact) = 0;

};
