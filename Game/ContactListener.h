#pragma once
#include <AbstractContactListener.h>

class ContactListener : public AbstractContactListener
{
public:
	void BeginContact(b2Contact* contact);
	void EndContact(b2Contact* contact);
};

