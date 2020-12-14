#include "pch.h"
#include "AnimationExtension.h"

AnimationExtension::AnimationExtension() {
	type = "AnimationExtension";
}

void AnimationExtension::setAnimationHandler(shared_ptr<AbstractAnimationHandler> animationHandler) {
	_animationHandler = animationHandler;
}

shared_ptr<AbstractAnimationHandler> AnimationExtension::getAnimationHandler() {
	return _animationHandler;
}

void AnimationExtension::registerAnimations() {
	if (_animationHandler != nullptr)
		_animationHandler->registerAnimations();
}

void AnimationExtension::animate() {
	if (_animationHandler != nullptr)
		_animationHandler->animate(_subject);
}

Rect AnimationExtension::getCurrentSprite() {
	return _animationHandler->sprite;
}

bool AnimationExtension::shouldFlipLeft() {
	return _animationHandler->shouldFlipLeft;
}


void AnimationExtension::fillProperties(std::map<std::string, ExtensionProperty> properties) {

}
