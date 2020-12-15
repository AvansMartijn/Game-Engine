#pragma once

#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_Physics __declspec(dllexport)
#else
#define GAMEENGINE_Physics __declspec(dllimport)
#endif

#ifndef Physics_h
#define Physics_h


#include <Box2D.h>
#include <memory>
#include "GameObject.h"
#include "AbstractContactListener.h"
#include "CustomUserData.h"
#include "TeleportObject.h"
#include "Scene.h"
#include "RotateObj.h"
#include "AbstractContactListener.h"

class CollisionListener;
class GAMEENGINE_Physics Physics {
private:
	Physics();
	static Physics instance;

	// TODO: DEZE WEG WERKEN.
	b2World* _world;
	b2Vec2 _gravity;
	shared_ptr<AbstractContactListener> _colListener;
public:
	static Physics& getInstance() { return instance; }

	// prohibit copy & move
	Physics(const Physics&) = delete;
	Physics(Physics&&) = delete;
	Physics& operator=(const Physics&) = delete;
	Physics& operator=(Physics&&) = delete;
	
	vector<TeleportObject> teleportQueue;
	vector<RotateObj> rotateQueue;
	vector<shared_ptr<GameObject>> setStaticQueue;
	vector<int> deleteQueue;
	vector<int> expirationQueue;

	/// <summary>
	/// Executes a step in the wordl.
	/// </summary>
	/// <param name="timeStep">The time step we want to use.</param>
	/// <param name="velocityIterations">The amount of velocity iterations.</param>
	/// <param name="positionIterations">The amount of position iterations.</param>
	void step(float timeStep, int velocityIterations, int positionIterations);

	/// <summary>
	/// Adds a player to the world.
	/// </summary>
	/// <param name="obj">The player.</param>
	/// <param name="x">The x-coordinate.</param>
	/// <param name="y">The y-coordinate.</param>
	/// <param name="width">The width</param>
	/// <param name="height">The height.</param>
	void addPlayer(shared_ptr<GameObject> obj, float x, float y, float width, float height);

	/// <summary>
	/// Adds an entity to the world.
	/// </summary>
	/// <param name="obj">The entity.</param>
	/// <param name="x">The x-coordinate.</param>
	/// <param name="y">The y-coordinate.</param>
	/// <param name="width">The width</param>
	/// <param name="height">The height.</param>
	/// <param name="userDataType">The identifier.</param>
	void addEntity(shared_ptr<GameObject> obj, float x, float y, float width, float height, std::string userDataType = "entityFixture");

	/// <summary>
	/// Adds a portal to the world.
	/// </summary>
	/// <param name="obj">The player.</param>
	/// <param name="x">The x-coordinate.</param>
	/// <param name="y">The y-coordinate.</param>
	/// <param name="width">The width</param>
	/// <param name="height">The height.</param>
	void addNonRigidBody(shared_ptr<GameObject> obj, float x, float y, float width, float height, std::string userDataType);

	/// <summary>
	/// Adds a body to the world.
	/// </summary>
	/// <param name="obj">The player.</param>
	/// <param name="x">The x-coordinate.</param>
	/// <param name="y">The y-coordinate.</param>
	/// <param name="width">The width</param>
	/// <param name="height">The height.</param>
	/// <param name="friction">The friction.</param>
	/// <param name="fixed">If this body should be affected by collisions.</param>
	/// <param name="fixedRotation">If the rotation should be effected by collisions.</param>
	void addBody(shared_ptr<GameObject> obj, float x, float y, float width, float height, float friction, bool fixed, bool fixedRotation, bool isBullet = false, std::string userDataType = "fixture");

	/// <summary>
	/// Reset the physics.
	/// </summary>
	void reset();

	/// <summary>
	/// Executes the queued teleports.
	/// </summary>
	void executeTeleportQueue();

	/// <summary>
	/// Executes the queued deletes.
	/// </summary>
	void executeDeleteQueue();

	/// <summary>
	/// Executes the queued deletes.
	/// </summary>
	void executeSetStaticQueue();

	/// <summary>
	/// Executes the queued rotates.
	/// </summary>
	void executeRotateQueue();
	/// <summary>
	/// Executes the queued expirations.
	/// </summary>
	void executeExpirationQueue();

	/// <summary>
	/// Set's the contact listener.
	/// </summary>
	/// <param name="contactListener">The contact listener.</param>
	void setContactListener(shared_ptr<AbstractContactListener> contactListener);

	/// <summary>
	/// Clear all the queues.
	/// </summary>
	void clearAllQueues();

	/// <summary>
	/// Get Linear velocity of game object
	/// </summary>
	/// <param name="gameObject">The gameobject</param>
	/// <returns>The linear velocity.</returns>
	Vec2 getLinearVelocity(shared_ptr<GameObject> gameObject);

	/// <summary>
	/// Get Linear velocity of game object
	/// </summary>
	/// <param name="gameObject">The game object</param>
	/// <returns>The linear velocity</returns>
	void setLinearVelocity(shared_ptr<GameObject> gameObject, const Vec2& vel);

	/// <summary>
	/// Get's the position of the game object.
	/// </summary>
	/// <param name="gameObject">The game object.</param>
	/// <returns>The position of the game object</returns>
	Vec2 getPosition(shared_ptr<GameObject> gameObject);
};

#endif