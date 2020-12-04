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

class GAMEENGINE_TimerExtension TimerExtension : public AbstractGameObjectExtension
{
private:
	std::chrono::steady_clock::time_point _creationTime;
	long _expiresAfter;
public:
	TimerExtension();
	std::chrono::steady_clock::time_point getCreationTime();
	long getExpiresAfter();
	bool isExpired();
	void setExpiresAfter(int miliseconds);

	static AbstractGameObjectExtension* __stdcall create() { return new TimerExtension(); }

};

