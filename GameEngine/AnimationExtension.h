#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_AnimationExtension __declspec(dllexport)
#else
#define GAMEENGINE_AnimationExtension __declspec(dllimport)
#endif
#include "AbstractGameObjectExtension.h"
#include "AbstractAnimationHandler.h"

class GAMEENGINE_AnimationExtension AnimationExtension : public AbstractGameObjectExtension
{
private:
	shared_ptr<AbstractAnimationHandler> _animationHandler;
public:
	AnimationExtension();

	void registerAnimations();
	void setAnimationHandler(shared_ptr<AbstractAnimationHandler> animationHandler);
	shared_ptr<AbstractAnimationHandler> getAnimationHandler();
	void animate();
	Rect getCurrentSprite();
	bool shouldFlipLeft();

	static AbstractGameObjectExtension* __stdcall create() { return new AnimationExtension(); }
};