#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_AbstractEntityAI __declspec(dllexport)
#else
#define GAMEENGINE_AbstractEntityAI __declspec(dllimport)
#endif
#include <list>
#include "GameObject.h"

/// <summary>
/// Abstract class for entity ai
/// </summary>
class GAMEENGINE_AbstractEntityAI AbstractEntityAI
{
public:
	AbstractEntityAI();

	/// <summary>
	/// Create the behaviour tree.
	/// </summary>
	/// <param name="self">The player</param>
	/// <param name="scene">All the game objects</param>
	virtual void createBehaviourTree(shared_ptr<GameObject> self) = 0;
};
