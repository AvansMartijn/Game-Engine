#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_AbstractEntityAI __declspec(dllexport)
#else
#define GAMEENGINE_AbstractEntityAI __declspec(dllimport)
#endif
#include <list>
#include "AbstractBehaviour.h"
#include "GameObject.h"
#include <chrono>

/// <summary>
/// Abstract class for entity ai
/// </summary>
class GAMEENGINE_AbstractEntityAI AbstractEntityAI {
protected:
	AbstractBehaviour* _currentBehaviour;
	std::chrono::steady_clock::time_point _begin;
public:
	AbstractEntityAI();

	/// <summary>
	/// Create the behaviour tree.
	/// </summary>
	/// <param name="self">The player</param>
	/// <param name="scene">All the game objects</param>
	virtual void createBehaviourTree(GameObject* self) = 0;

	/// <summary>
	/// Executes the current behaviour and goes to the next.
	/// </summary>
	virtual void execute();
};
