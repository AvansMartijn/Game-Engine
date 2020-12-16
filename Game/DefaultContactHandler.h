#pragma once
#include "AbstractContactHandler.h"
#include <CustomUserData.h>
#include <GameObject.h>
#include <RotateObj.h>
#include <Physics.h>

class DefaultContactHandler : public AbstractContactHandler {
public:
	/// <summary>
	/// When the contact begins.
	/// </summary>
	/// <param name="contact">The contact.</param>
	void onBeginContact(std::unique_ptr<Contact> contact);

	/// <summary>
	/// When the contact ends.
	/// </summary>
	/// <param name="contact">The contact</param>
	void onEndContact(std::unique_ptr<Contact> contact);

	/// <summary>
	/// Check if the jump sensor was triggered.
	/// </summary>
	/// <param name="val">First object.</param>
	/// <param name="valB">Second object.</param>
	void checkJumpSensor(const CustomUserData& val, const CustomUserData& valB);

	/// <summary>
	/// Check if the left arm sensor was triggered.
	/// </summary>
	/// <param name="val">First object.</param>
	/// <param name="valB">Second object.</param>
	void checkLeftArmSensor(const CustomUserData& val, const std::unique_ptr<Body>& bodyB);

	/// <summary>
	/// Check if the right arm sensor was triggered.
	/// </summary>
	/// <param name="val">First object.</param>
	/// <param name="valB">Second object.</param>
	void checkRightArmSensor(const CustomUserData& val, const std::unique_ptr<Body>& bodyB);

	/// <summary>
	/// Check if the exit sensor was triggered.
	/// </summary>
	/// <param name="val">First object.</param>
	/// <param name="valB">Second object.</param>
	void checkExitSensor(const CustomUserData& valA, const CustomUserData& valB);

	void checkPickupSensor(const CustomUserData& valA, const CustomUserData& valB, GameObject* gameObjectA, GameObject* gameObjectB);
	void checkGlueBullet(CustomUserData& valA, const CustomUserData& valB, GameObject* gameObject, const CustomUserData& objA, const std::unique_ptr<Fixture>& fixtureA);
	void checkPortalBullet(const CustomUserData& valA, const CustomUserData& valB, const CustomUserData& objA, GameObject* gameObjectA, GameObject* gameObjectB);
	void checkTeleport(GameObject* gameObjectA, GameObject* gameObjectB, const CustomUserData& valB);
	void checkDamage(GameObject* gameObjectA, GameObject* gameObjectB);
};

