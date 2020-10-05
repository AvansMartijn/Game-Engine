#pragma once
#include "IEMath.h"
struct Shape;

struct Body
{
	Vec2 position;
	Vec2 velocity;

	real angularVelocity;
	real torque;
	real orient; // radians

	Vec2 force;

	// Set by shape
	real I;  // moment of inertia
	real iI; // inverse inertia
	real m;  // mass
	real im; // inverse masee

	real restitution;
};

