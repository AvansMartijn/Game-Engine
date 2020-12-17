#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_Body __declspec(dllexport)
#else
#define GAMEENGINE_Body __declspec(dllimport)
#endif
#include <Box2D.h>
#include "Vec2.h"
#include "CustomUserData.h"

enum BodyType {
	staticBody = 0,
	kinematicBody,
	dynamicBody
};

class GAMEENGINE_Body Body {
private:
	b2Body* _body;
public:
	Body();

	float width;
	float height;
	int canJump;

	/// <summary>
	/// Get Linear velocity of game object
	/// </summary>
	/// <returns>The linear velocity.</returns>
	Vec2 getLinearVelocity();

	/// <summary>
	/// Get Linear velocity of game object
	/// </summary>
	/// <returns>The linear velocity</returns>
	void setLinearVelocity(const Vec2& vel);

	/// <summary>
	/// Get's the position of the game object.
	/// </summary>
	/// <returns>The position of the game object</returns>
	Vec2 getPosition();

	/// <summary>
	/// Change the transform of the body.
	/// </summary>
	/// <param name="position">The position of the body.</param>
	/// <param name="angle">The angle of the body.</param>
	void setTransform(const Vec2& position, float angle);

	/// <summary>
	/// Get's the angle of the body.
	/// </summary>
	/// <returns>The angle.</returns>
	float getAngle();

	/// <summary>
	/// Get's the body type.
	/// </summary>
	/// <returns>The body type.</returns>
	BodyType getType();

	/// <summary>
	/// Set's the body type.
	/// </summary>
	/// <param name="bodyType">The new body type.</param>
	void setType(BodyType bodyType);

	/// <summary>
	/// Apply linear impulse to center.
	/// </summary>
	/// <param name="impulse">The impulse.</param>
	/// <param name="wake">If we should awake the body.</param>
	void applyLinearImpulseToCenter(const Vec2& impulse, bool wake);

	/// <summary>
	/// Set's the body from the box 2D version. FOR ENGINE USE ONLY. 
	/// </summary>
	/// <param name="body">The body.</param>
	void setBody(b2Body* body);

	/// <summary>
	/// Get's the original pointer from the box 2D version. FOR ENGINE USE ONLY.
	/// </summary>
	/// <returns></returns>
	b2Body* getOriginal();

	/// <summary>
	/// Get's the user data.
	/// </summary>
	/// <returns>The user data.</returns>
	CustomUserData* getUserData();
};

