#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_AbstractCollisionResolutionExtension __declspec(dllexport)
#else
#define GAMEENGINE_AbstractCollisionResolutionExtension __declspec(dllimport)
#endif
#include "AbstractGameObjectExtension.h"

class GAMEENGINE_AbstractCollisionResolutionExtension AbstractCollisionResolutionExtension : public AbstractGameObjectExtension {
public:
	virtual bool isDefault() = 0;
	virtual void resolveCollision(shared_ptr<GameObject> otherObject) = 0;
};