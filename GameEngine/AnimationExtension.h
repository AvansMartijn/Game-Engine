#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_AnimationExtension __declspec(dllexport)
#else
#define GAMEENGINE_AnimationExtension __declspec(dllimport)
#endif
#include "AbstractGameObjectExtension.h"
#include "AbstractAnimationHandler.h"

class GAMEENGINE_AnimationExtension AnimationExtension : public AbstractGameObjectExtension {
private:
	shared_ptr<AbstractAnimationHandler> _animationHandler;
public:
	AnimationExtension();

	/// <summary>
	/// Register the animations.
	/// </summary>
	void registerAnimations();
	
	/// <summary>
	/// Set's the animation handler.
	/// </summary>
	/// <param name="animationHandler">The animation handler.</param>
	void setAnimationHandler(shared_ptr<AbstractAnimationHandler> animationHandler);

	/// <summary>
	/// Get's the animation handler.
	/// </summary>
	/// <returns>The animation handler.</returns>
	shared_ptr<AbstractAnimationHandler> getAnimationHandler();

	/// <summary>
	/// Executes the animation.
	/// </summary>
	void animate();

	/// <summary>
	/// Get's the current sprite rectangle.
	/// </summary>
	/// <returns>The sprite rectangle.</returns>
	Rect getCurrentSprite();

	/// <summary>
	/// If the sprite should be flipped.
	/// </summary>
	/// <returns>If the sprite should be flipped.</returns>
	bool shouldFlipLeft();

	static AbstractGameObjectExtension* __stdcall create() { return new AnimationExtension(); }
};