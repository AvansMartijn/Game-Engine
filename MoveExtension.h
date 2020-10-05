#pragma once
#include "AbstractGameObjectExtension.h"

class MoveExtension : AbstractGameObjectExtension
{
private:
	float  _velocityX;
	float  _velocityY;

	//voor een movable platform die heen hen weer gaat
	float _startX;
	float _startY;
	float _endX;
	float _endY;
};

