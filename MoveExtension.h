#pragma once
#include "AbstractGameObjectExtension.h"
#include "PhysicsFacade.h"


class MoveExtension : public AbstractGameObjectExtension
{
private:
	//float  _velocityX;
	//float  _velocityY;

	//a movable platform on rails
	//float _startX;
	//float _startY;
	//float _endX;
	//float _endY;

public:
	MoveExtension();
	static AbstractGameObjectExtension* __stdcall create() { return new MoveExtension(); }
	void move();
};

