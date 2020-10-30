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
	real staticFriction;
	real dynamicFriction;
	bool canRotate;

	void SetOrient(real orient);
	void CanRotate(bool canrotate);

	void ApplyImpulse(const Vec2& impulse, const Vec2& contactVector)
	{
		velocity += im * impulse;
		angularVelocity += iI * Cross(contactVector, impulse);
	}

	void IntegrateForces()
	{
		if (im == 0.0f)
			return;

		velocity += (force * im + gravity) * (2.0f);
		angularVelocity += torque * iI * (2.0f);
	}

	void IntegrateVelocity()
	{
		if (im == 0.0f)
			return;

		position += velocity * dt;
		orient += angularVelocity * dt;
		SetOrient(orient);
		IntegrateForces();
	}

};

