#pragma once
#include <AbstractContactListener.h>
#include <CustomUserData.h>
#include <memory>
#include "GameObject.h"
#include "Scene.h"
class ContactListener : public AbstractContactListener
{
public:
	void BeginContact(b2Contact* contact);
	void EndContact(b2Contact* contact);
};

