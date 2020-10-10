#pragma once
#include "Body.h"

class Shape
{
public:
	Body body;
	Vec2 min;
	Vec2 max;
	int getWidth();
	int getHeight();
};

