#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_DefaultEntityAI __declspec(dllexport)
#else
#define GAMEENGINE_DefaultEntityAI __declspec(dllimport)
#endif
#include "AbstractEntityAI.h"

class GAMEENGINE_DefaultEntityAI DefaultEntityAI : public AbstractEntityAI
{
public:

	/// <summary>
	/// Create the behaviour tree.
	/// </summary>
	/// <param name="self">The player</param>
	void createBehaviourTree(shared_ptr<GameObject> self);
};

