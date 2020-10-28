#pragma once
#include "IEMath.h"

class Shape;

struct Body
{
	/// <summary>
	/// Position in Vec2{x, y}.
	/// </summary>
	Vec2 position;
	/// <summary>
	/// Velocity in Vec2{x, y}.
	/// </summary>
	Vec2 velocity;
	/// <summary>
	/// Angular velocity.
	/// </summary>
	real angularVelocity;
	/// <summary>
	/// Torque working on the object.
	/// </summary>
	real torque;
	/// <summary>
	/// Orientation (radians).
	/// </summary>
	real orient;
	/// <summary>
	/// Forces working on an object.
	/// </summary>
	Vec2 force;
	/// <summary>
	/// Moment of inertia.
	/// </summary>
	real I;
	/// <summary>
	/// Inverse inertia.
	/// </summary>	
	real iI;
	/// <summary>
	/// Mass.
	/// </summary>
	real m;
	/// <summary>
	/// Inverse Mass.
	/// </summary>
	real im;
	/// <summary>
	/// Restitution.
	/// </summary>
	real restitution;
};

