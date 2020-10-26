#pragma once
#include "Physics.h"
#include "Collision.h"
/// <summary>
/// Facade for physics subsystem.
/// </summary>
class PhysicsFacade
{
private:
	Physics _physics;
	Collision _collision;
public:
	/// <summary>
	/// Set the position of an object.
	/// </summary>
	/// <param name="gameObject">The object to set a position of.</param>
	/// <param name="position">The destination position.</param>
	void setPosition(shared_ptr<GameObject> gameObject, const Vec2& position);
	/// <summary>
	/// Update the position of an object, applying it's velocity to it's position.
	/// </summary>
	/// <param name="gameObject">The object of which the position should be updated.</param>
	void updatePosition(shared_ptr<GameObject> gameObject);
	/// <summary>
	/// Resolve collision between 2 objects, updating their velocities.
	/// </summary>
	/// <param name="objectA">Object A</param>
	/// <param name="objectB">Object B</param>
	void resolveCollision(shared_ptr<GameObject> objectA, shared_ptr<GameObject> objectB);
	/// <summary>
	/// Add the force of gravity to an objects velocity
	/// </summary>
	/// <param name="gameObject">The object to which gravity should be added.</param>
	void addGravityForce(shared_ptr<GameObject> gameObject);
	vector<shared_ptr<GameObject>> getCollisions(shared_ptr<GameObject> objectA, const std::vector<shared_ptr<GameObject>>& objectList);
};

