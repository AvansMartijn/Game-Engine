#pragma once

#include "GameObject.h"

/// <summary>
/// Physics Helper for the physics of the game
/// </summary>
class Physics
{
private:
	//std::vector<shared_ptr<GameObject>> _gameObjects;
public:
	/// <summary>
	/// Change the velocity of a game object
	/// </summary>
	/// <param name="object">The object to be changed</param>
	/// <param name="velocity">The new velocity</param>
	void changeVelocity(shared_ptr<GameObject> object, Vec2 velocity);
	/// <summary>
	/// Set the position of a game object
	/// </summary>
	/// <param name="object">The object to be changed</param>
	/// <param name="position">The new position</param>
	void setPosition(shared_ptr<GameObject> object, Vec2 position);
	/// <summary>
	/// Update the position of a game object, applying all physics forces like gravity.
	/// </summary>
	/// <param name="object">The object to be updated</param>
	void updatePosition(shared_ptr<GameObject> object);
	/// <summary>
	/// Add gravity to a game object
	/// </summary>
	/// <param name="object">The game object to get Gravity</param>
	void addGravityForce(shared_ptr<GameObject> object);

};

